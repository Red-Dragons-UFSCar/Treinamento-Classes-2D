#include <iostream>

using namespace std;

class Jogador{
    private:

        string jogador_nome;
        string jogador_pos;
    
    public:

        string getName() const{
            return jogador_nome;
        }

        string getPos() const{
            return jogador_pos;
        }
        
        void setName(string name){
             jogador_nome = name;
        }

        void setPos(string pos){
             jogador_pos = pos;
        }


        virtual void executarAcao(){
            cout << "Ação sendo executada" << endl;
        }

        virtual ~Jogador() {}

};

class Acao{
    public:
    
    virtual void executar(){
        cout << "Ação sendo executada" << endl;
    
    }

    virtual ~Acao(){}
};

class Atacar : public Acao{
    public:

    void executar() override{
        cout << "Recebill!!!" << endl;
    }

};

class Defender : public Acao{
    public:

    void executar() override{
        cout << "park the bus!!!" << endl;
    }

};

class DefenderGol : public Acao{
    public:

    void executar() override{
        cout << "TAFAREEEEEEEEELL!!!" << endl;
    }

};

class Atacante : public Jogador{
    public:
    void executarAcao() override{
        Atacar ataque;
        ataque.executar();
    }
};

class Goleiro : public Jogador{
    public:
    void executarAcao() override{
        DefenderGol defesa_gol;
        defesa_gol.executar();
    }
};

class Zaga : public Jogador{
    public:
    void executarAcao() override{
        Defender defesa;
        defesa.executar();
    }
};

int main(){

    Atacante* p1 = new Atacante();
    p1->setName("Joao");
    p1->setPos("Atacante");
    cout << p1->getName() << endl;
    cout << p1->getPos() << endl;
    p1->executarAcao();

    cout << endl;

    Goleiro* p2 = new Goleiro();
    p2->setName("Bacunim");
    p2->setPos("Goleiro");
    cout << p2->getName() << endl;
    cout << p2->getPos() << endl;
    p2->executarAcao();

    cout << endl;

    Zaga* p3 = new Zaga();
    p3->setName("Targas");
    p3->setPos("Zaga");
    cout << p3->getName() << endl;
    cout << p3->getPos() << endl;
    p3->executarAcao();

    
    delete p1,p2,p3;
    return 0;
}