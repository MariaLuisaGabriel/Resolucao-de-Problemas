/*
DESCRI��O DO PROBLEMA A: Ordena��o por Tamanho

resumidamente: ordenar nomes de frutas pelo tamanho das palavras. Caso hajam palavras de mesmo tamanho,
ordenar em ordem alfab�tica.

recebe-se: 1<=N<=100 (n�mero de palavras do conjunto), e logo em seguida as palavras sem acento,
cada uma numa linha.

retorna-se: cada palavra em uma linha, na ordem prescrita.

Por Exemplo:

entrada: 
4
banana
abacaxi
uva
maca

sa�da:
uva
maca
banana
abacaxi

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	else return a.size() < b.size();
}

int main() {
	int n;
	string str;
	vector<string> vstr;

	cin >> n;
	for (int i = 0; i <= n; i++) {
		getline(cin, str);
		vstr.push_back(str);
	}

	std::sort(vstr.begin(), vstr.end()-1, cmp);

	for (auto i : vstr) {
		cout << i << endl;
	}

	return 0;
}