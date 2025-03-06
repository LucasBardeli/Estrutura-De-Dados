#include <iostream>
#include "ListaEstatica.h"
#include <locale>

using namespace std;

char menuInicial();
char menuSaida();
void retornoOperacao(int x);

int main(){
    setlocale(LC_ALL, "Portuguese");

    char menu;
    int x, matA;
    Lista *lista;
    Aluno alunoN;

    lista = criarLista();

    do {
        menu = menuInicial();
        switch(menu) {
            case '1':
                cadastrarAluno(&alunoN);
                x = inserirFim(lista,&alunoN);
                retornoOperacao(x);
            break;
            case '2':
                cadastrarAluno(&alunoN);
                x = inserirInicio(lista,&alunoN);
                retornoOperacao(x);
            break;
            case '3':
                cadastrarAluno(&alunoN);
                x = inserirOrdenado(lista,&alunoN);
                retornoOperacao(x);
            break;
            case '4':
                x = removerFinal(lista);
                retornoOperacao(x);
            break;
            case '5':
                x = removerInicio(lista);
                retornoOperacao(x);
            break;
            case '6':
                cout << "Informe a matricula do aluno a ser removido: ";
                cin >> matA;
                x = removerItem(lista, matA);
                retornoOperacao(x);
            break;
            case '7':
                exibirLista(lista);
            break;
            case '8':
                cout << "Consultar aluno !";
                consultarAluno(lista, matA);
            break;
            default:
                cout << "Opção Inválida!";
        }

        menu = menuSaida();
        system("cls");

    } while(menu != 'S');

    apagarLista(lista);

    return 0;
}

char menuInicial() {
    char menu;

    cout << "\n--------- Menu --------" << endl;
    cout << "1 - para inserir aluno no final da lista;" << endl;
    cout << "2 - para inserir aluno no início da lista;" << endl;
    cout << "3 - para inserir aluno de forma ordenada na lista;" << endl;
    cout << "4 - para remover um aluno do início da lista;" << endl;
    cout << "5 - para remover um aluno do final da lista;" << endl;
    cout << "6 - para remover aluno um aluno determinado;" << endl;
    cout << "7 - exibir os alunos cadastrados;" << endl;
    cout << "8 - consultar um aluno na lista." << endl;
    cout << "-->  ";
    fflush(stdin);
    cin>>menu;

    return menu;
}

char menuSaida() {
    char menu;

    cout << "\nDeseja sair do programa ?" << endl;
    cout << "S para sim;" << endl;
    cout << "Qualquer tecla para continuar..." << endl;
    cout << "-->  ";
    cin >> menu;
    menu = toupper(menu);

    return menu;
}

void retornoOperacao(int x) {
    if (x == 1)
        cout << "Operação realizada com sucesso !" << endl;
    else
        cout << "Operação não realizada !" << endl;
}
