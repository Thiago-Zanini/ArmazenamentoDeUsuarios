#include "conta.h"
#include <iostream>
#include <fstream>
#include <vector>

void conta::arquivoA(const std::string& local, const std::string& nome, int idade) {
	std::ofstream armazenar(local,std::ios::out | std::ios::app);
	if (armazenar.is_open()) {
		armazenar << nome << " " << idade << "\n";
		std::cout << "arquivo salvo com sucesso \n";
	}else{
		std::cout << "nao foi possivel abrir o arquivo \n";
	}
}

void conta::arquivoB(const std::string& local, std::string& nome, int& idade) {
	std::ifstream armazenar1(local);
	if (armazenar1.is_open()) {
		armazenar1 >> nome >> idade;
	}else{
		std::cout << "nao foi possivel abrir o arquivo \n";
	}
}