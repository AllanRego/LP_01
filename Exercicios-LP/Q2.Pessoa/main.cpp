#include "pessoa.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	Pessoa novapessoa("Leleu", 26, 1.80);
	cout<< "Meliante de "<< &novapessoa <<endl;
	novapessoa.setNome("Miguel");
	cout<< "O individuo mudou "<< &novapessoa <<endl;
	novapessoa.setIdade(25);
	novapessoa.setAltura(1.82);
	cout<< "O dados foram atualizados:\n"<< &novapessoa <<endl;

	return 0;
}