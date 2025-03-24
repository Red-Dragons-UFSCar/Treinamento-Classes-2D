#include <iostream>  // Necessário para cout, cerr, endl
#include <string>    // Necessário para std::string

// Classe base Acao
class Acao {
public:
    virtual ~Acao() {}
    virtual void executar() const = 0;
};

// Subclasses de Acao
class AcaoAtacar : public Acao {
public:
    void executar() const override {
        std::cout << "atacando e chutando para o gol!" << std::endl;
    }
};

class AcaoDefender : public Acao {
public:
    void executar() const override {
        std::cout << "defendendo e interceptando a bola!" << std::endl;
    }
};

class AcaoDefenderGol : public Acao {
public:
    void executar() const override {
        std::cout << "defendendo o gol e fez uma defesaça!" << std::endl;
    }
};

// Classe Jogador
class Jogador {
private:
    std::string nome;
    std::string posicao;
    Acao* acao;

public:
    Jogador(const std::string& nome, const std::string& posicao) 
        : nome(nome), posicao(posicao) {
        if (posicao == "atacante") {
            acao = new AcaoAtacar();
        } else if (posicao == "defensor") {
            acao = new AcaoDefender();
        } else if (posicao == "goleiro") {
            acao = new AcaoDefenderGol();
        } else {
            throw std::invalid_argument("Posição inválida");
        }
    }

    ~Jogador() {
        delete acao;
    }

    void executarAcao() const {
        std::cout << nome << " está ";
        acao->executar();
    }

    // Desabilita cópia
    Jogador(const Jogador&) = delete;
    Jogador& operator=(const Jogador&) = delete;
};

int main() {
    try {
        Jogador atacante("Yuri Alberto", "atacante");
        Jogador defensor("Gil", "defensor");
        Jogador goleiro("Cássio", "goleiro");

        atacante.executarAcao();
        defensor.executarAcao();
        goleiro.executarAcao();

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}