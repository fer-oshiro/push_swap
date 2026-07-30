*This project has been created as part of the 42 curriculum by aschulz-, fsayuri-.*

# Push Swap

`push_swap` é um projeto de algoritmos da 42 no qual uma sequência de inteiros deve
ser ordenada usando duas pilhas e um conjunto limitado de operações. O desafio não é
apenas chegar à ordem correta: o programa deve produzir uma sequência de instruções
válida e tão curta quanto possível.

Este repositório implementa a versão do projeto feita em dupla, com quatro estratégias
de ordenação selecionáveis em tempo de execução e um modo de benchmark.

## Descrição

No início, todos os números estão na pilha `a`, com o primeiro argumento no topo, e a
pilha `b` está vazia. O objetivo é deixar `a` em ordem crescente, com o menor número
no topo, usando somente:

| Operação | Efeito |
| --- | --- |
| `sa`, `sb` | Troca os dois elementos do topo de `a` ou `b` |
| `ss` | Executa `sa` e `sb` ao mesmo tempo |
| `pa`, `pb` | Move o topo de uma pilha para a outra |
| `ra`, `rb` | Rotaciona a pilha para cima |
| `rr` | Executa `ra` e `rb` ao mesmo tempo |
| `rra`, `rrb` | Rotaciona a pilha para baixo |
| `rrr` | Executa `rra` e `rrb` ao mesmo tempo |

As instruções são escritas em `stdout`, uma por linha. Entradas inválidas — valores
duplicados, tokens que não são inteiros ou números fora do intervalo de `int` — geram
`Error\n` em `stderr`.

### Representação das pilhas

Cada pilha é representada por uma lista duplamente encadeada circular. Essa estrutura
permite alterar o topo em tempo constante durante rotações e inserir ou remover o
primeiro nó sem deslocar os demais elementos.

Antes da ordenação, cada valor recebe um índice entre `0` e `n - 1`. A indexação
preserva a ordem relativa dos valores e transforma números negativos ou muito
distantes entre si em uma faixa contínua, adequada principalmente ao Radix Sort.

## Métrica de disorder

O modo adaptativo mede o estado inicial da pilha antes de executar qualquer operação.
A métrica é a proporção de inversões entre todos os pares possíveis:

```text
disorder = pares fora de ordem / total de pares
```

- `0.00` representa uma sequência já ordenada;
- `1.00` representa uma sequência em ordem completamente inversa;
- valores intermediários indicam uma sequência parcialmente desordenada.

Essa análise não produz operações de `push_swap`; ela somente orienta a escolha da
estratégia.

## Estratégias e escolhas algorítmicas

As estratégias foram escolhidas para lidar com diferentes níveis de desordem e têm
sua complexidade expressa em quantidade de operações `push_swap`, como exige o
enunciado.

### Simple — Selection Sort adaptado, `O(n²)`

A estratégia Simple usa extração repetida do menor elemento:

1. encontra o menor índice presente em `a`;
2. escolhe `ra` ou `rra` de acordo com a menor distância até o topo;
3. envia o elemento para `b` com `pb`;
4. ao final, devolve os elementos para `a` com `pa`.

A escolha prioriza simplicidade, previsibilidade e facilidade de validação. Cada uma
das `n` extrações pode exigir até `O(n)` rotações; portanto, o limite superior é
`O(n²)` operações. O algoritmo usa `O(1)` de espaço auxiliar além das duas pilhas.

### Medium — ordenação por chunks, `O(n√n)`

A estratégia Medium divide os índices normalizados em aproximadamente `√n` faixas,
cada uma contendo aproximadamente `√n` elementos. As faixas são processadas em
ordem: elementos do chunk ativo são enviados para `b`, enquanto rotações posicionam
os demais candidatos e organizam cada bloco para a reconstrução de `a`.

Essa abordagem oferece um meio-termo entre o custo quadrático da extração simples e a
regularidade do Radix Sort. Há `O(√n)` chunks; cada passagem pode percorrer até
`O(n)` posições, e a reconstrução mantém o mesmo limite, resultando em
`O(n√n)` operações. Os limites dos chunks são mantidos em variáveis escalares, com
`O(1)` de espaço auxiliar além das pilhas.

### Complex — Binary Radix Sort LSD, `O(n log n)`

