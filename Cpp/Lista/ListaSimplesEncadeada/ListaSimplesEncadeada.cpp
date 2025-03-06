#include <iostream>
#include "ListaSimplesEncadeada.h"

using namespace std;

void cadastrarAluno(Aluno *alunoN) {
    cout << "Informe o nome do aluno: ";
    fflush(stdin);
    cin.getline(alunoN->nome, sizeof(alunoN->nome));
    cout << "Informe a matrícula do aluno: " ;
    cin >> alunoN->matricula;
    cout << "Informe a nota do aluno: ";
    cin >> alunoN->nota;
}

Lista* criarLista() {
    Lista *inicioLista; // ponteiro que irá apontar para uma estrutura Lista (que já é um ponteiro para struct NODE)
    inicioLista = new Lista; // alocação dinâmica da variável inicioLista

    if (inicioLista != nullptr) { //Se a lista (inicioLista) foi alocada corretamente, ela apontará para NULO
        *inicioLista = nullptr;
        cout << "\nLista Criada com sucesso!" << endl;
    }
    return inicioLista;
}

void liberarLista(Lista *inicioLista) {
    if (inicioLista != nullptr) { // se a lista existir
        No *no; // cria um ponteiro do tipo No
        while((*inicioLista) != nullptr) { // verifica se a lista não está vazia (se existem nós)
            no = *inicioLista; // aponta o ponteiro no para o início da lista
            *inicioLista = no->prox; // o inicio da lista avança para o próximo nó
            delete no; // apaga o nó da memória...
        } // esse processo é feito até que o inícioLista seja nulo.

        delete inicioLista; // apaga o inicioLista da memória
    }
}

// função que não vamos usar mais.... pois estamos exibindo as ações nas próprias funções
void retornoOperacao(int x) {
    if (x==0)
        cout << "\nOperação não foi realizada!" << endl;
    else
        cout << "\nOperação realizada com sucesso!" << endl;
}

//função para inserir um nó no fim da lista
int inserirFinal(Lista* inicioLista, Aluno *alunoN) {
    if (inicioLista == nullptr) {
        cout << "\nLista não foi criada!" << endl;
        return 0;
    }

    No *novoNo; // cria variável no como um ponteiro para estrutura No
    novoNo = new No; // aloca dinamicamente um espaço na memória
    if (novoNo == nullptr) {// verificar se o nó não foi alocado corretamente
        cout << "\nErro na alocação na memória, nó não foi alocado!" endl;
        return 0;
    }

    //se o nó foi alocado na memória corretamente, daí pega os valores inseridos no cadastro e atribui a ele
    novoNo->aluno = *alunoN;
    novoNo->prox = nullptr;
    if ((*inicioLista) == nullptr) { //lista vazia
        *inicioLista = novoNo; // o inícioLista aponta para o nó criado
        cout << "\nNó inserido na lista vazia!" endl;
        return 1;
    }

    // se a lista não estiver vazia... deverá percorrer até o último elemento
    No *aux;  // cria uma variável aux que é um ponteiro para estrutura No, para percorrer a lista
    aux = *inicioLista; // aux vai apontar para onde o inícioLista aponta
    while(aux->prox != nullptr) { // verifica se o próximo nó é nulo, se não for
       aux = aux->prox; // atualiza o ponteiro aux para o proximo elemento
    } // ao sair do while... significa que aux->prox é nulo

    aux->prox = novoNo;  // agora aux->prox apontará para o novo no;
    cout<< "\nNó inserido na lista!" endl;
    return 1;
}

