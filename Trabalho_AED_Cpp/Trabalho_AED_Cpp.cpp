// Trabalho_AED_Cpp.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <fstream>
#include <string>
#include <speechapi_cxx.h>
#include <locale.h>

using namespace std;
using namespace Microsoft::CognitiveServices::Speech;
using namespace Microsoft::CognitiveServices::Speech::Audio;

auto autenticacao = SpeechConfig::FromSubscription("bb33f111891842028908eae14f359dd0", "brazilsouth");
auto requisicao_textofala = SpeechSynthesizer::FromConfig(autenticacao);
auto audioConfig = AudioConfig::FromDefaultMicrophoneInput();
auto requisicao_falatexto = SpeechRecognizer::FromConfig(autenticacao, audioConfig);

void texto_em_fala(string Texto)
{
    cout << Texto + "\n";
    requisicao_textofala->SpeakTextAsync(Texto).get();
}

string fala_em_texto(){
    auto resultado = requisicao_falatexto->RecognizeOnceAsync().get();
    cout << resultado->Text+ "\n";
    return resultado->Text;
}

int main()
{
    setlocale(LC_ALL, "");
    autenticacao->SetSpeechRecognitionLanguage("pt-BR");
    autenticacao->SetSpeechSynthesisLanguage("pt-BR");
    autenticacao->SetSpeechSynthesisVoiceName("pt-BR-Daniel");
    requisicao_textofala = SpeechSynthesizer::FromConfig(autenticacao);
    requisicao_falatexto = SpeechRecognizer::FromConfig(autenticacao, audioConfig);

    try
    {
        texto_em_fala("SISTEMA LIGADO");
        texto_em_fala("Qual é o seu nome?");
        string nome = fala_em_texto();
        texto_em_fala("Olá "+nome+"! Informe a sua senha: ");
        string senha = fala_em_texto();
        texto_em_fala("Verificando. . .");

        if (senha == ("123456.")){
            texto_em_fala("ACESSO CONCEDIDO!");
        }
        else{
            texto_em_fala("ACESSO NEGADO!");
        }
    }
    catch(exception e)
    {
        cout << e.what();
    }
    return(0);
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