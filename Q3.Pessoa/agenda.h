#ifndef AGENDA_H
#define AGENDA_H

#define MAX_CONTATOS 100

#include <iostream>
#include <string>
#include "pessoa.h"

class Agenda {
	public :
/* armazena um novo contato */
		void insereContato ( string nome_ , int idade_ , float altura_ ) ;
/* remove um contato pelo nome e reorganiza a agenda */
		void removeContato ( string nome_ ) ;
/* retorna o indice para o contato ou -1 caso nao exista */
		int buscaContato ( string nome_ ) ;
/* lista todos os contatos ou apenas aqueles que
	iniciam por uma determinada letra */
		void listaContato ( char letra = ’ ’) ;
/* imprime os dados do contato armazenado na posicao i */
		void imprimeContato (int i) ;
	private :
		Pessoa m_contatos [MAX_CONTATOS];
		int m_total_contatos = 0 ;
};

#endif