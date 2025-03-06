#include <iostream>
#include "ListaSimplesEncadeada.h"

using namespace std;

void cadastrarAluno(Aluno *alunoN) {
    cout << "Informe o nome do aluno: ";
    fflush(stdin);
    cin.getline(alunoN->nome, sizeof(alunoN->nome));
    cout << "Informe a matr�cula do aluno: " ;
    cin >> alunoN->matricula;
    cout << "Informe a nota do aluno: ";
    cin >> alunoN->nota;
}

Lista* criarLista() {
    Lista *inicioLista; // ponteiro que ir� apontar para uma estrutura Lista (que j� � um ponteiro para struct NODE)
    inicioLista = new Lista; // aloca��o din�mica da vari�vel inicioLista

    if (inicioLista != nullptr) { //Se a lista (inicioLista) foi alocada corretamente, ela apontar� para NULO
        *inicioLista = nullptr;
        cout << "\nLista Criada com sucesso!" << endl;
    }
    return inicioLista;
}

void liberarLista(Lista *inicioLista) {
    if (inicioLista != nullptr) { // se a lista existir
        No *no; // cria um ponteiro do tipo No
        while((*inicioLista) != nullptr) { // verifica se a lista n�o est� vazia (se existem n�s)
            no = *inicioLista; // aponta o ponteiro no para o in�cio da lista
            *inicioLista = no->prox; // o inicio da lista avan�a para o pr�ximo n�
            delete no; // apaga o n� da mem�ria...
        } // esse processo � feito at� que o in�cioLista seja nulo.

        delete inicioLista; // apaga o inicioLista da mem�ria
    }
}

// fun��o que n�o vamos usar mais.... pois estamos exibindo as a��es nas pr�prias fun��es
void retornoOperacao(int x) {
    if (x==0)
        cout << "\nOpera��o n�o foi realizada!" << endl;
    else
        cout << "\nOpera��o realizada com sucesso!" << endl;
}

//fun��o para inserir um n� no fim da lista
int inserirFinal(Lista* inicioLista, Aluno *alunoN) {
    if (inicioLista == nullptr) {
        cout << "\nLista n�o foi criada!" << endl;
        return 0;
    }

    No *novoNo; // cria vari�vel no como um ponteiro para estrutura No
    novoNo = new No; // aloca dinamicamente um espa�o na mem�ria
    if (novoNo == nullptr) {// verificar se o n� n�o foi alocado corretamente
        cout << "\nErro na aloca��o na mem�ria, n� n�o foi alocado!" endl;
        return 0;
    }

    //se o n� foi alocado na mem�ria corretamente, da� pega os valores inseridos no cadastro e atribui a ele
    novoNo->aluno = *alunoN;
    novoNo->prox = nullptr;
    if ((*inicioLista) == nullptr) { //lista vazia
        *inicioLista = novoNo; // o in�cioLista aponta para o n� criado
        cout << "\nN� inserido na lista vazia!" endl;
        return 1;
    }

    // se a lista n�o estiver vazia... dever� percorrer at� o �ltimo elemento
    No *aux;  // cria uma vari�vel aux que � um ponteiro para estrutura No, para percorrer a lista
    aux = *inicioLista; // aux vai apontar para onde o in�cioLista aponta
    while(aux->prox != nullptr) { // verifica se o pr�ximo n� � nulo, se n�o for
       aux = aux->prox; // atualiza o ponteiro aux para o proximo elemento
    } // ao sair do while... significa que aux->prox � nulo

    aux->prox = novoNo;  // agora aux->prox apontar� para o novo no;
    cout<< "\nN� inserido na lista!" endl;
    return 1;
}

