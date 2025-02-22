#include<iostream>
#include "FilaEstatica.h"

using namespace std;

//criar lista
Fila* criarFila() {
    Fila *fila = new Fila;
    if (!fila) {
        cout << "\nErro de aloca��o!" << endl;
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
        cout << "\nFila est� cheia!" << endl;
        return 1;
    }
    else
        return 0; // 0 � para condi��o falsa
}

// verificar vazia
int filaVazia(Fila *fila) {
    // return (fila->qtd == 0);
    if (fila->qtd == 0) {
        cout << "\nFila est� vazia!" << endl;
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
    cout << "Matr�cula: ";
    cin >> alunoN->matricula;
    cout << "Nota: ";
    cin >> alunoN->nota;
 }

// inserir elemento sempre no final
int inserirFila(Fila *fila, Aluno *alunoN) {
    if (fila == nullptr) {
        cout << "\nFila n�o existe!" << endl;
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
        cout << "\nFila n�o existe!" << endl;
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
    cout << "\nRemo��o realizada com sucesso!" << endl;

    return 1;
}

void exibirFila(Fila *fila) {
    int i, j;
    if (fila->qtd == 0)
        cout << "\nN�o h� cadastro de aluno!" << endl;
    else {
        cout << endl;
        for (i=1, j = fila->inicio; i <= fila->qtd; i++) {
            cout << i << "� Cadastro:" << endl;
            cout << "Nome: " << fila->aluno[j].nome << endl;
            cout << "Matr�cula: " << fila->aluno[j].matricula << endl;
            cout << "Nota: " << fila->aluno[j].nota << endl;
            j++;

            if (j == MAX)
                j = 0;
        }
        cout << endl;
    }
}
