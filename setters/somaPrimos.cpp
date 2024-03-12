#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool ehprimo(int a){
    for(int i = 2; i <= sqrt(a);i++)
        if(a%i == 0)
            return false;
    return true;
}

int main(){
    int n,soma = 0;
    vector<int> vector;
    cin >> n;
    while(n != 0){
        soma = 0;
        for(int i = 2; i <= n; i++)
            if(ehprimo(i))
                soma += i;
        vector.push_back(soma);
        cin >> n;
    }

    for(auto i : vector){
        cout << i << " - ";
        if(ehprimo(i))
            cout << "sim" << endl;
        else cout << "nao" << endl;
    }

    return 0;
}