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

    ifstream entrada("entrada.csv");

    ofstream saida("saida.csv");

    if(!entrada){

        cout << "ERRO ao abrir entrada.csv!"
             << endl;

        return;
    }

    string valor;
    string origem;
    string destino;

    while(

        getline(entrada, valor, ';') &&
        getline(entrada, origem, ';') &&
        getline(entrada, destino)

    ){

        string resultado = "";

        // Remove possível \r do Windows
        if(destino[destino.length() - 1] == '\r'){

            destino.erase(destino.length() - 1);
        }

        // ##############################
        // DECIMAL -> BINARIO
        // ##############################

        if(origem == "10" && destino == "2"){

            resultado =
            decimalParaBinario(stoi(valor));
        }

        // ##############################
        // DECIMAL -> OCTAL
        // ##############################

        else if(origem == "10" && destino == "8"){

            resultado =
            decimalParaOctal(stoi(valor));
        }

        // ##############################
        // DECIMAL -> HEXADECIMAL
        // ##############################

        else if(origem == "10" && destino == "16"){

            resultado =
            decimalParaHexa(stoi(valor));
        }

        // ##############################
        // BINARIO -> DECIMAL
        // ##############################

        else if(origem == "2" && destino == "10"){

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

        else if(origem == "8" && destino == "10"){

            if(validarOctal(valor)){

                resultado =
                to_string(octalParaDecimal(valor));
            }
            else{

                resultado = "ERRO";
            }
        }

        // ##############################
        // HEXADECIMAL -> DECIMAL
        // ##############################

        else if(origem == "16" && destino == "10"){

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

        else if(origem == "2" && destino == "8"){

            if(validarBinario(valor)){

                resultado =
                binarioParaOctal(valor);
            }
            else{

                resultado = "ERRO";
            }
        }

        // ##############################
        // BINARIO -> HEXADECIMAL
        // ##############################

        else if(origem == "2" && destino == "16"){

            if(validarBinario(valor)){

                resultado =
                binarioParaHexa(valor);
            }
            else{

                resultado = "ERRO";
            }
        }

        // ##############################
        // OCTAL -> BINARIO
        // ##############################

        else if(origem == "8" && destino == "2"){

            if(validarOctal(valor)){

                resultado =
                octalParaBinario(valor);
            }
            else{

                resultado = "ERRO";
            }
        }

        // ##############################
        // HEXADECIMAL -> BINARIO
        // ##############################

        else if(origem == "16" && destino == "2"){

            if(validarHexa(valor)){

                resultado =
                hexaParaBinario(valor);
            }
            else{

                resultado = "ERRO";
            }
        }

        // ##############################
        // OCTAL -> HEXADECIMAL
        // ##############################

        else if(origem == "8" && destino == "16"){

            if(validarOctal(valor)){

                resultado =
                octalParaHexa(valor);
            }
            else{

                resultado = "ERRO";
            }
        }

        // ##############################
        // HEXADECIMAL -> OCTAL
        // ##############################

        else if(origem == "16" && destino == "8"){

            if(validarHexa(valor)){

                resultado =
                hexaParaOctal(valor);
            }
            else{

                resultado = "ERRO";
            }
        }

        // ##############################
        // CONVERSAO INVALIDA
        // ##############################

        else{

            resultado = "CONVERSAO INVALIDA";
        }

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
