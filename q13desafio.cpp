#include <iostream>
#include <string>

using namespace std;
/* DESAFIO 13*/
const int TAMANHO = 100;

struct Encomenda {
    int codigo;
    string bairro;
    int prioridade;
    int horario;
};

// Verifica se uma encomenda deve vir antes da outra
bool vemAntes(Encomenda a, Encomenda b) {

    if (a.prioridade > b.prioridade) {
        return true;
    }

    if (a.prioridade < b.prioridade) {
        return false;
    }

   /* CASO DÊ EMPATE NA PRIORIDADE, VAI SE ENTREGUE PRA QUEM PEDIU PRIMEIRO*/
    return a.horario < b.horario;
}

// Selection Sort
void ordenar(Encomenda encomendas[], int tamanho) {

    for (int i = 0; i < tamanho - 1; i++) {

        int posicaoMelhor = i;

        for (int j = i + 1; j < tamanho; j++) {

            if (vemAntes(encomendas[j],
                         encomendas[posicaoMelhor])) {

                posicaoMelhor = j;
            }
        }

        if (posicaoMelhor != i) {

            Encomenda temp = encomendas[i];

            encomendas[i] =
                encomendas[posicaoMelhor];

            encomendas[posicaoMelhor] =
                temp;
        }
    }
}

// Exibe encomendas
void exibir(Encomenda encomendas[], int tamanho) {

    for (int i = 0; i < tamanho; i++) {

        cout << "Código: "
             << encomendas[i].codigo

             << "  Bairro: "
             << encomendas[i].bairro

             << "  Prioridade: "
             << encomendas[i].prioridade

             << "  Horário: "
             << encomendas[i].horario

             << endl;
    }
}

int main() {

    Encomenda encomendas[10] = {

        {101, "Boa Viagem", 2, 800},
        {102, "Ibura", 3, 730},
        {103, "Casa Forte", 1, 700},
        {104, "Várzea", 3, 800},
        {105, "Imbiribeira", 2, 745},
        {106, "Recife", 3, 750},
        {107, "Jaboatão", 1, 650},
        {108, "Pina", 2, 815},
        {109, "Madalena", 3, 820},
        {110, "Torre", 1, 900}
    };

    int tamanho = 10;

    cout << "=== ANTES DA ORGANIZAÇÃO ===\n";
    exibir(encomendas, tamanho);

    ordenar(encomendas, tamanho);

    cout << "\n=== ORDEM DE ENTREGA ===\n";
    exibir(encomendas, tamanho);

    cout << "\n=== PROCESSAMENTO ===\n";

    // Depois da ordenação, a ordem do array
    // representa a fila de entrega.

    for (int i = 0; i < tamanho; i++) {

        cout << "Processando encomenda..Aguarde.. "
             << encomendas[i].codigo
             << " - "
             << encomendas[i].bairro
             << endl;
    }

    return 0;
}