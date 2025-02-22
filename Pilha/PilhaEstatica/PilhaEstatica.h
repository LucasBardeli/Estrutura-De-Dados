#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED
#define MAX 4

struct ALUNO {
    char nome[100];
    int matricula;
    float nota;
};
typedef struct ALUNO Aluno;

struct PILHA {
    int qtd;
    Aluno aluno[MAX];
};
typedef struct PILHA Pilha;

Pilha* criarPilha();
void apagarPilha(Pilha *pilha);

int pilhaCheia(Pilha *pilha);
int pilhaVazia(Pilha *pilha);

int inserirPilha(Pilha *pilha, Aluno *alunoN);
int removerPilha(Pilha *pilha);

void exibirTopo(Pilha *pilha);
void cadastrarAluno(Aluno *alunoN);

#endif // PILHAESTATICA_H_INCLUDED
