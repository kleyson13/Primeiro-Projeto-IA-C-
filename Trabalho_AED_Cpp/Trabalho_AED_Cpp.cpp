/*------------------------Trabalho de Algoritimo e Estrutura de Dados------------------------

Este projeto é um jogo que de palavras eem que o computador escolhe uma letra aleatória
e começa a falar palavras que iniciam com a letra escolhida e fica alternando entre palavra
dita pelo programa e palavra dita pelo jogador.

-----------------Projeto desenvolvido por Kleyson Mariano e Maria Eduarda-----------------*/

#include <iostream>
#include <fstream>
#include <string>
#include <speechapi_cxx.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>
#include <limits>

//Definindo o serviço de falas do Azure
using namespace std;
using namespace Microsoft::CognitiveServices::Speech;
using namespace Microsoft::CognitiveServices::Speech::Audio;

auto autenticacao = SpeechConfig::FromSubscription("bb33f111891842028908eae14f359dd0", "brazilsouth");
auto requisicao_textofala = SpeechSynthesizer::FromConfig(autenticacao);
auto audioConfig = AudioConfig::FromDefaultMicrophoneInput();
auto requisicao_falatexto = SpeechRecognizer::FromConfig(autenticacao, audioConfig);

//Funnção que converte o texto escritura em fala do computador
void texto_em_fala(string Texto)
{
    cout << Texto + "\n";
    requisicao_textofala->SpeakTextAsync(Texto).get();
}

//Função que converte a fala do usuário em texto no computador
string fala_em_texto()
{
    auto resultado = requisicao_falatexto->RecognizeOnceAsync().get();
    cout << resultado->Text + "\n";
    return resultado->Text;
}

//função que repete as intruções caso solicitado pelo jogador
void repeticao_instrucoes()
{
    void instrucoes();
    void jogo_iniciado();

    system("cls");
    texto_em_fala("\nPrecisa ouvir as regras mais uma vez?");
    string opcao = fala_em_texto();

    if (opcao == ("Sim.") || opcao == ("Preciso."))
    {
        instrucoes(); //chamando a função de instruções novamente
    }
    else {

    }
}

//função que informa as instruções do jogo para o jogador
void instrucoes()
{
    void repeticao_instrucoes(); //declarando função de repetição das instruções

    system("cls");

    texto_em_fala("---------------INSTRUÇÕES---------------\n\n");
    texto_em_fala("- O objetivo do jogo é falar a maior quantidade de palavras que comecem com uma determinada letra, \nsem repetir a mesma palavra.\n");
    texto_em_fala("- Eu vou escolher uma letra aleatoriamente e todas as palavras deverão iniciar com essa letra.\n");
    texto_em_fala("- Uma vez eu falo, outra vez você.\n");
    texto_em_fala("- Cada palavra correta, corresponde a 5 pontos.\n");
    texto_em_fala("- Se ficar mais de 5 segundos sem falar a palavra, \nperde o jogo e é exibido a quantidade de pontos e a maior pontuação já alcançada.\n");

    repeticao_instrucoes(); //chamando função de repetição das instruções
}

//Função que escolhe uma letra aleatória para o início do jogo
int escolhe_letra()
{
    int letra = 0;
    srand(time(NULL));
    letra = rand() % 25; // de 0 a 25 pois é a quantidade de letras no alfabeto
    return (letra); // retornando o o numero que corresponde a letra para a função main
}

