from abc import ABC, abstractmethod
from typing import List

class Cliente:
    def __init__(self, nome: str, email: str) -> None:
        self.__nome = nome
        self.__email = email

    @property
    def nome(self):
        return self.__nome

    @nome.setter
    def nome(self, value):
        self.__nome = value

    @property
    def email(self):
        return self.__email

    @email.setter
    def email(self, value):
        self.__email = value

    def getNome(self):
        return self.nome

    def getEmail(self):
        return self.email

class Produto(ABC):
    def __init__(self, codigo: int, desc: str, preco: float) -> None:
        self.__codigo = codigo
        self.__desc = desc
        self.__preco = preco

    @property
    def codigo(self):
        return self.__codigo

    @codigo.setter
    def codigo(self, value):
        self.__codigo = value

    @property
    def desc(self):
        return self.__desc

    @desc.setter
    def desc(self, value):
        self.__desc = value

    @property
    def preco(self):
        return self.__preco

    @preco.setter
    def preco(self, value):
        self.__preco = value

    def getCodigo(self):
        return self.codigo

    def getDesc(self):
        return self.desc

    def getPreco(self):
        return self.preco

    @abstractmethod
    def calculaImposto(self):
        pass

class ProdutoSoftware(Produto):
    def __init__(self, codigo: int, desc: str, preco: float, versao: str) -> None:
        super().__init__(codigo, desc, preco)
        self.__versao = versao

    @property
    def versao(self):
        return self.__versao

    @versao.setter
    def versao(self, value):
        self.__versao = value

    def getVersao(self):
        return self.versao

    def calculaImposto(self):
        preco = self.getPreco()

        if preco < 400:
            return preco * 0.05
        return preco * 0.07

class ProdutoHardware(Produto):
    def __init__(self, codigo: int, desc: str, preco: float, nroSerie: str) -> None:
        super().__init__(codigo, desc, preco)
        self.__nroSerie = nroSerie

    @property
    def nroSerie(self):
        return self.__nroSerie

    @nroSerie.setter
    def nroSerie(self, value):
        self.__nroSerie = value

    def getNroSerie(self):
        return self.nroSerie

    def calculaImposto(self):
        preco = self.getPreco()

        if preco < 500:
            return preco * 0.06
        return preco * 0.09

class ItemPedido:
    def __init__(self, nroItem: int, produto: Produto, quant: int) -> None:
        self.__nroItem = nroItem
        self.__produto = produto
        self.__quant = quant

    @property
    def nroItem(self):
        return self.__nroItem

    @nroItem.setter
    def nroItem(self, value):
        self.__nroItem = value

    @property
    def produto(self):
        return self.__produto

    @produto.setter
    def produto(self, value):
        self.__produto = value

    @property
    def quant(self):
        return self.__quant

    @quant.setter
    def quant(self, value):
        self.__quant = value

    def getNroItem(self):
        return self.nroItem

    def getProduto(self):
        return self.produto

    def getQuant(self):
        return self.quant

class Pedido:
    def __init__(self, numero: int, cliente: Cliente) -> None:
        self.__numero = numero
        self.__cliente = cliente
        self.__listaItens: List[ItemPedido] = []

    @property
    def numero(self):
        return self.__numero

    @numero.setter
    def numero(self, value):
        self.__numero = value

    @property
    def cliente(self):
        return self.__cliente

    @cliente.setter
    def cliente(self, value):
        self.__cliente = value

    @property
    def listaItens(self):
        return self.__listaItens

    @listaItens.setter
    def listaItens(self, value):
        self.__listaItens = value

    def getNumero(self):
        return self.numero

    def getCliente(self):
        return self.cliente

    def getListaItens(self):
        return self.listaItens

    def addItem(self, item: ItemPedido) -> None:
        self.listaItens.append(item)

    def maquinaOk(self) -> bool:
        checklist = {
            "gabinete": 0, # 100 - 199
            "placaMae": 0, # 200 - 299
            "processador": 0, # 300 - 399
            "ssd": 0, # 400 - 499
            "memoria": 0, # 500 - 599
            "sistemaOp": 0, # 600 - 699
        }

        for item in self.listaItens:
            codigo = item.getProduto().getCodigo()

            if codigo < 200:
                checklist['gabinete'] += 1
            elif codigo < 300:
                checklist['placaMae'] += 1
            elif codigo < 400:
                checklist['processador'] += 1
            elif codigo < 500:
                checklist['ssd'] += 1
            elif codigo < 600:
                checklist['memoria'] += 1
            else:
                checklist['sistemaOp'] += 1

        isOk = True
        for quant in checklist.values():
            if quant < 1:
                isOk = False

        return isOk

    def imprimePedido(self) -> bool:
        if self.maquinaOk() == False:
            return False

        somaTotal = 0

        print(f"Cliente: {self.getCliente().getNome()}", end="\n\n")

        print("Quant\t- Produto - Preço Unit - Preço Total")

        for item in self.getListaItens():
            quant = item.getQuant()
            produto = item.getProduto().getDesc()
            precoUnit = item.getProduto().getPreco() + item.getProduto().calculaImposto()
            precoTotal = quant * precoUnit

            print(f"{quant}\t- {produto} - {precoUnit:.1f} - {precoTotal:.1f}")

            somaTotal += precoTotal

        print()
        print(f"valor total: {somaTotal:.1f}")

        return True

if __name__ == "__main__":
    prod1 = ProdutoHardware(101, 'Gabinete Padrão', 200, '12345')
    prod2 = ProdutoHardware(102, 'Gabinete Gamer', 300, '23451')
    prod3 = ProdutoHardware(201, 'Placa Mãe ASUS ROG', 1400, '345123')
    prod4 = ProdutoHardware(202, 'Placa Mãe Gigabyte Elite', 1800, '45123')
    prod5 = ProdutoHardware(301, 'Intel Core I5', 900, '51234')
    prod6 = ProdutoHardware(302, 'AMD Ryzen 7', 700, '67890')
    prod7 = ProdutoHardware(401, 'SSD 256', 200, '78906')
    prod8 = ProdutoHardware(402, 'SSD 512', 300, '89067')
    prod9 = ProdutoHardware(501, 'Pente memória 8GB', 180, '90678')
    prod10 = ProdutoSoftware(601, 'Windows 11 Home Edition', 250, '23H2')

    cliente1 = Cliente('João Santos', 'santos@gmail.com')
    cliente2 = Cliente('Maria Souza', 'souza@gmail.com')

    pedido1 = Pedido(1001, cliente1)
    pedido1.addItem(ItemPedido(1, prod1, 1))
    pedido1.addItem(ItemPedido(2, prod3, 1))
    pedido1.addItem(ItemPedido(3, prod7, 1))
    pedido1.addItem(ItemPedido(4, prod9, 2))
    if not pedido1.imprimePedido():
        print("\nPedido está incompleto")

    pedido2 = Pedido(1002, cliente2)
    pedido2.addItem(ItemPedido(1, prod2, 1))
    pedido2.addItem(ItemPedido(2, prod4, 1))
    pedido2.addItem(ItemPedido(3, prod6, 1))
    pedido2.addItem(ItemPedido(4, prod8, 1))
    pedido2.addItem(ItemPedido(5, prod9, 2))
    pedido2.addItem(ItemPedido(6, prod10, 1))
    if not pedido2.imprimePedido():
        print("\nPedido está incompleto")
