#include <iostream>
#include <string>

using namespace std;

class Acao {
public:
    virtual void executar() = 0;

    virtual ~Acao() {}
};

class AcaoAtacar : public Acao {
public:
    void executar() override {
        cout << "O atacante esta atacando e tentando fazer gol!" << endl;
    }
};

class AcaoDefender : public Acao {
public:
    void executar() override {
        cout << "O defensor esta defendendo e tentando roubar a bola!" << endl;
    }
};

class AcaoDefenderGol : public Acao {
public:
    void executar() override {
        cout << "O goleiro esta defendendo o gol!" << endl;
    }
};

class Jogador {
private:
    string nome;
    string posicao;

public:
    Jogador(string nome, string posicao) {
        this->nome = nome;
        this->posicao = posicao;
    }

    void executarAcao() {
        Acao* acao = nullptr;

        cout << "Jogador: " << nome << endl;
        cout << "Posicao: " << posicao << endl;

        if (posicao == "atacante") {
            acao = new AcaoAtacar();
        } 
        else if (posicao == "defensor") {
            acao = new AcaoDefender();
        } 
        else if (posicao == "goleiro") {
            acao = new AcaoDefenderGol();
        } 
        else {
            cout << "Posicao invalida!" << endl;
            return;
        }

        acao->executar();

        delete acao;

        cout << endl;
    }
};

int main() {
    Jogador jogador1("Pedro", "atacante");
    Jogador jogador2("Lucas", "defensor");
    Jogador jogador3("Marcos", "goleiro");

    cout << "Sistema simples de acoes para jogadores" << endl;
    cout << "----------------------------------------" << endl << endl;

    jogador1.executarAcao();
    jogador2.executarAcao();
    jogador3.executarAcao();

    return 0;
}
