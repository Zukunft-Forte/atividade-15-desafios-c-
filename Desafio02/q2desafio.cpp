#include <iostream>
#include <string>
using namespace std;
/* DESAFIO 2 - jogadores com nome de bleach*/
struct jogo{
    string nome;
    int pont;
};

int main()
{
    jogo participantes[] ={
        {"Ichigo",89},
        {"Ishida",91},
        {"Chad",89},
        {"Orihime",90},
        {"Rukia",88},
        {"Renji",65},
        {"Shunsui",115},
        {"Shinji",76},
        {"Aizen",199},
        {"Urahara",200},
    };
    int quantidade = 10;
    cout << "Resultado Atual: " << endl;
    for (int i = 0; i < quantidade;i++){
        cout << "O "<< i + 1 <<"º partcipante: " << participantes[i].nome << endl << " PONTOS: " <<  participantes[i].pont << endl; 
    }
    cout << "--------------------------------------------------" << endl;
    
    for (int i = 1; i < quantidade; i++){
        jogo atual = participantes[i];
        int j = i - 1;
        
        while (j >= 0 && participantes[j].pont < atual.pont){
            participantes[j + 1] = participantes[j];
            j--;
        }
        participantes[j + 1] = atual;
    }
    cout << "Resultado ordenado: " << endl;
    for (int i = 0; i < quantidade;i++){
        cout << "O "<< i + 1 <<"º LUGAR: " << participantes[i].nome << endl << " PONTOS: " <<  participantes[i].pont << endl; 
    }
    return 0;
}
