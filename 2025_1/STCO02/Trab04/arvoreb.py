# 2023004480
# 2023006401

class noh:
	def __init__(self, fileName_="None"):
		#Todo noh corresponde a um arquivo no disco
		self.fileName = fileName_
		#a flag carregado indica se aquele noh jah foi lido do disco
		self.carregado = False
		#indica se o noh eh folha
		self.folha = True
		#lista das chaves e filhos ficam vazios ateh serem lidos do disco
		self.chaves = []
		self.filhos = []
		
	#  Quando essa funcao eh chamada o arquivo eh lido e chaves e filhos 
	#sao preenchidos, os filhos sao nos dumb com o nome do arquivo
	def carrega_arquivo(self, nome_arquivo):
		print("Lendo: ", nome_arquivo)
		self.carregado = True
		f = open(nome_arquivo, "r")
		i = 0
		for linha in f:
			if i % 2 == 0:
				if linha.strip('\n') != 'None':
					self.filhos.append(noh(linha.strip('\n')))
			else:
				self.chaves.append(int(linha))
			
			if i == 4:
				if len(self.filhos) != 0:
					self.folha = False
			i += 1



class arvoreB:
	def __init__(self, t, filename):
		self.t = t
		self.raiz = noh(filename)

	def busca(self, k, x):
		if x.carregado == False:
			#o nó existe mas não foi carregado
			x.carrega_arquivo(x.fileName)
		#procurando a chave ou o filho
		i = 0
		while i < len(x.chaves) and k > x.chaves[i]:
			i += 1
		
		if i < len(x.chaves) and k == x.chaves[i]:
			#encontrei a chave
			return (x, i)
		elif x.folha:
			#a chave k estaria no filho, mas x jah eh folha
			return None
		else:
			#a chave k esta no filho i
			return self.busca(k, x.filhos[i])
		


B = arvoreB(2, "0.tree")
i = int(input())
while(i != -1):
	if(B.busca(i, B.raiz) == None):
		print(str(i) + " nao encontrado")
	else:
		print(str(i) + " encontrado")
	i = int(input())
	
	
