/*
validação de expressões numéricas
permitido:
-(),[],{},+,-,*,/
-todo parentesis aberto tem q fechar
-nao pode parentesis vazio
-para cada parentesis aberto, deve haver uma operação aritmética envolvida (a nao ser que seja um par de parentesis que englobe toda a expressao)
(em exceção do caso acima, não pode haver outros símbolos um ao lado do outro)
*/

#include <iostream>
#include <string>
using namespace std;

bool isNumber(char a){
    if(a-'0'>=0 && a-'0'<=9) return true;
    return false;
}

int isPriority(char a){
    if(a=='(' || a==')')
        return 0;
    if(a=='[' || a==']')
        return 1;
    if(a=='{' || a =='}') 
        return 2;
    return -1;
}

bool isOp(char a){
    if(a=='+' || a=='-' || a=='*' || a=='/') return true;
    return false;
}

bool validate(string exp){
    int nro = 0, op = 0, parenthesis = 0, chave = 0, colchete = 0,v;
    for(auto i : exp){
        v = isPriority(i);
        if(isNumber(i)) nro++;
        else if(isOp(i)) op++;
        else if(v != -1){
            if(v==0) {parenthesis++;}
            if(v==1) {colchete++;}
            if(v==2) {chave++;}
        } 
        else return false;
    }

    if(parenthesis%2!=0 || chave%2!=0 || colchete%2!=0) return false;
    if(nro != op+1) return false;
    if(nro==0) return false; //expressao sem nro é paia

    return true;
}

int main(){
    string exp;
    cin >> exp;
    if(validate(exp)) cout << "Valida" << endl;
    else cout << "Invalida" << endl;
    return 0;
}

/*
CASOS DE USO:

entradas:
((((((((((((((((((((2)-3)))))))))))))))))))
(8]
23+9+[8]
(3-(2+(3(2(1)2)3)4)2)
1+2+3+4+5+6+6+7+8+9+0+
1+2+4*(4/5)+(9-0)
1-2
[2]+[3-4]
{[{[{[{[{[{[{[{[{[]}]}]}]}]}]}]}]}]}

saídas:

*/