#include <iostream>
#include <queue>
#include <string>
using namespace std;
/* DESAFIO 3*/
struct Cliente {
    string nome;
    string pedido;
};

void listarFila(queue<Cliente> fila) {
    if (fila.empty()) {
        cout << "A fila está vazia." << endl;
        return;
    }

    cout << "\n===== FILA DO CAFÉZINHO =====\n";

    int posicao = 1;

    while (!fila.empty()) {
        cout << posicao << " - "
             << fila.front().nome
             << "  Pedido: "
             << fila.front().pedido
             << endl;

        fila.pop();
        posicao++;
    }
}

int main() {
    queue<Cliente> fila;

    int opcao;

    do {
        cout << "\n===== FILA DO CAFÉZINHO =====\n";
        cout << "1 - Entrar na fila\n";
        cout << "2 - Atender cliente\n";
        cout << "3 - Listar fila\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        if (opcao == 1) {
            Cliente cliente;

            cout << "Nome: ";
            cin >> cliente.nome;

            cout << "Pedido: ";
            cin >> cliente.pedido;

            fila.push(cliente);

            cout << "Cliente entrou na fila." << endl;
        }

        else if (opcao == 2) {
            if (fila.empty()) {
                cout << "Não há clientes na fila." << endl;
            }
            else {
                cout << "Atendendo: "
                     << fila.front().nome
                     << "  Pedido: "
                     << fila.front().pedido
                     << endl;

                fila.pop();
            }
        }

        else if (opcao == 3) {
            listarFila(fila);
        }

    } while (opcao != 0);

    return 0;