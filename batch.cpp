#include <iostream>
#include <fstream>

#include "batch.h"
#include "conversor.h"
#include "validacao.h"

using namespace std;


// ##############################
// EXECUTA O MODO BATCH
// ##############################

void executarBatch(){

    // Arquivo de entrada
    ifstream entrada("entrada.csv");

    // Arquivo de saída
    ofstream saida("saida.csv");

    // Verifica se abriu corretamente
    if(!entrada){

        cout << "ERRO ao abrir entrada.csv!"
             << endl;

        return;
    }

    string valor;
    string origem;
    string destino;

    // Lê linha por linha
    while(

        getline(entrada, valor, ';') &&
        getline(entrada, origem, ';') &&
        getline(entrada, destino)

    ){

        string resultado = "";

        // ##############################
        // DECIMAL -> BINARIO
        // ##############################

        if(origem == "DEC" && destino == "BIN"){

            resultado =
            decimalParaBinario(stoi(valor));
        }

        // ##############################
        // DECIMAL -> OCTAL
        // ##############################

        else if(origem == "DEC" && destino == "OCT"){

            resultado =
            decimalParaOctal(stoi(valor));
        }

        // ##############################
        // DECIMAL -> HEXA
        // ##############################

        else if(origem == "DEC" && destino == "HEX"){

            resultado =
            decimalParaHexa(stoi(valor));
        }

        // ##############################
        // BINARIO -> DECIMAL
        // ##############################

        else if(origem == "BIN" && destino == "DEC"){

            if(validarBinario(valor)){

                resultado =
                to_string(binarioParaDecimal(valor));
            }
            else{

                resultado = "ERRO";
            }
        }

        // ##############################
        // OCTAL -> DECIMAL
        // ##############################

        else if(origem == "OCT" && destino == "DEC"){

            if(validarOctal(valor)){

                resultado =
                to_string(octalParaDecimal(valor));
            }
            else{

                resultado = "ERRO";
            }
        }

        // ##############################
        // HEXA -> DECIMAL
        // ##############################

        else if(origem == "HEX" && destino == "DEC"){

            if(validarHexa(valor)){

                resultado =
                to_string(hexaParaDecimal(valor));
            }
            else{

                resultado = "ERRO";
            }
        }

        // ##############################
        // BINARIO -> OCTAL
        // ##############################

        else if(origem == "BIN" && destino == "OCT"){

            resultado =
            binarioParaOctal(valor);
        }

        // ##############################
        // BINARIO -> HEXA
        // ##############################

        else if(origem == "BIN" && destino == "HEX"){

            resultado =
            binarioParaHexa(valor);
        }

        // ##############################
        // OCTAL -> BINARIO
        // ##############################

        else if(origem == "OCT" && destino == "BIN"){

            resultado =
            octalParaBinario(valor);
        }

        // ##############################
        // HEXA -> BINARIO
        // ##############################

        else if(origem == "HEX" && destino == "BIN"){

            resultado =
            hexaParaBinario(valor);
        }

        // ##############################
        // OCTAL -> HEXA
        // ##############################

        else if(origem == "OCT" && destino == "HEX"){

            resultado =
            octalParaHexa(valor);
        }

        // ##############################
        // HEXA -> OCTAL
        // ##############################

        else if(origem == "HEX" && destino == "OCT"){

            resultado =
            hexaParaOctal(valor);
        }

        // ##############################
        // CONVERSAO INVALIDA
        // ##############################

        else{

            resultado = "CONVERSAO INVALIDA";
        }

        // Escreve no arquivo de saída
        saida
            << valor << ";"
            << origem << ";"
            << resultado << ";"
            << destino
            << endl;
    }

    entrada.close();

    saida.close();

    cout << endl;

    cout << "Arquivo saida.csv gerado com sucesso!"
         << endl;
}