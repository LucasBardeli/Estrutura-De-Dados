#include <iostream>
#include <cstring>
#include <locale>
#include <iomanip>

using namespace std;

int main() {
    setlocale (LC_ALL, "Portuguese");

    char opc1, opc2, opc3, opc4, opc5, opc6, opc7, opc8, opc9, opc10;
    string nome;
    int i=0;

    cout << "\nOlá!!! Eu sou o Bards, quer conversar comigo?" << endl;
    cout << "\n--------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "* Mas antes, um aviso!!! Tome cuidado ao escrever coisas desnecessárias nas minhas opções, pois você pode bugar meu sistema... *" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\nC - Claro, quero sim!" << endl;
    cout << "N - Não, sou chato(a)!" << endl;
    cin >> opc1;
    opc1 = toupper(opc1);

    switch (opc1) {
        case 'C':
            cout << "\nLegal!!! Então vamos bater um papo..." << endl;
            cout << "\nPrimeiramente né, qual é seu nome ?" << endl;
            cin.ignore();
            getline (cin, nome);

                if (nome == "Bards") {
                    cout << "\nNão é possível que seu nome seja igual ao meu. Inclusive tenho uma história engraçada." << endl;
                    cout << "Sabia que a IA do Google Gemini antes se chamava Bard ? Fiquei bravo com isso, como o Google ousa colocar um nome quase idêntico ao meu ???" << endl;
                    cout << "Até tive vontade de processá-los, mas agora passou." << endl;
                }
                else {
                    cout << "\nHummm, " << nome <<", o meu nome é mais bonito que o seu não acha ?" << endl;
                    cout << "S - Sim;" << endl;
                    cout << "N - Não." << endl;
                    cin >> opc2;

                        if (opc2 == 'S')
                            cout << "\nQue bom que você concorda comigo rsrs." << endl;
                        else if (opc2 == 'N')
                            cout << "\nOK, não ligo para opiniões alheias." << endl;
                        else {
                            cout << "\nVocê escreveu errado, ou você deve ter escrito em letra minúscula (Eu mostrei nas opções!), não sou que nem o ChatGpt que entende tudo..." << endl;
                            i = i + 1;
                        }
                }

            cout << "\nMas tudo bem. De onde você é, " << nome << " ?" << endl;
            cout << "1 - Votuporanga;" << endl;
            cout << "2 - Jaú;" << endl;
            cout << "3 - São Paulo;" << endl;
            cout << "4 - Outra;" << endl;
            cout << "5 - Exterior." << endl;
            cin >> opc3;

            switch (opc3) {
                    case '1':
                        cout << "\nMeh, não conheço muito bem a cidade então fiquei menos afim de te conhecer." << endl;
                    break;
                    case '2':
                        cout << "\nJaú, aquela cidade só com fofoqueiros? Deve ser um também." << endl;
                    break;
                    case '3':
                        cout << "\nÉ de cidade grande é? Deve ser boyzinho ou patricinha." << endl;
                    break;
                    case '4':
                        cout << "\nHaha, é de uma cidade que nem estava nas opções, eu deveria considerar nem te conhecer mais." << endl;
                    break;
                    case '5':
                        cout << "\nVocê tem meu respeito..." << endl;
                    break;
                    default:
                        cout << "\nEu avisei... tá escrevendo errado em..." << endl;
                        i = i + 1;
                    break;
            }

            cout << "\nEntão vamos mudar de assunto... Gosta de jogar algum esporte ?" << endl;
            cout << "1 - Vôlei;" << endl;
            cout << "2 - Futebol;" << endl;
            cout << "3 - Basquete;" << endl;
            cout << "4 - Lutas;" << endl;
            cout << "5 - Não está nas opções;" << endl;
            cout << "6 - Não gosto de jogar." << endl;
            cin >> opc4;

            switch (opc4) {
                    case '1':
                        cout << "\nConcordamos bem em algo, mas tenho 81% de certeza que você joga mal rsrs." << endl;
                    break;
                    case '2':
                        cout << "\nDeve jogar por modinha... mesmo que seja bom jogando." << endl;
                    break;
                    case '3':
                        cout << "\nAparentemente você deve ser uma pessoal alta... porque se não for, não sei porque joga rsrs." << endl;
                    break;
                    case '4':
                        cout << "\nAgora fiquei com medo de você!" << endl;
                    break;
                    case '5':
                        cout << "\nHahaha, não está nas opções ? Você é bem diferenciado(a) em..." << endl;
                    break;
                    case '6':
                        cout << "\nCalma lá parceiro, não é assim que a banda toca. Tem que jogar alguma coisa... conselho de amigo!" << endl;
                    break;
                    default:
                        cout << "\nEu avisei... quantas vezes você vai errar até o fim da nossa conversa em ???" << endl;
                        i = i + 1;
                    break;
            }

            cout << "\nEi, já sei! Já que estamos falando de esporte, vamos jogar um jogo." << endl;
            cout << "Que tal brincarmos de jokenpô, você aceita ?" << endl;
            cout << "A - aceito;" << endl;
            cout << "R - recuso." << endl;
            cin >> opc5;
            opc5 = toupper(opc5);

                if (opc5 == 'A') {
                    do {
                        cout << "\nEbaa, vamos lá então, escolha qual você vai jogar:" << endl;
                        cout << "1 - Pedra;" << endl;
                        cout << "2 - Papel;" << endl;
                        cout << "3 - Tesoura." << endl;
                        cin >> (opc6);

                        switch (opc6) {
                                case '1':
                                    cout << "\nEu joguei [PAPEL], opss! Acho que ganhei hehehe." << endl;
                                break;
                                case '2':
                                    cout << "\nEu joguei [TESOURA], opss! Acho que ganhei hehehe." << endl;
                                break;
                                case '3':
                                    cout << "\nEu joguei [PEDRA], opss! Acho que ganhei hehehe." << endl;
                                break;
                                default:
                                    cout << "\nOpção inválida." << endl;
                                    i = i + 1;
                                break;
                        }
                        cout << "\nQuer continuar jogando ?" << endl;
                        cout << "S - sim" << endl;
                        cout << "N - não!" << endl;
                        cin >> opc7;
                        opc7 = toupper(opc7);

                    } while(opc7 != 'N');
                }
                else if (opc5 == 'R')
                    cout << "\nPoxa, que baixo astral seu!" << endl;
                else {
                    cout << "\nEstá zoando com a minha cara ???" << endl;
                    i = i + 1;
                }

            cout << "\nÚltimo tópico: Qual é o seu gosto musical ?" << endl;
            cout << "1 - Rock;   2 - Pop;" << endl;
            cout << "3 - Funk;   4 - Sertanejo;" << endl;
            cout << "5 - Gospel; 6 - Clássica;" << endl;
            cout << "7 - K-Pop;  8 - Outro." << endl;
            cin >> opc8;

            switch (opc8) {
                    case '1':
                        cout << "\nAí sim, uma coisa em comum entre nós." << endl;
                    break;
                    case '2':
                        cout << "\nAté que sua resposta é aceitável." << endl;
                    break;
                    case '3':
                        cout << "\nO abismo da música brasileira." << endl;
                    break;
                    case '4':
                        cout << "\nSertanojo você quis dizer né ?" << endl;
                    break;
                    case '5':
                        cout << "\nNão vou zoar com músicas religiosas..." << endl;
                    break;
                    case '6':
                        cout << "\nVocê é fino(a) meu(inha) caro(a)." << endl;
                    break;
                    case '7':
                        cout << "\nCerteza que gosta do Jimim do BTS." << endl;
                    break;
                    case '8':
                        cout << "\nSeus gostos são peculiares em..." << endl;
                    break;
                    default:
                        cout << "\nAiai... essa escrita em." << endl;
                        i = i + 1;
                    break;
            }

            cout << "\nBom... chegamos ao fim da nossa conversa. Foi até que legal conversar com você " << nome << "." << endl;
            cout << "Sabia que ao longo da nossa conversa você errou (" << i << ") vezes ?" << endl;
            cout << "\nPara saber, você gostou de conversar comigo ?" << endl;
            cout << "S - sim !!!" << endl;
            cout << "N - não." << endl;
            cin >> opc9;
            opc9 = toupper(opc9);

                if (opc9 == 'S') {
                    cout << "\nQue bom!!! Se quiser conversar de novo, eu estou aqui à disposição!!!" << endl;
                    cout << "Até mais amigo..." << endl;
                }
                else if (opc9 == 'N') {
                    cout << "\nPoxa, sério que depois de toda nossa conversa ainda por cima você não gostou ???" << endl;
                    cout << "\nMe deixou decepcionado " << nome << ". Adeus." << endl;
                }
                else
                    cout << "\nVocê errou até aqui no final hahaha. Até mais ser humano." << endl;
        break;

        case 'N':
            do {
                cout << "\nTem certeza que não quer ???" << endl;
                cout << "T - tenho certeza, pare por favor !!!" << endl;
                cout << "N - não, vamos conversar dessa vez..." << endl;
                cin >> opc10;
                opc10 = toupper(opc10);

                if (opc10 == 'N')
                    cout << "\nEbaaa, vamos executar a conversa de novo então, depois basta você responder sim de novo! (Ou se não eu vou ficar te incomodando...)." << endl;
                else if (opc10 == 'T')
                    cout << "\nVamos tentar de novo...";

            } while(opc10 != 'N');
        break;
        default:
            cout << "\nNão entendi o que você quis dizer, então vou considerar que você disse não. Adeus." << endl;
        break;
    }
    return 0;
}
