#include "conversor.h"
#include <cmath>

using namespace std;

// ##############################
// TROCA VIRGULA POR PONTO
// ##############################

string trocarVirgula(string num){

    for(int i = 0; i < num.length(); i++){

        if(num[i] == ','){

            num[i] = '.';
        }
    }

    return num;
}

// ##################################
// CONVERSÕES DECIMAL -> OUTRAS BASES
// ##################################


// Função que converte decimal para binário
string decimalParaBinario(int num){

    // Caso especial para o número 0
    if(num == 0){
        return "0";
    }

    // String que armazenará o resultado
    string binario = "";

    // Faz divisões sucessivas por 2
    while(num > 0){

        // Guarda o resto da divisão
        int resto = num % 2;

        // Adiciona o resto no início da string
        binario = char(resto + '0') + binario;

        // Atualiza o número
        num = num / 2;
    }

    // Retorna o binário final
    return binario;
}


// Função que converte decimal para octal
string decimalParaOctal(int num){

    // Caso especial para 0
    if(num == 0){
        return "0";
    }

    // String que armazenará o resultado
    string octal = "";

    // Faz divisões sucessivas por 8
    while(num > 0){

        // Guarda o resto da divisão
        int resto = num % 8;

        // Adiciona o resto no início da string
        octal = char(resto + '0') + octal;

        // Atualiza o número
        num = num / 8;
    }

    // Retorna o octal final
    return octal;
}


// Função que converte decimal para hexadecimal
string decimalParaHexa(int num){

    // Caso especial para 0
    if(num == 0){
        return "0";
    }

    // String que armazenará o hexadecimal
    string hexa = "";

    // Faz divisões sucessivas por 16
    while(num > 0){

        // Guarda o resto
        int resto = num % 16;

        // Se o valor for menor que 10
        // adiciona número normal
        if(resto < 10){

            hexa = char(resto + '0') + hexa;
        }

        // Se for maior ou igual a 10
        // converte para letras A-F
        else{

            hexa = char(resto - 10 + 'A') + hexa;
        }

        // Atualiza o número
        num = num / 16;
    }

    // Retorna o hexadecimal final
    return hexa;
}



// ##################################
// CONVERSÕES OUTRAS BASES -> DECIMAL
// ##################################


// Função que converte binário para decimal
int binarioParaDecimal(string bin){

    // Variável acumuladora
    int decimal = 0;

    // Guarda o tamanho da string
    int tamanho = bin.length();

    // Percorre todos os dígitos
    for(int i = 0; i < tamanho; i++){

        // Se o bit atual for 1
        if(bin[i] == '1'){

            // Soma potência de 2 correspondente
            decimal += pow(2, tamanho - 1 - i);
        }
    }

    // Retorna o decimal final
    return decimal;
}


// Função que converte octal para decimal
int octalParaDecimal(string oct){

    // Variável acumuladora
    int decimal = 0;

    // Guarda tamanho da string
    int tamanho = oct.length();

    // Percorre todos os dígitos
    for(int i = 0; i < tamanho; i++){

        // Converte caractere para número
        int digito = oct[i] - '0';

        // Soma potência de 8 correspondente
        decimal += digito * pow(8, tamanho - 1 - i);
    }

    // Retorna decimal final
    return decimal;
}


// Função que converte hexadecimal para decimal
int hexaParaDecimal(string hex){

    // Variável acumuladora
    int decimal = 0;

    // Guarda tamanho da string
    int tamanho = hex.length();

    // Percorre todos os caracteres
    for(int i = 0; i < tamanho; i++){

        // Guarda valor decimal do caractere
        int valor;

        // Se for número
        if(hex[i] >= '0' && hex[i] <= '9'){

            valor = hex[i] - '0';
        }

        // Se for letra hexadecimal
        else{

            valor = hex[i] - 'A' + 10;
        }

        // Soma potência de 16 correspondente
        decimal += valor * pow(16, tamanho - 1 - i);
    }

    // Retorna decimal final
    return decimal;
}


// ##################################
// CONVERSÕES POR AGRUPAMENTO DE BITS
// ##################################

// Função que converte binário para octal
string binarioParaOctal(string bin){

    // String resultado
    string octal = "";

    // Adiciona zeros à esquerda
    // até o tamanho ser múltiplo de 3
    while(bin.length() % 3 != 0){

        bin = "0" + bin;
    }

    // Percorre grupos de 3 bits
    for(int i = 0; i < bin.length(); i += 3){

        // Guarda valor decimal do grupo
        int valor = 0;

        // Primeiro bit vale 4
        if(bin[i] == '1'){
            valor += 4;
        }

        // Segundo bit vale 2
        if(bin[i + 1] == '1'){
            valor += 2;
        }

        // Terceiro bit vale 1
        if(bin[i + 2] == '1'){
            valor += 1;
        }

        // Converte valor para caractere
        octal += char(valor + '0');
    }

    // Retorna octal final
    return octal;
}


