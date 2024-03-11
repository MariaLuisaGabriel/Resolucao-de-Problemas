#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <utility>
using namespace std;

bool ordStr(string p1, string p2){
    int i = p1.compare(p2);
    if(i>0){
        return true;
    }
    else return false;
}

bool ordInt(pair<int,vector<string>> p1, pair<int,vector<string>> p2){
    return p1.first<p2.first;
}

int findInPair(vector<pair<int,vector<string>>> v, int i){
    int a = 0;
    for(auto j : v){
        if(j.first == i){
            return a;
        }
        a++;
    }

    return -1;
}

int main(){
    int corredor,index;
    vector<pair<int,vector<string>>> supermercado;
    string nome;
    char nomeC[100];
    while(1){
        scanf("%d",&corredor);
        if(corredor==0) break;
        scanf(" %[^\n]",nomeC);
        nome = nomeC;

        if(index = findInPair(supermercado,corredor)!=-1){
            supermercado.at(index).second.push_back(nome);
        }
        else{
            vector<string> g;
            g.push_back(nome);
            supermercado.push_back(make_pair(corredor,g));
        }
    }

    sort(supermercado.begin(), supermercado.end(), ordInt);

    for(int i = 0; i<supermercado.size(); i++){
        sort(supermercado[i].second.begin(),supermercado[i].second.end(),ordStr);
    }

    for(auto i: supermercado){
        cout << i.first << ": ";
        for(auto j : i.second){
            cout << j << "; ";
        }
        cout << endl;
    }

    return 0;
}