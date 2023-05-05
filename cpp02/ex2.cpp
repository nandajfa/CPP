// Sobrecarga do operador =

#include <iostream>
#include <string.h>

using namespace std;

class Pessoa
{
private:
	char* nome;
	int id;
public:

	void inicializar(const char* novoNome, int novoID)
	{
		int tam = strlen(novoNome) + 1;
		nome = new char[tam];
		strcpy(nome, novoNome);
		id = novoID;
	}

	void destruir()
	{
		delete[] nome;
		nome = 0;
	}

	Pessoa(const char* novoNome, int novoID)
	{
		/*
		int tam = strlen(novoNome) + 1;
		nome = new char[tam];
		strcpy(nome, novoNome);
		id = novoID;
		*/
		inicializar(novoNome, novoID);
	}

	Pessoa(Pessoa& p){
		inicializar(p.nome, p.id);
	}

	virtual ~Pessoa(){
		destruir();
	}

	Pessoa& operator=(Pessoa& p)
	{
		if(this != &p) //enderaço do objeto passado diferente do objeto atual (cópia profunda)
		{
			destruir();

			inicializar(p.nome, p.id);
		}
		return *this;
	}

	const char* getNome()
	{
		return nome;
	}

	int getID()
	{
		return id;
	}

	void mudarNome(char l)
	{
		nome[0] = l;
	}
};

int main(int argc, char *argv[])
{
	Pessoa p1("marcos", 1), p2("pedro", 2);

	p1 = p2;

	p1.mudarNome('A');

	cout << "Nome: " << p1.getNome() << endl << "ID: " << p1.getID() << endl;
	cout << "Nome: " << p2.getNome() << endl << "ID: " << p2.getID() << endl;
	return 0;
}
