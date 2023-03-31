#include <iostream>
#include <string>
#include <algorithm> // necessário para usar a função std::reverse()

using namespace std;

bool ehPalindromo(string palavra) {
    // Remove todos os espaços da palavra
    palavra.erase(remove(palavra.begin(), palavra.end(), ' '), palavra.end());

    // Verifica se a palavra invertida é igual à original
    string palavraInvertida = palavra;
    reverse(palavraInvertida.begin(), palavraInvertida.end());
    return palavra == palavraInvertida;
}

int main() {
	setlocale(LC_ALL, "");
    string mensagem;

    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);

    if (ehPalindromo(mensagem)) {
        cout << "A mensagem digitada é um palíndromo!" << endl;
    } else {
        cout << "A mensagem digitada não é um palíndromo." << endl;
    }

    return 0;
}