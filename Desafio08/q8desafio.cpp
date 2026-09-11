#include <iostream>
#include <string>

using namespace std;
/* DESAFIO 8*/
const int TAMANHO = 100;

struct Trabalho {
    string usuario;
    int paginas;
    string arquivo;
};

Trabalho fila[TAMANHO];

int inicio = 0;
int fim = 0;

// Verifica se a fila está vazia
bool estaVazia() {
    return inicio == fim;
}

// Verifica se a fila está cheia
bool estaCheia() {
    return fim == TAMANHO;
}

// Adiciona um trabalho no final da fila
void adicionarTrabalho() {
    if (estaCheia()) {
        cout << "Fila cheia!\n";
        return;
    }

    cout << "Usuário: ";
    cin >> fila[fim].usuario;

    cout << "Número de páginas: ";
    cin >> fila[fim].paginas;

    cout << "Nome do arquivo: ";
    cin >> fila[fim].arquivo;

    fim++;

    cout << "Trabalho adicionado com sucesso!\n";
}

// Imprime o primeiro trabalho da fila
void imprimirTrabalho() {
    if (estaVazia()) {
        cout << "Não há trabalhos na fila.\n";
        return;
    }

    cout << "\nImprimindo:\n";
    cout << "Usuário: " << fila[inicio].usuario << endl;
    cout << "Arquivo: " << fila[inicio].arquivo << endl;
    cout << "Páginas: " << fila[inicio].paginas << endl;

    inicio++;
}

// Calcula quantas paginas ainda aguardam
void paginasAguardando() {
    int total = 0;

    for (int i = inicio; i < fim; i++) {
        total += fila[i].paginas;
    }

    cout << "Páginas aguardando: " << total << endl;
}

// Cancela um trabalho pelo nome do arquivo
void cancelarTrabalho() {
    if (estaVazia()) {
        cout << "Fila vazia.\n";
        return;
    }

    string nomeArquivo;

    cout << "Digite o nome do arquivo para cancelar: ";
    cin >> nomeArquivo;

    int posicao = -1;

    // Procura o arquivo
    for (int i = inicio; i < fim; i++) {
        if (fila[i].arquivo == nomeArquivo) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        cout << "Arquivo não encontrado.\n";
        return;
    }

    // Desloca os trabalhos seguintes uma posição para trás
    for (int i = posicao; i < fim - 1; i++) {
        fila[i] = fila[i + 1];
    }

    fim--;

    cout << "Trabalho cancelado.\n";
}

// Exibe todos os trabalhos
void exibirFila() {
    if (estaVazia()) {
        cout << "Fila vazia.\n";
        return;
    }

    cout << "\n--- FILA DE IMPRESSÃO ---\n";

    for (int i = inicio; i < fim; i++) {
        cout << "Arquivo: " << fila[i].arquivo
             << "  Usuário: " << fila[i].usuario
             << "  Páginas: " << fila[i].paginas << endl;
    }
}

int main() {
    int opcao;

    do {
        cout << "\n===== IMPRESSORA VIRTUAL - DESAFIO 8  =====\n";
        cout << "1 - Adicionar trabalho\n";
        cout << "2 - Imprimir trabalho\n";
        cout << "3 - Paginas aguardando\n";
        cout << "4 - Cancelar trabalho\n";
        cout << "5 - Exibir fila\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarTrabalho();
                break;

            case 2:
                imprimirTrabalho();
                break;

            case 3:
                paginasAguardando();
                break;

            case 4:
                cancelarTrabalho();
                break;

            case 5:
                exibirFila();
                break;

            case 0:
                cout << "Programa encerrado.\n";
                break;

            default:
                cout << "Opção inválida.\n";
        }

    } while (opcao != 0);

    return 0;
}
