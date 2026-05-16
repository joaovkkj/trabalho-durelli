#include <iostream>

using namespace std;

int binario(int num, int restos[]){ //Subprograma que converte decimal em binario
    int i = 0;

    while (num > 1){ //Faz as divisões sucessivas e guarda o resto.
    restos[i] = num % 2; 
    num = num / 2;
    i++;
    }
    restos[i] = num;
    i++;

    for(int j = 0; j < i / 2; j++){

        int temp = restos[j];

        restos[j] = restos[i - 1 - j];

        restos[i - 1 - j] = temp;
    }
    return i;
}

int octal(int num, int restos[]){ //Subprograma que converte decimal em octal
    int i = 0;

    while (num > 1){ //Faz as divisões sucessivas e guarda o resto.
    restos[i] = num % 8; 
    num = num / 8;
    i++;
    }
    restos[i] = num;
    i++;

    for(int j = 0; j < i / 2; j++){ //Inverte o ponteiro para que possamos formar o numero octal.

        int temp = restos[j]; 

        restos[j] = restos[i - 1 - j];

        restos[i - 1 - j] = temp;
    }

return i;
}

int hexa(int num, char restos[]){ //Subprograma que converte decimal em hexadecimal
    int i = 0;

    while (num > 1){ //Faz as divisões sucessivas e guarda o resto.
        int resto = num % 16;

        if(resto < 10){
            restos[i] = resto + '0';
        }
        else{
            restos[i] = resto - 10 + 'A';
        }
    num = num / 16;
    i++;
    }

    if(num < 10){
        restos[i] = num + '0';
    }
    else{
        restos[i] = num - 10 + 'A';
    }

    i++;

    for(int j = 0; j < i / 2; j++){ //Inverte o ponteiro para que possamos formar o numero hexadecimal.

        int temp = restos[j]; 

        restos[j] = restos[i - 1 - j];

        restos[i - 1 - j] = temp;
    }

return i;
}


int main() {
    int numero;
    char conversao;

    cout << "Digite um numero: ";

    cin >> numero;

    cout << "Digite 'a' para converter para binario," <<endl<<
            "'b' para converter para octal," <<endl<<
            "'c' para coverter para hexadecimal." <<endl;

    cin >> conversao;

    switch(conversao) {
        case 'a': {
            int* restos = new int[1000];
            int i = binario(numero, restos); // Linha 6
            for(int j = 0; j < i; j++){
                cout << restos[j];
            }

            delete[] restos;
        }   
        break;

        case 'b': {
            int* restos = new int[1000];
            int i = octal(numero, restos); //Linha 28
            for(int j = 0; j < i; j++){
                cout << restos[j];
            }

            delete[] restos;
        }
            break;

        case 'c': {
            char* restos = new char[1000];
            int i = hexa(numero, restos); //Linha 51
            for(int j = 0; j < i; j++){
                cout << restos[j];
            }

            delete[] restos;
        }
            break;

        default: {
            cout << "ERRO! Voce nao digitou corretamente.";
        }
            break;
    }
    
    
return 0;
}



/* if(restos[j] == 10){
                    restos[j] = 'A';
                }
                else if(restos[j] == 11){
                    restos[j] = 'B';
                }
                else if(restos[j] == 12){
                    restos[j] = 'C';
                }
                else if(restos[j] == 13){
                    restos[j] = 'D';
                }
                else if(restos[j] == 14){
                    restos[j] = 'E';
                }
                else if(restos[j] = 15){
                    restos[j] = 'F';
                }*/