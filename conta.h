#pragma once
#include <string>

class conta {
public:
    void arquivoA(const std::string& local, const std::string& nome, int idade);
    void arquivoB(const std::string& local, std::string& nome, int& idade);
};
