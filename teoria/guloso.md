* problemas de otimização sobre um conjunto de elementos (maximizar um somatório, descobrir o menor inteiro que satisfaz uma propriedade...)
* você deve fazer escolhas sobre quais elementos constituirão sua resposta
* o algoritmo guloso realiza escolhas localmente ótimas de maneira que essas se combinem em uma solução globalmente ótima
* normalmente em O(n) - pois intera sobre os elementos - ou O(nlogn)

### restaurant

um restaurante recebe N pedidos de reserva. Cada pedido ocupa o restaurante por um período contínuo de Li are Ri, por ex, das 9h às 10h. Com a restrição de que duas reservas não podem ter intersecção, qual o meior número de pedidos que podemos aceitar?

guloso -> percorrer elementos e fazer escolha de ótimo local e garante global ótima, vamos escolher como percorrer.

nesse caso, vamos percorrer ordenando os elementos

* vetor de números: ordenar de forma crescente ou decrescente
* vetor de palavras: ordenar lexxicograficamente
* vetor de pares: ordenar pela diferença (second-first), ordenar pelo priemiro/ segundo elemento, ordenar por alguma fórmula

ideias de ordenação dos intervalos

* ordenar pelo final dos intervalos -> criar uma função booleana que nos diz quando um número é "menor" que outro

        // se o final do primeiro é menor que o final do segundo

### corredor

Bruninho está programando um personagem virtual para o próximo desafio de um jogo de aventura em que, numa das fases, o personagem tem que entrar em um corredor, percorrer algumas salas e depois sair do corredor. Ele pode entrar apenas uma vez, e passar por cada sala apenas uma vez. Todas as salas possuem uma porta de entrada e uma de saída, como ilustra a parte (a) da figura abaixo. Ao passar por uma sala o jogador ganha um certo número de vidas (que pode ser negativo!). O objetivo é passar pelo corredor coletando a maior quantidade possível de vidas! Por sorte, sempre existe ao menos uma sala onde se ganha um número positivo de vidas.

- se o vetor for todo positivo, a resposta será a soma de todos elementos
- se todo vetor é negativo a resposta é o maior elemento 
- a soma máxima que termina na posição i, só depende da soma máxima da posição i-1 e do valor v[i]