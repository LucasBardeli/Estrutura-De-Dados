#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define MAX 5

struct ALUNO {
    char nome[100];
    int matricula;
    float nota;
};

struct LISTA {
    int qtd;
    ALUNO aluno[MAX];
};

typedef struct ALUNO Aluno;
typedef struct LISTA Lista;

Lista* criarLista();
void apagarLista(Lista *lista);
int listaCheia(Lista *lista);
int listaVazia(Lista *lista);

int inserirFim(Lista *lista, Aluno *alunoN);
int inserirInicio(Lista *lista, Aluno *alunoN);
int inserirOrdenado(Lista *lista, Aluno *alunoN);

void exibirLista (Lista *lista);
void cadastrarAluno (Aluno *alunoN);
void consultarAluno (Lista *lista, int matA);

int removerFinal (Lista *lista);
int removerInicio (Lista *lista);
int removerItem (Lista *lista, int matA);

#endif // LISTA_H_INCLUDED
