#include <iostream>
#include <string>
#include <algorithm> // necess�rio para usar a fun��o std::reverse()

using namespace std;

bool ehPalindromo(string palavra) {
    // Remove todos os espa�os da palavra
    palavra.erase(remove(palavra.begin(), palavra.end(), ' '), palavra.end());

    // Verifica se a palavra invertida � igual � original
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
        cout << "A mensagem digitada � um pal�ndromo!" << endl;
    } else {
        cout << "A mensagem digitada n�o � um pal�ndromo." << endl;
    }

    return 0;
}