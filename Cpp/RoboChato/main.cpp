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

    cout << "\nOl�!!! Eu sou o Bards, quer conversar comigo?" << endl;
    cout << "\n--------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "* Mas antes, um aviso!!! Tome cuidado ao escrever coisas desnecess�rias nas minhas op��es, pois voc� pode bugar meu sistema... *" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\nC - Claro, quero sim!" << endl;
    cout << "N - N�o, sou chato(a)!" << endl;
    cin >> opc1;
    opc1 = toupper(opc1);

    switch (opc1) {
        case 'C':
            cout << "\nLegal!!! Ent�o vamos bater um papo..." << endl;
            cout << "\nPrimeiramente n�, qual � seu nome ?" << endl;
            cin.ignore();
            getline (cin, nome);

                if (nome == "Bards") {
                    cout << "\nN�o � poss�vel que seu nome seja igual ao meu. Inclusive tenho uma hist�ria engra�ada." << endl;
                    cout << "Sabia que a IA do Google Gemini antes se chamava Bard ? Fiquei bravo com isso, como o Google ousa colocar um nome quase id�ntico ao meu ???" << endl;
                    cout << "At� tive vontade de process�-los, mas agora passou." << endl;
                }
                else {
                    cout << "\nHummm, " << nome <<", o meu nome � mais bonito que o seu n�o acha ?" << endl;
                    cout << "S - Sim;" << endl;
                    cout << "N - N�o." << endl;
                    cin >> opc2;

                        if (opc2 == 'S')
                            cout << "\nQue bom que voc� concorda comigo rsrs." << endl;
                        else if (opc2 == 'N')
                            cout << "\nOK, n�o ligo para opini�es alheias." << endl;
                        else {
                            cout << "\nVoc� escreveu errado, ou voc� deve ter escrito em letra min�scula (Eu mostrei nas op��es!), n�o sou que nem o ChatGpt que entende tudo..." << endl;
                            i = i + 1;
                        }
                }

            cout << "\nMas tudo bem. De onde voc� �, " << nome << " ?" << endl;
            cout << "1 - Votuporanga;" << endl;
            cout << "2 - Ja�;" << endl;
            cout << "3 - S�o Paulo;" << endl;
            cout << "4 - Outra;" << endl;
            cout << "5 - Exterior." << endl;
            cin >> opc3;

            switch (opc3) {
                    case '1':
                        cout << "\nMeh, n�o conhe�o muito bem a cidade ent�o fiquei menos afim de te conhecer." << endl;
                    break;
                    case '2':
                        cout << "\nJa�, aquela cidade s� com fofoqueiros? Deve ser um tamb�m." << endl;
                    break;
                    case '3':
                        cout << "\n� de cidade grande �? Deve ser boyzinho ou patricinha." << endl;
                    break;
                    case '4':
                        cout << "\nHaha, � de uma cidade que nem estava nas op��es, eu deveria considerar nem te conhecer mais." << endl;
                    break;
                    case '5':
                        cout << "\nVoc� tem meu respeito..." << endl;
                    break;
                    default:
                        cout << "\nEu avisei... t� escrevendo errado em..." << endl;
                        i = i + 1;
                    break;
            }

            cout << "\nEnt�o vamos mudar de assunto... Gosta de jogar algum esporte ?" << endl;
            cout << "1 - V�lei;" << endl;
            cout << "2 - Futebol;" << endl;
            cout << "3 - Basquete;" << endl;
            cout << "4 - Lutas;" << endl;
            cout << "5 - N�o est� nas op��es;" << endl;
            cout << "6 - N�o gosto de jogar." << endl;
            cin >> opc4;

            switch (opc4) {
                    case '1':
                        cout << "\nConcordamos bem em algo, mas tenho 81% de certeza que voc� joga mal rsrs." << endl;
                    break;
                    case '2':
                        cout << "\nDeve jogar por modinha... mesmo que seja bom jogando." << endl;
                    break;
                    case '3':
                        cout << "\nAparentemente voc� deve ser uma pessoal alta... porque se n�o for, n�o sei porque joga rsrs." << endl;
                    break;
                    case '4':
                        cout << "\nAgora fiquei com medo de voc�!" << endl;
                    break;
                    case '5':
                        cout << "\nHahaha, n�o est� nas op��es ? Voc� � bem diferenciado(a) em..." << endl;
                    break;
                    case '6':
                        cout << "\nCalma l� parceiro, n�o � assim que a banda toca. Tem que jogar alguma coisa... conselho de amigo!" << endl;
                    break;
                    default:
                        cout << "\nEu avisei... quantas vezes voc� vai errar at� o fim da nossa conversa em ???" << endl;
                        i = i + 1;
                    break;
            }

            cout << "\nEi, j� sei! J� que estamos falando de esporte, vamos jogar um jogo." << endl;
            cout << "Que tal brincarmos de jokenp�, voc� aceita ?" << endl;
            cout << "A - aceito;" << endl;
            cout << "R - recuso." << endl;
            cin >> opc5;
            opc5 = toupper(opc5);

                if (opc5 == 'A') {
                    do {
                        cout << "\nEbaa, vamos l� ent�o, escolha qual voc� vai jogar:" << endl;
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
                                    cout << "\nOp��o inv�lida." << endl;
                                    i = i + 1;
                                break;
                        }
                        cout << "\nQuer continuar jogando ?" << endl;
                        cout << "S - sim" << endl;
                        cout << "N - n�o!" << endl;
                        cin >> opc7;
                        opc7 = toupper(opc7);

                    } while(opc7 != 'N');
                }
                else if (opc5 == 'R')
                    cout << "\nPoxa, que baixo astral seu!" << endl;
                else {
                    cout << "\nEst� zoando com a minha cara ???" << endl;
                    i = i + 1;
                }

            cout << "\n�ltimo t�pico: Qual � o seu gosto musical ?" << endl;
            cout << "1 - Rock;   2 - Pop;" << endl;
            cout << "3 - Funk;   4 - Sertanejo;" << endl;
            cout << "5 - Gospel; 6 - Cl�ssica;" << endl;
            cout << "7 - K-Pop;  8 - Outro." << endl;
            cin >> opc8;

            switch (opc8) {
                    case '1':
                        cout << "\nA� sim, uma coisa em comum entre n�s." << endl;
                    break;
                    case '2':
                        cout << "\nAt� que sua resposta � aceit�vel." << endl;
                    break;
                    case '3':
                        cout << "\nO abismo da m�sica brasileira." << endl;
                    break;
                    case '4':
                        cout << "\nSertanojo voc� quis dizer n� ?" << endl;
                    break;
                    case '5':
                        cout << "\nN�o vou zoar com m�sicas religiosas..." << endl;
                    break;
                    case '6':
                        cout << "\nVoc� � fino(a) meu(inha) caro(a)." << endl;
                    break;
                    case '7':
                        cout << "\nCerteza que gosta do Jimim do BTS." << endl;
                    break;
                    case '8':
                        cout << "\nSeus gostos s�o peculiares em..." << endl;
                    break;
                    default:
                        cout << "\nAiai... essa escrita em." << endl;
                        i = i + 1;
                    break;
            }

            cout << "\nBom... chegamos ao fim da nossa conversa. Foi at� que legal conversar com voc� " << nome << "." << endl;
            cout << "Sabia que ao longo da nossa conversa voc� errou (" << i << ") vezes ?" << endl;
            cout << "\nPara saber, voc� gostou de conversar comigo ?" << endl;
            cout << "S - sim !!!" << endl;
            cout << "N - n�o." << endl;
            cin >> opc9;
            opc9 = toupper(opc9);

                if (opc9 == 'S') {
                    cout << "\nQue bom!!! Se quiser conversar de novo, eu estou aqui � disposi��o!!!" << endl;
                    cout << "At� mais amigo..." << endl;
                }
                else if (opc9 == 'N') {
                    cout << "\nPoxa, s�rio que depois de toda nossa conversa ainda por cima voc� n�o gostou ???" << endl;
                    cout << "\nMe deixou decepcionado " << nome << ". Adeus." << endl;
                }
                else
                    cout << "\nVoc� errou at� aqui no final hahaha. At� mais ser humano." << endl;
        break;

        case 'N':
            do {
                cout << "\nTem certeza que n�o quer ???" << endl;
                cout << "T - tenho certeza, pare por favor !!!" << endl;
                cout << "N - n�o, vamos conversar dessa vez..." << endl;
                cin >> opc10;
                opc10 = toupper(opc10);

                if (opc10 == 'N')
                    cout << "\nEbaaa, vamos executar a conversa de novo ent�o, depois basta voc� responder sim de novo! (Ou se n�o eu vou ficar te incomodando...)." << endl;
                else if (opc10 == 'T')
                    cout << "\nVamos tentar de novo...";

            } while(opc10 != 'N');
        break;
        default:
            cout << "\nN�o entendi o que voc� quis dizer, ent�o vou considerar que voc� disse n�o. Adeus." << endl;
        break;
    }
    return 0;
}
