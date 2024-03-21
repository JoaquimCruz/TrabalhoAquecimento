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
</p>
<p align="center">
<img src="https://github.com/JoaquimCruz/TrabalhoAquecimento/assets/162636656/97f853ea-9322-4443-9a16-c18a71010c01"/> 
</p>
<h1 align="justify"> JogoDaVida.cpp </h1>
</p>
<p align="justify"> 
</p>
O arquivo JogoDaVida.cpp contém as implementações das funções definidas no arquivo JogoDaVida.hpp.
</p>
Assim, para a implementação dessas funções, foram utlizadas a biblioteca iostream - Biblioteca que declara objetos que controlam a leitura e a gravação nos fluxos padrão - e a biblioteca fstream - Biblioteca que define várias classes que dão suporte a operações de iostreams em sequências armazenadas em arquivos externos. As principais funções implementadas são: LerMatrizdoArquivo, VerificarMorte, VerificarSeRevive e ColocarMatrizNoArquivo. 
</p>
<h1 align="justify"> Função para leitura de matriz do arquivo</h1>
<p align="justify">
</p>
A função para leitura da  matriz original do arquivo utiliza de recursos da biblioteca fstream para fazer a leitura da matriz do arquivo. Primeiramente, com o arquivo já aberto, o código lê as primeiras duas informações da primeira linha do arquivo, e armazena essas duas informações nas variáveis Linhas e Colunas, respectivamente. Após esse processo, uma matriz é alocada dinâmicamente para receber o conteúdo que contém no arquivo txt. Por fim, ultilizando 2 loops de repetição for aninhados, o conteúdo do arquivo é colocado em sua respectiva célula da matriz. 
</p>
<p align="center">
<img src="https://github.com/JoaquimCruz/TrabalhoAquecimento/assets/162636656/8db5d8f4-402c-40c7-b54a-908b335d452d"/> 
</p>
<h1 align="justify"> Função para Verificar Célula Morta</h1>
<p align="justify">
</p>
A função para verificar a existência de células mortas foi implementada para as modificações na matriz serem feitas em tempo real. Desse modo, para percorrer a matriz, foram utilizadas 2 laços de repetição for aninhadas. Para fazer a verificação se a célula ficaria viva, foi criada uma variável auxiliar (ContadorVizinhos), que era incrementada sempre que 1 dos 8 vizinhos era uma célula viva(com valor 1). Para fazer isso, foram utilizadas várias estruturas condicionais if que conferem o valor das células vizinhas. Após essa verificação, a ultima estrutura condicional verifica o valor da variável auxiliar, se ela estiver com o valor menor do que 2, ou maior do que 3, a célula analisada morre. Nessa implementação, após a célula morrer, ela já é modificada antes do laço de repetição ir para a próxima célula da matriz, ou seja, as modificações passadas do loop afetaram as modificações nas posiçoes a serem analisadas. 
</p>
<p align="center">
<img src="https://github.com/JoaquimCruz/TrabalhoAquecimento/assets/162636656/b07e780c-13e7-4168-a4df-429565c2cece"/> 
</p>
<h1 align="justify"> Função para Verificar Célula Revivente</h1>
</p>
A função para verificar se alguma célula morta voltará a vida verifica se alguma das células com valor 0 atende as condições para reviver. Desse modo, para percorrer a matriz, foram utilizadas 2 laços de repetição for aninhadas. Para fazer a verificação se a célula ficaria viva, foi criada uma variável auxiliar (ContadorVizinhos), que era incrementada sempre que 1 dos 8 vizinhos era uma célula viva(com valor 1). Para fazer isso, foram utilizadas várias estruturas condicionais if que conferem o valor das células vizinhas. Após essa verificação, a ultima estrutura condicional verifica o valor da variável auxiliar, se ela estiver com o valor igual a 3, a célula analisada volta a vida(com valor 1).
</p>
<p align="center">
<img src="https://github.com/JoaquimCruz/TrabalhoAquecimento/assets/162636656/b07e780c-13e7-4168-a4df-429565c2cece"/> 
</p>
<h1 align="justify"> Função para Colocar as Matrizes no Arquivo</h1>
</p>







# Compilação e Execução

O método Bubble Sort disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