//fun��o para inser��o de um n� no in�cio da lista
int inserirInicio(Lista* inicioLista, Aluno *alunoN) {
    if (inicioLista == nullptr) {
        cout << "\nMem�ria insuficiente: Lista n�o foi alocada!" << endl;
        return 0;
    }

    No* novoNo;
    novoNo = new No;
    if (novoNo == nullptr) { // se a aloca��o n�o foi feita corretamente
        cout << "\nMem�ria insuficiente: N� (novoNo) n�o foi alocado!" << endl;
        return 0;
    }

    // atribuindo os valores do cadastro ao n� criado (novoNo)
    novoNo->aluno = *alunoN;
    novoNo->prox = (*inicioLista); // apontando o prox do n� criado (novoNo) para o in�cio da lista
    *inicioLista = novoNo; // apontando a cabe�a da lista para o n� criado (novoNo)
    cout << "\nNovo n� foi inserido na lista com sucesso!" << endl;
    return 1;
}

//fun��o para inserir um n� em uma lista ordenada
int inserirItem(Lista* inicioLista, Aluno *alunoN) {
      if (inicioLista == nullptr) {
        cout << "\nMem�ria insuficiente: Lista n�o foi alocada!" << endl;
        return 0;
    }

    No* novoNo;
    novoNo = new No;
    if (novoNo == nullptr) { // se a aloca��o n�o foi feita corretamente
        cout << "\nMem�ria insuficiente: N� (novoNo) n�o foi alocado!" << endl;
        return 0;
    }

    novoNo->aluno = *alunoN;// atribuindo os valores do cadastro ao n� criado (novoNo)
    if ((*inicioLista) == nullptr) {//lista vazia, atribui nulo para o novoNo->prox e aponta o inicioLista para o novoNO
        novoNo->prox = nullptr;
        *inicioLista = novoNo;
        cout << "\nNovo n� foi inserido na lista com sucesso!" << endl;
        return 1;
    }

    No *noAnt, *noAtual; //cria dois ponteiros para que esses percorram a lista
    noAtual = *inicioLista; // noAtual aponta para o endere�o que o inicioLista est� indicando

    // se o noAtual for nulo n�o entra na repeti��o
    // se a matricula do aluno que est� no noAtual tamb�m for >= a matr�cula do novoAluno tamb�m n�o entra na repeti��o
    while((noAtual != nullptr) && (noAtual->aluno.matricula < alunoN->matricula)) {
        noAnt = noAtual;
        noAtual = noAtual->prox;
    } // faz a repeti��o enquanto o noAtual n�o for null e a matricula da lista seja menor que a matricula (novoNo) n�o seja maior ou igual

    //verifica se o noAtual est� no inicio da lista, pois se sim a inser��o ser� no in�cio
    if (noAtual == *inicioLista) {//insere in�cio
        novoNo->prox = (*inicioLista);
        *inicioLista = novoNo;
        cout << "\nNovo n� foi inserido na lista com sucesso!" << endl;
        return 1;
    }

    //inser��o quando n�o � no inicio da lista, necess�rio os dois ponteiros...
    noAnt->prox = novoNo;
    novoNo->prox = noAtual;
    cout << "\nNovo n� foi inserido na lista com sucesso!" << endl;
    return 1;

}

void imprimirLista(Lista *inicioLista) {
   No *noAux = *inicioLista;
   if (noAux == nullptr)
        cout << "\nN�o h� dados cadastrados na lista!" << endl;
   else {
        while(noAux != nullptr) {
            cout<< "\nNome: " << noAux->aluno.nome << endl;
            cout<< "Matr�cula: " << noAux->aluno.matricula << endl;
            cout<< "Nota: " << noAux->aluno.nota << endl;
            noAux = noAux->prox;
        }
    }
}

int removerInicio(Lista* inicioLista) {
    if (inicioLista == nullptr) { //lista n�o foi criada corretamente
        cout << "\nMem�ria insuficiente: Lista n�o foi alocada!" << endl;
        return 0;
    }
    if ((*inicioLista) == nullptr) { //lista vazia, n�o h� o que remover
        cout << "\nLista vazia! N�o h� n�s para remover!" << endl;
        return 0;
    }
    No *no = *inicioLista;
    *inicioLista = no->prox;

    delete no;
    cout << "\nPrimeiro n� removido na lista com sucesso!" << endl;
    return 1;
}

