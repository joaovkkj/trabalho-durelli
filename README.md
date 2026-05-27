# trabalho-durelli
Conversor de Bases Numéricas

Projeto desenvolvido em C++ para realizar conversões entre diferentes bases numéricas: binário, octal, decimal e hexadecimal.

O programa também possui:

 modo passo a passo;
 conversões fracionárias;
 modo batch com arquivos `.csv`;
 quiz de conversão de bases.



Integrantes do trabalho

 João Victor - 202611322
 Guilherme Silva Saraiva - 202520178


 Linguagem utilizada

 C++

Compilador utilizado:

 g++ (MinGW)



 Funcionalidades

O programa realiza:

 Conversões inteiras

 Decimal -> Binário
 Decimal -> Octal
 Decimal -> Hexadecimal
 Binário -> Decimal
 Binário -> Octal
 Binário -> Hexadecimal
Octal -> Decimal
Octal -> Binário
Octal -> Hexadecimal
Hexadecimal -> Decimal
Hexadecimal -> Binário
Hexadecimal -> Octal


Conversões fracionárias

 Decimal fracionário -> Binário
Decimal fracionário -> Octal
Decimal fracionário -> Hexadecimal
 Binário fracionário -> Decimal
 Octal fracionário -> Decimal
 Hexadecimal fracionário -> Decimal


 Passo a passo

O usuário pode escolher se deseja visualizar:

divisões sucessivas;
 somatório posicional;
 agrupamento de bits.


Modo Batch

O programa consegue ler várias conversões automaticamente através do arquivo:

txt
entrada.csv
`

E gera automaticamente:

txt
saida.csv




 Quiz

O programa possui um quiz com:

 níveis de dificuldade;
pontuação;
conversões aleatórias.



 Como compilar

Abrir o terminal na pasta do projeto e executar:

g++ main.cpp conversor.cpp validacao.cpp passoapasso.cpp batch.cpp quiz.cpp -o programa




 Como executar

Tanto Windows quanto Linux:
no terminal, digite ./programa e dê enter


 Como usar o modo batch

Criar um arquivo chamado:


entrada.csv


Formato:


valor;base_origem;base_destino


Bases:

2 = Binário
 8 = Octal
 10 = Decimal
 16 = Hexadecimal

Exemplo:

csv
10;10;2
255;10;16
1010;2;10
17;8;10
2A;16;10


Depois de executar o programa no modo batch, será gerado:


saida.csv




 Exemplos de uso

 Exemplo 1

Entrada:


42


Conversão:

Decimal -> Binário

Saída:


101010




 Exemplo 2

Entrada:


FF


Conversão:

 Hexadecimal -> Decimal

Saída:


255



Exemplo 3

Entrada:


10,625

Conversão:

 Decimal fracionário -> Binário

Saída:


1010.101



Limitações conhecidas

 Conversões fracionárias possuem limite de precisão.
 O programa utiliza até 16 casas fracionárias.
 O modo batch aceita apenas o formato especificado no README.
 O quiz trabalha apenas com números inteiros.



 Suite de testes

    | Entrada | Conversão | Resultado Esperado |
 1 | 10 | Decimal -> Binário | 1010 |
 2 | 25 | Decimal -> Binário | 11001 |
 3 | 42 | Decimal -> Octal | 52 |
 4 | 100 | Decimal -> Octal | 144 |
 5 | 255 | Decimal -> Hexadecimal | FF |
 6 | 4095 | Decimal -> Hexadecimal | FFF |
 7 | 1010 | Binário -> Decimal | 10 |
 8 | 11111111 | Binário -> Decimal | 255 |
 9 | 17 | Octal -> Decimal | 15 |
 10 | 144 | Octal -> Decimal | 100 |
 11 | 2A | Hexadecimal -> Decimal | 42 |
 12 | FF | Hexadecimal -> Decimal | 255 |
 13 | 101011 | Binário -> Octal | 53 |
 14 | 111111111 | Binário -> Octal | 777 |
 15 | 10101111 | Binário -> Hexadecimal | AF |
 16 | 11111111 | Binário -> Hexadecimal | FF |
 17 | 52 | Octal -> Binário | 101010 |
 18 | 777 | Octal -> Binário | 111111111 |
 19 | 2F | Hexadecimal -> Binário | 00101111 |
 20 | FF | Hexadecimal -> Binário | 11111111 |
 21 | 75 | Octal -> Hexadecimal | 3D |
 22 | 377 | Octal -> Hexadecimal | FF |
 23 | 2A | Hexadecimal -> Octal | 52 |
 24 | FF | Hexadecimal -> Octal | 377 |
 25 | 10,625 | Decimal fracionário -> Binário | 1010.101 |
 26 | 15,75 | Decimal fracionário -> Octal | 17.6 |
 27 | 26,5 | Decimal fracionário -> Hexadecimal | 1A.8 |
 28 | 1010.101 | Binário fracionário -> Decimal | 10.625 |
 29 | 17.6 | Octal fracionário -> Decimal | 15.75 |
 30 | 1A.8 | Hexadecimal fracionário -> Decimal | 26.5 |

Testes inválidos

 Entrada | Base | Resultado Esperado |
 10201   | Binário | ERRO |
   89        | Octal | ERRO |
   G1        | Hexadecimal | ERRO |
 12AB      | Binário | ERRO |
 128         | Octal | ERRO |
 Z9          | Hexadecimal | ERRO |


 Observações finais

Projeto desenvolvido para praticar:

 estruturas de decisão;
 funções;
 modularização;
 manipulação de arquivos;
 strings;
 conversões entre bases numéricas em C++.
