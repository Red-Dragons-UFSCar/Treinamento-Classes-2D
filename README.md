#Resumo do Código
Este código demonstra o uso de herança e polimorfismo em C++ para simular ações de jogadores em um time de futebol.

#Funcionamento do Código

Herança:
As classes AcaoAtacar, AcaoDefender e AcaoDefenderGol herdam da classe base Acao, compartilhando a mesma interface (executar()).

Polimorfismo:
O método executar() é chamado de forma polimórfica através de um ponteiro para a classe base Acao, permitindo que o comportamento correto seja executado em tempo de execução.

Composição:
A classe Jogador contém um ponteiro para Acao, demonstrando como objetos podem ser compostos por outros objetos para delegar comportamentos específicos.
