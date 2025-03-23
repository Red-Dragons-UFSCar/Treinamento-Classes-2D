//Código desenvolvido pela Isabela Castro
#include <iostream>
#include <string>

using namespace std;

//Classe base Ação
class Acao {
public:
    virtual void executar(const string& nome) const = 0;
    virtual ~Acao() {}
};

//Subclasses de Ação
class AcaoAtacar : public Acao {
public:
    void executar(const string& nome) const override {
        cout << nome << " Está atacando!" << endl;
    }
};

class AcaoDefender : public Acao {
public:
    void executar(const string& nome) const override {
        cout << nome << " Está defendendo!" << endl;
    }
};

class AcaoDefenderGol : public Acao {
public:
    void executar(const string& nome) const override {
        cout << nome << " Está defendendo o gol!" << endl;
    }
};

//Classe Jogador
class Jogador {
private:
    string nome;
    string posicao;
    Acao* acao;

public:
    Jogador(string nome, string posicao) : nome(nome), posicao(posicao), acao(nullptr) {}

    ~Jogador() {
        delete acao;
    }

    void executarAcao() {
        if (acao) {
            acao->executar(nome);
        } else {
            if (posicao == "Atacante") {
                acao = new AcaoAtacar();
            } else if (posicao == "Defensor") {
                acao = new AcaoDefender();
            } else if (posicao == "Goleiro") {
                acao = new AcaoDefenderGol();
            }

            if (acao) {
                acao->executar(nome);
            } else {
                cout << nome << " Não tem uma ação definida!" << endl;
            }
        }
    }
};

int main() {
    Jogador* jogador1 = new Jogador("Rafael", "atacante");
    Jogador* jogador2 = new Jogador("Alisson", "goleiro");
    Jogador* jogador3 = new Jogador("Murilo", "defensor");
    Jogador* jogador4 = new Jogador("Richard", "meio-campo"); 

    jogador1->executarAcao(); 
    jogador2->executarAcao(); 
    jogador3->executarAcao(); 
    jogador4->executarAcao(); 

    delete jogador1;
    delete jogador2;
    delete jogador3;
    delete jogador4;

    return 0;
}
