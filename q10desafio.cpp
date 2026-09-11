#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
/* DESAFIO 10
fiz um algoritmo que gera números aleatórios, como os indicados na questão pelo prof Alex,
analisando movimentações e mostrando as comparações.
*/
struct Resultado {
    long long comparacoes;
    long long movimentacoes;
    double tempo;
};

// Selection Sort
Resultado selectionSort(int vetor[], int tamanho) {

    long long comparacoes = 0;
    long long movimentacoes = 0;

    auto inicio = chrono::high_resolution_clock::now();

    for (int i = 0; i < tamanho - 1; i++) {

        int menor = i;

        for (int j = i + 1; j < tamanho; j++) {

            comparacoes++;

            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        if (menor != i) {

            int temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;

            movimentacoes += 3;
        }
    }

    auto fim = chrono::high_resolution_clock::now();

    double tempo =
        chrono::duration<double, milli>(fim - inicio).count();

    Resultado resultado;

    resultado.comparacoes = comparacoes;
    resultado.movimentacoes = movimentacoes;
    resultado.tempo = tempo;

    return resultado;
}

// Insertion Sort
Resultado insertionSort(int vetor[], int tamanho) {

    long long comparacoes = 0;
    long long movimentacoes = 0;

    auto inicio = chrono::high_resolution_clock::now();

    for (int i = 1; i < tamanho; i++) {

        int chave = vetor[i];
        movimentacoes++;

        int j = i - 1;

        while (j >= 0) {

            comparacoes++;

            if (vetor[j] > chave) {

                vetor[j + 1] = vetor[j];
                movimentacoes++;

                j--;

            } else {
                break;
            }
        }

        vetor[j + 1] = chave;
        movimentacoes++;
    }

    auto fim = chrono::high_resolution_clock::now();

    double tempo =
        chrono::duration<double, milli>(fim - inicio).count();

    Resultado resultado;

    resultado.comparacoes = comparacoes;
    resultado.movimentacoes = movimentacoes;
    resultado.tempo = tempo;

    return resultado;
}

// É aqui que eu desenrolo a função pra que sejam gerado números aleatórios
void gerarVetor(int vetor[], int tamanho) {

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100000;
    }
}

// Aqui copiei o vetor
void copiarVetor(int origem[], int destino[], int tamanho) {

    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

int main() {

    srand(time(NULL));

    int tamanhos[] = {100, 1000, 10000};

    for (int t = 0; t < 3; t++) {

        int tamanho = tamanhos[t];

        int original[10000];
        int vetorSelection[10000];
        int vetorInsertion[10000];

        gerarVetor(original, tamanho);

        copiarVetor(original, vetorSelection, tamanho);
        copiarVetor(original, vetorInsertion, tamanho);

        cout << "\n====================================\n";
        cout << "TAMANHO: " << tamanho << endl;
        cout << "====================================\n";

        Resultado selection =
            selectionSort(vetorSelection, tamanho);

        Resultado insertion =
            insertionSort(vetorInsertion, tamanho);

        cout << "\nSELECTION SORT\n";
        cout << "Comparaçõess: "
             << selection.comparacoes << endl;

        cout << "Movimentações: "
             << selection.movimentacoes << endl;

        cout << "Tempo: "
             << selection.tempo << " ms\n";

        cout << "\nINSERTION SORT\n";
        cout << "Comparações: "
             << insertion.comparacoes << endl;

        cout << "Movimentações: "
             << insertion.movimentacoes << endl;

        cout << "Tempo: "
             << insertion.tempo << " ms\n";
    }

    return 0;
}