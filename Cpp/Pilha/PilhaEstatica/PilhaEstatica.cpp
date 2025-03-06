#include <iostream>
#include "PilhaEstatica.h"

using namespace std;

Pilha* criarPilha() {
    Pilha *pilha = new Pilha;
    if (!pilha) {
        cout << "\nErro de alocação!" << endl;
        exit(1);
    }
    pilha->qtd = 0;
    return pilha;
}

void apagarPilha(Pilha *pilha) {
    delete pilha;
}

int pilhaCheia(Pilha *pilha) {
    if (pilha->qtd == MAX) {
        cout << "\nPilha está cheia!" << endl;
        return 1;
    }
    else
        return 0; // 0 é para condição falsa
}

int pilhaVazia(Pilha *pilha) {
    if (pilha->qtd == 0) {
        cout << "nPilha está vazia!" << endl;
        return 1;
    }
    else
        return 0;
}

// inserir elemento sempre no topo
int inserirPilha(Pilha *pilha, Aluno *alunoN) {
    if (pilha == nullptr) {
        cout << "\nPilha não existe!" << endl;
        return 0;
    }
    if (pilhaCheia(pilha) == 1) { // if(pilhaCheia(pilha))
        cout << "\nPilha está cheia, não é possível inserir!" << endl;
        return 0;
    }
    pilha->aluno[pilha->qtd] = *alunoN;
    pilha->qtd++;

    cout << "\nCadastro realizado com sucesso!" << endl;
    return 1;
}

// remover elemento sempre do topo
int removerPilha(Pilha *pilha) {
    if (pilha == nullptr)
        return 0;
    if (pilha->qtd == 0) { // if(pilhaVazia(pilha))
        cout << "\nPilha está vazia, não é possível remover!" << endl;
        return 0;
    }
    pilha->qtd--;

    cout << "\nRemoção realizada com sucesso!" << endl;
    return 1;
}

void exibirTopo(Pilha *pilha) {
    if (pilha->qtd == 0)
        cout << "\nNão há elementos na pilha!" << endl;
    else {
        cout << "\nExibindo dados de cadastro (Topo):" << endl;
        cout << "Nome: " << pilha->aluno[pilha->qtd-1].nome << endl;
        cout << "Matrícula: " << pilha->aluno[pilha->qtd-1].matricula << endl;
        cout << "Nota: " << pilha->aluno[pilha->qtd-1].nota << endl;
    }
    cout << "\n\n";
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
