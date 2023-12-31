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

    plt.tight_layout()  # Adiciona espaço entre os gráficos para evitar sobreposição

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

    animation = canvas.new_timer(interval=500) 
    animation.add_callback(animate)
    animation.start()

# Cria a janela
janela = tk.Tk()
janela.title('Simulação de Codificação')
janela.attributes('-fullscreen', True)  # Inicia a janela em tela cheia

# Cria os componentes da interface
label = tk.Label(janela, text='Digite uma mensagem:')
label.pack()

entrada_texto = tk.Entry(janela)
entrada_texto.pack()

botao = tk.Button(janela, text='Exibir Gráficos', command=exibir_graficos)
botao.pack()

def fechar_janela(event=None):
    janela.quit()  # Encerra o loop principal da aplicação

janela.bind('<Escape>', fechar_janela)  # Associa a função de fechar janela ao evento <Escape>

janela.protocol("WM_DELETE_WINDOW", fechar_janela)  # Define a função a ser chamada quando a janela for fechada

# Inicia o loop da interface
janela.mainloop()
