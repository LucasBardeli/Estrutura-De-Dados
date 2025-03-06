#include <iostream>
#include "menu.h"

using namespace std;

void menuPrincipal(char *menu) {
    cout<<"\n\n********* Menu! *********\n\n";
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
    "--> ";
    fflush(stdin);
    cin >> *menu;
}

void menuSaida(char *menu) {
    cout << "\nDeseja sair do programa ?" << endl;
    cout << "Digite S para sair. Ou outra tecla para continuar..." << endl;
    fflush(stdin);
    cin >> *menu;
    *menu = toupper(*menu);
}
