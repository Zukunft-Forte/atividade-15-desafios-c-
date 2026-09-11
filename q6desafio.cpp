#include <iostream>
#include <string>
#include <iomanip> //com essa biblioteca, consigo manipular as casas decimais!

using namespace std;
/* DESAFIO 06 - GABRIEL F, GABRIEL O, LUIS PEDROSA*/
struct Paciente {
    string nome;
    float prioridade;
    int idade;
};

int main() {
    Paciente pacientes[8] = {
        {"No aguardo: Ana", 1.0, 22},
        {"No aguardo: Bruno", 2.0, 68},
        {"No aguardo: Carlos", 1.0, 18},
        {"Entrada: Dona Deia", 3.0, 999},
        {"Eduarda", 1.0, 18},
        {"Próximo atendimento: Ferdinando Fernando Fernandes", 3.0, 90},
        {"No aguardo: Gabriel", 1.0, 18},
        {"No Aguardo:Helena", 1.0, 32}
    };

    // Implementando o Insertion Sort da maior nota para a menor
    for (int i = 1; i < 8; i++) {
        Paciente pacientesAtual = pacientes[i];
        int j = i - 1;

        while (j >= 0 && pacientes[j].prioridade < pacientesAtual.prioridade) {
            pacientes[j + 1] = pacientes[j];
            j--;
        }

        pacientes[j + 1] = pacientesAtual;
    }

    cout << fixed << setprecision(1); /* essa lista de exercícios está sendo muito boa pois 
    estou aprendendo muitas coisas novas sobre c++. Como esse fixed setprecision(1), que
    descobri que funciona como o .%2f para casas decimais/pontos flutuantes.*/

    cout << "================================\n" << endl;
    cout << "     CLÍNICA KUROSAKI\n" << endl;
    cout << "================================\n" << endl;

    cout << "Fila de atendimento do dia: :\n";

    for (int i = 0; i < 8; i++) {
        cout << i + 1 << " - "
             << pacientes[i].nome
             << " | Prioridade: " << pacientes[i].prioridade << endl;
    }

    return 0;
}