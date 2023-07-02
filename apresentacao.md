# Apresentação

## Introdução (Gabriel)

Bom dia. Hoje, temos o prazer de apresentar a vocês as codificações binária, Manchester e bipolar. Essas técnicas são amplamente utilizadas na transmissão de dados digitais e desempenham um papel fundamental na comunicação eficiente e confiável. Nesta apresentação, iremos explorar cada uma delas em detalhes, discutindo seus princípios de funcionamento, características e aplicações.

## Codificação Binária (Guilherme)

A codificação binária é a forma mais básica de representação de dados digitais, onde cada bit é representado por um sinal de dois níveis: 0 ou 1. Essa codificação é amplamente utilizada em sistemas digitais, como computadores e redes, devido à sua simplicidade e facilidade de implementação. No entanto, ela possui algumas limitações, como a sensibilidade a erros de transmissão em ambientes ruidosos.

## Codificação Mancherster (Mateus)

A codificação Manchester é uma técnica de codificação que resolve o problema de sensibilidade a erros da codificação binária. Nessa codificação, cada bit é dividido em dois intervalos de tempo e representado por uma transição de sinal. Se o bit for 0, ocorre uma transição de sinal de alto para baixo. Já se o bit for 1, ocorre uma transição de sinal de baixo para alto. Essa codificação é auto-sincronizável e garante uma taxa de transmissão de pelo menos o dobro da taxa de bits.

## Codificação Bipolar (Yuiti)

A codificação bipolar é uma técnica que utiliza níveis de tensão positivos e negativos para representar os bits. Nessa codificação, o sinal assume três níveis: positivo, negativo e zero. O bit 0 é representado por um sinal de zero volts, enquanto o bit 1 é representado alternadamente por um sinal positivo e negativo. Essa técnica é amplamente utilizada em sistemas de transmissão de longa distância, pois reduz o problema da distorção de sinal e melhora a detecção de erros.

## Comentário sobre a parte gráfica do código (Gabriel e Mateus)

Na parte gráfica do código apresentado, foi utilizada a biblioteca matplotlib em conjunto com tkinter para criar uma interface gráfica. A representação visual dos dados transmitidos é exibida por meio de gráficos.

A função update_graph() é responsável por atualizar os gráficos com as informações dos bits, além dos fluxos codificados nas técnicas binária, Manchester e bipolar.

A biblioteca matplotlib.pyplot é utilizada para criar os gráficos. Cada gráfico é adicionado em um subplot separado dentro de uma figura principal (fig) com uma disposição de 4 linhas e 1 coluna. Isso permite que os gráficos sejam exibidos em sequência verticalmente.

Para cada subplot, é utilizado o método plt.step() para traçar as linhas que representam os níveis dos sinais. Os parâmetros range() definem os valores do eixo x, enquanto os fluxos codificados correspondentes são utilizados como valores do eixo y. As cores e estilos de linha são configurados através dos parâmetros fornecidos, como 'r' para vermelho, 'g' para verde, 'b' para azul e 'm' para magenta.

Além disso, são definidos títulos para cada subplot com a função plt.title(), rótulos dos eixos x e y com plt.xlabel() e plt.ylabel(), respectivamente. Os limites dos eixos x e y são definidos com plt.xlim() e plt.ylim() para garantir que os gráficos sejam exibidos corretamente. A função plt.grid(True) é utilizada para exibir a grade nos gráficos.

Por fim, a função plt.tight_layout() é chamada para adicionar espaço entre os gráficos e evitar sobreposição. Após a configuração dos subplots, a função canvas.draw() é chamada para atualizar o gráfico no canvas.

No botão "Exibir Gráficos", a função exibir_graficos() é chamada quando o botão é clicado. Essa função cria a figura (fig) e o objeto FigureCanvasTkAgg responsável por vincular a figura à janela do tkinter. Em seguida, a função update_graph() é chamada repetidamente por meio de um temporizador (animation) para atualizar os gráficos a cada intervalo de tempo.

## Conclusão (Guilherme)

Nesta apresentação, discutimos as codificações binária, Manchester e bipolar, destacando suas características e aplicações. A codificação binária é simples, mas sensível a erros. A codificação Manchester resolve esse problema, garantindo uma taxa de transmissão mais alta. Já a codificação bipolar utiliza níveis de tensão positivos e negativos para melhorar a detecção de erros. Cada técnica tem suas vantagens e aplicações específicas, e é importante considerar os requisitos do sistema ao escolher a melhor codificação para uma determinada situação.