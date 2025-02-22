#include<iostream>
#include "FilaEstatica.h"

using namespace std;

//criar lista
Fila* criarFila() {
    Fila *fila = new Fila;
    if (!fila) {
        cout << "\nErro de alocação!" << endl;
        exit(1);
    }
    fila->qtd = 0;
    fila->inicio = 0;
    fila->fim = 0;

    return fila;
}

// apagar lista
void apagarFila(Fila *fila) {
    delete fila;
}

// verificar cheia
int filaCheia(Fila *fila) {
    if (fila->qtd == MAX) {
        cout << "\nFila está cheia!" << endl;
        return 1;
    }
    else
        return 0; // 0 é para condição falsa
}

// verificar vazia
int filaVazia(Fila *fila) {
    // return (fila->qtd == 0);
    if (fila->qtd == 0) {
        cout << "\nFila está vazia!" << endl;
        return 1;
    }
    else
        return 0;
}

// cadastro aluno
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

// inserir elemento sempre no final
int inserirFila(Fila *fila, Aluno *alunoN) {
    if (fila == nullptr) {
        cout << "\nFila não existe!" << endl;
        return 0;
    }
    if (fila->qtd == MAX) { // if(filaCheia(fila))
        cout << "\nFila cheia!" << endl;
        return 0;
    }
    if (fila->fim == MAX) {
        fila->fim = 0;
    }
    fila->aluno[fila->fim] = *alunoN;
    fila->fim++;
    fila->qtd++;
    cout << "\nCadastro realizado com sucesso!" << endl;

    return 1;
}

// remover elemento sempre no inicio
int removerFila(Fila *fila) {
    if (fila == nullptr) {
        cout << "\nFila não existe!" << endl;
        return 0;
    }
    if (fila->qtd == 0) { // if(filaVazia(fila))
        cout << "\nFila vazia!" << endl;
        return 0;
    }

    fila->inicio++;

    if (fila->inicio == MAX) {
        fila->inicio = 0;
    }
    fila->qtd--;
    cout << "\nRemoção realizada com sucesso!" << endl;

    return 1;
}

void exibirFila(Fila *fila) {
    int i, j;
    if (fila->qtd == 0)
        cout << "\nNão há cadastro de aluno!" << endl;
    else {
        cout << endl;
        for (i=1, j = fila->inicio; i <= fila->qtd; i++) {
            cout << i << "º Cadastro:" << endl;
            cout << "Nome: " << fila->aluno[j].nome << endl;
            cout << "Matrícula: " << fila->aluno[j].matricula << endl;
            cout << "Nota: " << fila->aluno[j].nota << endl;
            j++;

            if (j == MAX)
                j = 0;
        }
        cout << endl;
    }
}
