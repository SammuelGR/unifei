import tkinter as tk
from tkinter import ttk
from tkinter import messagebox

class Vinho:
    def __init__(self, codigo, nome, tipo, variedade, origem, preco):
        self.__codigo = codigo
        self.__nome = nome
        self.tipo = tipo
        self.variedade = variedade
        self.origem = origem
        self.preco = preco
    
    @property
    def codigo(self):
        return self.__codigo

    @property
    def nome(self):
        return self.__nome

    @property
    def tipo(self):
        return self.__tipo

    @tipo.setter
    def tipo(self, valor):
        self.tipos = ["Branco", "Tinto", "Rose", "Espumante"]
        if not valor in self.tipos:
            raise ValueError("Tipo inválido: {}".format(valor))
        else:
            self.__tipo = valor

    @property
    def variedade(self):
        return self.__variedade

    @variedade.setter
    def variedade(self, valor):
        self.variedades = ["Cabernet Sauvignon", "Carmenere", "Merlot", "Malbec", "Sauvignon Blanc", "Pinot Grigio"]
        if not valor in self.variedades:
            raise ValueError("Variedade inválida: {}".format(valor))
        else:
            self.__variedade = valor

    @property
    def origem(self):
        return self.__origem

    @origem.setter
    def origem(self, valor):
        self.paises = ["Brasil", "Argentina", "Chile", "Itália", "França", "Portugal", "África do Sul"]
        if not valor in self.paises:
            raise ValueError("Origem inválida: {}".format(valor))
        else:
            self.__origem = valor            

    @property
    def preco(self):
        return self.__preco

    @preco.setter
    def preco(self, valor):
        if valor < 20 or valor > 500:
            raise ValueError("Valor inválido: {}".format(valor))
        else:
            self.__preco = valor

    def getVinho(self):
        return "Nome: " + str(object=self.nome)\
        + "\nCodigo: " + str(object=self.codigo)\
        + "\nTipo: " + str(object=self.tipo)\
        + "\nVariedade: " + str(object=self.variedade)\
        + "\nOrigem: " + str(object=self.origem)\
        + "\nPreço: " + str(object=self.preco)
    

class LimiteInsereVinho(tk.Toplevel):
    def __init__(self, controle):

        tk.Toplevel.__init__(self)
        self.geometry('250x200')
        self.title("Vinho")
        self.controle = controle

        self.frameCodigo = tk.Frame(self)
        self.frameNome = tk.Frame(self)
        self.frameTipo = tk.Frame(self)
        self.frameVariedade = tk.Frame(self)
        self.frameOrigem = tk.Frame(self)
        self.framePreco = tk.Frame(self)
        self.frameButton = tk.Frame(self)
        
        self.frameCodigo.pack()
        self.frameNome.pack()
        self.frameTipo.pack()
        self.frameVariedade.pack()
        self.frameOrigem.pack()
        self.framePreco.pack()
        self.frameButton.pack()
      
        self.labelCodigo = tk.Label(self.frameCodigo, text="Codigo: ")
        self.labelNome = tk.Label(self.frameNome,text="Nome: ")
        self.labelTipo = tk.Label(self.frameTipo, text="Tipo: ")
        self.labelVariedade = tk.Label(self.frameVariedade, text="Variedade: ")
        self.labelOrigem = tk.Label(self.frameOrigem, text="Origem: ")
        self.labelPreco = tk.Label(self.framePreco, text="Preco: ")
        self.labelCodigo.pack(side="left")
        self.labelNome.pack(side="left")
        self.labelTipo.pack(side="left")
        self.labelVariedade.pack(side="left")
        self.labelOrigem.pack(side="left")
        self.labelPreco.pack(side="left")

        self.inputCodigo = tk.Entry(self.frameCodigo, width=10)
        self.inputNome = tk.Entry(self.frameNome, width=20)
        self.inputTipo = tk.Entry(self.frameTipo, width=15)
        self.inputVariedade = tk.Entry(self.frameVariedade, width=20)
        self.inputOrigem = tk.Entry(self.frameOrigem, width=15)
        self.inputPreco = tk.Entry(self.framePreco, width=10)
        self.inputCodigo.pack(side="left")
        self.inputNome.pack(side="left")
        self.inputTipo.pack(side="left")
        self.inputVariedade.pack(side="left")
        self.inputOrigem.pack(side="left")
        self.inputPreco.pack(side="left")
      
        self.buttonSubmit = tk.Button(self.frameButton ,text="Enter")      
        self.buttonSubmit.pack(side="left")
        self.buttonSubmit.bind("<Button>", controle.enterHandler)
      
        self.buttonClear = tk.Button(self.frameButton ,text="Clear")      
        self.buttonClear.pack(side="left")
        self.buttonClear.bind("<Button>", controle.clearHandler)  

        self.buttonFecha = tk.Button(self.frameButton ,text="Concluído")      
        self.buttonFecha.pack(side="left")
        self.buttonFecha.bind("<Button>", controle.fechaHandler)

    def mostraJanela(self, titulo, msg):
        messagebox.showinfo(titulo, msg)