//função para inserção de um nó no início da lista
int inserirInicio(Lista* inicioLista, Aluno *alunoN) {
    if (inicioLista == nullptr) {
        cout << "\nMemória insuficiente: Lista não foi alocada!" << endl;
        return 0;
    }

    No* novoNo;
    novoNo = new No;
    if (novoNo == nullptr) { // se a alocação não foi feita corretamente
        cout << "\nMemória insuficiente: Nó (novoNo) não foi alocado!" << endl;
        return 0;
    }

    // atribuindo os valores do cadastro ao nó criado (novoNo)
    novoNo->aluno = *alunoN;
    novoNo->prox = (*inicioLista); // apontando o prox do nó criado (novoNo) para o início da lista
    *inicioLista = novoNo; // apontando a cabeça da lista para o nó criado (novoNo)
    cout << "\nNovo nó foi inserido na lista com sucesso!" << endl;
    return 1;
}

//função para inserir um nó em uma lista ordenada
int inserirItem(Lista* inicioLista, Aluno *alunoN) {
      if (inicioLista == nullptr) {
        cout << "\nMemória insuficiente: Lista não foi alocada!" << endl;
        return 0;
    }

    No* novoNo;
    novoNo = new No;
    if (novoNo == nullptr) { // se a alocação não foi feita corretamente
        cout << "\nMemória insuficiente: Nó (novoNo) não foi alocado!" << endl;
        return 0;
    }

    novoNo->aluno = *alunoN;// atribuindo os valores do cadastro ao nó criado (novoNo)
    if ((*inicioLista) == nullptr) {//lista vazia, atribui nulo para o novoNo->prox e aponta o inicioLista para o novoNO
        novoNo->prox = nullptr;
        *inicioLista = novoNo;
        cout << "\nNovo nó foi inserido na lista com sucesso!" << endl;
        return 1;
    }

    No *noAnt, *noAtual; //cria dois ponteiros para que esses percorram a lista
    noAtual = *inicioLista; // noAtual aponta para o endereço que o inicioLista está indicando

    // se o noAtual for nulo não entra na repetição
    // se a matricula do aluno que está no noAtual também for >= a matrícula do novoAluno também não entra na repetição
    while((noAtual != nullptr) && (noAtual->aluno.matricula < alunoN->matricula)) {
        noAnt = noAtual;
        noAtual = noAtual->prox;
    } // faz a repetição enquanto o noAtual não for null e a matricula da lista seja menor que a matricula (novoNo) não seja maior ou igual

    //verifica se o noAtual está no inicio da lista, pois se sim a inserção será no início
    if (noAtual == *inicioLista) {//insere início
        novoNo->prox = (*inicioLista);
        *inicioLista = novoNo;
        cout << "\nNovo nó foi inserido na lista com sucesso!" << endl;
        return 1;
    }

    //inserção quando não é no inicio da lista, necessário os dois ponteiros...
    noAnt->prox = novoNo;
    novoNo->prox = noAtual;
    cout << "\nNovo nó foi inserido na lista com sucesso!" << endl;
    return 1;

}

void imprimirLista(Lista *inicioLista) {
   No *noAux = *inicioLista;
   if (noAux == nullptr)
        cout << "\nNão há dados cadastrados na lista!" << endl;
   else {
        while(noAux != nullptr) {
            cout<< "\nNome: " << noAux->aluno.nome << endl;
            cout<< "Matrícula: " << noAux->aluno.matricula << endl;
            cout<< "Nota: " << noAux->aluno.nota << endl;
            noAux = noAux->prox;
        }
    }
}

int removerInicio(Lista* inicioLista) {
    if (inicioLista == nullptr) { //lista não foi criada corretamente
        cout << "\nMemória insuficiente: Lista não foi alocada!" << endl;
        return 0;
    }
    if ((*inicioLista) == nullptr) { //lista vazia, não há o que remover
        cout << "\nLista vazia! Não há nós para remover!" << endl;
        return 0;
    }
    No *no = *inicioLista;
    *inicioLista = no->prox;

    delete no;
    cout << "\nPrimeiro nó removido na lista com sucesso!" << endl;
    return 1;
}

