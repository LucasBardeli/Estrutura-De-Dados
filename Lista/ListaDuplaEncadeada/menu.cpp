#include <iostream>
#include <limits>
#include "menu.h"

using namespace std;

void menuPrincipal(char *menu) {
    cout<<"\n\n*************  Menu  *************\n"
              "*** Lista Duplamente Encadeada ***\n\n";
    cout << "Informe a op��o desejada: \n"
    "1 - para cadastrar aluno no final da lista.\n"
    "2 - para cadastrar aluno no in�cio da lista.\n"
    "3 - para cadastrar aluno ordenado.\n"
    "4 - para remover um aluno do in�cio da lista\n"
    "5 - para remover um aluno do fim da lista.\n"
    "6 - para remover um  determinado aluno.\n"
    "7 - para consultar os dados do aluno a partir da matr�cula.\n"
    "8 - para consultar os dados do aluno a partir da posi��o.\n"
    "9 - para exibir a lista de alunos cadastrados.\n"
    "0 - para exibir a lista inversa de alunos cadastrados.\n"
    "-->  ";
    fflush(stdin);
    cin >> *menu;
}

void menuSaida(char *menu) {
    cout << "\nDigite S para sair. Ou outra tecla para continuar: ";
    fflush(stdin);
    cin >> *menu;
    *menu = toupper(*menu);
}

// fun��o acrescentada para poder garantir que ser� informado um n�mero real
float verificaNumReal() {
    float num;

    while(true) {
        cout << "\nDigite a nota do aluno: ";
        cin >> num;

        if (cin.fail()) {
            cin.clear();  // Limpa o estado de erro da entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o resto da linha
            cout << "\nEntrada inv�lida! Informar um n�mero!" << endl;
        }
        else {
            break;  // Se a entrada for v�lida, sai do loop
        }
    }
    return num;
}

// fun��o acrescentada para poder garantir que ser� informado um n�mero real
int verificaNumInt() {
    int num;

    while(true) {
        cout << "\nDigite a matr�cula do aluno: ";
        cin >> num;

        if (cin.fail()) {
            cin.clear();  // Limpa o estado de erro da entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o resto da linha
            cout << "\nEntrada inv�lida. Por favor, informar um n�mero inteiro." << endl;
        }
        else {
            break; // Se a entrada for v�lida, sai do loop
        }
    }
    return num;
}
