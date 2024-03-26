#include "JogoDaVida.hpp"
#include <iostream>


int main(){

    int Quantidade = 0, linhas = 0, Colunas = 0;
    int **mat;
    JogoDaVida aux;

    cout << "Digite a quantidade de vezes em que o programa será rodado: " << endl;
    cin >> Quantidade;

    linhas = aux.VerificarQuantidadeLinhas();
    Colunas = aux.verificarQuantidadeColunas();

    mat = (int**) malloc(linhas * sizeof(int*));
    
    for(int i = 0; i < linhas; ++i){
        mat[i] = (int *) malloc(Colunas * sizeof(int));
    }
    
    mat = aux.LerMatrizdoArquivo();
    aux.VerificarMatriz(mat, linhas, Colunas);
    aux.PrintarMatriz(mat, linhas, Colunas);
    aux.ColocarMatrizNoArquivo(mat, linhas, Colunas);

    do{
        
        mat = aux.VerificarMorte(mat, linhas, Colunas);

        mat = aux.TransporMatrizEmOutra(mat, linhas, Colunas);
        
        cout << endl;
        mat = aux.VerificarSeRevive(mat,linhas, Colunas);

        aux.ColocarMatrizNoArquivo(mat, linhas, Colunas);
        
        aux.PrintarMatriz(mat, linhas, Colunas);

        aux.VerificarMatrizNula(mat, linhas, Colunas);

        Quantidade--;
        
    }while(Quantidade != 0);

    return 0;

}