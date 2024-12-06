// 1 - Planejando uma festa da empresa

/*
Problema 15-4 do CLRS (Planejando uma festa da empresa) O professor Stewart presta consultoria ao presidente de uma corporacao que esta planejando uma festa da empresa. A empresa tem uma estrutura hierarquica; isto e, a relacao de supervisores forma uma arvore com raiz no presidente. O pessoal do escritorio classificou cada funcionario com uma avaliacao de sociabilidade, que e um numero real. Para tornar a festa divertida para todos os participantes, o presidente nao deseja que um funcionario e seu supervisor imediato participem.

O professor Stewart recebe a arvore que descreve a estrutura da corporacao, usando a representacao de filho da esquerda, irmao da direita, usada para o armazenamento de arvores enraizadas (olhe na secao 10.4 se precisar). Cada no da arvore contem, alem dos ponteiros, o nome de um funcionario e a ordem de sociabilidade desse funcionario.

Escreva um algoritmo para compor uma lista de convidados que maximize a soma das avaliacoes de sociabilidade dos convidados. Analise o tempo de execucao do seu algoritmo.
*/

/* Para cada nó (funcionário), temos dois estados:

    - f(i,0) -> max soma de sociabilidade se i NÃO ir
    - f(i,1) -> max soma de sociabilidade se i IR

    f(i,0) = Σ max (f(j,0), f(j,1)), ou seja, se um funcionário não for, escolhemos a combinação de seus filhos para irem
    f(i,1) = sociabilidade(i) + Σ f(j,0)

    obs: ambos somátorios percorrem j, pertencente aos filhos de i
*/

// 2 - Cortes de tora

/*
PC 111105 (Cortes de tora) Voce deve cortar uma tora de madeira em varios pedacos. A empresa mais em conta para fazer isso e a Analog Cutting Machinery (ACM), que cobra de acordo com o comprimento da tora a ser cortada. A maquina de corte deles permite que apenas um corte seja feito por vez.

Se queremos fazer varios cortes, e facil ver que ordens diferentes destes cortes levam a precos diferentes. Por exemplo, considere uma tora com 10 metros de comprimento, que tem que ser cortada a 2, 4 e 7 metros de uma de suas extremidades. Ha varias possibilidades. Podemos primeiramente fazer o corte dos 2 metros, depois dos 4 e depois dos 7. Tal ordem custa 10 + 8 + 6 = 24, porque a primeira tora tinha comprimento 10, o que restou tinha 8 metros de comprimento e o ultimo pedaco tinha comprimento 6. Se cortassemos na ordem 4, depois 2, depois 7, pagariamos 10 + 4 + 6 = 20, que e mais barato.

Seu chefe encomendou um programa que, dado o comprimento l da tora e k pontos p1, ..., pk de corte da tora, encontre o custo minimo para executar esses cortes na ACM.
*/

/*  
    C(i, j) -> corte de menor custo para uma tora que começa em i e termina em j
    P[i] -> custo do corte da tora de um ponto i até um ponto a 

    A recorrência é dada por:
        C(i, j) = min { C(i-1, x) + C(i-1, j-x) } + (P[j] - P[i]) } , para i < a < j    
*/

// 3 - Carregamento de balsa

/*
PC 111106 (Carregamento de balsa) Balsas sao usadas para transportar carros para a outra margem de um rio ou outro trecho de agua. Considere balsas que sejam largas o suficiente para acomodar duas faixas de carros em todo o seu comprimento. Os carros entram nas faixas por um lado da balsa e saem, na outra margem, do outro lado da balsa.

A fila de carros para entrar na balsa e uma fila unica e o operador direciona cada carro para uma das duas faixas da balsa — a faixa esquerda ou a faixa direita — de modo a balancear as duas faixas da balsa. Cada carro na fila tem um comprimento diferente, que e estimado pelo operador enquanto os carros estao na fila. Baseando-se nessas estimativas, o operador decide em qual das duas faixas cada carro deve embarcar, e embarca tantos carros da fila quanto possivel.

Escreva um programa que informe o operador para qual faixa ele deve direcionar cada carro de modo a maximizar o numero de carros embarcados na balsa.
*/

/*
    L:  comprimento da balsa
    Ci: comprimento do carro i

    memo[i,l]: i é o número de carros colocados até agora e l o comprimento restante

    Para cada carro Ci temos duas possibilidades:
        - colocar na esquerda, se l >= Ci
        - colocar na direita, se o comprimento restante da direita for suficiente para acomodar Ci, ou seja:
            [L - (comprimento_total_de_carror_processados - l)] >= Ci
*/

