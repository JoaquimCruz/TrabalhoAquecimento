#include "JogoDaVida.hpp"
#include <iostream>
#include <fstream>

JogoDaVida :: JogoDaVida(){}

int** JogoDaVida :: LerMatrizdoArquivo(){
    int Linhas = 0, Colunas = 0;

    ifstream Arquivo;

    Arquivo.open("/home/joaquim/Documents/TrabalhoAquecimento/TrabalhoAquecimento/datasets/input.txt");

    if(!Arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
    }

    Arquivo >> Linhas >> Colunas;

    int **Mat = (int**) malloc(Linhas * sizeof(int*));

    for(int i = 0; i < Linhas; ++i){
        Mat[i] = (int*) malloc(Colunas * sizeof(int));
    }

    for(int i = 0; i < Linhas; ++i){
        for(int j = 0; j < Colunas; ++j){
            Arquivo >> Mat[i][j];
        }
    }

    Arquivo.close();

    return Mat;
}

void JogoDaVida :: ColocarMatrizNoArquivo(int **mat, int Linhas, int Colunas){

    ofstream Arquivo("/home/joaquim/Documents/TrabalhoAquecimento/TrabalhoAquecimento/datasets/geracoes.mps",ios::app);
    
    if(!Arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
    }

    Arquivo << Linhas << " " << Colunas << endl; 

    for (int i = 0; i < Linhas; ++i) {
        for (int j = 0; j < Colunas; ++j) {
            Arquivo << mat[i][j] << " ";
        }
        Arquivo << endl;
    }

    Arquivo.close();
}

int** JogoDaVida :: TransporMatrizEmOutra(int **mat,int Linhas, int Colunas){

    int **Mat = (int **) malloc(Linhas * sizeof(int*));

    for(int i = 0; i < Linhas; ++i){
        Mat[i] = (int *) malloc(Colunas * sizeof(int));
    }

    for(int i = 0; i < Linhas; ++i){
        for(int j = 0; j < Colunas; ++j){
            Mat[i][j] = mat[i][j];
        }
    }

    return Mat;
}

int** JogoDaVida :: VerificarMorte(int **mat, int Linhas, int Colunas){

    int ContadorVizinhos = 0;

    int **Mat = (int**) malloc(Linhas * sizeof(int*));

    for(int i = 0; i < Linhas; ++i){
        Mat[i] = (int*) malloc(Colunas * sizeof(int));
    }

    for(int i = 0; i < Linhas; ++i){
        for(int j = 0; j < Colunas; ++j){
            Mat[i][j] = mat[i][j];
        }
        cout << endl;
    }

    for(int i = 0; i < Linhas; ++i){
        for(int j = 0; j < Colunas; ++j){

            if(mat[i][j]== 1){
                ContadorVizinhos = 0;
                if(i > 0 && mat[i -1 ][j] == 1){ 
                    ContadorVizinhos++;
                }

                if(i < Linhas -1  && mat[i+1][j] == 1){
                    ContadorVizinhos++;
                }

                if(j > 0 && mat[i][j-1] == 1){
                    ContadorVizinhos++;
                }

                if(j < Colunas -1 && mat[i][j + 1] == 1){
                    ContadorVizinhos++;
                }

                if (i > 0 && j > 0 && mat[i - 1][j - 1] == 1){
                    ContadorVizinhos++;
                }

                if (i > 0 && j < Colunas - 1 && mat[i - 1][j + 1] == 1){
                    ContadorVizinhos++;
                }

                if (i < Linhas - 1 && j > 0 && mat[i + 1][j - 1] == 1){
                    ContadorVizinhos++;
                }

                if (i < Linhas - 1 && j < Colunas - 1 && mat[i + 1][j + 1] == 1){
                    ContadorVizinhos++;
                }

                if( ContadorVizinhos < 2 || ContadorVizinhos > 3){
                    Mat[i][j] = 0;
                }
            } 

            ContadorVizinhos = 0;
        }
    }

    return Mat;
}

