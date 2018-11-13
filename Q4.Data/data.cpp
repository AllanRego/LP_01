#include "data.h"

#include <iostream>
#include <chrono>

using namespace std;


Data::Data(){
	auto now = Clock::now();
    time_t now_c = Clock::to_time_t(now);
    struct tm *parts = localtime(&now_c);

    m_ano = 1900 +  parts->tm_year;  // tem que somar +1900 para ser o ano atual;
    m_mes = parts->tm_mon + 1; 		// para iniciar do mes 1;
    m_dia = parts->tm_mday;
}

Data::Data(int dia_, int mes_, int ano_){
	if(validaData(dia_, mes_, ano_)){
		m_dia = dia_;
		m_mes = mes_;
		m_ano = ano_;
	}
	else {
		cout<<"Data Invalida"<<endl;
	}

}
//Samo de Anos a Data;
void Data::somarAnos(int quantidade){
	int totalDias = 0;
	
	for(int aux=1; quantidade > 0; quantidade--, aux++){
		
		totalDias += 365;

		if(validaData(29,2,m_ano + aux)){
			totalDias++; //o ano tem um dia a mais(bissesto); 
		} 
	}
	somarDias(totalDias);
}
void Data::somarMeses(int quantidade){
	somarAnos(quantidade/12);
	
	int addMes = quantidade % 12;

	m_mes += addMes;

	if(m_mes > 12){//se colocar mais de 12 meses, irar add o ano mais os meses que sobra;
		m_ano++;
		m_mes = m_mes-12;
	}

	if(m_dia==29 && m_mes ==2){//validar 29 de fevereiro;
		if(!validaData(m_dia,m_mes, m_ano)){
			m_dia = 1;
			m_mes = 3;
		}
	}
}

void Data::somarDias(int quantidade){

	while(quantidade > 0){
		
		int diasMes = qntDiasMes(m_mes, m_ano);

		for(;m_dia < diasMes && quantidade >0;){
			m_dia++;
			quantidade--;

		}
		if(m_dia >= diasMes && quantidade > 0){
			m_dia = 1;
			m_mes ++;
			quantidade--; 
		}
		if(m_mes > 12){
			m_ano++;
			m_mes = 1;
		}

	}
}

void Data::proximoDia(){
	somarDias(1);
}

int Data::qntDiasMes(int mes_, int ano_){
	int dias = 0;

	if(mes_ == 4 || mes_ == 6 || mes_ == 9|| mes_ == 11){//meses com 30 dias;
		dias = 30;
	}
	else if( mes_ == 2){// conferindo de fevereiro é bissesto
		bool bissesto = ( ano_ % 4 == 0 && ano_ % 100 != 0) || (ano_ % 400 == 0);

		if(bissesto == 0){
			dias = 28;
		}
			else { 
				dias = 29;
			}

	}
	else{ 
			dias = 31;
	}
	return dias;
}

//validaData evita data: 29/02/2018;

bool Data::validaData(int dia_, int mes_, int ano_){

	if(dia_ < 28 || dia_>31 || mes_ < 0 || mes_ > 12 || ano_ < 0){
		return false;
	}
	else{
		
		int diasMes = qntDiasMes(mes_, ano_);
	    
	    if( dia_ > diasMes){
	    	return false;
	    }
	}
	return true;
}

ostream& operator<< (ostream &o, Data const data){

	o << "Data: " << data.m_dia << "|" <<data.m_mes << "|" <<data.m_ano;
	return o;
}

Data::~Data(){}
