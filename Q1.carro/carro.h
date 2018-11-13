#ifndef CARRO_H
#define CARRO_H

#include <iostream>
#include <string>

using namespace std;

class Carro{
	private:
		string m_modelo;
		int m_ano;
		double m_volTanque;
		double m_consumo;
		double m_qtdeCombustivel;
		double m_distanciaPercorrida;

	public:
		Carro(string modelo, int ano, double volTanque, double consumo);
		~Carro();

		string getModelo();
		int getAno();

		double getVolTanque();
		double getConsumo();
		double getDistanciaPercorrida();
		double getQtdeCombustivel();

		double getAutonomia();	
		void abastecer(double litros);
		void mover(double distancia);
		

};

#endif