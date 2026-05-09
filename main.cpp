#include <iostream>

using namespace std;

class Acao {
public:
  virtual void executar() = 0;
  virtual ~Acao() {};
};

class AcaoAtacar : public Acao {
public:
  void executar() override { cout << "Atacante chuta em direção ao gol! \n"; }
};

class AcaoDefender : public Acao {
public:
  void executar() override {
    cout << "Defensor desarma o atacante inimigo! \n";
  }
};

class AcaoDefenderGol : public Acao {
public:
  void executar() override { cout << "Goleirão defende de mão trocada! \n"; }
};

class Jogador {
private:
  string nome;
  string posicao;
  Acao *acao;

public:
  Jogador(const string &nome, const string &posicao)
      : nome(nome), posicao(posicao) {
    if (posicao == "atacante") {
      acao = new AcaoAtacar();
    } else if (posicao == "defensor") {
      acao = new AcaoDefender();
    } else if (posicao == "goleiro") {
      acao = new AcaoDefenderGol();
    }
  }

  ~Jogador() { delete acao; }

  void executarAcao() const {
    cout << "[" << posicao << "] " << nome << ":\n";
    if (acao) {
      acao->executar();
    } else {
      cout << "Posição desconhecida, sem ação definida! \n";
    }
  }

  const string &getNome() const { return nome; }
  const string &getPosicao() const { return posicao; }
};

int main() {

  Jogador jogador1("Yuri alberto", "atacante");
  Jogador jogador2("Gustavo Henrique", "defensor");
  Jogador jogador3("Hugo Souza", "goleiro");

  jogador1.executarAcao();
  cout << endl;
  jogador2.executarAcao();
  cout << endl;
  jogador3.executarAcao();

  return 0;
}