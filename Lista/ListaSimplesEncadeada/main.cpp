#include <iostream>
#include <locale>
#include "ListaSimplesEncadeada.h"
#include "menu.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    Lista *inicioLista; //ponteiro para ponteiro da estrutura -> cabeça da lista
    Aluno alunoN; //alunoN será usado no preenchimento do cadastroAluno
    char menu;
    int x; //usado para receber o retorno das funçãos (não é obrigatório, pois não usaremos mais a função retornoOperacao)

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
                cout << "\nInforme a matrícula do aluno a ser removido: ";
                cin >> matA;
                x = removerItem(inicioLista, matA);
                //retornoOperacao(x);
            break;
            case '7': {
                int matA;
                cout << "\nInforme a matrícula do aluno a ser procurado: ";
                cin >> matA;
                x = consultarMatricula(inicioLista, matA);
                //retornoOperacao(x);
            break;
            }
            case '8': {
                int pos;
                cout << "\nInforme a posição que deseja saber informações do aluno: ";
                cin >> pos;
                x = consultarPosicao(inicioLista, pos);
                //retornoOperacao(x);
            break;
            }
            case '9':
                imprimirLista(inicioLista);
            break;
            default:
                cout << "Opção inválida!";
        }
        menuSaida(&menu);
        system("clear||cls"); //comando usado para limpar a tela do prompt

    } while(menu != 'S');

    liberarLista(inicioLista);
    return 0;
}
