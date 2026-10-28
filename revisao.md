Lista de exercícios — Estruturas de Dados

1. Ponteiros e alocação dinâmica
Exercícios 1–6 · Fundamentos
Revisar endereços de memória, referências, new, delete, passagem por referência e ponteiros para estruturas.




2. Pilhas e filas
Exercícios 7–12 · Estruturas lineares
Implementar operações, controlar início e fim e compreender as diferenças entre LIFO e FIFO.




3. Listas encadeadas
Exercícios 13–18 · Manipulação de nós
Inserção, remoção, busca, inversão e tratamento de listas vazias e de um único elemento.




4. Árvores ABB e AVL
Exercícios 19–26 · Árvores e balanceamento
Recursão, percursos, altura, fator de balanceamento, rotações e remoção.



Parte 1 — Ponteiros
Objetivo: conseguir prever exatamente o que acontece com os endereços e os valores armazenados na memória.
Exercício 1 — Rastreamento de ponteiros
Sem executar o código, determine o valor de a, b e c ao final.
int a = 10;
int b = 20;

int *p = &a;
int *q = &b;

*p = 15;
q = p;
*q = 30;

b = 50;


Responda também: p e q apontam para a mesma variável? O que aconteceu com o valor original de a?
Exercício 2 — Ponteiro para ponteiro
Determine os valores finais de x e y e explique cada alteração.
int x = 5;
int y = 10;

int *p = &x;
int **q = &p;

**q = 20;
*q = &y;
**q = 30;


Exercício 3 — Troca por referência
Implemente:
void trocar(int *a, int *b);


A função deve trocar os valores das variáveis apontadas por a e b, sem retornar nada.
Teste com duas variáveis inteiras.
Exercício 4 — Alocação dinâmica
Implemente uma função que:
1. Aloque dinamicamente um vetor de n inteiros.
2. Preencha o vetor com os valores de entrada.
3. Retorne o ponteiro para o vetor.
4. Libere a memória no momento apropriado.
Explique a diferença entre:
int *p = new int(10);


e
int *p = new int[10];


Exercício 5 — Ponteiro em função
Implemente uma função que receba um ponteiro para inteiro e altere o valor apontado para o dobro.
Depois, responda: qual é a diferença entre receber int *p e receber int &x?
Exercício 6 — Criando um nó
Considere:
typedef struct No {
    int valor;
    struct No *prox;
} No;


Implemente uma função que aloque um nó, atribua um valor recebido como parâmetro e inicialize prox corretamente.
Depois, crie dois nós e conecte-os.

Parte 2 — Pilhas e filas
Aqui, pratique implementações com nós encadeados, sem utilizar std::stack, std::queue ou contêineres prontos.
Exercício 7 — Pilha com lista encadeada
Implemente a estrutura:
typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct Pilha {
    No *topo;
} Pilha;


Implemente as funções:
- inicializar
- empilhar
- desempilhar
- consultarTopo
- estaVazia
- liberar
Trate corretamente a tentativa de desempilhar uma pilha vazia.
Exercício 8 — Rastreamento de uma pilha
Uma pilha começa vazia. Execute mentalmente as operações:
1. Empilhar 10.
2. Empilhar 20.
3. Empilhar 30.
4. Desempilhar.
5. Empilhar 40.
6. Desempilhar.
7. Consultar o topo.
Desenhe a pilha após cada operação e informe o estado final.
Exercício 9 — Fila encadeada
Implemente uma fila utilizando nós, com os campos:
typedef struct Fila {
    No *inicio;
    No *fim;
} Fila;


Implemente:
- enfileirar
- desenfileirar
- consultarInicio
- estaVazia
- liberar
Atenção: o caso mais importante é remover o último elemento. Quando a fila ficar vazia, tanto inicio quanto fim devem representar corretamente esse estado.
Exercício 10 — Rastreamento de uma fila
Começando com uma fila vazia:
1. Enfileirar 5, 10 e 15.
2. Desenfileirar uma vez.
3. Enfileirar 20.
4. Desenfileirar duas vezes.
5. Enfileirar 25.
Informe a ordem dos elementos restantes e para quais nós apontam inicio e fim.
Exercício 11 — Inverter uma fila usando uma pilha
Receba uma fila de inteiros e inverta a ordem dos elementos utilizando uma pilha auxiliar.
Exemplo:
- Entrada: frente → 1, 2, 3, 4
- Saída: frente → 4, 3, 2, 1
Não utilize vetores para armazenar os elementos.
Exercício 12 — Análise de complexidade
Considere implementações de pilhas e filas encadeadas.
Determine a complexidade temporal de cada operação:
Operação	Complexidade
Empilhar	?
Desempilhar	?
Enfileirar	?
Desenfileirar	?
Consultar topo	?
Consultar início	?
Justifique suas respostas considerando que a fila mantém ponteiros para o início e o fim.

Parte 3 — Listas encadeadas
Nesta etapa, o objetivo é dominar os casos em que os ponteiros precisam ser atualizados com cuidado.
Exercício 13 — Lista simplesmente encadeada
Implemente uma lista com as seguintes operações:
- Inserir no início.
- Inserir no final.
- Imprimir os elementos.
- Buscar um valor.
- Contar a quantidade de nós.
- Liberar toda a memória.
Utilize um ponteiro para o início da lista.
Exercício 14 — Remover um elemento
Implemente:
No *remover(No *inicio, int valor);


