# Treinamento-Classes-2D
Repositório destinado para avaliação da atividade referente ao treinamento de C++ 

##  Projeto de Simulação de Jogadores de Futebol 2D
Simulador de ações de jogadores usando POO em C++ com herança e polimorfismo,explicação do uso de herança e polimorfismo no código.

### Herança
O código utiliza herança para estabelecer uma relação hierárquica entre classes, onde a classe base Acao define uma interface comum com o método virtual executar(), enquanto as classes derivadas (AcaoAtacar, AcaoDefender e AcaoDefenderGol) implementam comportamentos específicos para cada posição. Dessa forma, a herança permite especializar o comportamento de cada tipo de ação mantendo uma estrutura organizada.

### Polimorfismo
Além disso, o polimorfismo é aplicado através do ponteiro para a classe base (Acao*) na classe Jogador. Quando o método executarAcao() é invocado, ocorre uma chamada polimórfica a acao->executar(), de modo que o C++ determina em tempo de execução qual implementação específica deve ser executada, seja a do atacante, defensor ou goleiro,consequentemente,isso proporciona flexibilidade ao sistema ppois a classe Jogador pode trabalhar com qualquer tipo de ação sem conhecer seus detalhes específicos. Por exemplo, quando criamos um jogador atacante como Yuri Alberto, ele automaticamente executa AcaoAtacar::executar(), ao passo que um goleiro como Cássio executa AcaoDefenderGol::executar(). Portanto, o mesmo comando (executar()) produz resultados diferentes conforme o tipo real do objeto, demonstrando assim o poder do polimorfismo na programação orientada a objetos.
