#include <iostream>
#include <string>

using namespace std;
/* DESAFIO 15 - Que questão trabalhosa, essa levou tempo*/
const int TAMANHO = 100;

struct Tarefa {
    int id;
    string titulo;
    int prioridade;
    int estimativa;
};

/* FILA*/
Tarefa fila[TAMANHO];

int inicioFila = 0;
int fimFila = 0;

/* PILHA */

Tarefa concluidas[TAMANHO];

int topoConcluidas = -1;

/*FILA */

bool filaVazia() {
    return inicioFila == fimFila;
}

bool filaCheia() {
    return fimFila == TAMANHO;
}

// Adiciona tarefa na fila
void adicionarTarefa(Tarefa tarefa) {

    if (filaCheia()) {
        cout << "Fila cheia.\n";
        return;
    }

    fila[fimFila] = tarefa;
    fimFila++;

    cout << "Tarefa adicionada!\n";
}

// Mostra tarefas aguardando
void mostrarFila() {

    if (filaVazia()) {
        cout << "Nenhuma tarefa aguardando.\n";
        return;
    }

    cout << "\n--- TAREFAS AGUARDANDO ---\n";

    for (int i = inicioFila; i < fimFila; i++) {

        cout << "Verificação ID: " << fila[i].id
             << "  Titulo: " << fila[i].titulo
             << "  Prioridade: " << fila[i].prioridade
             << "  Estimativa: " << fila[i].estimativa
             << " minutos\n";
    }
}

// Executa primeira tarefa
void executarTarefa() {

    if (filaVazia()) {
        cout << "Não existem tarefas aguardando.\n";
        return;
    }

    if (topoConcluidas == TAMANHO - 1) {
        cout << "Pilha de concluídas cheia.\n";
        return;
    }

    Tarefa tarefa = fila[inicioFila];

    inicioFila++;

    // aqui eu implemento na pilha de concluídas
    topoConcluidas++;
    concluidas[topoConcluidas] = tarefa;

    cout << "\nTarefa concluída:\n";
    cout << "Verificação ID: " << tarefa.id << endl;
    cout << "Titulo: " << tarefa.titulo << endl;
}

/* PILHA,

MOSTRANDO AS TAREFAS CONCLUÍDAS */
void mostrarConcluidas() {

    if (topoConcluidas == -1) {
        cout << "Nenhuma tarefa concluída.\n";
        return;
    }

    cout << "\n--- TAREFAS CONCLUÍDAS ---\n";

    for (int i = topoConcluidas; i >= 0; i--) {

        cout << "VERIFICAÇÃO ID: "
             << concluidas[i].id

             << "  Titulo: "
             << concluidas[i].titulo

             << "  Prioridade: "
             << concluidas[i].prioridade

             << "  Estimativa: "
             << concluidas[i].estimativa
             << " minutos\n";
    }
}

// Desfaz última conclusão
void desfazerConclusao() {

    if (topoConcluidas == -1) {
        cout << "Não existem conclusões a serem desfeitas.\n";
        return;
    }

    if (filaCheia()) {
        cout << "Fila cheia. Não foi possível devolver a tarefa.\n";
        return;
    }

    Tarefa tarefa = concluidas[topoConcluidas];

    topoConcluidas--;

    // Devolve para a fila
    fila[fimFila] = tarefa;
    fimFila++;

    cout << "Conclusão desfeita.\n";
    cout << "Tarefa devolvida para a fila: "
         << tarefa.titulo << endl;
}

// ==============================
// ORDENAÇÃO
// ==============================

// Ordena por prioridade
void ordenarPrioridade(Tarefa vetor[], int tamanho) {

    for (int i = 0; i < tamanho - 1; i++) {

        int melhor = i;

        for (int j = i + 1; j < tamanho; j++) {

            if (vetor[j].prioridade >
                vetor[melhor].prioridade) {

                melhor = j;
            }
        }

        if (melhor != i) {

            Tarefa temp = vetor[i];

            vetor[i] = vetor[melhor];

            vetor[melhor] = temp;
        }
    }
}

