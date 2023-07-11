# Motoboy 1286

Joseph é um motociclista que trabalha fazendo entregas para uma pizzaria. Seu salário é baseado no número de pizzas entregues. Como essa pizzaria está crescendo ele pediu ao amigo Roberto que o ajudasse nas entregas. Como Roberto não está trabalhando no momento, ele aceita receber os piores pedidos (cujas entregas serão mais demoradas).

Assim, sempre que eles chegam à pizzaria antes de partir para novas entregas, José determina a quantidade de pizzas que Roberto deve entregar e seleciona aquela que terá mais tempo. Por exemplo, se houver 22 pizzas a serem entregues e José determinar que no máximo 10 dessas pizzas (pode ser menos) seriam entregues por Roberto, essas obrigatoriamente devem estar entre os pedidos que demoram mais para serem entregues. Isso é ilustrado no primeiro caso de teste, onde Roberto entregará o segundo, terceiro e sexto pedido, totalizando 8 pizzas e 62 minutos (23 + 21 + 18). Se Roberto fosse realmente entregar 10 pizzas, ele teria que entregar o segundo, terceiro e quarto pedido e levaria 59 minutos (23 + 21 + 16), o que não é o objetivo de José, pois neste caso seriam entregues mais pizzas em um tempo mais curto.

Para fazer a divisão desse trabalho, Joseph pediu a um amigo acadêmico de informática que desenvolvesse um programa que determinasse quanto tempo seu amigo Roberto levaria para entregar essas piores entregas (em tempo demorado).

##  Entrada 
A entrada contém muitos casos de teste. Cada caso de teste contém na primeira linha um número inteiro N (1 ≤ N ≤ 20) que indica o número de pedidos. A linha a seguir contém um número inteiro P (1 ≤ P ≤ 30) que indica o número máximo de pizzas que podem ser entregues por Roberto. Cada uma das próximas N linhas contém um pedido com o tempo total a ser entregue e a quantidade de pizzas desse pedido, respectivamente. O fim da entrada é representado por N = 0 e não pode ser processado.

## Saida 

Para cada caso de teste, a entrada deve ser impressa como um número inteiro que determina o tempo gasto por Roberto para entregar as pizzas seguido de um espaço e o texto "min.", conforme os exemplos dados.


![sample](/motoboy/m1.png)