#include <iostream>
#include <string>

using namespace std;

const int TAMANHO = 100;

struct Cliente {
    int senha;
    string nome;
    bool prioritario;
};

Cliente filaNormal[TAMANHO];
Cliente filaPrioritaria[TAMANHO];

int inicioNormal = 0;
int fimNormal = 0;

int inicioPrioritaria = 0;
int fimPrioritaria = 0;

int senhaAtual = 1;

int preferenciasAtendidas = 0;

// Adiciona cliente
void adicionarCliente() {

    Cliente cliente;

    cliente.senha = senhaAtual++;

    cout << "Nome: ";
    cin >> cliente.nome;

    int tipo;

    cout << "1 - Normal\n";
    cout << "2 - Prioritario\n";
    cout << "Tipo: ";
    cin >> tipo;

    cliente.prioritario = (tipo == 2);

    if (cliente.prioritario) {

        filaPrioritaria[fimPrioritaria] = cliente;
        fimPrioritaria++;

    } else {

        filaNormal[fimNormal] = cliente;
        fimNormal++;
    }

    cout << "Cliente recebido. Senha: "
         << cliente.senha << endl;
}

// Atende cliente
void atenderCliente() {

    bool temNormal = inicioNormal < fimNormal;
    bool temPrioritario = inicioPrioritaria < fimPrioritaria;

    if (!temNormal && !temPrioritario) {
        cout << "Não existem clientes aguardando.\n";
        return;
    }

    Cliente cliente;

    /*
       Lembrando que, caso atendamos 2 clientes prioritários,
       devemos tentar atender um normal, pelo que entendi.
    */

    if (temNormal && temPrioritario &&
        preferenciasAtendidas >= 2) {

        cliente = filaNormal[inicioNormal];
        inicioNormal++;

        preferenciasAtendidas = 0;

    } else if (temPrioritario) {

        cliente = filaPrioritaria[inicioPrioritaria];
        inicioPrioritaria++;

        preferenciasAtendidas++;

    } else {

        cliente = filaNormal[inicioNormal];
        inicioNormal++;

        preferenciasAtendidas = 0;
    }

    cout << "\nATENDENDO CLIENTE\n";
    cout << "Senha: " << cliente.senha << endl;
    cout << "Nome: " << cliente.nome << endl;

    if (cliente.prioritario) {
        cout << "Tipo: PRIORITÁRIO\n";
    } else {
        cout << "Tipo: NORMAL\n";
    }
}

// Exibe filas
void exibirFilas() {

    cout << "\n--- FILA PRIORITÁRIA ---\n";

    for (int i = inicioPrioritaria; i < fimPrioritaria; i++) {
        cout << "Senha: "
             << filaPrioritaria[i].senha
             << " - "
             << filaPrioritaria[i].nome
             << endl;
    }

    cout << "\n--- FILA NORMAL ---\n";

    for (int i = inicioNormal; i < fimNormal; i++) {
        cout << "Senha: "
             << filaNormal[i].senha
             << " - "
             << filaNormal[i].nome
             << endl;
    }
}

int main() {

    int opcao;

    do {

        cout << "\n===== CENTRAL DE ATENDIMENTO CLÍNICA KUROSAKI =====\n";
        cout << "1 - Receber cliente\n";
        cout << "2 - Atender cliente\n";
        cout << "3 - Exibir filas\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {

            case 1:
                adicionarCliente();
                break;

            case 2:
                atenderCliente();
                break;

            case 3:
                exibirFilas();
                break;

            case 0:
                cout << "Turno Finalizado! Encerrando atividades...\n";
                break;

            default:
                cout << "Opção inválida.\n";
        }

    } while (opcao != 0);

    return 0;
}
