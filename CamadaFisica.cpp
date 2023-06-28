#include <iostream>
#include <string>
using namespace std;

void AplicacaoTransmissora();
void CamadaDeAplicacaoTransmissora(string mensagem);
void CamadaFisicaTransmissora(int quadro[], int tamanhoQuadro);
int* CamadaFisicaTransmissoraCodificacaoBinaria(int quadro[], int tamanhoQuadro);
int* CamadaFisicaTransmissoraCodificacaoManchester(int quadro[], int tamanhoQuadro);
int* CamadaFisicaTransmissoraCodificacaoBipolar(int quadro[], int tamanhoQuadro);
void MeioDeComunicacao(int fluxoBrutoDeBits[], int tamanhoFluxoBrutoDeBits);
void CamadaFisicaReceptora(int quadro[], int tamanhoQuadro);
int* CamadaFisicaReceptoraDecodificacaoBinaria(int quadro[], int tamanhoQuadro);
int* CamadaFisicaReceptoraDecodificacaoManchester(int quadro[], int tamanhoQuadro);
int* CamadaFisicaReceptoraDecodificacaoBipolar(int quadro[], int tamanhoQuadro);
void CamadaDeAplicacaoReceptora(int quadro[], int tamanhoQuadro);
void AplicacaoReceptora(string mensagem);

int main() {
    AplicacaoTransmissora();
    return 0;
}

void AplicacaoTransmissora() {
    string mensagem;
    cout << "Digite uma mensagem: " << endl;
    getline(cin, mensagem);

    // chama a próxima camada
    CamadaDeAplicacaoTransmissora(mensagem); // em um exemplo mais realístico, aqui seria dado um SEND do SOCKET
}

void CamadaDeAplicacaoTransmissora(string mensagem) {
    int tamanhoQuadro = mensagem.length(); // tamanho do quadro
    int* quadro = new int[tamanhoQuadro * 8]; // Criar um array de inteiros para representar os bits da mensagem (cada caractere tem 8 bits)

    // Converter a mensagem para bits e preencher o array quadro
    for (int i = 0; i < tamanhoQuadro; i++) {
        char caractere = mensagem[i];
        for (int j = 0; j < 8; j++) {
            quadro[i * 8 + j] = (caractere >> (7 - j)) & 1; // Converter cada caractere da mensagem para os bits correspondentes
        }
    }

    // chama a próxima camada
    CamadaFisicaTransmissora(quadro, tamanhoQuadro * 8);
}

void CamadaFisicaTransmissora(int quadro[], int tamanhoQuadro) {
    int tipoDeCodificacao = 0; // alterar de acordo com o teste
    int* fluxoBrutoDeBits = nullptr; // trabalhar com bits!!!
    int tamanhoFluxoBrutoDeBits = 0;

    switch (tipoDeCodificacao) {
        case 0: // codificacao binaria
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro, tamanhoQuadro);
            tamanhoFluxoBrutoDeBits = tamanhoQuadro;
            break;
        case 1: // codificacao Manchester
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro, tamanhoQuadro);
            tamanhoFluxoBrutoDeBits = tamanhoQuadro * 2;
            break;
        case 2: // codificacao bipolar
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(quadro, tamanhoQuadro);
            tamanhoFluxoBrutoDeBits = tamanhoQuadro * 2;
            break;
        default:
            cout << "Tipo de codificacao invalido" << endl;
            return;
    }

    // chama a próxima camada
    MeioDeComunicacao(fluxoBrutoDeBits, tamanhoFluxoBrutoDeBits);
}

int* CamadaFisicaTransmissoraCodificacaoBinaria(int quadro[], int tamanhoQuadro) {
    int* fluxoBrutoDeBits = new int[tamanhoQuadro];
    for (int i = 0; i < tamanhoQuadro; i++) {
        fluxoBrutoDeBits[i] = quadro[i];
    }
    return fluxoBrutoDeBits;
}

int* CamadaFisicaTransmissoraCodificacaoManchester(int quadro[], int tamanhoQuadro) {
    int* fluxoBrutoDeBits = new int[tamanhoQuadro * 2];
    for (int i = 0; i < tamanhoQuadro; i++) {
        if (quadro[i] == 0) {
            fluxoBrutoDeBits[i * 2] = 0;
            fluxoBrutoDeBits[i * 2 + 1] = 1;
        } else {
            fluxoBrutoDeBits[i * 2] = 1;
            fluxoBrutoDeBits[i * 2 + 1] = 0;
        }
    }
    return fluxoBrutoDeBits;
}

