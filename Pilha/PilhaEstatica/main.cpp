#include <iostream>
#include <locale>
#include "PilhaEstatica.h"

using namespace std;

char menuInicial() {
    char menu;
    cout << "\n --------- Menu --------\n"
            "1 - para inserir aluno na pilha\n"
            "2 - para remover um aluno da pilha\n"
            "3 - exibir o topo da pilha\n"
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

    char menu;
    Pilha *pilha;
    Aluno alunoN;
    pilha = criarPilha();

    do {
        menu = menuInicial();
        switch(menu) {
            case '1':
                if (pilha->qtd == MAX)
                    cout << "\nPilha cheia, impossível inserir!" << endl;
                else {
                    cadastrarAluno(&alunoN);
                    inserirPilha(pilha,&alunoN);
                }
            break;
            case '2':
                removerPilha(pilha);
            break;
            case '3':
                exibirTopo(pilha);
            break;
            default:
                cout << "\nOpção inválida!" << endl;
            break;
        }
        menu = menuSaida();
        system("cls");

    } while(menu != 'S');

    apagarPilha(pilha);

    return 0;
}
