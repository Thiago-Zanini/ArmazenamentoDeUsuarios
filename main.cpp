#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include "conta.h"

//força ao usuario colocar um numero sem ser letras
void retry(int& x) {
	while (!(std::cin >> x)){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "coloque um numero valido \n";
	}
}

	//verificar para ver se existi o nome no mine.txt
	bool encontrar(const std::string& local, std::string& nome) {
		std::ifstream armazenar2(local);
		std::string procura;
		int idade = 0;
	
		if (!armazenar2.is_open()) {
			std::cout << "nao foi possivel abrir o arquivo \n";
			return false;
		}

		while (armazenar2 >> procura >> idade) {
			if (procura == nome) {
				return true;
			}	
		}
		return false;
	}

int main() {

	const std::string local = "mine.txt";
	std::string nome;
	int idade = 0;

	std::cout << "coloque o nome q voce quer armazenar \n";
	std::getline(std::cin, nome);

	bool enc = encontrar(local, nome);

	//cria uma instancia
	conta cont;

	//se enc for verdadeiro executa o if
	if (!enc) {
		std::cout << "coloque sua idade \n";
		bool enc = encontrar(local, nome);
		retry(idade);
		cont.arquivoA(local, nome, idade);
	}
	else {
		std::cout << "o nome " << nome << " já existe \n";
	}


}