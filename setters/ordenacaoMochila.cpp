//problema da mochila infinita do geraldo: produtos postos em pilha decrescente

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool decresc(double i, double j){
    return i>j;
}

int main(){
    int n;
    double m;
    vector<int> v;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> m;
        v.push_back(m);
    }

    sort(v.begin(), v.end(), decresc);
    for(auto i: v){
        cout << i << endl;
    }

    return 0;
}