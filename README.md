# Implementação das Classes Jogador e Ação

Este repositório apresenta uma implementação básica de classes que utiliza herança e polimorfismo. A proposta é simular um jogo em que os jogadores realizam diversas ações de acordo com suas posições.

## Herança

A herança é empregada para desenvolver a classe base Acao e suas respectivas subclasses: AcaoAtacar, AcaoDefender e AcaoDefenderGol. A classe Acao é abstrata e incorpora o método virtual puro executar(), que é concretizado pelas subclasses com comportamentos distintos.

- AcaoAtacar: simboliza o comportamento de um jogador que ataca.

- AcaoDefender: simboliza o comportamento de um jogador que defende.

- AcaoDefenderGol: simboliza o comportamento de um goleiro.

## Polimorfismo

O conceito de polimorfismo é utilizado no método executarAcao() da classe Jogador, que faz uso do ponteiro Acao* para invocar a ação apropriada conforme a posição do jogador. Essa posição é o que dita qual ação será realizada. Dessa maneira, a classe Jogador consegue chamar a função executar() da classe correspondente, sem a necessidade de saber especificamente qual tipo de ação está em andamento.

- Se a posição do jogador for "atacante", a ação AcaoAtacar será executada.

- Caso a posição seja "defensor", a ação AcaoDefender será acionada.

- Se a posição for "goleiro", será chamada a ação AcaoDefenderGol.

Essa abordagem proporciona uma definição de comportamento para cada jogador de maneira flexível e expansível.
