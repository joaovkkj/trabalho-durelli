#include <iostream>
#include <string>
#include <cmath>

#include "conversor.h"
#include "validacao.h"
#include "passoapasso.h"
#include "batch.h"
#include "quiz.h"

using namespace std;


// ##############################
// VERIFICA SE O NUMERO
// POSSUI PONTO DECIMAL
// ##############################

bool possuiPonto(string num){

    for(int i = 0; i < num.length(); i++){

        if(num[i] == '.'){

            return true;
        }
    }

    return false;
}


// ##############################
// MENU PASSO A PASSO
// ##############################

int escolherPasso(){

    int passo;

    cout << endl;
    cout << "Mostrar passo a passo?" << endl;
    cout << "0 - Nao" << endl;
    cout << "1 - Sim" << endl;

    cin >> passo;

    return passo;
}


int main(){

    int opcao;

    do{

        cout << endl;
        cout << "##### CONVERSOR #####" << endl << endl;

        // ##############################
        // DECIMAL
        // ##############################

        cout << "=== DECIMAL ===" << endl;

        cout << "1 - Decimal para Binario" << endl;
        cout << "2 - Decimal para Octal" << endl;
        cout << "3 - Decimal para Hexadecimal" << endl;

        cout << endl;

        // ##############################
        // BINARIO
        // ##############################

        cout << "=== BINARIO ===" << endl;

        cout << "4 - Binario para Decimal" << endl;
        cout << "5 - Binario para Octal" << endl;
        cout << "6 - Binario para Hexadecimal" << endl;

        cout << endl;

        // ##############################
        // OCTAL
        // ##############################

        cout << "=== OCTAL ===" << endl;

        cout << "7 - Octal para Decimal" << endl;
        cout << "8 - Octal para Binario" << endl;
        cout << "9 - Octal para Hexadecimal" << endl;

        cout << endl;

        // ##############################
        // HEXADECIMAL
        // ##############################

        cout << "=== HEXADECIMAL ===" << endl;

        cout << "10 - Hexadecimal para Decimal" << endl;
        cout << "11 - Hexadecimal para Binario" << endl;
        cout << "12 - Hexadecimal para Octal" << endl;

        cout << endl;

        // ##############################
        // EXTRAS
        // ##############################

        cout << "=== EXTRAS ===" << endl;

        cout << "13 - Calculadora de Maximos" << endl;
        cout << "14 - Modo Batch CSV" << endl;
        cout << "15 - Modo Quiz" << endl;

        cout << endl;

        cout << "0 - Sair" << endl;

        cin >> opcao;

        switch(opcao){

            // ##############################
            // DECIMAL -> BINARIO
            // ##############################

            case 1:{

                string entrada;

                cout << "Digite um numero decimal: ";
                cin >> entrada;

                entrada = trocarVirgula(entrada);

                int passo = escolherPasso();

                if(possuiPonto(entrada)){

                    double num = stod(entrada);

                    cout << "Binario: "
                         << decimalFracionarioParaBinario(num)
                         << endl;
                }
                else{

                    int num = stoi(entrada);

                    if(passo == 1){

                        mostrarPassoBinario(num);
                    }

                    cout << "Binario: "
                         << decimalParaBinario(num)
                         << endl;
                }

                break;
            }

            // ##############################
            // DECIMAL -> OCTAL
            // ##############################

            case 2:{

                string entrada;

                cout << "Digite um numero decimal: ";
                cin >> entrada;

                entrada = trocarVirgula(entrada);

                int passo = escolherPasso();

                if(possuiPonto(entrada)){

                    double num = stod(entrada);

                    cout << "Octal: "
                         << decimalFracionarioParaOctal(num)
                         << endl;
                }
                else{

                    int num = stoi(entrada);

                    if(passo == 1){

                        mostrarPassoOctal(num);
                    }

                    cout << "Octal: "
                         << decimalParaOctal(num)
                         << endl;
                }

                break;
            }

            // ##############################
            // DECIMAL -> HEXADECIMAL
            // ##############################

            case 3:{

                string entrada;

                cout << "Digite um numero decimal: ";
                cin >> entrada;

                entrada = trocarVirgula(entrada);

                int passo = escolherPasso();

                if(possuiPonto(entrada)){

                    double num = stod(entrada);

                    cout << "Hexadecimal: "
                         << decimalFracionarioParaHexa(num)
                         << endl;
                }
                else{

                    int num = stoi(entrada);

                    if(passo == 1){

                        mostrarPassoHexa(num);
                    }

                    cout << "Hexadecimal: "
                         << decimalParaHexa(num)
                         << endl;
                }

                break;
            }

            // ##############################
            // BINARIO -> DECIMAL
            // ##############################

            case 4:{

                string bin;

                cout << "Digite um numero binario: ";
                cin >> bin;

                bin = trocarVirgula(bin);

                int passo = escolherPasso();

                if(validarBinario(bin)){

                    if(possuiPonto(bin)){

                        cout << "Decimal: "
                             << binarioFracionarioParaDecimal(bin)
                             << endl;
                    }
                    else{

                        if(passo == 1){

                            mostrarSomatorioBinario(bin);
                        }

                        cout << "Decimal: "
                             << binarioParaDecimal(bin)
                             << endl;
                    }
                }
                else{

                    cout << "ERRO: binario invalido!"
                         << endl;
                }

                break;
            }

            // ##############################
            // BINARIO -> OCTAL
            // ##############################

            case 5:{

                string bin;

                cout << "Digite um numero binario: ";
                cin >> bin;

                bin = trocarVirgula(bin);

                int passo = escolherPasso();

                if(validarBinario(bin)){

                    if(passo == 1){

                        mostrarAgrupamentoOctal(bin);
                    }

                    cout << "Octal: "
                         << binarioParaOctal(bin)
                         << endl;
                }
                else{

                    cout << "ERRO: binario invalido!"
                         << endl;
                }

                break;
            }

            // ##############################
            // BINARIO -> HEXADECIMAL
            // ##############################

            case 6:{

                string bin;

                cout << "Digite um numero binario: ";
                cin >> bin;

                bin = trocarVirgula(bin);

                int passo = escolherPasso();

                if(validarBinario(bin)){

                    if(passo == 1){

                        mostrarAgrupamentoHexa(bin);
                    }

                    cout << "Hexadecimal: "
                         << binarioParaHexa(bin)
                         << endl;
                }
                else{

                    cout << "ERRO: binario invalido!"
                         << endl;
                }

                break;
            }

            // ##############################
            // OCTAL -> DECIMAL
            // ##############################

            case 7:{

                string oct;

                cout << "Digite um numero octal: ";
                cin >> oct;

                oct = trocarVirgula(oct);

                int passo = escolherPasso();

                if(validarOctal(oct)){

                    if(possuiPonto(oct)){

                        cout << "Decimal: "
                             << octalFracionarioParaDecimal(oct)
                             << endl;
                    }
                    else{

                        if(passo == 1){

                            mostrarSomatorioOctal(oct);
                        }

                        cout << "Decimal: "
                             << octalParaDecimal(oct)
                             << endl;
                    }
                }
                else{

                    cout << "ERRO: octal invalido!"
                         << endl;
                }

                break;
            }

            // ##############################
            // OCTAL -> BINARIO
            // ##############################

            case 8:{

                string oct;

                cout << "Digite um numero octal: ";
                cin >> oct;

                oct = trocarVirgula(oct);

                if(validarOctal(oct)){

                    cout << "Binario: "
                         << octalParaBinario(oct)
                         << endl;
                }
                else{

                    cout << "ERRO: octal invalido!"
                         << endl;
                }

                break;
            }

            // ##############################
            // OCTAL -> HEXADECIMAL
            // ##############################

            case 9:{

                string oct;

                cout << "Digite um numero octal: ";
                cin >> oct;

                oct = trocarVirgula(oct);

                if(validarOctal(oct)){

                    cout << "Hexadecimal: "
                         << octalParaHexa(oct)
                         << endl;
                }
                else{

                    cout << "ERRO: octal invalido!"
                         << endl;
                }

                break;
            }

            // ##############################
            // HEXADECIMAL -> DECIMAL
            // ##############################

            case 10:{

                string hex;

                cout << "Digite um numero hexadecimal: ";
                cin >> hex;

                hex = trocarVirgula(hex);

                int passo = escolherPasso();

                if(validarHexa(hex)){

                    if(possuiPonto(hex)){

                        cout << "Decimal: "
                             << hexaFracionarioParaDecimal(hex)
                             << endl;
                    }
                    else{

                        if(passo == 1){

                            mostrarSomatorioHexa(hex);
                        }

                        cout << "Decimal: "
                             << hexaParaDecimal(hex)
                             << endl;
                    }
                }
                else{

                    cout << "ERRO: hexadecimal invalido!"
                         << endl;
                }

                break;
            }

            // ##############################
            // HEXADECIMAL -> BINARIO
            // ##############################

            case 11:{

                string hex;

                cout << "Digite um numero hexadecimal: ";
                cin >> hex;

                hex = trocarVirgula(hex);

                if(validarHexa(hex)){

                    cout << "Binario: "
                         << hexaParaBinario(hex)
                         << endl;
                }
                else{

                    cout << "ERRO: hexadecimal invalido!"
                         << endl;
                }

                break;
            }

            // ##############################
            // HEXADECIMAL -> OCTAL
            // ##############################

            case 12:{

                string hex;

                cout << "Digite um numero hexadecimal: ";
                cin >> hex;

                hex = trocarVirgula(hex);

                if(validarHexa(hex)){

                    cout << "Octal: "
                         << hexaParaOctal(hex)
                         << endl;
                }
                else{

                    cout << "ERRO: hexadecimal invalido!"
                         << endl;
                }

                break;
            }

            // ##############################
            // CALCULADORA DE MAXIMOS
            // ##############################

            case 13:{

                int k;

                cout << "Digite a quantidade de bits: ";
                cin >> k;

                int maximo = pow(2, k) - 1;

                cout << endl;

                cout << "Decimal: "
                     << maximo
                     << endl;

                cout << "Binario: "
                     << decimalParaBinario(maximo)
                     << endl;

                cout << "Octal: "
                     << decimalParaOctal(maximo)
                     << endl;

                cout << "Hexadecimal: "
                     << decimalParaHexa(maximo)
                     << endl;

                break;
            }

            // ##############################
            // MODO BATCH
            // ##############################

            case 14:{

                executarBatch();

                break;
            }

            // ##############################
            // MODO QUIZ
            // ##############################

            case 15:{

                iniciarQuiz();

                break;
            }

            // ##############################
            // OPCAO INVALIDA
            // ##############################

            default:{

                if(opcao != 0){

                    cout << "Opcao invalida!"
                         << endl;
                }
            }
        }

    }while(opcao != 0);

    return 0;
}
