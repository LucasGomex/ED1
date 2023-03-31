/*
Exercício 3 - À partir de uma lista de nomes disponível em um arquivo TXT, transforma-los em nomes no formato agenda telefônica. Exemplo:

José Antonio Santos Silva
Silva, José Antonio Santos
*/

#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");

    int linhas = 0;
    string linha;
    ifstream arq("lista2.txt");

    if (arq.is_open())
    {
        while (!arq.eof())
        {
            getline(arq, linha);
            linhas++;
        }
        arq.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    }

    string nomes[linhas];

    ifstream arq2("lista2.txt");

    if (arq2.is_open())
    {
        int i = 0;
        while (getline(arq2, linha)) {
  	
    string lastName = linha.substr(linha.find_last_of(" ") + 1);
    nomes[i++] = linha.erase(linha.find_last_of(" "))+" "+lastName[0]+"." ;
}


        arq2.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
        return 1;
    }

    ofstream arq3("citacoes.txt");
    if (arq3.is_open())
    {
        for (int i = 0; i < linhas; i++)
        {
            arq3 << nomes[i] << endl;
        }
        arq3.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
        return 1;
    }

    return 0;
}