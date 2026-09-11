#include <iostream>
#include <string>
using namespace std;

const int TAMANHO = 100;
/* DESAFIO 06 - GABRIEL F, GABRIEL O, LUIS PEDROSA
*/
int main() {
    char pilha[TAMANHO];
    int topo = -1;

    string expressao;
    bool valida = true;

    cout << "Digite uma expressão: ";
    getline(cin, expressao);

    for (int i = 0; i < expressao.length(); i++) {

        if (expressao[i] == '(' ||
            expressao[i] == '[' ||
            expressao[i] == '{') {

            topo++;
            pilha[topo] = expressao[i];
        }

        else if (expressao[i] == ')' ||
                 expressao[i] == ']' ||
                 expressao[i] == '}') {

            if (topo == -1) {
                valida = false;
                break;
            }

            if (expressao[i] == ')' && pilha[topo] != '(') {
                valida = false;
                break;
            }

            if (expressao[i] == ']' && pilha[topo] != '[') {
                valida = false;
                break;
            }

            if (expressao[i] == '}' && pilha[topo] != '{') {
                valida = false;
                break;
            }

            topo--;
        }
    }

    if (topo != -1) {
        valida = false;
    }

    if (valida) {
        cout << "A expressão está válida!" << endl;
    } else {
        cout << "A expressão está inválida! Olhe direito o que você escreveu!" << endl;
    }

    return 0;
}