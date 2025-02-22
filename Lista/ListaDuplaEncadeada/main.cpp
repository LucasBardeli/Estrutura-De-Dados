#include <iostream>
#include <locale>
#include "ListaDuplaEncadeada.h"
#include "menu.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    Lista *inicioLista; //ponteiro para ponteiro da estrutura -> cabe�a da lista
    Aluno alunoN; //alunoN ser� usado no preenchimento do cadastroAluno
    char menu;
    //int x; // usado para receber o retorno das fun��os (n�o � obrigat�rio, pois n�o usaremos mais a fun��o retornoOperacao)

    inicioLista = criarLista();
    do {
        menuPrincipal(&menu);
        switch(menu) {
        case '1':
            cadastrarAluno(&alunoN);
            inserirFinal(inicioLista, &alunoN);
        break;
        case '2':
            cadastrarAluno(&alunoN);
            inserirInicio(inicioLista, &alunoN);
        break;
        case '3':
             cadastrarAluno(&alunoN);
             inserirItem(inicioLista, &alunoN);
        break;
        case '4':
            removerInicio(inicioLista);
        break;
        case '5':
            removerFinal(inicioLista);
        break;
        case '6':
            int matA;
            cout << "\nInforme a matr�cula do aluno a ser removido: ";
            cin >> matA;
            removerItem(inicioLista, matA);
            break;
        case '7': {
            int matA;
            cout << "\nInforme a matr�cula do aluno a ser procurado: ";
            cin >> matA;
            consultarMatricula(inicioLista, matA);
        break;
        }
        case '8': {
            int pos;
            cout << "\nInforme a posi��o que deseja saber informa��es do aluno: " << endl;
            cout << "Posi��o: ";
            cin >> pos;
            consultarPosicao(inicioLista, pos);
            //retornoOperacao(x);
        break;
        }
        case '9':
            imprimirLista(inicioLista);
        break;
        case '0':
            imprimirListaInversa(inicioLista);
        break;
        default:
            cout << "\nOp��o inv�lida!" << endl;
        }
        menuSaida(&menu);
        system("clear||cls"); //comando usado para limpar a tela do prompt

    } while(menu != 'S');

    liberarLista(inicioLista);
    return 0;
}
