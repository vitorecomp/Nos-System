#include <iostream>
#include <fstream>
#include <string.h>
#include <list>
#include <stdlib.h>

using namespace std;

int compare(fstream *file1, fstream *file2)
{
	char string1[256], string2[256];
	int j; 
	j = 0;
	
	while(!file1->eof())
	{
		file1->getline(string1,256);
		file2->getline(string2,256);
		j++;
		if(strcmp(string1,string2) != 0)
		{
			cout << j;
			return 1;
		}
	}

	return 0;
}

int main()
{

	list<string> entradas;
	entradas.push_front("Entrada1.txt");
	entradas.push_front("Entrada2.txt");
	entradas.push_front("Entrada3.txt");
	entradas.push_front("Entrada4.txt");
	list<string> saidas;
	saidas.push_front("Saida1.txt");
	saidas.push_front("Saida2.txt");
	saidas.push_front("Saida3.txt");
	saidas.push_front("Saida4.txt");

	for (int i = 0; i < 4; i++)
	{
		string a = entradas.front();
		entradas.pop_front();
		string b = saidas.front();
		string d = "temp" + b;
		saidas.pop_front();
		string c = "./result < " + a + " >> " + d;  
		string c2 = "rm " + d;
		system(c2.c_str());
		system(c.c_str());
		entradas.push_back(d);
		saidas.push_back(b);
	}
	cout << "///////////////////////////////////////" << endl;
	cout << "testes" << endl;
	cout << "///////////////////////////////////////" << endl;

	cout << "///////////////////////////////////////" << endl;
	cout << "motor" << endl;
	cout << "///////////////////////////////////////" << endl;


	fstream motor(entradas.front().c_str());
	fstream motorout(saidas.front().c_str());
	entradas.pop_front();
	saidas.pop_front();

	if(compare(&motor, &motorout) == 0)
	{
		cout << "Teste realizado com sucesso" << endl;
	}else{
		cout << "Teste realizado com erro" << endl;
	}


	cout << "///////////////////////////////////////" << endl;
	cout << "direcao" << endl;
	cout << "///////////////////////////////////////" << endl;
	fstream direcao(entradas.front().c_str());
	fstream direcaoout(saidas.front().c_str());
	entradas.pop_front();
	saidas.pop_front();
	if(compare(&direcao, &direcaoout) == 0)
	{
		cout << "Teste realizado com sucesso" << endl;
	}else{
		cout << "Teste realizado com erro" << endl;
	}

	cout << "///////////////////////////////////////" << endl;
	cout << "integrado" << endl;
	cout << "///////////////////////////////////////" << endl;
	fstream integrado(entradas.front().c_str());
	fstream integradoout(saidas.front().c_str());
	entradas.pop_front();
	saidas.pop_front();

	if(compare(&integrado, &integradoout) == 0)
	{
		cout << "Teste realizado com sucesso" << endl;
	}else{
		cout << "Teste realizado com erro" << endl;
	}

	cout << "///////////////////////////////////////" << endl;
	cout << "stress" << endl;
	cout << "///////////////////////////////////////" << endl;

	fstream stress(entradas.front().c_str());
	fstream stressout(saidas.front().c_str());
	entradas.pop_front();
	saidas.pop_front();

	if(compare(&stress, &stressout) == 0)
	{
		cout << "Teste realizado com sucesso" << endl;
	}else{
		cout << "Teste realizado com erro" << endl;
	}
}
