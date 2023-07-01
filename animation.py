import tkinter as tk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

canvas = None  # Variável global para o objeto FigureCanvasTkAgg

def binarizar_mensagem():
    mensagem = entrada_texto.get()
    mensagem_binaria = ''.join(format(ord(char), '08b') for char in mensagem)
    bits = [int(bit) for bit in mensagem_binaria]
    return bits, mensagem

def codificar_binaria(bits):
    return bits

def codificar_manchester(bits):
    fluxo_codificado_manchester = []
    for bit in bits:
        if bit == 0:
            fluxo_codificado_manchester.extend([1, 0])
        else:
            fluxo_codificado_manchester.extend([0, 1])
    return fluxo_codificado_manchester

def codificar_bipolar(bits):
    fluxo_codificado_bipolar = []
    polaridade = 1
    for bit in bits:
        if bit == 0:
            fluxo_codificado_bipolar.append(0)
        else:
            fluxo_codificado_bipolar.append(polaridade)
            polaridade *= -1
    return fluxo_codificado_bipolar

def update_graph():
    bits, mensagem = binarizar_mensagem()
    fluxo_codificado_binaria = codificar_binaria(bits)
    fluxo_codificado_manchester = codificar_manchester(bits)
    fluxo_codificado_bipolar = codificar_bipolar(bits)

    plt.clf()  # Limpa a figura atual

    tamanho_bits = len(bits)
    
    plt.subplot(4, 1, 1)
    plt.step(range(tamanho_bits), bits, 'r', where='post')
    plt.title('Mensagem Binária')
    plt.xlabel('Amostras')
    plt.ylabel('Bit')
    plt.xlim([0, tamanho_bits])
    plt.ylim([-0.5, 1.5])
    plt.grid(True)

    plt.subplot(4, 1, 2)
    plt.step(range(tamanho_bits), fluxo_codificado_binaria, 'g', where='post')
    plt.title('Codificação Binaria')
    plt.xlabel('Amostras')
    plt.ylabel('Nível')
    plt.xlim([0, tamanho_bits])
    plt.ylim([-0.5, 1.5])
    plt.grid(True)

    plt.subplot(4, 1, 3)
    plt.step(range(len(fluxo_codificado_manchester)), fluxo_codificado_manchester, 'b', where='post')
    plt.title('Codificação Manchester')
    plt.xlabel('Amostras')
    plt.ylabel('Nível')
    plt.xlim([0, len(fluxo_codificado_manchester)])
    plt.ylim([-1.5, 1.5])
    plt.grid(True)

    plt.subplot(4, 1, 4)
    plt.step(range(len(fluxo_codificado_bipolar)), fluxo_codificado_bipolar, 'm', where='post')
    plt.title('Codificação Bipolar')
    plt.xlabel('Amostras')
    plt.ylabel('Nível')
    plt.xlim([0, len(fluxo_codificado_bipolar)])
    plt.ylim([-1.5, 1.5])
    plt.grid(True)

    canvas.draw()  # Atualiza o gráfico no canvas

def exibir_graficos():
    global canvas  # Declara a variável como global para acessá-la dentro da função
    bits, mensagem = binarizar_mensagem()
    fluxo_codificado_binaria = codificar_binaria(bits)
    fluxo_codificado_manchester = codificar_manchester(bits)
    fluxo_codificado_bipolar = codificar_bipolar(bits)

    fig, axs = plt.subplots(4, 1, figsize=(10, 8))
    canvas = FigureCanvasTkAgg(fig, master=janela)
    canvas.get_tk_widget().pack()

    def animate():
        update_graph()

    animation = canvas.new_timer(interval=1000)  # Atualiza o gráfico a cada 1000ms (1 segundo)
    animation.add_callback(animate)
    animation.start()

# Cria a janela
janela = tk.Tk()
janela.title('Simulação de Codificação')
janela.geometry('500x600')

# Cria os componentes da interface
label = tk.Label(janela, text='Digite uma mensagem:')
label.pack()

entrada_texto = tk.Entry(janela)
entrada_texto.pack()

botao = tk.Button(janela, text='Exibir Gráficos', command=exibir_graficos)
botao.pack()

# Inicia o loop da interface
janela.mainloop()
