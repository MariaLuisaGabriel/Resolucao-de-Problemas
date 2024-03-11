#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdio>
#include <utility>
using namespace std;

int mdc(int a, int b){
    if(b==0) return a;
    mdc(b,a%b);
}

int mmc(int a, int b){
    return a*b/mdc(a,b);
}

int main(){
    int n,m;
    queue<int> horas,horas1;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> m;
        horas.push(m);
        horas1.push(m);
    }

    while(horas.size()!=1){
        n = horas.front();
        horas.pop();
        m = horas.front();
        horas.pop();

        horas.push(mmc(n,m));
    }

    n = horas.front();
    int i = 1;

    while(!horas1.empty()){
        cout << "onibus " << i << " : " << n/horas1.front() << " voltas;" << endl;
        horas1.pop();
        i++;
    }

    return 0;
}