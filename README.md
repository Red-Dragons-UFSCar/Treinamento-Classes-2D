# Treinamento-Classes-2D
Repositório destinado para avaliação da atividade referente ao treinamento de C++ 

Nesse desafio foi necessário utilizar 5 classes:
    Jogador: contém atributos como nome e posição, sendo esse último podendo ser atacante, goleiro e defensor.
             Contendo, também, método de executar uma determinada ação dependendo da posição do jogador.
             Essa classe foi implementada após as outras classes, já que o código foi implementado em um único arquivo, logo, é necessário a sequencialidade.
    
    Ação: Classe que contém o método abstrato executar() = 0;, assumindo determinada ação a depender da posição do jogador;
    AçãoAtacar: Implementa a ação de atacar quando o jogador for atacante, é uma classe filha de ação.
    AçãoDefender: Implementa a ação de atacar quando o jogador for defensor, é uma classe filha de ação.
    AçãoDefenderGol: Implementa a ação de atacar quando o jogador for goleiro, é uma classe filha de ação.

No arquivo main foi utilizado alocação dinâmica, para criar 3 jogadores, um de cada tipo, e executar suas respectivas ações.