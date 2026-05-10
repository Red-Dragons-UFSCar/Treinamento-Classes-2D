#include <iostream>
#include <string>

using namespace std;
class Acao; //compilardor entender que essa classe será criada 

class Jogador{
    private: 
    string nome;
    string posicao;
    Acao* acao1; //usei esse ponteiro para utilizar aqui na classe jogador e lá emabixo na classe Acao
    
    public:
    Jogador(string n, string p, Acao* a): nome(n), posicao(p), acao1(a) {}
    virtual void executar_acao();

    void setnome(string Nome){
       nome = Nome; 

    }
    string getnome(){
        return nome; 
    }

    void setposicao(string Posicao){
        posicao = Posicao; 

    }
    string getposicao(){
        return posicao; 
    }
  

}; 

//classe ação , acao atacar, acao defender, acaodefendergol
//método virtual executar()
class Acao{
    private:
    string acao;
    public: 
    Acao(string a): acao(a) {}
    virtual ~Acao() {}

    void setacao(string action){
        acao = action; 

    }
   string getacao() const {
        return acao; 
    }

    virtual void executar() const{
        cout<< "Ação" << getacao() << std::endl; 
    }


}; 

class acaoatacar : public Acao{
    public:
    acaoatacar() : Acao(" O atacante esta atacando e tentando fazer gol!") {}
    void executar() const override{
        cout<< "\n Ação: "<< getacao() << std::endl; 
    }
};

class acaodefender : public Acao{
    public:
    acaodefender() : Acao(" O defensor esta defendendo e tentando roubar a bola! ") {}
    void executar() const override{
        cout << "\n Ação: "<< getacao() << std::endl; 
    }
};
class acaodefendergol : public Acao{
    public:
    acaodefendergol() : Acao(" O goleiro esta defendendo o gol! ") {}
    void executar() const override{
        cout << "\n Ação: "<< getacao() <<std::endl; 
    }
};

void Jogador::executar_acao() {
    cout << "\n Jogador:  " << nome << "\n Posição: " << posicao;
    if (acao1) {
        acao1->executar(); 
    }
}

int main(){
    acaodefendergol defesagol;
    acaodefender defender; 
    acaoatacar atacar; 
    
    Jogador j1("Marcos", "Goleiro", &defesagol); 
    Jogador j2("Lucas"," Zagueiro ", &defender);
    Jogador j3("Pedro", " Atacante ", &atacar);

    j1.executar_acao();
    
    j2.executar_acao();
   
    j3.executar_acao();
     



return 0; 
}
