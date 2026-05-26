#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <string>

using namespace std;
// ##############################
//TROCAR VIRGULA POR PONTO
// ##############################

string trocarVirgula(string num);

// ##############################
// DECIMAL -> OUTRAS BASES
// ##############################

string decimalParaBinario(int num);

string decimalParaOctal(int num);

string decimalParaHexa(int num);


// ##############################
// OUTRAS BASES -> DECIMAL
// ##############################

int binarioParaDecimal(string bin);

int octalParaDecimal(string oct);

int hexaParaDecimal(string hex);


// ##############################
// CONVERSOES DIRETAS
// ##############################

string binarioParaOctal(string bin);

string binarioParaHexa(string bin);

string octalParaBinario(string oct);

string hexaParaBinario(string hex);

string octalParaHexa(string oct);

string hexaParaOctal(string hex);


// ##############################
// FRACIONARIOS
// ##############################

string decimalFracionarioParaBinario(double num);

string decimalFracionarioParaOctal(double num);

string decimalFracionarioParaHexa(double num);

double binarioFracionarioParaDecimal(string bin);

double octalFracionarioParaDecimal(string oct);

double hexaFracionarioParaDecimal(string hex);

#endif