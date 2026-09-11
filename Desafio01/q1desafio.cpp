#include <iostream>
using namespace std;

int main() {
    const int LIMITE = 100;//coloquei esse limite já que o computador que estou usando é meio fraco, para não pesar nele(não estou com o meu no momento)

    int numeros[LIMITE];
    int quantidade;
    int quantidadeTrocas = 0;
    /* DESAFIO 1 - GABRIEL F, GABRIEL O, LUIS PEDROSA*/

    cout << "       ====================================================\n" << endl;
    cout << "                      STEEL BALL RUN  RACE                 \n" << endl;
    cout << "       ====================================================" << endl;

    cout << "Árbitro, informe quantos participantes foram identificados na corrida(definindo quantos 'tempos' que queres inserir): ";
    cin >> quantidade;

    if (quantidade < 1 || quantidade > LIMITE) {
        cout << "Quantidade inválida." << endl;
        return 0;
    }

    cout << "Informe a quantidade de tempo que cada competidor levou para finalizar a 1ª etapa da corrida:" << endl;

    for (int i = 0; i < quantidade; i++) {
        cin >> numeros[i];
    }

    // Selection Sort
    for (int i = 0; i < quantidade; i++) {
        int menor = i;

        for (int j = i + 1; j < quantidade; j++) {
            if (numeros[j] < numeros[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            int temp = numeros[i];
            numeros[i] = numeros[menor];
            numeros[menor] = temp;

            quantidadeTrocas++;

            cout << "PASSO: " << quantidadeTrocas << ": ";

            for (int k = 0; k < quantidade; k++) {
                cout << numeros[k] << " ";
            }

            cout << "\n";
        }
    }

    cout << "\nQuantidade total de trocas: "
         << quantidadeTrocas << endl;

    cout << "\nLista após implementação da ordenação correta: " << endl;
    for (int i = 0; i < quantidade; i++){
        cout << numeros[i] << " ";
    }
    return 0;
}
