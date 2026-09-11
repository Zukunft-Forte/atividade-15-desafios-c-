#include <iostream>
#include <string>

using namespace std;
/* DESAFIO 14*/
const int TAMANHO = 100;

struct Chamada {
    int numero;
    string cliente;
};

Chamada fila[TAMANHO];

int inicio = 0;
int fim = 0;

string pilhaAcoes[TAMANHO];
int topoAcoes = -1;

Chamada chamadaAtual;
bool existeChamada = false;

int proximoNumero = 1;

// Recebe uma chamada
void receberChamada() {

    if (fim == TAMANHO) {
        cout << "Fila atualmente cheia.\n";
        return;
    }

    cout << "Nome do cliente: ";

    cin >> fila[fim].cliente;

    fila[fim].numero = proximoNumero++;

    cout << "Chamada recebida. Número: "
         << fila[fim].numero << endl;

    fim++;
}

// Atende próxima chamada
void atenderChamada() {

    if (existeChamada) {
        cout << "Finalize a chamada atual primeiro.\n";
        return;
    }

    if (inicio == fim) {
        cout << "Não existem chamadas aguardando.\n";
        return;
    }

    chamadaAtual = fila[inicio];
    inicio++;

    existeChamada = true;

    // Limpa histórico de ações
    topoAcoes = -1;

    cout << "\nAtendendo chamada "
         << chamadaAtual.numero
         << " de "
         << chamadaAtual.cliente
         << endl;
}

// Registra uma ação
void registrarAcao() {

    if (!existeChamada) {
        cout << "Não existe atendimento em andamento.\n";
        return;
    }

    if (topoAcoes == TAMANHO - 1) {
        cout << "Histórico cheio.\n";
        return;
    }

    string acao;

    cout << "Digite a ação: ";

    cin.ignore();
    getline(cin, acao);

    topoAcoes++;
    pilhaAcoes[topoAcoes] = acao;

    cout << "Ação registrada.\n";
}

// Desfaz última ação
void desfazerAcao() {

    if (!existeChamada) {
        cout << "Não existe atendimento em andamento.\n";
        return;
    }

    if (topoAcoes == -1) {
        cout << "Não existem ações para desfazer.\n";
        return;
    }

    cout << "Desfazendo: "
         << pilhaAcoes[topoAcoes]
         << endl;

    topoAcoes--;
}

// Exibe ações
void exibirAcoes() {

    if (!existeChamada) {
        cout << "Nao existe atendimento em andamento.\n";
        return;
    }

    if (topoAcoes == -1) {
        cout << "Nenhuma ação registrada.\n";
        return;
    }

    cout << "\n--- HISTÓRICO DE AÇÕES ---\n";

    for (int i = topoAcoes; i >= 0; i--) {
        cout << pilhaAcoes[i] << endl;
    }
}

// Encerra chamada
void encerrarChamada() {

    if (!existeChamada) {
        cout << "Não existe chamada em andamento!\n";
        return;
    }

    cout << "Encerrando chamada "
         << chamadaAtual.numero
         << " de "
         << chamadaAtual.cliente
         << endl;

    // Aqui limpamos o histórico de chamadas
    topoAcoes = -1;

    existeChamada = false;
}

int main() {

    int opcao;

    do {

        cout << "\n===== CENTRAL DE CHAMADAS - GREEN DOLPHIN STREET =====\n";
        cout << "1 - Receber chamada\n";
        cout << "2 - Atender chamada\n";
        cout << "3 - Registrar ação\n";
        cout << "4 - Desfazer última ação\n";
        cout << "5 - Mostrar histórico\n";
        cout << "6 - Encerrar chamada\n";
        cout << "0 - Sair\n";
        cout << "Opção: ";

        cin >> opcao;

        switch (opcao) {

            case 1:
                receberChamada();
                break;

            case 2:
                atenderChamada();
                break;

            case 3:
                registrarAcao();
                break;

            case 4:
                desfazerAcao();
                break;

            case 5:
                exibirAcoes();
                break;

            case 6:
                encerrarChamada();
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
