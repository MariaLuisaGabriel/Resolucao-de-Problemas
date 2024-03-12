#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

unsigned long long int fatduplo(unsigned long long int n){
    if(n <= 2)
        return n;
    return n* fatduplo(n-2);
}

int main(){
    unsigned long long int n;
    cin >> n;
    cout << fatduplo(n) << endl;
    return 0;
}