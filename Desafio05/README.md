DESAFIO 05
O programa verifica se uma expressão contendo (), [] e {} está corretamente balanceada utilizando uma pilha. 
Os delimitadores de abertura são empilhados e, quando aparece um delimitador de fechamento, o programa verifica se ele corresponde ao elemento no topo da pilha. 
Ao final, se todos os delimitadores estiverem corretamente fechados e a pilha estiver vazia, a expressão é considerada VALIDA; caso contrário, é INVALIDA. 
Testes realizados: () → VALIDA; ([{}]) → VALIDA; ([)] → INVALIDA; {[()]} → VALIDA; ((()) → INVALIDA; {[(])} → INVALIDA. A complexidade do algoritmo é O(n),
pois a expressão é percorrida uma vez.
