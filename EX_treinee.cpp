#include <iostream>
#include <string>

// Definicao da classe Acao -> Classe abstrata
class Acao
{
public:
    virtual void executar(const std::string& nome) = 0;
    virtual ~Acao() = default;
};
class AcaoAtacar : public Acao
{
public:
    void executar(const std::string& nome) override
    {std::cout << nome << " faz : " << " ATAQUE " << "\n";}
};
class AcaoDefender : public Acao
{
public:
    void executar(const std::string& nome) override
    {std::cout <<  nome << " faz : " << " DEFESA " << "\n";}
};
class AcaoDefenderGol : public Acao
{
public:
    void executar(const std::string& nome) override
    {std::cout <<  nome << " faz : " <<" DEFESA GOL " << "\n";}
};

// Definicao da classe Jogador
// Polimorfismo por meio de um ponteiro para classe abs Acao
// Essa classe sabe, em tempo de execucao, para qual subclasse apontar
class Jogador
{
private:
    std::string nome;
    std::string pos;

    // Ponteiro para a classe acao. O mais razoavel eh usar unique pointer, mas isso nao quebra
    Acao* tipo_acao;
public:
    Jogador(const std::string& nome_e, const std::string& pos_e)
    : nome(nome_e), pos(pos_e)
    {
        if(pos == "ATACANTE")           tipo_acao = new AcaoAtacar();
        else if(pos == "DEFENSOR")      tipo_acao = new AcaoDefender();
        else if(pos == "GOLEIRO")       tipo_acao = new AcaoDefenderGol();
        else                            tipo_acao = nullptr;                // Caso parsing errado
    }
    void executarAcao()
    { if(tipo_acao != nullptr) tipo_acao->executar(this->nome); }

    // Destrutor para lidar com memory leak
    ~Jogador() { delete tipo_acao; }
};

int main(void)
{
    Jogador def("Pedro Caio", "ATACANTE");
    def.executarAcao();

    Jogador ataq("Joao Valerio", "DEFENSOR");
    ataq.executarAcao();

    Jogador golr("Luis Antonio", "GOLEIRO");
    golr.executarAcao();

    Jogador ataq2("Cesar Augusto", "ATACANTE");
    ataq2.executarAcao();

    return 0;
}
