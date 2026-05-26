#include "validacao.h"


// ##############################
// VALIDA NUMERO BINARIO
// Aceita:
// 0
// 1
// .
// ##############################

bool validarBinario(string bin){

    int pontos = 0;

    for(int i = 0; i < bin.length(); i++){

        // Conta pontos decimais
        if(bin[i] == '.'){

            pontos++;

            // Mais de um ponto = invalido
            if(pontos > 1){

                return false;
            }
        }

        // Se nao for 0 nem 1
        else if(bin[i] != '0' && bin[i] != '1'){

            return false;
        }
    }

    return true;
}


// ##############################
// VALIDA NUMERO OCTAL
// Aceita:
// 0 ate 7
// .
// ##############################

bool validarOctal(string oct){

    int pontos = 0;

    for(int i = 0; i < oct.length(); i++){

        if(oct[i] == '.'){

            pontos++;

            if(pontos > 1){

                return false;
            }
        }

        else if(oct[i] < '0' || oct[i] > '7'){

            return false;
        }
    }

    return true;
}


// ##############################
// VALIDA NUMERO HEXADECIMAL
// Aceita:
// 0 ate 9
// A ate F
// a ate f
// .
// ##############################

bool validarHexa(string hex){

    int pontos = 0;

    for(int i = 0; i < hex.length(); i++){

        if(hex[i] == '.'){

            pontos++;

            if(pontos > 1){

                return false;
            }
        }

        else if(
            !(hex[i] >= '0' && hex[i] <= '9') &&
            !(hex[i] >= 'A' && hex[i] <= 'F') &&
            !(hex[i] >= 'a' && hex[i] <= 'f')
        ){

            return false;
        }
    }

    return true;
}