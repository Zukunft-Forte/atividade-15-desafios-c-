#include <iostream>
#include <sstream>
#include <string>

using namespace std;
/* DESAFIO 12 - CALCULADORA PÓS-FIXA(aleatória dms)*/
const int TAMANHO = 100;

int pilha[TAMANHO];
int topo = -1;

// Vendo se deu alguma bronca e está vazia
bool estaVazia() {
    return topo == -1;
}

// Vendo se está cheia
bool estaCheia() {
    return topo == TAMANHO - 1;
}

// Empilhando
bool empilhar(int valor) {

    if (estaCheia()) {
        return false;
    }

    topo++;
    pilha[topo] = valor;

    return true;
}

// Desempilhando
bool desempilhar(int &valor) {

    if (estaVazia()) {
        return false;
    }

    valor = pilha[topo];
    topo--;

    return true;
}

// Vendo se um token é operador
bool ehOperador(string token) {

    return token == "+" ||
           token == "-" ||
           token == "*" ||
           token == "/";
}

int main() {

    string expressao;

    cout << "Digite a expressão pos-fixa:\n";
    getline(cin, expressao);

    stringstream ss(expressao);

    string token;

    bool erro = false;

    while (ss >> token) {

        // Se for operador
        if (ehOperador(token)) {

            int a, b;

            // Precisamos de dois operandos
            if (!desempilhar(a) ||
                !desempilhar(b)) {

                cout << "Erro: expressão inválida!\n";
                erro = true;
                break;
            }

            int resultado;

            if (token == "+") {
                resultado = b + a;

            } else if (token == "-") {
                resultado = b - a;

            } else if (token == "*") {
                resultado = b * a;

            } else {

                if (a == 0) {
                    cout << "Erro: divisão por zero.\n";
                    erro = true;
                    break;
                }

                resultado = b / a;
            }

            empilhar(resultado);

        } else {

            // Tenta transformar o token em inteiro
            stringstream conversao(token);

            int numero;

            if (!(conversao >> numero)) {

                cout << "Erro: valor inválido: "
                     << token << endl;

                erro = true;
                break;
            }

            empilhar(numero);
        }
    }

    // Uma expressão correta precisa deixar
    // exatamente um resultado na pilha.

    if (!erro) {

        if (topo != 0) {

            cout << "Erro: expressão inválida.\n";

        } else {

            cout << "Resultado: "
                 << pilha[topo] << endl;
        }
    }

    return 0;
}