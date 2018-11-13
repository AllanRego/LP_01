#ifndef Pessoa_H
#define Pessoa_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa{
	private:
		string m_nome;
		int    m_idade;
		double m_altura;
	public:
		Pessoa(string nome, int idade, double altura);
		~Pessoa();

		string getNome();
		void setNome(string nome);

		int getIdade();
		void setIdade(int idade);

		double getAltura();
		void setAltura(double altura);

		friend ostream& operator<< (ostream &o, Pessoa  *pessoa);
};

#endif