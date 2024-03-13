#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <utility>
using namespace std;

long long int fat(long long int i){
    if(i==0) return 1;

    return i*fat(i-1);
}

int main(){
    long long int n,m;
    cin >> n >> m;
    cout << fat(n-1) - (m*fat(n-m)) << endl;
    return 0;
}