// Função que converte binário para hexadecimal
string binarioParaHexa(string bin){

    // String resultado
    string hexa = "";

    // Adiciona zeros à esquerda
    // até o tamanho ser múltiplo de 4
    while(bin.length() % 4 != 0){

        bin = "0" + bin;
    }

    // Percorre grupos de 4 bits
    for(int i = 0; i < bin.length(); i += 4){

        // Guarda valor decimal do grupo
        int valor = 0;

        // Primeiro bit vale 8
        if(bin[i] == '1'){
            valor += 8;
        }

        // Segundo bit vale 4
        if(bin[i + 1] == '1'){
            valor += 4;
        }

        // Terceiro bit vale 2
        if(bin[i + 2] == '1'){
            valor += 2;
        }

        // Quarto bit vale 1
        if(bin[i + 3] == '1'){
            valor += 1;
        }

        // Se valor for menor que 10
        if(valor < 10){

            // Adiciona número normal
            hexa += char(valor + '0');
        }

        // Se for maior ou igual a 10
        else{

            // Converte para letra hexadecimal
            hexa += char(valor - 10 + 'A');
        }
    }

    // Retorna hexadecimal final
    return hexa;
}

// ##################################
// CONVERSÃO DE OCTAL E HEXADECIMAL PARA BINÁRIO 
//##################################

string octalParaBinario(string oct){

    string binario = "";

    // Percorre todos os dígitos octais
    for(int i = 0; i < oct.length(); i++){

        // Verifica qual é o dígito
        switch(oct[i]){

            case '0':
                binario += "000";
                break;

            case '1':
                binario += "001";
                break;

            case '2':
                binario += "010";
                break;

            case '3':
                binario += "011";
                break;

            case '4':
                binario += "100";
                break;

            case '5':
                binario += "101";
                break;

            case '6':
                binario += "110";
                break;

            case '7':
                binario += "111";
                break;
        }
    }

    return binario;
}

string hexaParaBinario(string hex){

    string binario = "";

    // Percorre todos os caracteres
    for(int i = 0; i < hex.length(); i++){

        switch(hex[i]){

            case '0':
                binario += "0000";
                break;

            case '1':
                binario += "0001";
                break;

            case '2':
                binario += "0010";
                break;

            case '3':
                binario += "0011";
                break;

            case '4':
                binario += "0100";
                break;

            case '5':
                binario += "0101";
                break;

            case '6':
                binario += "0110";
                break;

            case '7':
                binario += "0111";
                break;

            case '8':
                binario += "1000";
                break;

            case '9':
                binario += "1001";
                break;

            case 'A':
            case 'a':
                binario += "1010";
                break;

            case 'B':
            case 'b':
                binario += "1011";
                break;

            case 'C':
            case 'c':
                binario += "1100";
                break;

            case 'D':
            case 'd':
                binario += "1101";
                break;

            case 'E':
            case 'e':
                binario += "1110";
                break;

            case 'F':
            case 'f':
                binario += "1111";
                break;
        }
    }

    return binario;
}

// ##############################
// OCTAL -> HEXADECIMAL
// Conversão indireta utilizando
// octal -> binario -> hexadecimal
// ##############################

string octalParaHexa(string oct){

    // Primeiro converte para binário
    string binario = octalParaBinario(oct);

    // Depois converte o binário para hexadecimal
    return binarioParaHexa(binario);
}

// ##############################
// HEXADECIMAL -> OCTAL
// Conversão indireta utilizando
// hexadecimal -> binario -> octal
// ##############################

string hexaParaOctal(string hex){

    // Primeiro converte para binário
    string binario = hexaParaBinario(hex);

    // Depois converte o binário para octal
    return binarioParaOctal(binario);
}

// ##############################
// DECIMAL FRACIONÁRIO -> BINÁRIO
// ##############################

string decimalFracionarioParaBinario(double num){

    // Parte inteira
    int parteInteira = (int) num;

    // Parte fracionária
    double parteFracionaria = num - parteInteira;

    // Conversão da parte inteira
    string binarioInteiro = decimalParaBinario(parteInteira);

    string binarioFracionario = "";

    int contador = 0;

    bool truncado = false;

    // Limite de 16 casas
    while(parteFracionaria > 0 && contador < 16){

        parteFracionaria *= 2;

        // Se passou de 1
        if(parteFracionaria >= 1){

            binarioFracionario += '1';

            parteFracionaria -= 1;
        }
        else{

            binarioFracionario += '0';
        }

        contador++;
    }

    // Verifica truncamento
    if(parteFracionaria > 0){

        truncado = true;
    }

    // Caso não exista parte fracionária
    if(binarioFracionario == ""){

        return binarioInteiro;
    }

    string resultado =
        binarioInteiro
        + "."
        + binarioFracionario;

    if(truncado){

        resultado += " (truncado)";
    }

    return resultado;
}