// Ordena por estimativa
void ordenarEstimativa(Tarefa vetor[], int tamanho) {

    for (int i = 0; i < tamanho - 1; i++) {

        int menor = i;

        for (int j = i + 1; j < tamanho; j++) {

            if (vetor[j].estimativa <
                vetor[menor].estimativa) {

                menor = j;
            }
        }

        if (menor != i) {

            Tarefa temp = vetor[i];

            vetor[i] = vetor[menor];

            vetor[menor] = temp;
        }
    }
}

// Relatório
void gerarRelatorio() {

    int quantidade = fimFila - inicioFila;

    if (quantidade == 0) {
        cout << "Não existem tarefas aguardando.\n";
        return;
    }

    Tarefa copia[TAMANHO];

    // Copia apenas as tarefas que ainda aguardam
    for (int i = 0; i < quantidade; i++) {
        copia[i] = fila[inicioFila + i];
    }

    int opcao;

    cout << "\n=== RELATÓRIO ===\n";
    cout << "1 - Ordenar por prioridade\n";
    cout << "2 - Ordenar por estimativa\n";
    cout << "Opção desejada: ";
    cin >> opcao;

    if (opcao == 1) {

        ordenarPrioridade(copia, quantidade);

    } else if (opcao == 2) {

        ordenarEstimativa(copia, quantidade);

    } else {

        cout << "Opção inválida.\n";
        return;
    }

    cout << "\n--- RELATÓRIO ORDENADO ---\n";

    for (int i = 0; i < quantidade; i++) {

        cout << "VERIFICAÇÃO ID: " << copia[i].id
             << "  Título: " << copia[i].titulo
             << "  Prioridade: " << copia[i].prioridade
             << "  Estimativa: "
             << copia[i].estimativa
             << " minutos\n";
    }

    cout << "\nAs estruturas originais foram preservadas.\n";
}

/* DADOS DE DEMONSTRAÇÃO ABAIXO.*/

void inserirDadosDemo() {

    Tarefa tarefas[8] = {

        {1, "Corrigir login", 5, 60},
        {2, "Criar tela inicial", 3, 120},
        {3, "Corrigir banco", 5, 45},
        {4, "Criar cadastro", 4, 90},
        {5, "Testar API", 2, 30},
        {6, "Criar menu", 3, 50},
        {7, "Corrigir CSS", 1, 20},
        {8, "Documentar sistema", 2, 70}
    };

    for (int i = 0; i < 8; i++) {
        adicionarTarefa(tarefas[i]);
    }

    cout << "Dados de demonstração inseridos com sucesso.\n";
}

/* função principal abaixo*/

int main() {

    int opcao;

    do {

        cout << "\n================================\n";
        cout << "   ARENA INTEGRADA  - TAREFAS\n";
        cout << "================================\n";

        cout << "1 - Adicionar tarefa\n";
        cout << "2 - Mostrar fila\n";
        cout << "3 - Executar tarefa\n";
        cout << "4 - Mostrar concluídas\n";
        cout << "5 - Desfazer última conclusão\n";
        cout << "6 - Gerar relatorio\n";
        cout << "7 - Inserir dados de demonstração\n";
        cout << "0 - Sair\n";

        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {

            case 1: {

                Tarefa tarefa;

                cout << "VERIFICAÇÃO ID: ";
                cin >> tarefa.id;

                cout << "Titulo: ";
                cin >> tarefa.titulo;

                cout << "Prioridade: ";
                cin >> tarefa.prioridade;

                cout << "Estimativa em minutos: ";
                cin >> tarefa.estimativa;

                adicionarTarefa(tarefa);

                break;
            }

            case 2:

                mostrarFila();

                break;

            case 3:

                executarTarefa();

                break;

            case 4:

                mostrarConcluidas();

                break;

            case 5:

                desfazerConclusao();

                break;

            case 6:

                gerarRelatorio();

                break;

            case 7:

                inserirDadosDemo();

                break;

            case 0:

                cout << "Encerrando sistema...\n";

                break;

            default:

                cout << "Opção inválida.\n";
        }

    } while (opcao != 0);

    return 0;
}
