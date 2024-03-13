#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

long long int fat(long long int i){
    if(i==0) return 1;

    return i*fat(i-1);
}

long long int permute(map<char,int> m, int strSize){
    long long int total = fat(strSize);
    long long int repeticoes = 1;
    for(auto i: m){
        if(i.second>1){
            repeticoes*=fat(i.second);
        }
    }

    return total/repeticoes;
}

int main(){
    int n;
    string str;
    vector<long long int> resp;
    map<char,int> m;

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> str;
        for(auto j: str){
            if(m.find(j) == m.end()){//o mapa nao tem a letra
                m.insert(make_pair(j,1));
            }
            else{//o mapa tem a letra
                m[j]++;
            }
        }

        resp.push_back(permute(m,str.size()));
        m.clear();
    }

    for(auto i: resp){
        cout << i << endl;
    }
    return 0;
}
