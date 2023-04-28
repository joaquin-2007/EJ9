#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int CambiarDictado(string frase) {
    int n = frase.size();
    string frase_invertida = frase;
    reverse(frase_invertida.begin(), frase_invertida.end());
    int tabla[n+1][n+1];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0 || j==0)
                tabla[i][j] = 0;
            else if(frase[i-1] == frase_invertida[j-1])
                tabla[i][j] = tabla[i-1][j-1] + 1;
            else
                tabla[i][j] = max(tabla[i-1][j], tabla[i][j-1]);
        }
    }
    return n - tabla[n][n];
}

int main() {
    string frase = "reconocer";
    int letras_faltantes = CambiarDictado(frase);
    cout << "La cantidad de letras que faltan para hacer la cadena palindroma es: " << letras_faltantes << endl;
    return 0;
}

