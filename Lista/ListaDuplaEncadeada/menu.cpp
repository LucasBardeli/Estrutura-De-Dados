#include <iostream>
#include <limits>
#include "menu.h"

using namespace std;

void menuPrincipal(char *menu) {
    cout<<"\n\n*************  Menu  *************\n"
              "*** Lista Duplamente Encadeada ***\n\n";
    cout << "Informe a opção desejada: \n"
    "1 - para cadastrar aluno no final da lista.\n"
    "2 - para cadastrar aluno no início da lista.\n"
    "3 - para cadastrar aluno ordenado.\n"
    "4 - para remover um aluno do início da lista\n"
    "5 - para remover um aluno do fim da lista.\n"
    "6 - para remover um  determinado aluno.\n"
    "7 - para consultar os dados do aluno a partir da matrícula.\n"
    "8 - para consultar os dados do aluno a partir da posição.\n"
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

// função acrescentada para poder garantir que será informado um número real
float verificaNumReal() {
    float num;

    while(true) {
        cout << "\nDigite a nota do aluno: ";
        cin >> num;

        if (cin.fail()) {
            cin.clear();  // Limpa o estado de erro da entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o resto da linha
            cout << "\nEntrada inválida! Informar um número!" << endl;
        }
        else {
            break;  // Se a entrada for válida, sai do loop
        }
    }
    return num;
}

// função acrescentada para poder garantir que será informado um número real
int verificaNumInt() {
    int num;

    while(true) {
        cout << "\nDigite a matrícula do aluno: ";
        cin >> num;

        if (cin.fail()) {
            cin.clear();  // Limpa o estado de erro da entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o resto da linha
            cout << "\nEntrada inválida. Por favor, informar um número inteiro." << endl;
        }
        else {
            break; // Se a entrada for válida, sai do loop
        }
    }
    return num;
}
