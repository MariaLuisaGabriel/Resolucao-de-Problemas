'''
Verificar se uma palavra/frase é palíndromo ou não.
'''

str1 = input()
str2 = str1[::-1]

if str1==str2 : print("sim")
else : print("nao")