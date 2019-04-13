#pragma once

#include <iostream>

class Matrix {
protected:
	//quantidade de linhas e colunas da matriz
	int i, j;
	//caracteristicas da matriz
	bool identidade, quadrada, linha, coluna, nula, diagonal; int ordem; double determ;
	//matriz[n][n]
	float **matrix = nullptr;

	float **allocMatrix(float **matrix_, int i_, int j_);	//aloca a matriz conforme o numero de linhas e colunas
	void freeMatrix(float **matrix_, int i_);	//desaloca toda memoria da matriz
	void reallocMatrix(int newI, int newJ);	//realoca a matriz conforme o numero de linhas e colunas
	void printMatrix(std::ofstream &file);	//mostra ao usuario toda a matriz
	void printFetures(std::ofstream &file);	//exporta todas as caracteristicas da matriz
	double determinant(float **matrix_, int ordem);	//seleciona o melhor modo para calcular a determinante
	double determinant3x3(float **matrix_);	//calcula a determinante da matriz 3x3
	double determinantLaPlace(float **matrix, int ordem);	//calcula determinante pelo metodo de La Place
	double determinantChio(float **matrix, int ordem);	//calcula determinante pelo metodo de La Place

public:
	//nome da matriz
	std::string name;

	Matrix(std::string _name, int _i, int _j);	//metodo construtor
	~Matrix( );	//metodo destrutor

	void populadorMatriz( );	//preenche toda matriz com inputs do usuario
	void populadorMatriz(float value, int x, int y);	//preenche um elemento da matriz
	void checkMatrixFetures( );	//verifica e armazena qual e o tipo de matriz
	void printMatrix( );	//mostra ao usuario toda a matriz
	void printFetures( );	//mostra ao usuario todas as caracteristicas da matriz
	void exportMatrixTxt( );	//exporta a matriz para um arquivo.txt
	double determinant( );	//calcula a determinante da matriz
	Matrix transpose( );	//cria uma matriz transposta

	float getValue(int x, int y);	//retorna o valor correspondente da matriz
	int getI( );	//retorna o numero de linhas
	int getJ( );	//retorna o numero de colunas
	bool getIdentidade( );	//retorna se e uma matriz identidade
	bool getQuadrada( );	//retorna se e uma matriz quadrada
	bool getLinha( );		//retorna se e uma matriz linha
	bool getColuna( );		//retorna se e uma matriz coluna
	bool getNula( );		//retorna se e uma matriz nula
	bool getDiagonal( );	//retorna se e uma matriz diagonal
	int getOrdem( );		//retorna a ordem da matriz
	double getDeterminant( );	//retorna a determinante da matriz
};

//declaracoes das funcoes do arquivo functionsMatrix.cpp
Matrix soma(std::string newName, Matrix & m1, Matrix & m2);
Matrix soma(std::string newName, Matrix & m1, float & n2);
Matrix subtracao(std::string newName, Matrix & m1, Matrix & m2);
Matrix subtracao(std::string newName, Matrix & m1, float & n2);
Matrix multiplicacao(std::string newName, Matrix & m1, Matrix & m2);
Matrix multiplicacao(std::string newName, Matrix & m1, float & n2);
Matrix divisao(std::string newName, Matrix & m1, float & n2);
Matrix potencia(std::string newName, Matrix & m1, float & n2);