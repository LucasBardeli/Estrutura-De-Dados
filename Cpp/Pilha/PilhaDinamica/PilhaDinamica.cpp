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
        cout << "\nPilha não existe!" << endl;
        return 0;
    }
    No *novoNo = new No;

    if (novoNo == nullptr) {
        cout << "\nEspaço de memória não alocado para o nó!" << endl;
        return 0;
    }
    novoNo->dados = *alunoN;
    novoNo->prox = nullptr;

    novoNo->prox = *topo;
    *topo = novoNo;

    cout << "\nInserção realizada com sucesso!" << endl;
    return 1;
}

int removerPilha(Pilha* topo) {
     if (topo == nullptr) {
        cout << "\nPilha não existe!" << endl;
        return 0;
    }
    if (*topo == nullptr) {
        cout << "\nPilha vazia!" << endl;
        return 0;
    }
    No *noAux = *topo;
    *topo = noAux->prox;
    delete noAux;

    cout << "\nRemoção realizada com sucesso!" << endl;
    return 1;
}

int exibirTopo(Pilha* topo) {
    if (topo == nullptr) {
        cout << "\nPilha não existe!" << endl;
        return 0;
    }
    if (*topo == nullptr) {
        cout << "\nPilha vazia!" << endl;
        return 0;
    }
    No *noAux = *topo;

    cout << "\nExibindo dados de cadastro (Topo):" << endl;
    cout << "Nome: " << noAux->dados.nome << endl;
    cout << "Matrícula: " << noAux->dados.matricula << endl;
    cout << "Nota: " << noAux->dados.nota << endl;
    return 1;
}

void cadastrarAluno(Aluno *alunoN) {
    cout << "\nCadastro aluno:" << endl;
    cout << "Nome: ";
    fflush(stdin);
    cin.getline(alunoN->nome, sizeof(alunoN->nome));
    cout << "Matrícula: ";
    cin >> alunoN->matricula;
    cout << "Nota: ";
    cin >> alunoN->nota;
 }
