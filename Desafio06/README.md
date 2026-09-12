DESAFIO 06

O programa simula uma fila de pacientes, armazenando nome, idade e prioridade de 1 a 3. A prioridade 3 é atendida primeiro, seguida pela 2 e depois pela 1. 
Quando dois pacientes possuem a mesma prioridade, é respeitada a ordem de chegada, mantendo o princípio FIFO dentro de cada nível, tudo conforme solicitado do Prof. Alex.
O sistema permite cadastrar pacientes, realizar o próximo atendimento e listar os pacientes que ainda aguardam.
A política de prioridade foi implementada utilizando filas separadas para cada nível, verificando primeiro a fila de prioridade 3, depois a 2 e, por último, a 1. 
As operações de entrada e atendimento possuem complexidade O(1), enquanto a listagem possui complexidade O(n).