//Função onde o jogo ocorre de fato
int jogo(string caminho)
{
    int pontos = 0;
    string palavraPc;
    string palavraJogador;

    ifstream arquivo;
    arquivo.open(caminho); // recebe caminho específico de cada letra da função main

    if (arquivo.is_open()) {
        arquivo.seekg(0, arquivo.beg);

        palavraJogador[0] = caminho[0]; // inicia a variável com uma opção correta para que o jogo possa iniciar
        while (palavraJogador[0] == caminho[0]) { // Loop que gera a palavra no pc e analisa a palavra
            getline(arquivo, palavraPc);          // dita pelo jogador.
            arquivo.seekg(0, arquivo.cur); //posiciona o cursor no final da palavra falada do dicionário

            texto_em_fala("\n" +palavraPc + "\n");

            palavraJogador = fala_em_texto();

            if (palavraJogador[0] == caminho[0]) { // verifica se a palavra dita pelo jogar está correta e 
                pontos = pontos + 5;               // soma +5 pontos para o jogador
            }
            else {
                texto_em_fala("\nVocê perdeu!\n"); // se a palavra estiver errada perde o jogo e encerra o loóp
            }
        }
    }
    else {
        texto_em_fala("ERROR: Não foi possivel encontrar o dicionario."); // Mensagem de erro caso não exista os
    }                                                                     // arquivos de dicionário
    return pontos; //retorna a pontuação para a função main
}

//Função que converte a pontução numéria em string para que o computador possa falar
string pontuacao(int ponto) {
    string pontos;

    //caso para cada uma das pontuações de 0 a 100
    switch (ponto)
    {
    case(0):
        pontos = "0";
        break;

    case(5):
        pontos = "5";
        break;

    case(10):
        pontos = "10";
        break;

    case(15):
        pontos = "15";
        break;

    case(20):
        pontos = "20";
        break;

    case(25):
        pontos = "25";
        break;

    case(30):
        pontos = "30";
        break;

    case(35):
        pontos = "35";
        break;

    case(40):
        pontos = "40";
        break;

    case(45):
        pontos = "45";
        break;

    case (50):
        pontos = "50";
        break;

    case(55):
        pontos = "55";
        break;

    case(60):
        pontos = "60";
        break;

    case(65):
        pontos = "65";
        break;

    case(70):
        pontos = "70";
        break;

    case(75):
        pontos = "75";
        break;

    case(80):
        pontos = "80";
        break;

    case(85):
        pontos = "85";
        break;

    case(90):
        pontos = "90";
        break;

    case(95):
        pontos = "95";
        break;

    case(100):
        pontos = "100";
        break;

    default:
        break;
    }
    return pontos;
}

//Função que inicia o jogo
void jogo_iniciado()
{
    system("cls");
    texto_em_fala("Okay, vamos iniciar o jogo!\n");
    texto_em_fala("Iniciando em 3... 2... 1...\n");

    system("cls");
}

//Função de inicio
void inicio()
{
    system("cls");
    texto_em_fala("-----------JOGO DE PALAVRAS!-----------");
    texto_em_fala("\nQual é o seu nome?\n");
    string nome = fala_em_texto();
    texto_em_fala("\nOlá " + nome + " Vamos jogar um jogo?\n");
    string opcao = fala_em_texto();

    if (opcao == ("Sim.") || opcao == ("Claro.") || opcao == ("Com certeza.") || opcao == ("Vamos."))
    {
        texto_em_fala("\nÓtimo, quer que eu te passe as instruções?\n");
        opcao = fala_em_texto();
        if (opcao == ("Sim.") || opcao == ("Claro.") || opcao == ("Com certeza.") || opcao == ("Por favor."))
        {
            instrucoes(); // chamando função de instruções caso solicitado pelo jogador
        }
    }
    else
    {
        texto_em_fala("Que pena! Deseja sair?");
        string reinicio = fala_em_texto();
        if (reinicio == ("Sim.") || reinicio == ("Claro.") || reinicio == ("Com certeza."))
        {
            texto_em_fala("Até logo.");
            system("cls");
        }
    }
}

//Função que reinicia o jogo caso o jogador deseje
void reinicio() {
    system("cls");

    int main();

    texto_em_fala("Deseja jogar novamente?\n");
    string opcao = fala_em_texto();

    if (opcao == "Sim." || opcao == "Claro." || opcao == "Com certeza.") {
        main(); // chamando função principal novamente caso o jogador deseje jogar novamente
    }
    else {
        texto_em_fala("\nAté logo!\n"); // Caso o jogador não queira jogar novamente, despede do jogador e
    }                                   // encerra o jogo.
}

