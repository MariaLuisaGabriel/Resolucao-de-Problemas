'''
validação de expressões numéricas
permitido:
-(),[],{},+,-,*,/
-todo parenteses aberto tem q fechar
-nao pode parenteses vazio
-para cada parenteses aberto, deve haver uma operação aritmética antes
(em exceção do caso acima, não pode haver outros símbolos um ao lado do outro)
'''

nroparnt = 0
parenteses = 0
algebrico = 0

exp = input()

for i in exp:
    if i == '(' :
        parenteses += 1
        nroparnt += 1
    elif i == ')' :
        parenteses += 1
        nroparnt += 1
        if algebrico>0 :
            parenteses = -1
            print('expressao invalida')
            break
    elif i == '+' :
        algebrico += 1
    elif i == '-' :
        algebrico += 1
    elif i == '*' :
        algebrico += 1
    elif i == '/' :
        algebrico += 1
    elif i == '[' :
        parenteses += 1
        nroparnt += 1
    elif i == ']' :
        parenteses += 1
        nroparnt += 1
        if algebrico>0 :
            parenteses = -1
            print('expressao invalida')
            break
    elif i == '{' :
        parenteses += 1
        nroparnt += 1
    elif i == '}' :
        parenteses += 1
        nroparnt += 1
        if algebrico>0 :
            parenteses = -1
            print('expressao invalida')
            break
    elif i.isnumeric() :
        parenteses = 0
        algebrico = 0
    else :
        parenteses = -1
        print('expressao invalida')
        break

    if algebrico>1:
        parenteses = -1
        print('expressao invalida')
        break

    if parenteses>1:
        parenteses = -1
        print('expressao invalida')
        break

if parenteses != -1 and nroparnt%2 == 0:
    print('expressao valida')

if nroparnt%2 != 0:
    print('expressao invalida')