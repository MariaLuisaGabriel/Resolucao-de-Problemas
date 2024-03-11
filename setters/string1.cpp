#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    int n;
    string str,str2;
    vector<string> palindromos;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        str2 = str;
        reverse(str.begin(),str.end());
        if(str == str2)
            palindromos.push_back(str2);
    }
    for(auto i : palindromos)
        cout << i << endl;

    return 0;
}
