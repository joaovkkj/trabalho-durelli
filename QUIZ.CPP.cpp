#include <iostream>
#include <string>

using namespace std;


int aleatorio(int limite, unsigned long long &semente)
{
    semente = (1103515245 * semente + 12345);

    return semente % limite;
}

// Converte valor para caractere de hexadecimal
char valorParaChar(int valor)
{
    if (valor <= 9)
        return '0' + valor;

    return 'A' + (valor - 10);
}


void inverter(string &texto)
{
    int inicio = 0;
    int fim = texto.length() - 1;

    while (inicio < fim)
    {
        char temp = texto[inicio];
        texto[inicio] = texto[fim];
        texto[fim] = temp;

        inicio++;
        fim--;
    }
}

// Decimal para qualquer base
string deDecimal(int numero, int base)
{
    if (numero == 0)
        return "0";

    string resultado = "";

    while (numero > 0)
    {
        int resto = numero % base;

        resultado += valorParaChar(resto);

        numero /= base;
    }

    inverter(resultado);

    return resultado;
}

// Nome das bases
string nomeBase(int base)
{
    if (base == 2)
        return "Binario";

    if (base == 8)
        return "Octal";

    if (base == 10)
        return "Decimal";

    return "Hexadecimal";
}

// Gera as dificuldades 
int gerarNumero(int nivel, unsigned long long &semente)
{
    if (nivel == 1)
        return aleatorio(16, semente) + 1;

    if (nivel == 2)
        return aleatorio(64, semente) + 1;

    if (nivel == 3)
        return aleatorio(256, semente) + 1;

    if (nivel == 4)
        return aleatorio(1024, semente) + 1;

    return aleatorio(4096, semente) + 1;
}

void iniciarQuiz()
{
    int pontos = 0;

    unsigned long long semente = 123456789;

    int bases[4] = {2, 8, 10, 16};

    cout << " QUIZ DE CONVERSAO DE BASES ";

    for (int nivel = 1; nivel <= 5; nivel++)
    {
        cout << " NIVEL "
             << nivel
             << "         ";

        for (int rodada = 1; rodada <= 3; rodada++)
        {
            int numero =
                gerarNumero(nivel, semente);

            int baseOrigem =
                bases[aleatorio(4, semente)];

            int baseDestino =
                bases[aleatorio(4, semente)];

            while (baseDestino == baseOrigem)
            {
                baseDestino =
                    bases[aleatorio(4, semente)];
            }

            string valorOrigem =
                deDecimal(numero, baseOrigem);

            string respostaCorreta =
                deDecimal(numero, baseDestino);

            string respostaUsuario;

            cout << "\nConverta "
                 << valorOrigem
                 << " de "
                 << nomeBase(baseOrigem)
                 << " para "
                 << nomeBase(baseDestino)
                 << ": ";

            cin >> respostaUsuario;

            if (respostaUsuario == respostaCorreta)
            {
                cout << "Correto!\n";
                pontos++;
            }
            else
            {
                cout << "Errado!\n";
                cout << "Resposta correta: "
                     << respostaCorreta << "\n";
            }

            cout << "Pontuacao atual: "
                 << pontos << "\n";
        }
    }

    cout << " FIM DO QUIZ ";
    cout << "Pontuacao final: "
         << pontos << "\n";

}
