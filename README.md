# Trabalho Aquecimento Disciplina AEDS: Manipulação de Matrizes

<div style="display: inline-block;">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Maintained%3F-yes-green.svg"/> 
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
<a href="https://github.com/mpiress/midpy/issues">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat"/>
<img align="center" height="20px" width="80px" src="https://badgen.net/badge/license/MIT/green"/>
</a> 
</div>

<p> </p>
<p> </p>

<p align="justify">
  
</p>
O código usa da manipulação de matrizes bidimensionais para simular o famoso jogo de celular: Jogo da vida. As matrizes são preenchidas por céulas vivas(com valor 1) ou por céulas mortas(com valor 0). De acordo com as regras do jogo, cada posição da matriz possue possibilidade de 3 ações: morrer, reviver, ou continuar viva. 
<p></p>
<p align="justify">
  1. Morrer: Uma célula que está viva(com valor 1) pode morrer por superpopulação ou por falta de vizinhos vivos. Para essa análise, são observadas as posições adjacentes à      célula, como seu vizinho a cima, a baixo, dos lados, e por fim, em suas 4 diagonais. Para uma célula morrer por falta de vizinhos, ela deve possuir menos de 2 vizinhos          vivos. Já para ela morrer por superpopulação, ela deve possuir mais de 3 vizinhos. 
<p></p>
<p align="justify">
2. Reviver: Uma célula que está morta(com valor 0) pode voltar a vida(com valor 1) caso ela tenha exatamente 3 viznhos. Para essa análise, são observadas as posições adjacentes à célula, como seu vizinho a cima, a baixo, dos lados, e por fim, em suas 4 diagonais.
<p></p>
<p align="justify">
3. Continuar vivo: Uma célula que está viva(com valor 1) continuará nesse estado caso possua 2 ou 3 vizinhos. Para essa análise, são observadas as posições adjacentes à célula, como seu vizinho a cima, a baixo, dos lados, e por fim, em suas 4 diagonais.
<h1 align="center"> Código </h1>
</p>
<p align="justify">
 O código é dividido em 3 arquivos: JogoDaVida.hpp, JogoDaVida.cpp e main.cpp. Ademais, utilizo 2 arquivos texto para armazenar as matrizes. O primeiro arquivo texto, com nome Input.txt, armazena a matriz quadrática original. O segundo arquivo texto, com nome geracoes.mps, armazena as matrizes modificadas a cada chamada de função para verificar a morte das células e para verificar se a célula revive.
</p>
<h1 align="justify"> JogoDaVida.hpp </h1>
</p>
<p align="justify"> 
</p>
O arquivo JogoDaVida.hpp define a classe JogoDaVida. Tal classe não possui atributos privados, porém possui os seguintes atributos públicos: 
</p>
1. void PrintarMatriz: Função que recebe como parâmetrosuma matriz passada por referência, a quantidade de linhas, e a quantidade de colunas. Possui como objetivo printar a matriz no terminal.
</p>
2. void ColocarMatrizNoArquivo: Função que recebe como parâmetros uma matriz passada por referência, a quanitidade de linhas, e a quantidade de colunas. Possui como objetivo colocar as matrizes modificadas dentro do arquivo geracoes.mps.
</p>
3. int** LerMatrizdoArquivo: A função não recebe parâmetros. Possui como objetivo ler a matriz original do arquivo e armazenar o seu conteúdo em uma matriz gerada no arquivo main.cpp.
</p>
4. int** TransporMatrizEmOutra: Função que recebe como parâmetros uma matriz passada por referência, a quanitidade de linhas, e a quantidade de colunas. Possui como objetivo transpor o conteúdo de uma matriz em outra, para fazer a atualização dos dados da matriz.
</p>
5. int** VerificarMorte: Função que recebe como parâmetros uma matriz passada por referência, a quanitidade de linhas, e a quantidade de colunas. Possui como objetivo verificar quais células da matriz irão morrer.
</p>
6. int** VerificarSeRevive: Função que recebe como parâmetros uma matriz passada por referência, a quanitidade de linhas, e a quantidade de colunas. Possui como objetivo verificar quais células mortas voltam a vida.
</p>
7.int VerificarQuantidadadeLinhas: Função não recebe parâmetros. Possui como objetivo verificar o número de linhas da matriz.
</p>
8.int VerificarQuantidadadeColunas: Função não recebe parâmetros. Possui como objetivo verificar o número de colunas da matriz.
</p>
9. JogoDaVida: Construtor vazio da classe, não recebe parâmetros.
</p>
10. ~JogoDaVida: Destrutor da classe, não recebe parâmetros.
<p align="center">
	<img src="imgs/bubble.png"/> 
</p>


<p align="justify">
Observe pela figura acima que a cada interação do algoritmo, apenas um elemento é colocado em ordem, o que exige muito trabalho durante o processo de composição da ordenação correta. Nesse processo, a cada interação o vetor é revisitado para os n - 1 elementos restantes, o que faz com que o método seja executado até que se tenha 2 elementos ainda não vizitados. 
</p>

# Compilação e Execução

O método Bubble Sort disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


