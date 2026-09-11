#include <iostream>
#include <string>
using namespace std;

const int TAMANHO = 10;
/*Quebrei a cabeça pra fazer essa, mas foi! 
Nunca pensei que fosse simular a ação do control + z em um algoritmo.
Optei por não usar o switch case pois sempre usei ele, e provavelmente
seria mais trabalhoso.*/
string pilha[TAMANHO];
int topo = -1;

void registrarAcao(string acao) {
    if (topo == TAMANHO - 1) {
        cout << "O histórico está cheio." << endl;
    } else {
        topo++;
        pilha[topo] = acao;

        cout << "Ação registrada." << endl;
    }
}

void desfazerAcao() {
    if (topo == -1) {
        cout << "No momento, Não há ações para se desfazer." << endl;
    } else {
        cout << "Ação desfeita: " << pilha[topo] << endl;
        topo--;
    }
}

void mostrarUltimaAcao() {
    if (topo == -1) {
        cout << "Não há ações registradas." << endl;
    } else {
        cout << "Última ação: " << pilha[topo] << endl;
    }
}

void mostrarHistorico() {
    if (topo == -1) {
        cout << "O histórico está vazio." << endl;
    } else {
        cout << "\nHistórico de ações do Usuário:\n";

        for (int i = topo; i >= 0; i--) {
            cout << pilha[i] << endl;
        }
    }
}

int main() {
    int opcao;
    string acao;

    do {
        cout << "\n===== HISTÓRICO - DESAFIO 4: GABRIEL F, GABRIEL O, LUIS PEDROSA =====" << endl;
        cout << "1 - Registrar ação" << endl;
        cout << "2 - Desfazer ultima ação" << endl;
        cout << "3 - Mostrar ultima ação" << endl;
        cout << "4 - Mostrar histórico" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcão: ";
        cin >> opcao;

        if (opcao == 1) {
            cin.ignore();

            cout << "Digite a ação desejada: ";
            getline(cin, acao);

            registrarAcao(acao);
        }
        else if (opcao == 2) {
            desfazerAcao();
        }
        else if (opcao == 3) {
            mostrarUltimaAcao();
        }
        else if (opcao == 4) {
            mostrarHistorico();
        }
        else if (opcao == 0) {
            cout << "Programa encerrado." << endl;
        }
        else {
            cout << "Opcão inválida." << endl;
        }

    } while (opcao != 0);

    return 0;
}
