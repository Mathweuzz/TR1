# Comunicação em Camadas

Este é um exemplo simples de implementação de comunicação em camadas em C++.

## Descrição

O programa simula a comunicação em camadas entre uma aplicação transmissora e uma aplicação receptora. A comunicação é dividida em diferentes camadas, cada uma realizando uma etapa específica do processo de transmissão e recepção de dados.

As camadas implementadas são as seguintes:

- Camada de Aplicação Transmissora: recebe uma mensagem da entrada do usuário e chama a próxima camada.
- Camada Física Transmissora: converte a mensagem em bits e aplica uma codificação específica de acordo com o tipo selecionado.
- Meio de Comunicação: simula a transmissão dos bits, transferindo-os para a camada física receptora.
- Camada Física Receptora: decodifica os bits recebidos e chama a próxima camada.
- Camada de Aplicação Receptora: converte os bits em mensagem original e exibe o resultado.

O programa atualmente suporta três tipos de codificação na camada física transmissora: binária, Manchester e bipolar. A decodificação correspondente é realizada na camada física receptora.

## Como Executar

1. Certifique-se de ter um compilador C++ instalado.
2. Clone este repositório.
3. Navegue até o diretório clonado e compile o programa com o seguinte comando:

   ```bash
   g++ -o comunicacao-camadas CamdaFisica.cpp

- Execute o programa com o seguinte comando:

  ```bash
  ./comunicacao-camadas

- Siga as instruções exibidas no console para interagir com o programa.