int** JogoDaVida :: VerificarSeRevive( int **mat, int Linhas, int Colunas){

    int ContadorVizinhos = 0;

    int **Mat = (int**) malloc(Linhas * sizeof(int*));

    for(int i = 0; i < Linhas; ++i){
        Mat[i] = (int*) malloc(Colunas * sizeof(int));
    }

    for(int i = 0; i < Linhas; ++i){
        for(int j = 0; j < Colunas; ++j){
            Mat[i][j] = mat[i][j];
        }
    }

    
    for(int i = 0; i < Linhas; ++i){
        for(int j = 0; j < Colunas; ++j){

            if(Mat[i][j]== 0){
                ContadorVizinhos = 0;

                if(i > 0 && mat[i -1 ][j] == 1){ 
                    ContadorVizinhos++;
                }

                if(i < Linhas -1  && mat[i+1][j] == 1){
                    ContadorVizinhos++;
                }

                if(j > 0 && mat[i][j-1] == 1){
                    ContadorVizinhos++;
                }

                if(j < Colunas -1 && mat[i][j + 1] == 1){
                    ContadorVizinhos++;
                }

                if (i > 0 && j > 0 && mat[i - 1][j - 1] == 1){
                    ContadorVizinhos++;
                }

                if (i > 0 && j < Colunas - 1 && mat[i - 1][j + 1] == 1){
                    ContadorVizinhos++;
                }

                if (i < Linhas - 1 && j > 0 && mat[i + 1][j - 1] == 1){
                    ContadorVizinhos++;
                }

                if (i < Linhas - 1 && j < Colunas - 1 && mat[i + 1][j + 1] == 1){
                    ContadorVizinhos++;
                }

                if(ContadorVizinhos == 3){
                    Mat[i][j] = 1;
                }
                ContadorVizinhos = 0;

            }
        }
    }

    return Mat;
} 


void JogoDaVida :: PrintarMatriz(int **mat, int Linhas, int Colunas){
    
    cout << endl;
    
    for(int i = 0; i < Linhas; ++i){
        for(int j = 0; j < Colunas; ++j){
            cout << mat[i][j] << "|";
        }
        cout << endl;
    }
}

int JogoDaVida :: VerificarQuantidadeLinhas(){

    int Linhas = 0;

    ifstream Arquivo;

    Arquivo.open("/home/joaquim/Documents/TrabalhoAquecimento/TrabalhoAquecimento/datasets/input.txt");

    if(!Arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
    }

    Arquivo >> Linhas;

    Arquivo.close();

    return Linhas;
}

int JogoDaVida :: verificarQuantidadeColunas(){

    int Colunas = 0, aux = 0;

    ifstream Arquivo;

    Arquivo.open("/home/joaquim/Documents/TrabalhoAquecimento/TrabalhoAquecimento/datasets/input.txt");

    if(!Arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
    }

    Arquivo >> aux >> Colunas;

    Arquivo.close();

    return Colunas;
}

void JogoDaVida::VerificarMatrizNula(int **mat, int linhas, int colunas) {
    int aux = 0;

    for(int i = 0; i < linhas; ++i){
        for(int j = 0; j < colunas; ++j){
            if(mat[i][j] == 0){
                aux++;
            }
        }
    }

    if(aux == linhas * colunas){
        throw runtime_error("A matriz é nula.");
    }
}

void JogoDaVida :: VerificarMatriz(int **mat, int linhas, int colunas){

    for(int i = 0; i < linhas; ++i){
        for(int j = 0; j < colunas; ++j){
            if(mat[i][j] != 1 && mat[i][j] != 0){
                throw runtime_error("A matriz possui células com valor diferente de 0 ou 1!");
            }
        }
    }
}

JogoDaVida :: ~JogoDaVida(){}
