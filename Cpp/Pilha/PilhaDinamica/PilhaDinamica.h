#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED

struct ALUNO {
    int matricula;
    char nome[30];
    float nota;
};
typedef struct ALUNO Aluno;

struct NODE {
    Aluno dados;
    struct NODE *prox;
};
typedef struct NODE *Pilha;
typedef struct NODE No;

Pilha* criarPilha();
void liberarPilha(Pilha* topo);

int inserirPilha(Pilha* topo, Aluno *alunoN);
int removerPilha(Pilha* topo);

int exibirTopo(Pilha* topo);
void cadastrarAluno(Aluno *alunoN);

#endif // PILHADINAMICA_H_INCLUDED
