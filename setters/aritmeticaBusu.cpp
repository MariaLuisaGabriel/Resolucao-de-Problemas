#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <utility>
using namespace std;

int mdc(int a, int b){
    if(a==0) return b;
    mdc(b,a%b);
}

int mmc(){

}