// ##############################
// DECIMAL FRACIONÁRIO -> OCTAL
// ##############################

string decimalFracionarioParaOctal(double num){

    // Parte inteira
    int parteInteira = (int) num;

    // Parte fracionária
    double parteFracionaria = num - parteInteira;

    // Conversão da parte inteira
    string octalInteiro = decimalParaOctal(parteInteira);

    string octalFracionario = "";

    int contador = 0;

    bool truncado = false;

    // Limite de 16 casas
    while(parteFracionaria > 0 && contador < 16){

        parteFracionaria *= 8;

        int digito = (int) parteFracionaria;

        octalFracionario += char(digito + '0');

        parteFracionaria -= digito;

        contador++;
    }

    // Verifica truncamento
    if(parteFracionaria > 0){

        truncado = true;
    }

    // Caso não exista parte fracionária
    if(octalFracionario == ""){

        return octalInteiro;
    }

    string resultado =
        octalInteiro
        + "."
        + octalFracionario;

    if(truncado){

        resultado += " (truncado)";
    }

    return resultado;
}

// ##############################
// DECIMAL FRACIONÁRIO -> HEXADECIMAL
// ##############################

string decimalFracionarioParaHexa(double num){

    // Parte inteira
    int parteInteira = (int) num;

    // Parte fracionária
    double parteFracionaria = num - parteInteira;

    // Conversão da parte inteira
    string hexaInteiro = decimalParaHexa(parteInteira);

    string hexaFracionario = "";

    int contador = 0;

    bool truncado = false;

    // Limite de 16 casas
    while(parteFracionaria > 0 && contador < 16){

        parteFracionaria *= 16;

        int digito = (int) parteFracionaria;

        // Se for menor que 10
        if(digito < 10){

            hexaFracionario += char(digito + '0');
        }
        else{

            hexaFracionario += char(digito - 10 + 'A');
        }

        parteFracionaria -= digito;

        contador++;
    }

    // Verifica truncamento
    if(parteFracionaria > 0){

        truncado = true;
    }

    // Caso não exista parte fracionária
    if(hexaFracionario == ""){

        return hexaInteiro;
    }

    string resultado =
        hexaInteiro
        + "."
        + hexaFracionario;

    if(truncado){

        resultado += " (truncado)";
    }

    return resultado;
}

// ##############################
// BINÁRIO FRACIONÁRIO -> DECIMAL
// ##############################

double binarioFracionarioParaDecimal(string bin){

    double decimal = 0;

    int posicaoVirgula = bin.find('.');

    // Parte inteira
    for(int i = posicaoVirgula - 1, potencia = 0;
        i >= 0;
        i--, potencia++){

        if(bin[i] == '1'){

            decimal += pow(2, potencia);
        }
    }

    // Parte fracionária
    for(int i = posicaoVirgula + 1, potencia = -1;
        i < bin.length();
        i++, potencia--){

        if(bin[i] == '1'){

            decimal += pow(2, potencia);
        }
    }

    return decimal;
}

// ##############################
// OCTAL FRACIONÁRIO -> DECIMAL
// ##############################

double octalFracionarioParaDecimal(string oct){

    double decimal = 0;

    int posicaoVirgula = oct.find('.');

    // Parte inteira
    for(int i = posicaoVirgula - 1, potencia = 0;
        i >= 0;
        i--, potencia++){

        int digito = oct[i] - '0';

        decimal += digito * pow(8, potencia);
    }

    // Parte fracionária
    for(int i = posicaoVirgula + 1, potencia = -1;
        i < oct.length();
        i++, potencia--){

        int digito = oct[i] - '0';

        decimal += digito * pow(8, potencia);
    }

    return decimal;
}

// ##############################
// HEXADECIMAL FRACIONÁRIO -> DECIMAL
// ##############################

double hexaFracionarioParaDecimal(string hex){

    double decimal = 0;

    int posicaoVirgula = hex.find('.');

    // Parte inteira
    for(int i = posicaoVirgula - 1, potencia = 0;
        i >= 0;
        i--, potencia++){

        int digito;

        if(hex[i] >= '0' && hex[i] <= '9'){

            digito = hex[i] - '0';
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F'){

            digito = hex[i] - 'A' + 10;
        }
        else{

            digito = hex[i] - 'a' + 10;
        }

        decimal += digito * pow(16, potencia);
    }

    // Parte fracionária
    for(int i = posicaoVirgula + 1, potencia = -1;
        i < hex.length();
        i++, potencia--){

        int digito;

        if(hex[i] >= '0' && hex[i] <= '9'){

            digito = hex[i] - '0';
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F'){

            digito = hex[i] - 'A' + 10;
        }
        else{

            digito = hex[i] - 'a' + 10;
        }

        decimal += digito * pow(16, potencia);
    }

    return decimal;
}