#include <iostream>
#include "ListaDuplaEncadeada.h"
#include "menu.h"

using namespace std;

void cadastrarAluno(Aluno *alunoN) {
    cout << "\nInforme o nome do aluno: ";
    fflush(stdin);
    cin.getline(alunoN->nome, sizeof(alunoN->nome));

    //cout<<"Matr�cula do aluno! ";
    alunoN->matricula = verificaNumInt();
    //cin >> alunoN->matricula;
    fflush(stdin);

    // cout<<"Nota do aluno! ";
    alunoN->nota = verificaNumReal();
    //cin >> alunoN->nota;
    fflush(stdin);
}

Lista* criarLista() {
    //ponteiro que ir� apontar para uma estrutura Lista (que j� � um ponteiro para struct NODE)
    Lista *inicioLista;
    inicioLista = new Lista; // aloca��o din�mica da vari�vel inicioLista
    //Se a lista (inicioLista) foi alocada corretamente, ela apontar� para NULO
    if (inicioLista != nullptr) {
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

//fun��o para inserir um n� no fim da lista
int inserirFinal(Lista* inicioLista, Aluno *alunoN) {
    if (inicioLista == nullptr) {
        cout << "\nLista n�o foi criada!" << endl;
        return 0;
    }
    No *novoNo; // cria vari�vel no como um ponteiro para estrutura No
    novoNo = new No; // aloca dinamicamente um espa�o na mem�ria

    if (novoNo == nullptr) { // verificar se o n� n�o foi alocado corretamente
        cout << "\nErro na aloca��o na mem�ria, n� n�o foi alocado!" << endl;
        return 0;
    }
    //valores inseridos no cadastro e s�o atribuidos ao novoNo
    novoNo->aluno = *alunoN;
    novoNo->prox = nullptr;
    novoNo->ant = nullptr; //ponteiro que aponta para o n� anterior

    //se a lista estiver vazia, apontar o inicioLista para novoNo;
    if (*inicioLista == nullptr) {
        *inicioLista = novoNo;
        cout << "\nNovo n� inserido na lista com sucesso, primeiro elemento!" << endl;
        return 1;
    }
    // se a lista n�o estiver vazia... dever� percorrer at� o �ltimo elemento
    No *noAtual;  // vari�vel noAtual � um ponteiro para estrutura No
    noAtual = *inicioLista; // noAtual vai apontar  in�cioLista aponta
    // verifica se o pr�ximo n� n�o � nulo
    while(noAtual->prox != nullptr) {
       noAtual = noAtual->prox; //atualiza noAtual para o proximo elemento
    }// ao sair do while... significa que noAtual->prox � nulo

    noAtual->prox = novoNo;  // noAtual->prox apontar� para o novoNo;
    novoNo->ant = noAtual; // #### novoNo->ant aponta para noAtual
    cout << "\nNovo n� inserido no final lista com sucesso!" << endl;
    return 1;
}

//fun��o para inser��o de um n� no in�cio da lista
int inserirInicio(Lista* inicioLista, Aluno *alunoN) {
    if(inicioLista == nullptr){
        cout << "\nMem�ria Insuficiente: Lista n�o foi alocada!" << endl;
        return 0;
    }
    No* novoNo;
    novoNo = new No;

    if (novoNo == nullptr) { // se a aloca��o n�o foi feita corretamente
        cout << "\nMem�ria Insuficiente: N� (novoNo) n�o foi alocado!" << endl;
        return 0;
    }
    // atribuindo os valores do cadastro ao n� criado (novoNo)
    novoNo->aluno = *alunoN;
    novoNo->prox = nullptr; //atribuindo nulo ao prox do novoNo
    novoNo->ant = nullptr; // ###atribuindo nulo ao ant do novoNo

    //se a lista estiver vazia, apontar o inicioLista para novoNo;
    if (*inicioLista==nullptr) {
        *inicioLista = novoNo;
        cout << "\nNovo n� inserido na lista com sucesso - primeiro elemento!" << endl;
        return 1;
    }

    novoNo->prox = (*inicioLista); //aponta o prox do novoNo para o in�cioLista
    (*inicioLista)->ant = novoNo; //###Apontando o ant do inicioLista para o novoNo
    *inicioLista = novoNo; // apontando a cabe�a da lista para o n� criado (novoNo)
    cout << "\nNovo n� inserido no in�cio da lista com sucesso!" << endl;
    return 1;
}

//fun��o para inserir um n� em uma lista ordenada
int inserirItem(Lista* inicioLista, Aluno *alunoN) {
    if (inicioLista == nullptr) {
        cout << "\nMem�ria Insuficiente: Lista n�o foi alocada!" << endl;
        return 0;
    }
    No* novoNo;
    novoNo = new No;

    if (novoNo == nullptr) { // se a aloca��o n�o foi feita corretamente
        cout << "\nMem�ria Insuficiente: N� (novoNo) n�o foi alocado!" << endl;
        return 0;
    }
    novoNo->aluno = *alunoN;// atribuindo os valores do cadastro ao n� criado (novoNo)
    novoNo->prox = nullptr; // atribui nulo ao prox
    novoNo->ant = nullptr; //### atribui nulo ao anterior

    if ((*inicioLista) == nullptr) { //lista vazia, aponta o inicioLista para o novoNO
        *inicioLista = novoNo;
        cout << "\nNovo n� inserido na lista com sucesso, primeiro elemento!" << endl;
        return 1;
    }

    No *noAtual;//ponteiro para percorrer a lista:noAtual->prox;noAtual->ant
    noAtual = *inicioLista; // noAtual aponta o inicio da Lista

    // se noAtual->mat >= a alunoN->mat n�o entra
    // faz a repeti��o enquanto o noAtual for diferente null
    // e a matr da lista < mat (novoNo)
    while((noAtual->prox != nullptr) && (noAtual->aluno.matricula < alunoN->matricula)) {
        noAtual = noAtual->prox;
    }
    //novoNo ser� inserido como primeiro elemento da lista
    if ((noAtual == *inicioLista) && (noAtual->aluno.matricula > alunoN->matricula)) {
        novoNo->prox = noAtual;
        noAtual->ant = novoNo;  // ###aponto o ant (noAtual) para o novoNo
        *inicioLista = novoNo;
        cout << "\nNovo n� inserido no in�cio da lista com sucesso!" << endl;
        return 1;
    }

    //inser��o no fim da lista, O atual->prox � nulo FIM DA LISTA
    if ((noAtual->prox == nullptr) && (noAtual->aluno.matricula < alunoN->matricula)) {
        novoNo->ant = noAtual; // ##### NovoNo->ant aponta noAtual
        noAtual->prox = novoNo;
        cout << "\nNovo n� inserido no fim da lista com sucesso!" << endl;
        return 1;
    }

    //inser��o quando n�o � no inicio da lista e nem no fim...
    //cuidado com a ordem pois sen�o pode perder o acesso do noAtual->ant
    novoNo->prox = noAtual;
    novoNo->ant = noAtual->ant; // ##### NovoNo aponta ant para o
    (noAtual->ant)->prox = novoNo;
    noAtual->ant = novoNo; //#### ant do noAtual aponta para o novoNo
    cout << "\nNovo n� inserido na lista com sucesso, ordenado!" << endl;
    return 1;
}

void imprimirLista(Lista *inicioLista) {
    No *noAux = *inicioLista;
    if (noAux == nullptr)
        cout << "\nN�o h� dados cadastrados na lista!" << endl;
    else {
        while(noAux != nullptr) {
            cout << "\nNome: " << noAux->aluno.nome << endl;
            cout << "Matr�cula: " << noAux->aluno.matricula << endl;
            cout << "Nota: " << noAux->aluno.nota << endl;
            noAux = noAux->prox;
        }
    }
}

void imprimirListaInversa(Lista *inicioLista) {
    No *noAux = *inicioLista;
    if (noAux == nullptr)
        cout << "\nN�o h� dados cadastrados na lista!" << endl;
    else {
        while(noAux->prox != nullptr)
            noAux = noAux->prox;
        do {
            cout << "\nNome: " << noAux->aluno.nome << endl;
            cout << "Matr�cula: " << noAux->aluno.matricula << endl;
            cout << "Nota: " << noAux->aluno.nota << endl;
            noAux = noAux->ant;
        } while(noAux != nullptr);
    }
}

int removerInicio(Lista* inicioLista) {
    if (inicioLista == nullptr) { //lista n�o foi criada corretamente
        cout << "\nMem�ria Insuficiente: Lista n�o foi alocada!" << endl;
        return 0;
    }
    if ((*inicioLista) == nullptr) { //lista vazia, n�o h� o que remover
        cout << "\nLista vazia! N�o h� n�s para remover!" << endl;
        return 0;
    }
    No *no = *inicioLista;

    if (no->prox == nullptr) { //�nico elemento, inicioLista deve apontar null
        *inicioLista = nullptr;
        cout << "\n�nico elemento removido com sucesso! Lista agora est� vazia!" << endl;
        delete no;
        return 1;
    }
    *inicioLista = no->prox;
    (*inicioLista)->ant = nullptr;  //(no->prox)->ant = nullptr;
    delete no;
    cout << "\nN� removido do in�cio da lista com sucesso!" << endl;
    return 1;
}

int removerFinal(Lista* inicioLista) {
    if (inicioLista == nullptr) { //lista n�o foi criada corretamente
        cout << "\nMem�ria Insuficiente: Lista n�o foi alocada!" << endl;
        return 0;
    }
    if ((*inicioLista) == nullptr) { //lista vazia, n�o h� o que remover
        cout << "\nLista vazia! N�o h� n�s para remover!" << endl;
        return 0;
    }
    No *no = *inicioLista; // precisa s� de um ponteiro!!!

    if (no->prox == nullptr) { //�nico elemento, inicioLista deve apontar null
        *inicioLista = nullptr;
        cout << "\n�nico elemento removido com sucesso! Lista agora est� vazia!" << endl;
        delete no;
        return 1;
    }

    while(no->prox != nullptr)  // percorre at� encontrar o nulo
        no = no->prox;

    if (no == (*inicioLista)) {
        *inicioLista = no->prox; // atribui nulo para o inicioLista
        (no->prox)->ant = nullptr; //### primeiro elemento tem ant nulo
    }
    else //se no foi movimentado no while... no->prox vai chegar at� nulo
        (no->ant)->prox = nullptr;

    delete no; // desaloca o no...
    cout << "\nN� removido do fim lista com sucesso!" << endl;
    return 1;
}

int removerItem(Lista* inicioLista, int matA) {
    if (inicioLista == nullptr) { //lista n�o foi criada corretamente
        cout << "\nMem�ria Insuficiente: Lista n�o foi alocada!" << endl;
        return 0;
    }
    if ((*inicioLista) == nullptr) { //lista vazia, n�o h� o que remover
        cout << "\nLista vazia! N�o h� n�s para remover!" << endl;
        return 0;
    }

    No *no = *inicioLista;
    // percorre a lista at� encontrar a matricula ou chegar no fim
    while((no != nullptr) && (no->aluno.matricula != matA)) {
        no = no->prox;
    }

    if (no == nullptr) { //valor da matr�cula n�o encontrado na lista
        cout << "\nLista n�o cont�m o elemento que procura!" << endl;
        return 0;
    }

    //lista tem apenas o no a ser removido, o *inicioLista ser� nulo
    if ((no->ant == nullptr) && (no->prox == nullptr)) {
        *inicioLista = nullptr;
        delete no;
        cout << "\nN� encontrado e removido com sucesso, a lista est� vazia!" << endl;
        return 1;
    }
    //n� a ser removido � o primeiro e a lista cont�m mais elementos.
    if (no == *inicioLista) { //ou if (no->ant == nullptr) {
        *inicioLista = no->prox;  //Reposicionar in�cioLista
        (no->prox)->ant = nullptr;
        delete no;
        cout << "\nN� encontrado e removido da lista com sucesso, primeiro elemento!" << endl;
        return 1;
    }
    //remo��o ser� no meio da lista, deve realocar os ponteiros
    if (no->prox != nullptr) {
        (no->ant)->prox = no->prox;
        (no->prox)->ant = no->ant;
    }
    else // O n� do fim da lista ser� removido
        (no->ant)->prox = nullptr;

    delete no;
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
    cout << "\nDados do aluno na posi��o "<< pos << endl;
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
