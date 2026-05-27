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

        cout << "=== DECIMAL ===" << endl;
        cout << "1 - Decimal para Binario" << endl;
        cout << "2 - Decimal para Octal" << endl;
        cout << "3 - Decimal para Hexadecimal" << endl;

        cout << endl;

        cout << "=== BINARIO ===" << endl;
        cout << "4 - Binario para Decimal" << endl;
        cout << "5 - Binario para Octal" << endl;
        cout << "6 - Binario para Hexadecimal" << endl;

        cout << endl;

        cout << "=== OCTAL ===" << endl;
        cout << "7 - Octal para Decimal" << endl;
        cout << "8 - Octal para Binario" << endl;
        cout << "9 - Octal para Hexadecimal" << endl;

        cout << endl;

        cout << "=== HEXADECIMAL ===" << endl;
        cout << "10 - Hexadecimal para Decimal" << endl;
        cout << "11 - Hexadecimal para Binario" << endl;
        cout << "12 - Hexadecimal para Octal" << endl;

        cout << endl;

        cout << "=== EXTRAS ===" << endl;
        cout << "13 - Calculadora de Maximos" << endl;
        cout << "14 - Modo Batch CSV" << endl;
        cout << "15 - Modo Quiz" << endl;

        cout << endl;

        cout << "0 - Sair" << endl;

        cin >> opcao;

        switch(opcao){

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

            case 14:{

                executarBatch();

                break;
            }

            case 15:{

                iniciarQuiz();

                break;
            }

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
