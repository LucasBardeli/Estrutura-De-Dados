#include <iostream>
#include <locale>
#include "FilaEstatica.h"

using namespace std;

char menuInicial() {
    char menu;
    cout <<"\n --------- Menu --------\n"
            "1 - para inserir aluno na fila\n"
            "2 - para remover um aluno da fila\n"
            "3 - exibir os alunos cadastrados\n"
            "--> ";
    fflush(stdin);
    cin >> menu;
    return menu;
}

char menuSaida() {
    char menu;
    cout<<"\nDeseja sair do programa? S para sim "
            "e qualquer tecla para continuar...\n--> ";
    cin >> menu;
    menu = toupper(menu);
    return menu;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    char menu;
    int x;
    Fila *fila;
    Aluno alunoN;
    fila = criarFila();

    do {
        menu = menuInicial();
        switch(menu) {
            case '1':
                if (fila->qtd == MAX)
                    cout << "\nFila cheia, imposs�vel inserir!" << endl;
                else {
                    cadastrarAluno(&alunoN);
                    x = inserirFila(fila,&alunoN);
                }
            break;
            case '2':
                x = removerFila(fila);
            break;
            case '3':
                exibirFila(fila);
            break;
            default:
                cout << "\nOp��o inv�lida!";
        }
        menu = menuSaida();
        system("cls");

    } while(menu != 'S');

    apagarFila(fila);

   return 0;
}
