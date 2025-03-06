#include <iostream>
#include "FilaDinamica.h"

using namespace std;

Fila* criarFila() {
    Fila* fila = new Fila;

    if (fila != nullptr) {
        fila->fim = nullptr;
        fila->inicio = nullptr;
        fila->qtd = 0;
    }
    return fila;
}

void liberarFila(Fila *fila) {
    if (fila != nullptr) {
        Elemento* no;

        while(fila->inicio != nullptr) {
            no = fila->inicio;
            fila->inicio = fila->inicio->prox;
            delete no;
        }
        delete fila;
    }
}

int consultarFila(Fila* fila, Aluno *alunoN) {
    if (fila == nullptr) {
        cout << "\nFila não existe!" << endl;
        return 0;
    }
    if (fila->inicio == nullptr) { //fila vazia
        cout << "\nFila vazia!" << endl;
        return 0;
    }
    *alunoN = fila->inicio->dados;

    return 1;
}

int inserirFila(Fila* fila, Aluno *alunoN) {
    if (fila == nullptr) {
        cout << "\nFila não existe!" << endl;
        return 0;
    }
    Elemento *no = new Elemento;
    if (no == nullptr) {
        cout << "\nEspaço de memória não alocado para o nó!" << endl;
        return 0;
    }
    no->dados = *alunoN;
    no->prox = nullptr;

    if (fila->fim == nullptr) //fila vazia
        fila->inicio = no;
    else
        fila->fim->prox = no;

    fila->fim = no;
    fila->qtd++;
    cout << "\nCadastro realizado com sucesso!" << endl;

    return 1;
}

int removerFila(Fila* fila) {
    if (fila == nullptr) {
        cout << "\nFila não existe!" << endl;
        return 0;
    }
    if (fila->inicio == nullptr) { //fila vazia
        cout << "\nFila Vazia!" << endl;
        return 0;
    }
    Elemento *no = fila->inicio;
    fila->inicio = fila->inicio->prox;

    if (fila->inicio == nullptr) //fila ficou vazia
        fila->fim = nullptr;

    delete no;
    fila->qtd--;
    cout << "\nRemoção realizada com sucesso!" << endl;

    return 1;
}

int tamanhoFila(Fila* fila) {
    if (fila == nullptr) {
        cout << "\nFila não existe!" << endl;
        return 0;
    }
    cout << endl;
    cout << fila->qtd << " cadastro(s) na fila!" << endl;

    return fila->qtd;
}

int filaVazia(Fila* fila) {
    if (fila == nullptr) {
        cout << "\nFila não existe!" << endl;
        return 0;
    }
    if (fila->inicio == nullptr) { //fila vazia
        cout << "\nFila vazia!" << endl;
        return 1;
    }
}

int exibirFila(Fila* fila) {
    if (fila == nullptr) {
        cout << "\nFila não existe!" << endl;
        return 0;
    }
    if (fila->inicio == nullptr) { //fila vazia
        cout << "\nNão há elementos na Fila!" << endl;
        return 0;
    }
    Elemento* no = fila->inicio;

    cout << endl;
    while(no != nullptr) {
        cout << "\nNome: " << no->dados.nome << endl;
        cout << "Matrícula: " << no->dados.matricula << endl;
        cout << "Nota: " << no->dados.nota << endl;
        no = no->prox;
    }
    return 1;
}

void cadastrarAluno(Aluno *alunoN) {
    cout << "\nCadastro Aluno:" << endl;
    cout << "Nome: ";
    fflush(stdin);
    cin.getline(alunoN->nome, sizeof(alunoN->nome));
    cout << "Matrícula: ";
    cin >> alunoN->matricula;
    cout << "Nota: ";
    cin >> alunoN->nota;
 }