// 4 - Programando para maximizar o lucro

/*
Problema 15-7 do CLRS (Programando para maximizar o lucro) Suponha que voce tem uma maquina e um conjunto de n trabalhos, identificados pelos numeros 1, 2, . . . , n, para processar nessa maquina. Cada trabalho j tem um tempo de processamento tj , um lucro pj e um prazo final dj . A maquina so pode processar um trabalho de cada vez, e o trabalho j deve ser executado ininterruptamente por tj unidades de tempo consecutivas. Se o trabalho j for concluido em seu prazo dj , voce recebe um lucro pj , mas, se ele for completado depois do seu prazo final, voce nao recebe nenhum lucro. Escreva um algoritmo para encontrar a ordem de execucao dos trabalho que maximiza a soma dos lucros, supondo que todos os tempos de processamento sao inteiros entre 1 e n. Qual e o tempo de execucao do seu algoritmo.
*/

/*
    memo[i,t] -> i: os primeiros i trabalhos (ordenados por prazo)
                t: o tempo total acumulado gasto até agora

    
    Assim, temos dois estados possívels:
        - NÃO fazer o trabalho i -> memo[i,t] = memo[i-1, t], pois o lucro é o mesmo que o anterior
        - FAZER o trabalho i -> memo[i, t+t(i)] = max { memo[i, t+t(i)] ,  memo[i-1, t] + p(i) } , ou seja, acumulamos o lucro 
        p(i) e atualizamos o tempo.

        obs: memo[0,0] = 0
*/

// 5 - Palitos chineses

/*
Na China, as pessoas usam pares de palitos (chopsticks) para comer, mas o Sr. L e um pouco diferente... Ele usa tres palitos: um par e mais um extra, longo, para pegar itens maiores, espetando-os. O comprimento dos dois palitos menores, normais, devem ser tao proximos quanto possivel, mas o comprimento do palito extra nao importa, desde que ele seja o mais comprido dos tres. Para um conjunto de palitos com comprimento a, b e c (a ≤ b ≤ c), a funcao (a − b)^2 mede quao ruim e o conjunto.

O Sr. L convidou k pessoas para sua festa de aniversario e ele esta ansioso para apresentar o seu jeito de usar os palitos. Ele deve preparar k+8 conjuntos de palitos (para ele, sua esposa, seu filhinho, sua filha, seus pais, seus sogros, e k outros convidados). Mas os palitos do Sr. L sao de comprimentos variados!

Escreva uma funcao que, dado k e os comprimentos de cada um dos n palitos do Sr. L, encontre um jeito de compor os k+8 conjuntos de palitos de maneira a minimizar a soma de quao ruim sao os k+8 conjuntos.
*/

/*

    dp[i,j] -> menor custo para os i primeiros palitos, de forma que atendam j convidados

    Assim, podemos incluir ou não o palito i:
        - NÃO incluir i -> dp[i,j] = dp[i-1,j]
        - INCLUIR i -> também precisamos incluir o adjacente i-1 e (j*3 <= i) para garantir que tem o terceiro palito c
            dp[i,j] = dp[i-2,j-2] + (a[i-1] - a[i])^2
        
    obs: dp[0,0] = 0
*/

// 6 - Test the Rods

/*
UVA 10086 (Test the Rods) National Construction and Project Centre (NCPC) and the Bureau of Civil Engineering Works (BCEW) have been given the authority of testing and certifying the quality of rods used in construction works in the country.

The Get and Do construction company has recently got a contract of construction at different sites of the country. Before the construction can start they want to get the rods from their n sites tested either at NCPC or at BCEW. Get and Do has got the permission of testing T1 rods at NCPC and T2 at BCEW. There are mi samples at site i (1 ≤ i ≤ n). The total sum of these samples over all the n sites is just equal to T1 + T2.

The cost of testing j items from site i at NCPC is Ci,j,1 and that of testing at BCEW is Ci,j,2.

Write a program to find a minimum cost testing schedule for the Get and Do company.
*/

/*
    dp[i,j] -> menor custo para NCPC testando i amostras e para BCEW testanto j amostras após uma quantidade de estações

    Assim:
        dp[i,j] = min { dp[i,j] , dp[i-1, j-1] + C_NCPC [i, k] + C_BCEW [i, sample[i] - k]}, de k = 0 até k = sample(i)

    obs: dp[0,0] = 0 e dp[i,j] = INF

*/