//Função principal do sistema
int main()
{
    //Configurando a fala do computador
    setlocale(LC_ALL, ".UTF8");
    autenticacao->SetSpeechRecognitionLanguage("pt-BR");
    autenticacao->SetSpeechSynthesisLanguage("pt-BR");
    autenticacao->SetSpeechSynthesisVoiceName("pt-BR-FranciscaNeural");
    requisicao_textofala = SpeechSynthesizer::FromConfig(autenticacao);
    requisicao_falatexto = SpeechRecognizer::FromConfig(autenticacao, audioConfig);

    try
    {
        int opcao = escolhe_letra(); // Opção chama função que gera letra e recebe o retorno da função
        int ponto;
        string caminho;
        string palavraPC;
        string pontos;

        inicio(); // Chamando função de início
        jogo_iniciado(); // após função de início, chama função de inicio do jogo

        //inciando os casos de acordo com a letra selecionada
        switch (opcao)
        {
        case (0):
            texto_em_fala("A letra selecionada, foi A");

            caminho = "A.txt"; // define o caminho do arquivo de dicionario correspondente a letra escolhida
            ponto = jogo(caminho); // variavel chama a função de jogo e recebe a pontuação numérica obtida pelo jogador

            pontos = pontuacao(ponto); // variavel chama função que converte pontuação numérica em string e recebe o retorno da função

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio(); // chama função de reinicio do jogo 
            break;

        case (1):
            texto_em_fala("A letra selecionada, foi B");

            caminho = "B.txt"; 
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (2):
            texto_em_fala("A letra selecionada, foi C");

            caminho = "C.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (3):
            texto_em_fala("A letra selecionada, foi D");

            caminho = "D.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (4):
            texto_em_fala("A letra selecionada, foi E");

            caminho = "E.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (5):
            texto_em_fala("A letra selecionada, foi F");

            caminho = "F.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (6):
            texto_em_fala("A letra selecionada, foi G");

            caminho = "G.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (7):
            texto_em_fala("A letra selecionada, foi H");

            caminho = "H.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (8):
            texto_em_fala("A letra selecionada, foi I");

            caminho = "I.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (9):
            texto_em_fala("A letra selecionada, foi J");

            caminho = "J.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (10):
            texto_em_fala("A letra selecionada, foi K");

            caminho = "K.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (11):
            texto_em_fala("A letra selecionada, foi L");

            caminho = "L.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (12):
            texto_em_fala("A letra selecionada, foi M");

            caminho = "M.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (13):
            texto_em_fala("A letra selecionada, foi N");

            caminho = "N.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (14):
            texto_em_fala("A letra selecionada, foi O");

            caminho = "O.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (15):
            texto_em_fala("A letra selecionada, foi P");

            caminho = "P.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (16):
            texto_em_fala("A letra selecionada, foi Q");

            caminho = "Q.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (17):
            texto_em_fala("A letra selecionada, foi R");

            caminho = "R.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (18):
            texto_em_fala("A letra selecionada, foi S");

            caminho = "S.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (19):
            texto_em_fala("A letra selecionada, foi T");

            caminho = "T.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (20):
            texto_em_fala("A letra selecionada, foi U");

            caminho = "U.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (21):
            texto_em_fala("A letra selecionada, foi V");

            caminho = "V.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (22):
            texto_em_fala("A letra selecionada, foi W");

            caminho = "W.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (23):
            texto_em_fala("A letra selecionada, foi X");

            caminho = "X.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (24):
            texto_em_fala("A letra selecionada, foi Y");

            caminho = "Y.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        case (25):
            texto_em_fala("A letra selecionada, foi Z");

            caminho = "Z.txt";
            ponto = jogo(caminho);

            pontos = pontuacao(ponto);

            texto_em_fala("\nA pontuação atingida foi de " + pontos + " pontos");

            reinicio();
            break;

        default:
            texto_em_fala("ERROR!");
            break;
        }

    }
    catch (exception e)
    {
        cout << e.what();
    }
    return (0);
}