dicio_girias = {
    'gg': 'good game',
    'hs': 'headshot',
    'fb': 'first blood',
    'smokar': 'soltar fumacinha',
    'pinar': 'erroar todos os tiros'
}

print(dicio_girias['gg'])

dicio_girias['dronar'] = 'soltar um drone'

print(dicio_girias['dronar'])
print(dicio_girias.get('dronar'))

dicio_girias[1] = 'um'
dicio_girias[(2, 3)] = 'dois tres'

print('dronar' in dicio_girias)
print('ns' not in dicio_girias)

print('\n')

for (k, v) in dicio_girias.items():
    print(f'{k}: {v}')

print('\n')

print(list(dicio_girias.keys()))
print(list(dicio_girias.values()))

print(dicio_girias.popitem())

novo_dicio = {
    'pinar': 'hokama',
    'ns': 'nice shot',
    'TR': 'terroristas',
    'CT': 'contra-terroristas'
}

dicio_girias.update(novo_dicio)

print('\n')

for (k, v) in dicio_girias.items():
    print(f'{k}: {v}')

print('\n')

print(len(dicio_girias))
dicio_girias.clear()
print(len(dicio_girias))

print('\n')

s1 = {5, 4, 3, 2, 1}
s2 = set([2, 4, 6, 8, 10])

print(s1)

print(1 in s1)
print(1 in s2)

print(s1 | s2)
print(s1.union(s2))

print(s1 & s2)
print(s1.intersection(s2))

print(s1 - s2)
print(s1.difference(s2))

print(s1 ^ s2)
print(s1.symmetric_difference(s2))

print(s1.issubset(s2))
print(s1 <= s2)

s3 = {1, 2}
print(s3.issubset(s1))
print(s3 <= s1)

print(s1.issuperset(s3))
print(s1 >= s3)

s1.add(6)
print(s1)
s1.remove(3)
print(s1)

s1.pop()
print(s1)
print('\n')

f1 = frozenset([1, 2, 3, 4,5])
f2 = frozenset({2, 4, 6, 8, 10})
print(f1)
print(f2)

dicio_girias[f1] = 'f1'
print(dicio_girias[f1])

# from collections
# namedtuple, defaultdict, OrderedDict, ChainMap, Counter, UserDict, deque
