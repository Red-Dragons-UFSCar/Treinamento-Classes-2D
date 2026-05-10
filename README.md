# Herança e Polimorfismo em C++

Exercio RED DRAGONS de treinamento sobre o uso de herança e polimorfismo para representar ações de jogadores em um sistema simples de futebol.

## Herança

A classe abstrata Acao define uma interface comum para todas as ações possíveis. Ela, por si só, não define comportamento algum, sendo responsável apenas pela interface. Suas classes derivadas (Herança), por sua vez, implementam o comportamento de acordo com cada função. Isso é realizado através de métodos virtuais puros (da classe forma, que não pode ser instanciada) e métodos sobrescritos (override das classes derivadas).

## Polimorfismo

A classe Jogador apresenta um comportamento da função executarAcao() diferente para cada instancia, de acordo com a sua posição. Nessa implementação, a classe Jogador possui um ponteiro para a classe abstrata Acao, de acordo com a função de cada jogador, esse ponteiro aponta para a classe derivada de Acao correspondente.

Dessa forma, a função-membro executarAcao sabe qual método chamar em tempo de execução.
