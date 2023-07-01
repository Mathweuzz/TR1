#ifndef CAMADAFISICA_HPP
#define CAMADAFISICA_HPP

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

#endif