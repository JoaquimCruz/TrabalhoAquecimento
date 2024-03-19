#ifndef JOGODAVIDA_HPP
#define JOGODAVIDA_HPP

using namespace std;

class JogoDaVida{

public:
    JogoDaVida();
    void PrintarMatriz(int **mat, int linhas, int colunas);
    void ColocarMatrizNoArquivo(int **mat, int Linhas, int Colunas); 
    int** LerMatrizdoArquivo(); 
    int** TransporMatrizEmOutra(int **mat, int Linhas, int Colunas); 
    int** VerificarMorte(int **mat, int Linhas, int Colunas);
    int VerificarVida(int **mat, int Linhas, int Colunas);
    int** VerificarSeRevive(int **mat, int Linhas, int Colunas); 
    int VerificarQuantidadeLinhas(); 
    int verificarQuantidadeColunas();
    ~JogoDaVida();
};

#endif