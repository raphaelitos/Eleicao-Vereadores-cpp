#include <sstream>
#include <iomanip>

#include "Candidato.hpp"
#include "Partido.hpp"

using namespace std;

Candidato::Candidato(const int& numero, const string& nomeUrna, std::shared_ptr<Partido> partido,
                     const string &dataNascStr, const int& genero, const int& situacao)
    : votos(0),          
    numero(numero),     
    nomeUrna(nomeUrna), 
    partido(partido),  
    dataNascimento(DataUtils::fromString(dataNascStr)), 
    genero(Genero::fromCodigo(genero)),               
    situacaoEleitoral(SituacaoEleitoral::fromCodigo(situacao))
{}

// Getters

int Candidato::getNumero() const { return numero; }

string Candidato::getNomeUrna(int flagFederado) const
{
    auto part = this->getPartido();
    if (part && part->getNumeroFederacao() != -1 && flagFederado != 0)
        return "*" + nomeUrna;
    return nomeUrna;
}

std::shared_ptr<Partido> Candidato::getPartido() const {
    return partido.lock();
}

int Candidato::getVotos() const { return votos; }

Genero Candidato::getGenero() const { return genero; }

DataUtils Candidato::getDataNascimento() const { return dataNascimento; }

bool Candidato::isEleito() const
{
    return (situacaoEleitoral.getCodigo() == SituacaoEleitoral::ELEITO ||
           situacaoEleitoral.getCodigo() == SituacaoEleitoral::ELEITO_POR_QUOCIENTE_PARTIDARIO ||
           situacaoEleitoral.getCodigo() == SituacaoEleitoral::ELEITO_POR_MEDIA);
}

void Candidato::addVotos(int votos)
{
    if (votos < 0)
    {
        throw invalid_argument("Votos não podem ser negativos");
    }
    this->votos += votos;
}

int Candidato::getIdade(const string &dataEleicaoStr) const
{
    DataUtils dataleicao = DataUtils::fromString(dataEleicaoStr);
    int result = this->dataNascimento.calculaPeriodoEmAnos(dataleicao);
    if(result < 0){
        throw invalid_argument( "Idade obtida foi negativa. Data de eleicao ou de nascimento do candidato estao incorretas.");
    }
    return result;
}