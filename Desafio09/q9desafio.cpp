#include <iostream>
#include <string>

using namespace std;
/* DESAFIO 9 */
const int TAMANHO = 100;

string voltar[TAMANHO];
string avancar[TAMANHO];

int topoVoltar = -1;
int topoAvancar = -1;

string paginaAtual = "Início";

// Visita uma nova página
void visitar(string pagina) {

    // A página atual vai para a pilha voltar
    if (topoVoltar < TAMANHO - 1) {
        topoVoltar++;
        voltar[topoVoltar] = paginaAtual;
    }

    paginaAtual = pagina;

    // Ao visitar uma nova página, limpa a pilha avançar
    topoAvancar = -1;

    cout << "Página atual: " << paginaAtual << endl;
}

// Volta para a página anterior
void voltarPagina() {

    if (topoVoltar == -1) {
        cout << "Não existe página anterior.\n";
        cout << "Página atual: " << paginaAtual << endl;
        return;
    }

    // Página atual vai para a pilha avançar
    topoAvancar++;
    avancar[topoAvancar] = paginaAtual;

    // Retira página anterior da pilha voltar
    paginaAtual = voltar[topoVoltar];
    topoVoltar--;

    cout << "Página atual: " << paginaAtual << endl;
}

// Avança para a próxima página
void avancarPagina() {

    if (topoAvancar == -1) {
        cout << "Não existe página para avançar.\n";
        cout << "Página atual: " << paginaAtual << endl;
        return;
    }

    // Página atual vai para voltar
    topoVoltar++;
    voltar[topoVoltar] = paginaAtual;

    // Recupera página da pilha avançar
    paginaAtual = avancar[topoAvancar];
    topoAvancar--;

    cout << "Página atual: " << paginaAtual << endl;
}

int main() {

    string comando;
    string pagina;

    do {
        cout << "\n===== NAVEGADOR FIREFOX - EDIÇÃO CMD =====\n";
        cout << "DÊ ENTRADA NOS COMANDOS ABAIXO PARA COMEÇAR:\n";
        cout << "VISITAR\n";
        cout << "VOLTAR\n";
        cout << "AVANCAR\n";
        cout << "SAIR\n";
        cout << "Comando: ";

        cin >> comando;

        if (comando == "VISITAR") {

            cout << "Página: ";
            cin >> pagina;

            visitar(pagina);

        } else if (comando == "VOLTAR") {

            voltarPagina();

        } else if (comando == "AVANÇAR") {

            avancarPagina();

        } else if (comando == "SAIR") {

            cout << "Navegador encerrado.\n";

        } else {

            cout << "Comando inválido.\n";
        }

    } while (comando != "SAIR");

    return 0;
}
