#include "conversor.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


// ##############################
// MOSTRA PASSO A PASSO
// DECIMAL -> BINÁRIO
// ##############################

void mostrarPassoBinario(int num){

    int original = num;

    string resultado = "";

    cout << endl;
    cout << "Conversao de "
         << original
         << " para binario:"
         << endl << endl;

    while(num > 0){

        int resto = num % 2;

        cout << num
             << " / 2 = "
             << num / 2
             << " resto "
             << resto
             << endl;

        resultado = char(resto + '0') + resultado;

        num = num / 2;
    }

    cout << endl;
    cout << "Resultado final: "
         << resultado
         << endl;
}


// ##############################
// MOSTRA PASSO A PASSO
// DECIMAL -> OCTAL
// ##############################

void mostrarPassoOctal(int num){

    int original = num;

    string resultado = "";

    cout << endl;
    cout << "Conversao de "
         << original
         << " para octal:"
         << endl << endl;

    while(num > 0){

        int resto = num % 8;

        cout << num
             << " / 8 = "
             << num / 8
             << " resto "
             << resto
             << endl;

        resultado = char(resto + '0') + resultado;

        num = num / 8;
    }

    cout << endl;
    cout << "Resultado final: "
         << resultado
         << endl;
}


// ##############################
// MOSTRA PASSO A PASSO
// DECIMAL -> HEXADECIMAL
// ##############################

void mostrarPassoHexa(int num){

    int original = num;

    string resultado = "";

    cout << endl;
    cout << "Conversao de "
         << original
         << " para hexadecimal:"
         << endl << endl;

    while(num > 0){

        int resto = num % 16;

        cout << num
             << " / 16 = "
             << num / 16
             << " resto "
             << resto
             << endl;

        if(resto < 10){

            resultado = char(resto + '0') + resultado;
        }
        else{

            resultado = char(resto - 10 + 'A') + resultado;
        }

        num = num / 16;
    }

    cout << endl;
    cout << "Resultado final: "
         << resultado
         << endl;
}


// ##############################
// MOSTRA SOMATÓRIO POSICIONAL
// BINÁRIO -> DECIMAL
// ##############################

void mostrarSomatorioBinario(string bin){

    int decimal = 0;

    int tamanho = bin.length();

    cout << endl;
    cout << "Somatorio posicional:" << endl << endl;

    for(int i = 0; i < tamanho; i++){

        int bit = bin[i] - '0';

        int potencia = tamanho - 1 - i;

        int valor = bit * pow(2, potencia);

        cout << bit
             << " x 2^"
             << potencia
             << " = "
             << valor
             << endl;

        decimal += valor;
    }

    cout << endl;
    cout << "Resultado final: "
         << decimal
         << endl;
}


// ##############################
// MOSTRA SOMATÓRIO POSICIONAL
// OCTAL -> DECIMAL
// ##############################

void mostrarSomatorioOctal(string oct){

    int decimal = 0;

    int tamanho = oct.length();

    cout << endl;
    cout << "Somatorio posicional:" << endl << endl;

    for(int i = 0; i < tamanho; i++){

        int digito = oct[i] - '0';

        int potencia = tamanho - 1 - i;

        int valor = digito * pow(8, potencia);

        cout << digito
             << " x 8^"
             << potencia
             << " = "
             << valor
             << endl;

        decimal += valor;
    }

    cout << endl;
    cout << "Resultado final: "
         << decimal
         << endl;
}


// ##############################
// MOSTRA SOMATÓRIO POSICIONAL
// HEXADECIMAL -> DECIMAL
// ##############################

void mostrarSomatorioHexa(string hex){

    int decimal = 0;

    int tamanho = hex.length();

    cout << endl;
    cout << "Somatorio posicional:" << endl << endl;

    for(int i = 0; i < tamanho; i++){

        int digito;

        // Verifica se é número
        if(hex[i] >= '0' && hex[i] <= '9'){

            digito = hex[i] - '0';
        }

        // Letras maiúsculas
        else if(hex[i] >= 'A' && hex[i] <= 'F'){

            digito = hex[i] - 'A' + 10;
        }

        // Letras minúsculas
        else{

            digito = hex[i] - 'a' + 10;
        }

        int potencia = tamanho - 1 - i;

        int valor = digito * pow(16, potencia);

        cout << digito
             << " x 16^"
             << potencia
             << " = "
             << valor
             << endl;

        decimal += valor;
    }

    cout << endl;
    cout << "Resultado final: "
         << decimal
         << endl;
}


// ##############################
// MOSTRA AGRUPAMENTO
// BINÁRIO -> OCTAL
// ##############################

void mostrarAgrupamentoOctal(string bin){

    while(bin.length() % 3 != 0){

        bin = "0" + bin;
    }

    cout << endl;
    cout << "Agrupamento em 3 bits:" << endl << endl;

    for(int i = 0; i < bin.length(); i += 3){

        cout << bin[i]
             << bin[i + 1]
             << bin[i + 2]
             << " ";
    }

    cout << endl << endl;

    cout << "Resultado final: "
         << binarioParaOctal(bin)
         << endl;
}


// ##############################
// MOSTRA AGRUPAMENTO
// BINÁRIO -> HEXADECIMAL
// ##############################

void mostrarAgrupamentoHexa(string bin){

    while(bin.length() % 4 != 0){

        bin = "0" + bin;
    }

    cout << endl;
    cout << "Agrupamento em 4 bits:" << endl << endl;

    for(int i = 0; i < bin.length(); i += 4){

        cout << bin[i]
             << bin[i + 1]
             << bin[i + 2]
             << bin[i + 3]
             << " ";
    }

    cout << endl << endl;

    cout << "Resultado final: "
         << binarioParaHexa(bin)
         << endl;
}