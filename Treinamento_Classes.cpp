#include <iostream>
#include <string>
using namespace std;

// Classe Base de Ação
class Acao {
public:
    virtual void executar() {
        cout << "Player is performing an action." << endl;
    };
    virtual ~Acao() {}
};

// Classes Derivadas de Ação
class AcaoAtacar : public Acao {
public:
    void executar() override {
        cout << "Atacante está se movendo em direção ao gol!" << endl;
    }
};

class AcaoDefender : public Acao {
public:
    void executar() override {
        cout << "Defensor está defendendo a área!" << endl;
    }
};

class AcaoDefenderGol : public Acao {
public:
    void executar() override {
        cout << "Goleiro está defendendo o gol!" << endl;
    }
};

// Classe Jogador
class Jogador {
private:
    string nome;
    string posicao;
    Acao* acao;

public:
    Jogador(string nome, string posicao) : nome(nome), posicao(posicao) {
        if(posicao == "atacante") {
            acao = new AcaoAtacar();
        }
        else if(posicao == "defensor") {
            acao = new AcaoDefender();
        }
        else if(posicao == "goleiro") {
            acao = new AcaoDefenderGol();
        }
        else {
            throw invalid_argument("Posição inválida!");
        }
    }

    ~Jogador() {
        delete acao;
    }

    void executarAcao() {
        cout << nome << " (" << posicao << "): ";
        acao->executar();
    }
};

// Função principal
int main() {

    Jogador* jogador1 = new Jogador("Yuri Alberto", "atacante");
    Jogador* jogador2 = new Jogador("Fabrizio Angileri", "defensor");
    Jogador* jogador3 = new Jogador("Hugo Souza", "goleiro");

    jogador1->executarAcao();
    jogador2->executarAcao();
    jogador3->executarAcao();

    delete jogador1;
    delete jogador2;
    delete jogador3;

    return 0;
}
