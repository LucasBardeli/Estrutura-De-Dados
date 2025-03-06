#include <iostream>
#include "ListaEstatica.h"

using namespace std;

//criar lista
Lista* criarLista() {
    Lista *lista = new Lista;
    if (!lista) {
        cout << "Erro de alocação !" << endl;
        exit(1);
    }
    lista->qtd = 0;
    return lista;
}

//apagar lista
void apagarLista(Lista *lista) {
    delete lista;
}

//verificar lista cheia
int listaCheia(Lista *lista) {
    //return (lista -> qtd == MAX); //outra maneira
    if (lista->qtd == MAX)
        return 1; // 1 condição verdadeira
    else
        return 0; // 0 condição falsa
}

//verificar lista vazia
int listaVazia(Lista *lista) {
    //return (lista -> qtd == MAX); //outra maneira
    if (lista->qtd == 0)
        return 1;
    else
        return 0;
}

//inserir no final da lista
int inserirFim(Lista *lista, Aluno *alunoN) {
    if (listaCheia(lista) == 1)
        return 0;
    lista->aluno[lista->qtd] = *alunoN;
    lista->qtd++;
    return 1;
}

//inserir no início da lista
int inserirInicio(Lista *lista, Aluno *alunoN) {
    if (listaCheia(lista) == 1)
        return 0;

    for (int i = lista->qtd; i>0; i--) {
        lista->aluno[i] = lista->aluno[i-1];
    }
    lista->aluno[0] = *alunoN;
    lista->qtd++;
    return 1;
}

//inserir ordenado na lista
int inserirOrdenado(Lista *lista, Aluno *alunoN) {
    int p=0;
    if (listaCheia(lista) == 1)
        return 0;

    for (int i=0; i < lista->qtd; i++) {
        if (lista->aluno[i].matricula <= alunoN->matricula)
            p++;
        else
            i = MAX;
    }
    for (int i = lista->qtd; i>p; i--) {
        lista->aluno[i] = lista->aluno[i-1];
    }
    lista->aluno[p] = *alunoN;
    lista->qtd++;
    return 1;
}

void exibirLista (Lista *lista) {
    if (listaVazia(lista) == 1)
        cout << "Não há cadastro de alunos !" << endl;
    else {
        for (int i=0; i < lista->qtd; i++) {
            cout << i+1 << "º Cadastro:" << endl;
            cout << "Nome: " << lista->aluno[i].nome << endl;
            cout << "Matrícula: " << lista->aluno[i].matricula << endl;
            cout << "Nota: " << lista->aluno[i].nota << endl;
        }
        cout << endl << endl;
    }
}

void cadastrarAluno (Aluno *alunoN) {
    cout << "Cadastro aluno:" << endl;
    cout << "Nome: ";
    fflush(stdin);
    cin.getline(alunoN->nome, sizeof(alunoN->nome));
    cout << "Matrícula: ";
    cin >> alunoN->matricula;
    cout << "Nota: ";
    cin >> alunoN->nota;
}

void consultarAluno (Lista *lista, int matA) {
    int i=0;
    if (listaVazia(lista) == 1)
        cout << "Não há cadastro de alunos !" << endl;
    else {
        for (i=0; i < lista->qtd; ) {
            if (lista->aluno[i].matricula != matA)
                i++;
            else {
                cout << "Aluno encontrado !" << endl;
                cout << i+1 << "º Cadastro:" << endl;
                cout << "Nome: " << lista->aluno[i].nome << endl;
                cout << "Matrícula: " << lista->aluno[i].matricula << endl;
                cout << "Nota: " << lista->aluno[i].nota << endl;
                i = lista->qtd+1; //se matA for única para cadastro
                //i++; //se puder haver matrículas iguais
            }
        }

        /*
        //quando matrículas poderem ser iguais para cadastros diferentes, ou outra informação
        for (i=0; i < lista->qtd; i++) {
            if (lista->aluno[i].matricula == matA) {
                cout << "Aluno encontrado !" << endl;
                cout << i+1 << "º Cadastro:" << endl;
                cout << "Nome: " << lista->aluno[i].nome << endl;
                cout << "Matrícula: " << lista->aluno[i].matricula << endl;
                cout << "Nota: " << lista->aluno[i].nota << endl;
            }
        }
        */

        if (i == lista->qtd)
            cout << "Matrícula " << matA << " não encontrada." << endl;
    }
}

//remover no final da lista
int removerFinal (Lista *lista) {
    if (listaVazia(lista) == 1)
        return 0;

    lista->qtd--;
    return 1;
}

//remover no início da lista
int removerInicio (Lista *lista) {
    if (listaVazia(lista) == 1)
        return 0;

    for (int i=0; i < lista->qtd-1; i++) {
        lista->aluno[i] = lista->aluno[i+1];
    }
    lista->qtd--;
    return 1;
}

//remover ordenado na lista
int removerItem (Lista *lista, int matA) {
    int p=0;
    if (listaVazia(lista) == 1)
        return 0;

    for (int i=0; i < lista->qtd; i++) {
        if (lista->aluno[i].matricula <= matA)
            p++;
        else
            i = MAX;
    }

    if (p == MAX)
        return 0;

    for (int i=p; i < lista->qtd-1; i++) {
        lista->aluno[i] = lista->aluno[i+1];
    }
    lista->qtd--;
    return 1;
}
