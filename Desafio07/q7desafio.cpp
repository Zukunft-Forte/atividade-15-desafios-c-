#include <iostream>
#include <string>
using namespace std;

struct produtos {
    int codigo;
    string nome;
    double preco;
    int quantidade;
};

int main() {
    produtos itens[] = {
        {456, "Abacate", 2.50, 20},
        {434, "Abacaxi", 5.50, 15},
        {222, "Banana", 1.50, 45},
        {789, "Biscoito", 2.65, 50},
        {143, "Molho de Tomate", 15.50, 24},
        {567, "Atum", 11.45, 43},
        {385, "Sorvete", 17.99, 10},
        {768, "Refrigerante", 10.99, 70},
        {934, "Escova", 7.55, 9},
        {035, "Lasanha", 12.99, 28},
        
    };
    int x = 10;
    cout << "Produtos Desorganizados: " << endl;
    for (const auto& item : itens) {
        cout << "O código: "  << item.codigo << "------ O produto: " << item.nome << "------ R$: " << item.preco << "------ Estoque:" << item.quantidade << endl;
    }
    cout << "-------------------------------------------------------------" << endl;
    int opcao;
    cout << "Escolha a forma de ordenar: " << endl;
    cout << "1 - Nome em ordem alfabetica" << endl;
    cout << "2 - Preço em ordem crescente" << endl;
    cout << "3 - Estoque decrescente" << endl;
    cout << "Opção: ";
    cin >> opcao;
    int comparacao = 0;
    
    for(int i = 0; i < x - 1; i++){
        for (int j = 0; j < x - 1; j++){
            bool muda = false;
            comparacao ++;
            
            switch(opcao){
                case 1: 
                if(itens[j].nome > itens[j + 1].nome) muda = true;
                break;
                case 2:
                if(itens[j].preco > itens[j + 1].preco) muda = true;
                break;
                case 3:
                if(itens[j].quantidade < itens[j + 1].quantidade) muda = true;
                break;
            };
            if (muda) {
                produtos temp = itens[j];
                itens[j] = itens[j + 1];
                itens[j + 1] = temp;
            }
        }
    }
    cout << "Produtos Organizados: " << endl;
    for (const auto& item : itens) {
        cout << "O código: "  << item.codigo << "------ O produto: " << item.nome << "------ R$: " << item.preco << "------ Estoque:" << item.quantidade << endl;
    }
    cout << "Quantidade de comparações: " << comparacao << endl;
    
    
    return 0;
}
