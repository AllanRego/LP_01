#include "agenda.h"

using namespace std;

void Agenda::insereContato( string nome_ , int idade_ , float altura_){

	Pessoa p(nome_, idade_, altura_);
	contatos[total_contatos] = p; /**<sobrecarga do operador = */

	total_contatos++;
	cou<<"Contato Adicionado"<<endl;

}

void Agenda::removeContato (string nome_){

	int indice = buscaContato(nome_);
	int aux = 0;

	if(total_contatos == 0){
		
		cout<<"Não existe contatos na agenda"<<endl;
	} 
	else if(total_contatos == 1){

		total_contatos = 0;
		cout<<"Contato Removido"<<endl;
	}
	else if(indice != -1){
		
	}


}