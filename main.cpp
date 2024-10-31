#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <stdexcept>
#include "conta.h"

void retry(int& x) {
	while (!(std::cin >> x)){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "coloque um numero valido \n";
	}
}

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


	conta cont;

	if (!enc) {
		std::cout << "coloque sua idade \n";
		bool enc = encontrar(local, nome);
		retry(idade);
			if (!enc) {
				cont.arquivoA(local, nome, idade);
			}
	}
	else {
		std::cout << "o nome " << nome << " já existe \n";
	}


}