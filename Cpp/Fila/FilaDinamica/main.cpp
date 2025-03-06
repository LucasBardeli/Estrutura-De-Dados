#include <iostream>
#include <locale>
#include "FilaDinamica.h"

using namespace std;

char menuInicial() {
    char menu;
    cout << "\n --------- Menu --------\n"
            "1 - para inserir aluno na fila\n"
            "2 - para remover um aluno da fila\n"
            "3 - exibir os alunos cadastrados\n"
            "4 - consultar primeiro aluno.\n"
            "5 - consultar número de alunos cadastrados.\n"
            "--> ";
    fflush(stdin);
    cin >> menu;
    return menu;
}

char menuSaida() {
    char menu;
    cout << "\nDeseja sair do programa? S para sim "
            "e qualquer tecla para continuar...\n--> ";
    cin >> menu;
    menu = toupper(menu);
    return menu;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Aluno alunoN;
    char menu;
    int x, tam;
    Fila* fila = criarFila();

    do {
        menu = menuInicial();
        switch(menu) {
            case '1':
                cadastrarAluno(&alunoN);
                x = inserirFila (fila, &alunoN);
            break;
            case '2':
                x = removerFila(fila);
            break;
            case '3':
                exibirFila(fila);
            break;
            case '4':
                consultarFila(fila, &alunoN);
            break;
            case '5':
                tam = tamanhoFila(fila);
            break;
            default:
                cout << "\nOpção inválida!" << endl;
            break;
        }
        menu = menuSaida();
        system("clear||cls");

    } while(menu != 'S');

    liberarFila(fila);

    return 0;
}
