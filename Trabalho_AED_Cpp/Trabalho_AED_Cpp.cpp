#include <iostream>
#include <fstream>
#include <string>
#include <speechapi_cxx.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>
#include <limits>

using namespace std;
using namespace Microsoft::CognitiveServices::Speech;
using namespace Microsoft::CognitiveServices::Speech::Audio;

/*std::fstream& GotoLine(std::fstream& file, unsigned int num) {
    file.seekg(std::ios::beg);
    for (int i = 0; i < num - 1; ++i) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}*/

auto autenticacao = SpeechConfig::FromSubscription("bb33f111891842028908eae14f359dd0", "brazilsouth");
auto requisicao_textofala = SpeechSynthesizer::FromConfig(autenticacao);
auto audioConfig = AudioConfig::FromDefaultMicrophoneInput();
auto requisicao_falatexto = SpeechRecognizer::FromConfig(autenticacao, audioConfig);

void texto_em_fala(string Texto)
{
    cout << Texto + "\n";
    requisicao_textofala->SpeakTextAsync(Texto).get();
}

string fala_em_texto()
{
    auto resultado = requisicao_falatexto->RecognizeOnceAsync().get();
    cout << resultado->Text + "\n";
    return resultado->Text;
}

void repeticao_instrucoes()
{
    void instrucoes();
    void jogo_iniciado();

    system("cls");
    texto_em_fala("\nPrecisa ouvir as regras mais uma vez?");
    string opcao = fala_em_texto();

    if (opcao == ("Sim.") || opcao == ("Preciso."))
    {
        instrucoes();
        opcao = "";
    }
    else {
        jogo_iniciado();
    }
}

void instrucoes()
{
    void repeticao_instrucoes();

    system("cls");

    texto_em_fala("---------------INSTRUÇÕES---------------\n\n");
    texto_em_fala("- O objetivo do jogo é falar a maior quantidade de palavras que comecem com uma determinada letra, \nsem repetir a mesma palavra.\n");
    texto_em_fala("- Eu vou escolher uma letra aleatoriamente e todas as palavras deverão iniciar com essa letra.\n");
    texto_em_fala("- Uma vez eu falo, outra vez você.\n");
    texto_em_fala("- Cada palavra correta, corresponde a 5 pontos.\n");
    texto_em_fala("- Se ficar mais de 5 segundos sem falar a palavra, perde o jogo e é exibido a quantidade de pontos e a maior pontuação já alcançada.\n");

    repeticao_instrucoes();
}

int escolhe_letra()
{
    int letra = 0;
    srand(time(NULL));
    letra = rand() % 26;
    return (letra);
}

string palavra_aleatoria()
{
    string palavra;
    int linhaAleatoria;

    fstream arquivo("A.txt");

    srand(time(NULL));
    linhaAleatoria = rand() % 44237;

    fseek(arquivo, 2 * sizeof(linhaAleatoria), SEEK_SET);

    
    return(palavra);
}

void jogo_iniciado()
{
    texto_em_fala("Okay, vamos iniciar o jogo!");
    texto_em_fala("Iniciando em 3... 2... 1...");

    system("cls");
}

void inicio()
{
    texto_em_fala("-----------JOGO DE PALAVRAS!-----------");
    texto_em_fala("\nQual é o seu nome?\n");
    string nome = fala_em_texto();
    texto_em_fala("\nOlá " + nome + " Vamos jogar um jogo?\n");
    string opcao = fala_em_texto();

    if (opcao == ("Sim.") || opcao == ("Claro.") || opcao == ("Com certeza."))
    {
        texto_em_fala("\nÓtimo, quer que eu te passe as instruções?");
        opcao = fala_em_texto();
        if (opcao == ("Sim.") || opcao == ("Claro.") || opcao == ("Com certeza.") || opcao == ("Por favor."))
        {
            instrucoes();
        }
        else
        {
            jogo_iniciado();
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

int main()
{
    setlocale(LC_ALL, ".UTF8");
    autenticacao->SetSpeechRecognitionLanguage("pt-BR");
    autenticacao->SetSpeechSynthesisLanguage("pt-BR");
    autenticacao->SetSpeechSynthesisVoiceName("pt-BR-FranciscaNeural");
    requisicao_textofala = SpeechSynthesizer::FromConfig(autenticacao);
    requisicao_falatexto = SpeechRecognizer::FromConfig(autenticacao, audioConfig);

    try
    {
        inicio();

        int opcao = escolhe_letra();

        texto_em_fala(palavra_aleatoria());






       /* switch (opcao)
        {
        case (0):
            string palavra;
            arquivo.open("C:\Workspaces\ws-trabalho_AED1\Primeiro-Projeto-IA-Cpp-main\Trabalho_AED_Cpp\Dicionario\A.txt");
            if (arquivo.is_open()) {
                getline(arquivo, palavra);
            }
            else {
                texto_em_fala("Não foi encontrado o dicionário");
            }



        default:
            break;
        }*/

    }
    catch (exception e)
    {
        cout << e.what();
    }
    return (0);
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar:
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln