#include "carro.h"

#include <iostream>
#include <string>

using namespace std;

Carro::Carro(string modelo, int ano, double volTanque, double consumo): m_modelo(modelo), m_ano(ano), m_volTanque(volTanque), m_consumo(consumo)
{
	cout<<"Foi crido um"<<m_modelo<<", ano "<< m_ano <<". Suporta "<<m_volTanque<<" litro e consome "<<m_consumo<<" Km/l." <<endl;
}

Carro::~Carro(){}

string Carro::getModelo(){
	return m_modelo;
}

int Carro::getAno(){
	return m_ano;
}

double Carro::getVolTanque(){
	return m_volTanque;
}

double Carro::getConsumo(){
	return m_consumo;
}

double Carro::getQtdeCombustivel(){
	return m_qtdeCombustivel;
}

double Carro::getDistanciaPercorrida(){
	return m_distanciaPercorrida;
}

double Carro::getAutonomia(){
	return (m_qtdeCombustivel - 1.0)*m_consumo;
}

void Carro::abastecer(double litros){
	m_qtdeCombustivel += litros;
}

void Carro::mover(double distancia){
	if(getQtdeCombustivel() <= 1 || getAutonomia() < distancia ){
		cout<< "combustível insuficiente para mover.  "<<endl;
		return;
	}
	double consumido = distancia / m_consumo;
	m_qtdeCombustivel -= consumido;
	m_distanciaPercorrida += distancia; 
}

