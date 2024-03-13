#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <iomanip>
#include <utility>
using namespace std;

int det(pair<int,int> a, pair<int,int> b , pair<int,int> c){
    return abs(a.first*b.second + a.second*c.first + b.first*c.second - b.second*c.first - a.second*b.first - a.first*c.second); 
}

int main(){
    int n;
    pair<int,int> a,b,c;
    vector<double> v;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a.first >> a.second;
        cin >> b.first >> b.second;
        cin >> c.first >> c.second;

        v.push_back((double)(det(a,b,c)/2.0));
    }

    for(auto i : v){
        cout << fixed << setprecision(2) << i << endl;
    }

    return 0;
}
