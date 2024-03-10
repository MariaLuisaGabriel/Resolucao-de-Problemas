'''
Verificar se uma palavra/frase é palíndromo ou não.

CASOS DE USO:
Entradas:
arara
anilina
batata
tomate
osso
me mata
socorram me subino onibus em marrocos
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
AAAAAAAAAAAAAAAAAB
que SACOOOOOOOOO
SAAAAAAAAAAAS
SUUUUUUUUUUUS
AMOGUS
PAM PAM PAM PAM PAM PAM PAM
PAM PAM PAM
GERALDOOOOOOOOOOOOOOOOOOOOOOOOOOOO
ABCDEFGHIJKLMNOPQRSTUVWXYZYXWVUTSRQPNMLKJHGIFEDBA
AABBCCDDEE
OOOOOOOOMAGAAAAAAAAAAAAAAAA
rodador
o lobo ama o bolo

saídas:
sim
sim
nao
nao
sim
nao
sim
sim
nao
nao
sim
sim
nao
nao
nao
nao
sim
nao
nao
sim
sim
'''

str1 = input()
str2 = str1[::-1]

if str1==str2 : print("sim")
else : print("nao")