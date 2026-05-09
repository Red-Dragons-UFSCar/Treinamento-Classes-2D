**Getting Started**

Compile e execute da seguinte maneira:

```bash
  g++ -o main main.cpp
  ./main
```


**Herança** 

A classe base *Acao* foi aplicada como a classe "pai"

```cpp
class Acao {
  public:
    virtual void executar() = 0;
    virtual ~Acao() {};
};
```

O `=0` torna o método `executar()` um método virtual puro, obrigando toda subclasse a implementar esse método.

Cada subclasse de Acao herda o seu comportamento usando `: public Acao` e sobrescrevem o método "executar" da classe pai através da palavra-chave `override`.

**Polimorfirsmo** 

Dentro da classe Jogador é armazenado um ponteiro para a classe base.

```cpp
class Jogador {
  private:
    Acao *acao;
}
```
No construtor da classe Jogador, esse ponteiro recebe diferentes objetos dependendo da posição do jogador:

```cpp
 if (posicao == "atacante") {
      acao = new AcaoAtacar();  
    } else if (posicao == "defensor") {
      acao = new AcaoDefender();
    } else if (posicao == "goleiro") {
      acao = new AcaoDefenderGol();
    }
```
Dentro do método `executarAcao()`, é chamado 

```cpp
  acao->executar()
```

Que executa diferentes ações de acordo com objeto que está sendo referenciado no tempo de execução.
