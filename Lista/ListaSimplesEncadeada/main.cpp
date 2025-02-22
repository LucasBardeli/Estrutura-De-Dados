#include <iostream>
#include <locale>
#include "ListaSimplesEncadeada.h"
#include "menu.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    Lista *inicioLista; //ponteiro para ponteiro da estrutura -> cabe�a da lista
    Aluno alunoN; //alunoN ser� usado no preenchimento do cadastroAluno
    char menu;
    int x; //usado para receber o retorno das fun��os (n�o � obrigat�rio, pois n�o usaremos mais a fun��o retornoOperacao)

    inicioLista = criarLista();
    do {
        menuPrincipal(&menu);
        switch(menu) {
            case '1':
                cadastrarAluno(&alunoN);
                x = inserirFinal (inicioLista, &alunoN);
                //retornoOperacao(x);
            break;
            case '2':
                cadastrarAluno(&alunoN);
                x = inserirInicio (inicioLista, &alunoN);
                //retornoOperacao(x);
            break;
            case '3':
                cadastrarAluno(&alunoN);
                x=inserirItem (inicioLista, &alunoN);
                //retornoOperacao(x);
            break;
            case '4':
                x = removerInicio(inicioLista);
                //retornoOperacao(x);
            break;
            case '5':
                x = removerFinal (inicioLista);
                //retornoOperacao(x);
            break;
            case '6':
                int matA;
                cout << "\nInforme a matr�cula do aluno a ser removido: ";
                cin >> matA;
                x = removerItem(inicioLista, matA);
                //retornoOperacao(x);
            break;
            case '7': {
                int matA;
                cout << "\nInforme a matr�cula do aluno a ser procurado: ";
                cin >> matA;
                x = consultarMatricula(inicioLista, matA);
                //retornoOperacao(x);
            break;
            }
            case '8': {
                int pos;
                cout << "\nInforme a posi��o que deseja saber informa��es do aluno: ";
                cin >> pos;
                x = consultarPosicao(inicioLista, pos);
                //retornoOperacao(x);
            break;
            }
            case '9':
                imprimirLista(inicioLista);
            break;
            default:
                cout << "Op��o inv�lida!";
        }
        menuSaida(&menu);
        system("clear||cls"); //comando usado para limpar a tela do prompt

    } while(menu != 'S');

    liberarLista(inicioLista);
    return 0;
}