A estratégia Complex aplica Radix Sort binário LSD (*Least Significant Digit*) aos
índices:

1. analisa um bit por vez, do menos significativo ao mais significativo;
2. executa `pb` quando o bit atual é `0`;
3. executa `ra` quando o bit atual é `1`;
4. devolve todos os elementos de `b` para `a` com `pa`;
5. repete o processo para os demais bits.

Cada bit exige no máximo uma passagem pela pilha e o retorno dos elementos movidos,
ou seja, `O(n)` operações. Como os índices de `0` a `n - 1` ocupam `O(log n)` bits, o
total é `O(n log n)` operações. O espaço auxiliar é `O(1)` além dos nós já existentes.

### Adaptive — seleção baseada em disorder

Sem uma flag de estratégia, `--adaptive` é o comportamento padrão. O seletor mede o
disorder e encaminha a entrada para:

| Disorder inicial | Estratégia interna | Limite de operações |
| --- | --- | --- |
| `< 0.20` | Simple | `O(n²)` |
| `0.20 ≤ disorder < 0.50` | Medium | `O(n√n)` |
| `≥ 0.50` | Complex | `O(n log n)` |

Os limiares são definidos pelo enunciado. Eles também representam três regimes úteis:
entradas pouco desordenadas, entradas parcialmente desordenadas e entradas muito
desordenadas. O seletor acrescenta somente a análise inicial e usa `O(1)` de espaço
auxiliar; no modelo de operações do projeto, o limite de cada regime é o da estratégia
escolhida.

Entradas com até três elementos usam uma rotina específica, independentemente da
estratégia, evitando o custo de inicializar um algoritmo geral.

## Instruções

### Compilação

```bash
cd push_swap
make
```

Outras regras disponíveis:

```bash
make clean    # remove os arquivos-objeto
make fclean   # remove os objetos e o executável
make re       # recompila o projeto do zero
```

### Uso

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <inteiros>
```

Os números podem ser enviados como argumentos separados ou dentro de uma string:

```bash
./push_swap 2 1 3
./push_swap "2 1 3"
./push_swap --simple 3 2 1
./push_swap --complex "4 67 3 87 23"
```

Apenas uma flag de estratégia pode ser usada. Quando nenhuma é informada, o programa
usa `--adaptive`.

### Benchmark

`--bench` mantém as operações em `stdout` e escreve as métricas em `stderr`:

```bash
./push_swap --adaptive --bench "4 67 3 87 23"
```

O relatório contém:

- disorder inicial com duas casas decimais;
- estratégia utilizada e sua classe de complexidade;
- total de operações;
- contagem individual de `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`,
  `rrb` e `rrr`.

Para contar apenas as operações:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
```

Para separar operações e métricas:

```bash
ARG="4 67 3 87 23"
./push_swap --bench $ARG 2> benchmark.log | wc -l
```

## Metas de desempenho

Os limites mínimos definidos pelo enunciado são:

| Quantidade | Mínimo para aprovação | Bom | Excelente |
| ---: | ---: | ---: | ---: |
| 100 números | menos de 2000 | menos de 1500 | menos de 700 |
| 500 números | menos de 12000 | menos de 8000 | menos de 5500 |

## Contribuições

O projeto foi desenvolvido e é defendido em conjunto, com participação de ambas as
integrantes nos arquivos centrais e nas decisões de arquitetura.

| Integrante | Principais contribuições |
| --- | --- |
| `aschulz-` | Métrica de disorder, indexação dos nós, estrutura do seletor de algoritmos, integração das flags de estratégia e colaboração no fluxo principal e no cabeçalho |
| `fsayuri-` | Parsing e validação das entradas, listas e operações das pilhas, contadores e benchmark, ordenação de entradas pequenas, funções auxiliares, Makefile e integração geral |

As escolhas algorítmicas, revisões, testes e correções são responsabilidade das duas
integrantes.

## Recursos

- [Open Data Structures — Sorting Algorithms](https://opendatastructures.org/ods-cpp/11_Sorting_Algorithms.html)
- [VisuAlgo — Sorting](https://visualgo.net/en/sorting)
- [Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
- [Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort)
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation)

### Uso de IA

Ferramentas de IA foram usadas como apoio para comparar alternativas de algoritmos,
revisar argumentos de complexidade e estruturar a documentação.
