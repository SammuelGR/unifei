import tkinter as tk
from tkinter import messagebox

class ModelCliente():
	def __init__(self, nome, email):
		self.__nome = nome
		self.__email = email

	@property
	def nome(self):
		return self.__nome

	@property
	def email(self):
		return self.__email

class View():
	def __init__(self, master, controller):
		self.controller = controller
		self.janela = tk.Frame(master)
		self.janela.pack()
		self.frame1 = tk.Frame(self.janela)
		self.frame2 = tk.Frame(self.janela)
		self.frame1.pack()
		self.frame2.pack()

		self.labelInfo1 = tk.Label(self.frame1,text="Nome: ")
		self.labelInfo2 = tk.Label(self.frame2,text="Email: ")
		self.labelInfo1.pack(side="left")
		self.labelInfo2.pack(side="left")

		self.inputText1 = tk.Entry(self.frame1, width=20)
		self.inputText1.pack(side="left")
		self.inputText2 = tk.Entry(self.frame2, width=20)
		self.inputText2.pack(side="left")

		self.buttonSubmit = tk.Button(self.janela,text="Salva")
		self.buttonSubmit.pack(side="left")
		self.buttonSubmit.bind("<Button>", controller.salvaHandler)

		self.buttonClear = tk.Button(self.janela,text="Limpa")
		self.buttonClear.pack(side="left")
		self.buttonClear.bind("<Button>", controller.clearHandler)

	def mostraJanela(self, titulo, mensagem):
		messagebox.showinfo(titulo, mensagem)

class Controller():
	def __init__(self):
		self.root = tk.Tk()
		self.root.geometry('300x100')
		self.listaClientes = []

		# Cria a view passando referência da janela principal e
		# de si próprio (controlador)
		self.view = View(self.root, self)

		self.root.title("Exemplo MVC")
		# Inicia o mainloop
		self.root.mainloop()

	def salvaHandler(self, event):
		nomeCli = self.view.inputText1.get()
		emailCli = self.view.inputText2.get()
		cliente = ModelCliente(nomeCli, emailCli)
		self.listaClientes.append(cliente)
		self.view.mostraJanela('Sucesso', 'Cliente cadastrado com sucesso')
		self.clearHandler(event)

	def clearHandler(self, event):
		self.view.inputText1.delete(0, len(self.view.inputText1.get()))
		self.view.inputText2.delete(0, len(self.view.inputText2.get()))

if __name__ == '__main__':
	c = Controller()
