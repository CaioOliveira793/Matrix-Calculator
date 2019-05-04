#pragma once

#include <iostream>
#include <vector>

class Matrix {
protected:
	//number of rows and columns in the matrix
	unsigned int countI, countJ;
	//matrix fetures:
	bool identity, square, row, column, null, diagonal; unsigned int order; double determ;
	//matrix[i][j]
	std::vector<std::vector<float>> matrix;
	
	void allocMatrix(std::vector<std::vector<float>> &matrix_, int i_, int j_);
	void reallocMatrix(int newI, int newJ);
	void printMatrix(std::ofstream &file);
	void printFetures(std::ofstream &file);
	int zerosInColumn(std::vector<std::vector<float>>& matrix_, int column_);
	int zerosInLine(std::vector<std::vector<float>>& matrix_, int line_);
	double determinant3x3(std::vector<std::vector<float>>& matrix_);
	double determinantLaPlace(std::vector<std::vector<float>>& matrix_, int order_);
	double determinantChio(std::vector<std::vector<float>> matrix_, int order_);
	double determinantGauss(std::vector<std::vector<float>> matrix_, int order_);

public:
	//the name of matrix
	std::string name;

	enum method {Gauss = 1, LaPlace, Chio};

	Matrix(std::string _name, unsigned int _i, unsigned int _j);
	~Matrix( );

	void populadorMatriz( );
	void populadorMatriz(float value, int positionX, int positionY);
	void checkMatrixFetures( );
	void printMatrix( );
	void printFetures( );
	void exportMatrixTxt( );
	double determinant(int method);
	Matrix transpose( );

	float getValue(int positionX, int positionY);
	int getI( );
	int getJ( );
	bool getIdentidade( );
	bool getQuadrada( );
	bool getLinha( );
	bool getColuna( );
	bool getNula( );
	bool getDiagonal( );
	int getOrdem( );
	double getDeterminant( );
};

//declaracoes de funcoes do arquivo functionsMatrix.cpp
Matrix soma(std::string newName, Matrix & m1, Matrix & m2);
Matrix soma(std::string newName, Matrix & m1, float & n2);
Matrix subtracao(std::string newName, Matrix & m1, Matrix & m2);
Matrix subtracao(std::string newName, Matrix & m1, float & n2);
Matrix multiplicacao(std::string newName, Matrix & m1, Matrix & m2);
Matrix multiplicacao(std::string newName, Matrix & m1, float & n2);
Matrix divisao(std::string newName, Matrix & m1, float & n2);
Matrix potencia(std::string newName, Matrix & m1, float & n2);