int removerFinal(Lista* inicioLista) {
     if (inicioLista == nullptr) { //lista não foi criada corretamente
        cout << "\nMemória insuficiente: Lista não foi alocada!" << endl;
        return 0;
    }
    if ((*inicioLista) == nullptr) { //lista vazia, não há o que remover
        cout << "Lista vazia! Não há nós para remover!" << endl;
        return 0;
    }

    No *noAnt, *noAux = *inicioLista;
    while(noAnt->prox != nullptr) {
        noAnt = noAux;
        noAux = noAux->prox;
    } // percorre até encontrar o nulo

    if (noAux == (*inicioLista)) //se houver um elemento só na lista, noAux vai estar apontando para o mesmo lugar que o inicioLista
        *inicioLista = noAux->prox; // atribui nulo para o inicioLista (lista vazia)
    else //se noAux foi movimentado no while... noAux->prox vai chegar até nulo
        noAnt->prox = noAux->prox;

    delete noAux; // desaloca o noAux...
    cout << "\nÚltimo nó removido na lista com sucesso!" << endl;
    return 1;
}

int removerItem(Lista* inicioLista, int matA) {
    if (inicioLista == nullptr) { //lista não foi criada corretamente
        cout << "\nMemória insuficiente: Lista não foi alocada!" << endl;
        return 0;
    }
    if ((*inicioLista) == nullptr) {//lista vazia, não há o que remover
        cout << "\nLista vazia! Não há nós para remover!" << endl;
        return 0;
    }

    No *noAnt, *noAux = *inicioLista;
    while((noAux != nullptr) && (noAux->aluno.matricula != matA)) {
        noAnt = noAux;
        noAux = noAux->prox;
    } // percorre a lista até encontrar a matricula ou até chegar no fim da lista

    if (noAux == nullptr) { //valor da matrícula não encontrado na lista
        cout << "\nLista não contém o elemento que procura!" << endl;
        return 0;
    }
    if (noAux == *inicioLista)
        *inicioLista = noAux->prox;
    else
        noAnt->prox = noAux->prox; //vai fazer a realocação dos ponteiros para poder remover o elemento.

    delete noAux;
    cout << "\nNó encontrado e removido da lista com sucesso!" << endl;
    return 1;
}


int consultarPosicao(Lista* inicioLista, int pos) {
    if (inicioLista == nullptr) {
        cout << "\nLista não criada!" << endl;
        return 0;
    }
    if (pos <= 0) {
        cout << "\nPosição informada inválida!" << endl;
        return 0;
    }

    if ((*inicioLista) == nullptr) { //lista vazia, não há o que consultar
        cout << "\nLista vazia!" << endl;
        return 0;
    }

    No *noAux = *inicioLista;
    int i = 1;
    while((noAux != nullptr) && (i < pos)) {
        noAux = noAux->prox;
        i++;
    }

    if (noAux == nullptr) {
        cout << "\nNão há elementos na posição solicitada!" << endl;
        return 0;
    }

    cout << "\nDados do aluno na posição: "<< pos << endl;
    cout << "Nome: " << noAux->aluno.nome << endl;
    cout << "Matrícula: " << noAux->aluno.matricula << endl;
    cout << "Nota: " << noAux->aluno.nota << endl;
    return 1;
}

int consultarMatricula(Lista* inicioLista, int mat) {
    if (inicioLista == nullptr) {
        cout << "\nLista não criada!" << endl;
        return 0;
    }
     if ((*inicioLista) == nullptr) { //lista vazia, não há o que consultar
        cout << "\nLista vazia!" << endl;
        return 0;
    }

    No *noAux = *inicioLista;
    while((noAux != nullptr) && (noAux->aluno.matricula != mat)) {
        noAux = noAux->prox;
    }

    if (noAux == nullptr) {
        cout << "\nMatrícula não encontrada na lista!" << endl;
        return 0;
    }

    cout << "\nDados do aluno de matrícula: "<< mat << endl;
    cout << "Nome: " << noAux->aluno.nome << endl;
    cout << "Matrícula: " << noAux->aluno.matricula << endl;
    cout << "Nota: " << noAux->aluno.nota << endl;
    return 1;
}
