/*
Exercício 1  - Receber através de digitação uma mensagem. 

Apresentar esta mensagem, centralizada, na linha 5 da tela.

À partir daí, cada letra desta mensagem deverá "cair", da linha 5 até a linha 20, simulando uma "cascata". Ao final, a mensagem deverá estar toda apresentada na linha 20.
*/

#include <iostream>
#include <locale.h>
#include <windows.h>
#include <string>
using namespace std;

void gotoxy(short x, short y) 
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");

    // Obtém a mensagem do usuário
    string mensagem;
    bool mostrar = true;
    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);
    int largura = mensagem.size();
    int posicao_x = (80 - largura) / 2;
    gotoxy(posicao_x, 5);
	for (int i = 0; i < mensagem.size(); i++) {
		gotoxy(posicao_x + (i+1), 5 + (i+1));
		if (i == 19) {
			mostrar = false;
      		gotoxy(posicao_x + (i+1), 20 + 5);
			cout << mensagem;
			break;
		}
		cout << mensagem[i];
	}
	if (mostrar == true) {
	gotoxy(posicao_x, 20);
	cout << mensagem;
	}
    return 0;
}