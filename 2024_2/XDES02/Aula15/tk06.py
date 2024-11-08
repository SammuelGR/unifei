# tk06.py
import tkinter as tk

class GUI:
   def __init__(self):
      self.janela = tk.Tk()
      self.frame1 = tk.Frame(self.janela)
      self.frame2 = tk.Frame(self.janela)
      self.frame3 = tk.Frame(self.janela)
      self.frame4 = tk.Frame(self.janela)
      self.frame1.pack()
      self.frame2.pack()
      self.frame3.pack()
      self.frame4.pack()

      self.labelInfo = tk.Label(self.frame1,text="Digite algo:")
      self.labelResult = tk.Label(self.frame2,text="Nada")
      self.labelInfo.pack(side="left")
      self.labelResult.pack(side="left")

      self.labelInfo2 = tk.Label(self.frame3,text="Digite mais:")
      self.labelResult2 = tk.Label(self.frame4,text="Nada 2")
      self.labelInfo2.pack(side="left")
      self.labelResult2.pack(side="left")

      self.buttonSubmit = tk.Button(self.janela,text="Enter", \
                                    command=self.submit)
      self.buttonSubmit.pack(side="left")

      self.buttonClear = tk.Button(self.janela,text="Clear", \
                                    command=self.clear)
      self.buttonClear.pack(side="left")

      # Criando o objeto Entry
      self.inputText = tk.Entry(self.frame1, width=20)
      self.inputText.pack(side="left")

      self.inputText2 = tk.Entry(self.frame3, width=20)
      self.inputText2.pack(side="left")

      self.janela.mainloop()

   # Criando as funções de callback
   def submit(self):
      # O texto pode ser recuperado do com o comando get()
      self.labelResult["text"] = self.inputText.get()
      self.labelResult2["text"] = self.inputText2.get()

   def clear(self):
      self.inputText.delete(0, len(self.inputText.get()))
      self.labelResult["text"] = "Nada"

      self.inputText2.delete(0, len(self.inputText2.get()))
      self.labelResult2["text"] = "Nada 2"

def main():
   GUI()

main()
