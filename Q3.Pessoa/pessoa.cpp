#include "pessoa.h"

#include <iostream>
#include <string>

using namespace std;

Pessoa::Pessoa(string nome, int idade, double altura ){
	m_nome = nome ;
	m_idade = idade;
	m_altura = altura;
}

Pessoa::~Pessoa(){}

string Pessoa::getNome(){
	return m_nome;
}

void Pessoa::setNome(string nome){
	m_nome = nome;
}
 int Pessoa::getIdade(){
 	return m_idade;
 }

 void Pessoa::setIdade(int idade){
 	m_idade = idade;
 }

 double Pessoa::getAltura(){
 	return m_altura;
 }

void Pessoa::setAltura(double altura){
	m_altura = altura;
}

ostream& operator<< (ostream &o, Pessoa  *pessoa) {

	o <<"Nome: "<<pessoa->m_nome << endl << "Idade: " 
	<< pessoa->m_idade << endl << "Altura: " << pessoa->m_altura << endl;

	return o;

}	