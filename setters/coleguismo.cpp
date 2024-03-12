#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <utility>
using namespace std;

int fat(int i){
    if(i==0) return 1;
    
    return i*fat(i-1);
}

int main(){
    int n;
    cin >> n;
    cout << fat(n-1) << endl;
    return 0;
}