int removerFinal(Lista* inicioLista) {
     if (inicioLista == nullptr) { //lista n�o foi criada corretamente
        cout << "\nMem�ria insuficiente: Lista n�o foi alocada!" << endl;
        return 0;
    }
    if ((*inicioLista) == nullptr) { //lista vazia, n�o h� o que remover
        cout << "Lista vazia! N�o h� n�s para remover!" << endl;
        return 0;
    }

    No *noAnt, *noAux = *inicioLista;
    while(noAnt->prox != nullptr) {
        noAnt = noAux;
        noAux = noAux->prox;
    } // percorre at� encontrar o nulo

    if (noAux == (*inicioLista)) //se houver um elemento s� na lista, noAux vai estar apontando para o mesmo lugar que o inicioLista
        *inicioLista = noAux->prox; // atribui nulo para o inicioLista (lista vazia)
    else //se noAux foi movimentado no while... noAux->prox vai chegar at� nulo
        noAnt->prox = noAux->prox;

    delete noAux; // desaloca o noAux...
    cout << "\n�ltimo n� removido na lista com sucesso!" << endl;
    return 1;
}

int removerItem(Lista* inicioLista, int matA) {
    if (inicioLista == nullptr) { //lista n�o foi criada corretamente
        cout << "\nMem�ria insuficiente: Lista n�o foi alocada!" << endl;
        return 0;
    }
    if ((*inicioLista) == nullptr) {//lista vazia, n�o h� o que remover
        cout << "\nLista vazia! N�o h� n�s para remover!" << endl;
        return 0;
    }

    No *noAnt, *noAux = *inicioLista;
    while((noAux != nullptr) && (noAux->aluno.matricula != matA)) {
        noAnt = noAux;
        noAux = noAux->prox;
    } // percorre a lista at� encontrar a matricula ou at� chegar no fim da lista

    if (noAux == nullptr) { //valor da matr�cula n�o encontrado na lista
        cout << "\nLista n�o cont�m o elemento que procura!" << endl;
        return 0;
    }
    if (noAux == *inicioLista)
        *inicioLista = noAux->prox;
    else
        noAnt->prox = noAux->prox; //vai fazer a realoca��o dos ponteiros para poder remover o elemento.

    delete noAux;
    cout << "\nN� encontrado e removido da lista com sucesso!" << endl;
    return 1;
}


int consultarPosicao(Lista* inicioLista, int pos) {
    if (inicioLista == nullptr) {
        cout << "\nLista n�o criada!" << endl;
        return 0;
    }
    if (pos <= 0) {
        cout << "\nPosi��o informada inv�lida!" << endl;
        return 0;
    }

    if ((*inicioLista) == nullptr) { //lista vazia, n�o h� o que consultar
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
        cout << "\nN�o h� elementos na posi��o solicitada!" << endl;
        return 0;
    }

    cout << "\nDados do aluno na posi��o: "<< pos << endl;
    cout << "Nome: " << noAux->aluno.nome << endl;
    cout << "Matr�cula: " << noAux->aluno.matricula << endl;
    cout << "Nota: " << noAux->aluno.nota << endl;
    return 1;
}

int consultarMatricula(Lista* inicioLista, int mat) {
    if (inicioLista == nullptr) {
        cout << "\nLista n�o criada!" << endl;
        return 0;
    }
     if ((*inicioLista) == nullptr) { //lista vazia, n�o h� o que consultar
        cout << "\nLista vazia!" << endl;
        return 0;
    }

    No *noAux = *inicioLista;
    while((noAux != nullptr) && (noAux->aluno.matricula != mat)) {
        noAux = noAux->prox;
    }

    if (noAux == nullptr) {
        cout << "\nMatr�cula n�o encontrada na lista!" << endl;
        return 0;
    }

    cout << "\nDados do aluno de matr�cula: "<< mat << endl;
    cout << "Nome: " << noAux->aluno.nome << endl;
    cout << "Matr�cula: " << noAux->aluno.matricula << endl;
    cout << "Nota: " << noAux->aluno.nota << endl;
    return 1;
}