class LimiteConsultaVinho(tk.Toplevel):
    def __init__(self, tipos, variedades, controle):

        tk.Toplevel.__init__(self)
        self.geometry('400x250')
        self.title("Consultar Vinhos")
        self.ctrl = controle

        self.frameCombos = tk.Frame(self)
        self.frameCombos.pack(pady=3)

        self.labelTipos = tk.Label(self.frameCombos,text="Tipos: ")
        self.labelTipos.pack(side="left")
        self.escolhaTipo = tk.StringVar()
        self.comboboxTipo = ttk.Combobox(self.frameCombos, width = 15 ,values=tipos, textvariable = self.escolhaTipo)
        self.comboboxTipo.pack(side="left")
        self.comboboxTipo.bind("<<ComboboxSelected>>", self.ctrl.exibeTipo)

        self.labelVariedade = tk.Label(self.frameCombos,text="Variedades: ")
        self.labelVariedade.pack(side="left")
        self.escolhaVariedade = tk.StringVar()
        self.comboboxVariedade = ttk.Combobox(self.frameCombos, width = 15 ,values=variedades, textvariable = self.escolhaVariedade)
        self.comboboxVariedade.pack(side="left")
        self.comboboxVariedade.bind("<<ComboboxSelected>>", self.ctrl.exibeVariedade)

        self.frameVinhos = tk.Frame(self)
        self.frameVinhos.pack()
        self.textVinhos = tk.Text(self.frameVinhos, height=20,width=40)
        self.textVinhos.pack()
        self.textVinhos.config(state=tk.DISABLED)

class CtrlVinho():
    def __init__(self, controlador):
        self.controlador = controlador
        self.listaVinhos =  []
    
    def cadastraVinho(self):
        self.limiteIns = LimiteInsereVinho(self)

    def consultaVinho(self):
        self.tipos = []
        self.variedades = []
        for vinho in self.listaVinhos:
            if(not vinho.tipo in self.tipos):
                self.tipos.append(vinho.tipo)
            if(not vinho.variedade in self.variedades):
                self.variedades.append(vinho.variedade)
        self.limiteCons = LimiteConsultaVinho(self.tipos, self.variedades, self)
    
    def enterHandler(self, event):
        codigo = self.limiteIns.inputCodigo.get()
        nome = self.limiteIns.inputNome.get()
        tipo = self.limiteIns.inputTipo.get()
        variedade = self.limiteIns.inputVariedade.get()
        origem = self.limiteIns.inputOrigem.get()
        preco = int(self.limiteIns.inputPreco.get())

        try:
            vinho = Vinho(codigo, nome, tipo, variedade, origem, preco)
            self.listaVinhos.append(vinho)            
            self.limiteIns.mostraJanela('Sucesso', 'Vinho cadastrado com sucesso')
            self.clearHandler(event)
        except ValueError as error:
            self.limiteIns.mostraJanela('Erro', error)            
    

    def clearHandler(self, event):
        self.limiteIns.inputCodigo.delete(0, len(self.limiteIns.inputCodigo.get()))
        self.limiteIns.inputNome.delete(0, len(self.limiteIns.inputNome.get()))
        self.limiteIns.inputTipo.delete(0, len(self.limiteIns.inputTipo.get()))
        self.limiteIns.inputVariedade.delete(0, len(self.limiteIns.inputVariedade.get()))
        self.limiteIns.inputOrigem.delete(0, len(self.limiteIns.inputOrigem.get()))
        self.limiteIns.inputPreco.delete(0, len(self.limiteIns.inputPreco.get()))
    
    def fechaHandler(self, event):
        self.limiteIns.destroy()

    def exibeTipo(self,event):
        self.limiteCons.comboboxVariedade.set("---")
        tipoSel = self.limiteCons.comboboxTipo.get()        
        self.limiteCons.textVinhos.config(state='normal')
        self.limiteCons.textVinhos.delete("1.0", tk.END)
        for vinho in self.listaVinhos:
            if(vinho.tipo == tipoSel):
                vinhoSel = vinho.getVinho() + "\n\n"
                self.limiteCons.textVinhos.insert(1.0, vinhoSel)
        self.limiteCons.textVinhos.config(state='disable')


    def exibeVariedade(self, event):
        self.limiteCons.comboboxTipo.set("---")
        variedadeSel = self.limiteCons.comboboxVariedade.get()
        self.limiteCons.textVinhos.config(state='normal')
        self.limiteCons.textVinhos.delete("1.0", tk.END)
        for vinho in self.listaVinhos:
            if(vinho.variedade == variedadeSel):
                vinhoSel = vinho.getVinho() + "\n\n"
                self.limiteCons.textVinhos.insert(1.0, vinhoSel)
        self.limiteCons.textVinhos.config(state='disable')