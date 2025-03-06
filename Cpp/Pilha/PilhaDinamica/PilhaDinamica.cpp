#include <iostream>
#include "PilhaDinamica.h"

using namespace std;

Pilha* criarPilha() {
    Pilha* topo = new Pilha;
    if (topo != nullptr) {
        *topo = nullptr;
        cout << "\nPilha criada com sucesso!" << endl;
    }
    return topo;
}

void liberarPilha(Pilha *topo) {
    if (topo != nullptr) {
        No *noAux;
        while((*topo) != nullptr) {
            noAux = *topo;
            *topo = noAux->prox; //*topo = topo->prox;
            delete noAux;
        }
        delete topo;
    }
}

int inserirPilha(Pilha* topo, Aluno *alunoN) {
    if (topo == nullptr) {
        cout << "\nPilha n�o existe!" << endl;
        return 0;
    }
    No *novoNo = new No;

    if (novoNo == nullptr) {
        cout << "\nEspa�o de mem�ria n�o alocado para o n�!" << endl;
        return 0;
    }
    novoNo->dados = *alunoN;
    novoNo->prox = nullptr;

    novoNo->prox = *topo;
    *topo = novoNo;

    cout << "\nInser��o realizada com sucesso!" << endl;
    return 1;
}

int removerPilha(Pilha* topo) {
     if (topo == nullptr) {
        cout << "\nPilha n�o existe!" << endl;
        return 0;
    }
    if (*topo == nullptr) {
        cout << "\nPilha vazia!" << endl;
        return 0;
    }
    No *noAux = *topo;
    *topo = noAux->prox;
    delete noAux;

    cout << "\nRemo��o realizada com sucesso!" << endl;
    return 1;
}

int exibirTopo(Pilha* topo) {
    if (topo == nullptr) {
        cout << "\nPilha n�o existe!" << endl;
        return 0;
    }
    if (*topo == nullptr) {
        cout << "\nPilha vazia!" << endl;
        return 0;
    }
    No *noAux = *topo;

    cout << "\nExibindo dados de cadastro (Topo):" << endl;
    cout << "Nome: " << noAux->dados.nome << endl;
    cout << "Matr�cula: " << noAux->dados.matricula << endl;
    cout << "Nota: " << noAux->dados.nota << endl;
    return 1;
}

void cadastrarAluno(Aluno *alunoN) {
    cout << "\nCadastro aluno:" << endl;
    cout << "Nome: ";
    fflush(stdin);
    cin.getline(alunoN->nome, sizeof(alunoN->nome));
    cout << "Matr�cula: ";
    cin >> alunoN->matricula;
    cout << "Nota: ";
    cin >> alunoN->nota;
 }
