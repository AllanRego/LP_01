#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <chrono>

using namespace std;

typedef std::chrono::system_clock Clock;

class Data{
	private:
		int m_dia;
		int m_mes;
		int m_ano;
	
	public:
		Data(int dia_, int mes_, int ano_);
		Data();
		~Data();

		void somarDias(int quantidade);
		void somarMeses(int quantidade);
		void somarAnos(int quantidade);
		void proximoDia();
		bool validaData(int dia_, int mes_, int ano_);
		int qntDiasMes(int mes_, int ano_);

		friend ostream& operator<< (ostream &o, Data const Data);


};

#endif