A função deve remover a primeira ocorrência de valor e retornar o novo início da lista.
Teste estes casos:
- Lista vazia.
- Valor inexistente.
- Valor no primeiro nó.
- Valor no meio.
- Valor no último nó.
- Lista com apenas um nó.
Exercício 15 — Inserção ordenada
Implemente uma função que insira um valor em uma lista crescente, mantendo a ordenação.
Exemplo:
- Lista: 2 → 5 → 8 → 12
- Inserir 7.
- Resultado: 2 → 5 → 7 → 8 → 12
Resolva sem reconstruir a lista e sem usar vetores.
Exercício 16 — Inverter uma lista
Implemente uma função que inverta uma lista simplesmente encadeada in-place, ou seja, sem criar novos nós.
Exemplo:
1 → 2 → 3 → 4 → NULL
Resultado:
4 → 3 → 2 → 1 → NULL
Explique a função dos ponteiros ant, atual e prox.
Exercício 17 — Remover duplicatas
Dada uma lista não ordenada, remova os elementos duplicados, preservando a primeira ocorrência de cada valor.
Exemplo:
- Entrada: 3 → 5 → 3 → 2 → 5 → 7
- Saída: 3 → 5 → 2 → 7
Desafio extra: resolva sem utilizar estruturas auxiliares, como conjuntos ou mapas.
Exercício 18 — Lista duplamente encadeada
Implemente uma lista com ponteiros ant e prox.
Implemente inserção e remoção no início e no final, além da impressão nos dois sentidos.
Explique quais ponteiros precisam ser atualizados ao remover um nó que está no meio da lista.

Parte 4 — Árvores ABB e AVL
Para esta parte, considere a estrutura:
typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;


Na ABB, todos os valores da esquerda são menores que o nó, e todos os valores da direita são maiores. Para simplificar, considere que não existem valores repetidos.
Exercício 19 — Construção de uma ABB
Insira, nesta ordem:
50, 30, 70, 20, 40, 60, 80, 35, 45
Desenhe a árvore resultante e responda:
1. Qual é a raiz?
2. Quais são as folhas?
3. Qual é a altura da árvore?
4. Qual é o caminho para buscar o valor 45?
5. Qual é o fator de balanceamento da raiz, considerando \(FB = h(\text{esq}) - h(\text{dir})\)?
Considere altura medida em arestas, com a altura de uma folha igual a zero.
Exercício 20 — Percursos em árvores
Utilize a árvore do exercício anterior e determine a sequência produzida por:
- Pré-ordem: raiz, esquerda, direita.
- Em ordem: esquerda, raiz, direita.
- Pós-ordem: esquerda, direita, raiz.
- Em largura: nível por nível.
Explique por que o percurso em ordem de uma ABB produz os valores em ordem crescente.
Exercício 21 — Implementação recursiva da ABB
Implemente:
No *inserir(No *raiz, int valor);
bool buscar(No *raiz, int valor);
void emOrdem(No *raiz);
int contarNos(No *raiz);
int contarFolhas(No *raiz);


Depois, determine a complexidade de cada operação no melhor caso e no pior caso, considerando a altura da árvore.
Exercício 22 — Remoção em ABB
Implemente a remoção de um valor de uma ABB.
Você deve tratar três situações:
1. O nó é uma folha.
2. O nó tem apenas um filho.
3. O nó tem dois filhos.
Para o terceiro caso, utilize o sucessor em ordem: o menor valor da subárvore direita.
Teste removendo 20, 30 e 50 da árvore do exercício 19, sempre começando novamente com a árvore original.
Exercício 23 — Altura e fator de balanceamento
Implemente:
int altura(No *raiz);
int fatorBalanceamento(No *raiz);


Considere altura -1 para árvore vazia e altura 0 para uma folha.
Responda:
1. Qual é o fator de balanceamento de uma folha?
2. Uma árvore é AVL se todos os nós têm fator de balanceamento entre -1 e 1?
3. Por que calcular a altura recursivamente em todos os nós pode ser ineficiente?
4. Como armazenar a altura em cada nó permite atualizar o fator de balanceamento em tempo constante por nó?
Exercício 24 — Identificação de rotações AVL
Para cada sequência, insira os valores em uma AVL inicialmente vazia. Desenhe a árvore após cada inserção e indique a rotação necessária quando houver desequilíbrio.
- Caso A — LL: 30, 20, 10
- Caso B — RR: 10, 20, 30
- Caso C — LR: 30, 10, 20
- Caso D — RL: 10, 30, 20
Para cada caso, informe a nova raiz após o rebalanceamento.
Lembrete das rotações
LL
Rotação simples à direita.

RR
Rotação simples à esquerda.



LR
Esquerda no filho; depois direita no nó.

RL
Direita no filho; depois esquerda no nó.



Exercício 25 — Implementação de AVL
Partindo da implementação da ABB, adicione ao nó um campo altura.
typedef struct No {
    int valor;
    int altura;
    struct No *esq;
    struct No *dir;
} No;


Implemente:
- alturaNo
- atualizarAltura
- fatorBalanceamento
- rotacaoDireita
- rotacaoEsquerda
- inserirAVL
A função inserirAVL deve inserir o elemento, atualizar as alturas e realizar a rotação adequada.
Restrição: não percorra a árvore inteira para recalcular todas as alturas depois de cada inserção. Atualize-as durante o retorno da recursão.
Exercício 26 — Desafio final: comparar ABB e AVL
Insira os números de 1 a 15, em ordem crescente, em uma ABB comum e em uma AVL.
Compare:
1. A altura final de cada árvore.
2. A quantidade de comparações necessária para buscar 15.
3. A quantidade de rotações feitas pela AVL.
4. A complexidade de busca, inserção e remoção em cada estrutura.
5. O que acontece com uma ABB quando a entrada já está ordenada.
Considere a altura em arestas para a comparação.