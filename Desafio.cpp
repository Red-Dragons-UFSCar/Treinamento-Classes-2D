#include <iostream>
#include <string>

using namespace std;

class Acao {
    public:
        virtual void executar() = 0; 
        virtual ~Acao() {

        }
};

class AcaoAtacar : public Acao {
    public:
        void executar() override {
            cout << "Executando atacar" << endl;
        }
};

class AcaoDefender : public Acao {
    public:
        void executar() override {
            cout << "Executando defesa" << endl;
        }
};

class AcaoDefenderGol : public Acao {
    public:
        void executar() override {
            cout << "Executando defesa do gol" << endl;
        }
};

class Jogador {
    private:
        string nome, posicao;
    
    public:
        Jogador(string nome, string posicao) : nome(nome), posicao(posicao) {}
        
        virtual ~Jogador(){

        }

        void executarAcao(){
            Acao* a = nullptr;
        
            if (posicao == "atacante") {
                a = new AcaoAtacar();
            } else if (posicao == "defensor") {
                a = new AcaoDefender();
            } else if (posicao == "goleiro") {
                a = new AcaoDefenderGol();
            } 
            a->executar();
            delete a;
        }

};

int main() {
    Jogador *j1 = new Jogador("Fulano", "atacante");
    Jogador *j2 = new Jogador("Beltrano", "defensor");
    Jogador *j3 = new Jogador("Ciclano", "goleiro");

    j1->executarAcao();
    j2->executarAcao(); 
    j3->executarAcao(); 

    delete j1;
    delete j2;
    delete j3;

    return 0;
}