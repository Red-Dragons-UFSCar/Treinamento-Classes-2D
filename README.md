# Treinamento-Classes-2D

Repositório destinado para avaliação da atividade referente ao treinamento de C++.

## Atividade Final: Sistema Simples de Ações para Jogadores com Herança

Este projeto implementa um sistema simples em C++ que simula ações de jogadores em um jogo de futebol 2D.

O sistema possui três tipos de jogadores:

- Atacante
- Defensor
- Goleiro

Cada tipo de jogador executa uma ação diferente, de acordo com sua posição.

## Classes implementadas

O projeto possui a classe `Jogador`, que armazena as informações principais do jogador:

- Nome
- Posição

Também foi criada a classe base `Acao`, que representa uma ação genérica de um jogador.

A partir da classe `Acao`, foram criadas três classes derivadas:

- `AcaoAtacar`
- `AcaoDefender`
- `AcaoDefenderGol`

Cada uma dessas classes representa uma ação específica dentro do jogo.

## Aplicação de herança

A herança foi aplicada na criação das classes de ação.

A classe `Acao` funciona como uma classe base. Ela define o método `executar()`, que será usado por todas as ações.

As classes `AcaoAtacar`, `AcaoDefender` e `AcaoDefenderGol` herdam da classe `Acao`.

Dessa forma, todas essas classes possuem a mesma estrutura básica, mas cada uma implementa o método `executar()` de uma maneira diferente.

Por exemplo:

- `AcaoAtacar` executa a ação de ataque.
- `AcaoDefender` executa a ação de defesa.
- `AcaoDefenderGol` executa a ação de defender o gol.

Assim, o código reutiliza a estrutura da classe base `Acao`, mas permite que cada classe filha tenha seu próprio comportamento.

## Aplicação de polimorfismo

O polimorfismo foi aplicado no método `executarAcao()` da classe `Jogador`.

Dentro desse método, é usado um ponteiro do tipo `Acao*`.

Dependendo da posição do jogador, esse ponteiro recebe um objeto diferente:

- Se o jogador for atacante, é criada uma `AcaoAtacar`.
- Se o jogador for defensor, é criada uma `AcaoDefender`.
- Se o jogador for goleiro, é criada uma `AcaoDefenderGol`.

Mesmo o ponteiro sendo do tipo da classe base `Acao`, o método executado é o da classe filha correspondente.

Isso acontece porque o método `executar()` foi declarado como `virtual` na classe base.

Com isso, o mesmo comando `acao->executar()` pode executar ações diferentes, dependendo do tipo real do objeto criado.

## Funcionamento do programa

Na função `main()`, foram criados três jogadores para demonstrar o funcionamento do sistema:

- Pedro, atacante
- Lucas, defensor
- Marcos, goleiro

Cada jogador chama o método `executarAcao()`.

O programa imprime na tela o nome do jogador, sua posição e a ação que ele executa.

## Exemplo de saída

Sistema simples de acoes para jogadores

Jogador: Pedro  
Posicao: atacante  
O atacante esta atacando e tentando fazer gol!

Jogador: Lucas  
Posicao: defensor  
O defensor esta defendendo e tentando roubar a bola!

Jogador: Marcos  
Posicao: goleiro  
O goleiro esta defendendo o gol!

## Conclusão

Este projeto mostra de forma simples como aplicar herança e polimorfismo em C++.

A herança foi usada para criar diferentes tipos de ações a partir de uma classe base.

O polimorfismo foi usado para permitir que o jogador execute a ação correta de acordo com sua posição, utilizando o mesmo método `executar()`.