int* CamadaFisicaTransmissoraCodificacaoBipolar(int quadro[], int tamanhoQuadro) {
    int* fluxoBrutoDeBits = new int[tamanhoQuadro * 2];
    int estado = 1;
    for (int i = 0; i < tamanhoQuadro; i++) {
        if (quadro[i] == 0) {
            fluxoBrutoDeBits[i * 2] = 0;
            fluxoBrutoDeBits[i * 2 + 1] = 0;
        } else {
            fluxoBrutoDeBits[i * 2] = estado;
            fluxoBrutoDeBits[i * 2 + 1] = -estado;
            estado = -estado;
        }
    }
    return fluxoBrutoDeBits;
}

void MeioDeComunicacao(int fluxoBrutoDeBits[], int tamanhoFluxoBrutoDeBits) {
    // Aqui você pode simular a transmissão real, como adicionar ruídos, distorções, atrasos, etc.
    // Neste exemplo, o meio de comunicação simplesmente chama a próxima camada.
    CamadaFisicaReceptora(fluxoBrutoDeBits, tamanhoFluxoBrutoDeBits);
}   

void CamadaFisicaReceptora(int quadro[], int tamanhoQuadro) {
    int tipoDeDecodificacao = 0; // alterar de acordo com o teste
    int* fluxoBrutoDeBits = nullptr; // trabalhar com bits!!!
    int tamanhoFluxoBrutoDeBits = 0;

    switch (tipoDeDecodificacao) {
        case 0: // decodificacao binaria
            fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoBinaria(quadro, tamanhoQuadro);
            tamanhoFluxoBrutoDeBits = tamanhoQuadro;
            break;
        case 1: // decodificacao Manchester
            fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoManchester(quadro, tamanhoQuadro);
            tamanhoFluxoBrutoDeBits = tamanhoQuadro / 2;
            break;
        case 2: // decodificacao bipolar
            fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoBipolar(quadro, tamanhoQuadro);
            tamanhoFluxoBrutoDeBits = tamanhoQuadro / 2;
            break;
        default:
            cout << "Tipo de decodificacao invalido" << endl;
            return;
    }

    // chama a próxima camada
    CamadaDeAplicacaoReceptora(fluxoBrutoDeBits, tamanhoFluxoBrutoDeBits);
}

int* CamadaFisicaReceptoraDecodificacaoBinaria(int quadro[], int tamanhoQuadro) {
    int* fluxoBrutoDeBits = new int[tamanhoQuadro];
    for (int i = 0; i < tamanhoQuadro; i++) {
        fluxoBrutoDeBits[i] = quadro[i];
    }
    return fluxoBrutoDeBits;
}

int* CamadaFisicaReceptoraDecodificacaoManchester(int quadro[], int tamanhoQuadro) {
    int* fluxoBrutoDeBits = new int[tamanhoQuadro / 2];
    for (int i = 0; i < tamanhoQuadro; i += 2) {
        if (quadro[i] == 0 && quadro[i + 1] == 1) {
            fluxoBrutoDeBits[i / 2] = 0;
        } else if (quadro[i] == 1 && quadro[i + 1] == 0) {
            fluxoBrutoDeBits[i / 2] = 1;
        } else {
            cout << "Erro de decodificacao Manchester" << endl;
            return nullptr;
        }
    }
    return fluxoBrutoDeBits;
}

int* CamadaFisicaReceptoraDecodificacaoBipolar(int quadro[], int tamanhoQuadro) {
    int* fluxoBrutoDeBits = new int[tamanhoQuadro / 2];
    int estado = 1;
    for (int i = 0; i < tamanhoQuadro; i += 2) {
        if (quadro[i] == 0 && quadro[i + 1] == 0) {
            fluxoBrutoDeBits[i / 2] = 0;
        } else if (quadro[i] == estado && quadro[i + 1] == -estado) {
            fluxoBrutoDeBits[i / 2] = 1;
            estado = -estado;
        } else {
            cout << "Erro de decodificacao bipolar" << endl;
            return nullptr;
        }
    }
    return fluxoBrutoDeBits;
}

void CamadaDeAplicacaoReceptora(int quadro[], int tamanhoQuadro) {
    // Converter o array de bits para a mensagem original
    string mensagem = "";
    for (int i = 0; i < tamanhoQuadro / 8; i++) {
        char caractere = 0;
        for (int j = 0; j < 8; j++) {
            caractere = (caractere << 1) | quadro[i * 8 + j];
        }
        mensagem += caractere;
    }

    // chama a próxima camada
    AplicacaoReceptora(mensagem); // em um exemplo mais realístico, aqui seria dado um SEND do SOCKET
}

void AplicacaoReceptora(string mensagem) {
    cout << "Mensagem recebida: " << mensagem << endl;
}
