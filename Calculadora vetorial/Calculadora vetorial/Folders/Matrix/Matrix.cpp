#include "Matrix.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>

Matrix::Matrix(std::string name_, unsigned int i_, unsigned int j_): name(name_), countI(i_), countJ(j_) {
	this->allocMatrix(this->matrix, countI, countJ);
	identity = square = row = column = null = diagonal = false;
	order = 0;
	determ = 0;
}

Matrix::~Matrix( ) {
}

void Matrix::allocMatrix(std::vector<std::vector<float>> &matrix_, int i_, int j_) {
	matrix_.resize(i_);
	for (int x = 0; x < i_; x++) {
		matrix_[x].resize(j_);
	}
}

void Matrix::reallocMatrix(int newI, int newJ) {
	this->countI = newI;
	this->countJ = newJ;
	this->allocMatrix(this->matrix, this->countI, this->countJ);
}

//causes errors when the user does not enter a number
void Matrix::populadorMatriz( ) {
	if(!this->matrix.empty( )) {
		std::cout << "Ocupe a matriz com numeros naturais:\n\n";
		
		for(int x = 0; x < this->countI; x++) {
			for(int y = 0; y < this->countJ; y++) {
				std::cout << x << ", " << y << " = ";
				std::cin >> this->matrix[x][y];
			}
		}
		std::cout << "\n\n";
		this->checkMatrixFetures( );
	}
}

void Matrix::populadorMatriz(float value, int positionX, int positionY) {
	this->matrix[positionX][positionY] = value;
}

void Matrix::checkMatrixFetures( ) {
	this->row = (this->countI == 1) ? true : false;
	this->column = (this->countJ == 1) ? true : false;
	this->square = (this->countI == this->countJ) ? true : false;
	this->order = (this->square) ? this->countI : false;

	//define as true for verifications change them if necessary
	this->diagonal = this->identity = this->null = true;
	if (!this->square) {
		this->diagonal = this->identity = false;
	}
	//runs all matrix
	for (int x = 0; x < this->countI; x++) {
		for (int y = 0; y < this->countJ; y++) {
			if ((x != y) and (matrix[x][y] != 0)) {
				//outside the main diagonal and different to 0
				this->diagonal = this->identity = this->null = false;
				break;
			} else {
				//inside the main diagonal
				if (matrix[x][y] != 1) this->identity = false;
				if (matrix[x][y] != 0) this->null = false;
			}
		}
	}
	this->diagonal = (this->null) ? false : this->diagonal;
}

void Matrix::printMatrix( ) {
	if(!this->matrix.empty( )){
		std::cout << "Visualizacao da matriz:\n\n";

		//column indicators
		for (int colInd = 0; colInd < this->countJ; colInd++) std::cout << "\t" << colInd;

		std::cout << "\n\n\n";
		for(int rowInd = 0; rowInd < this->countI; rowInd++) {
			//row indicators
			std::cout << rowInd << "\t";

			for(int y = 0; y < this->countJ; y++) {
				std::cout << this->matrix[rowInd][y] << "\t";
			}
			std::cout << "\n\n\n";
		}
	}
}

void Matrix::printMatrix(std::ofstream &file) {
	file << "Visualizacao da matriz:\n\n";

	//column indicators
	for (int colInd = 1; colInd <= this->countJ; colInd++) file << "\t" << colInd;

	file << "\n\n\n";
	for (int rowInd = 0; rowInd < this->countI; rowInd++) {
		//row indicators
		file << rowInd << "\t";

		for (int y = 0; y < this->countJ; y++) {
			file << this->matrix[rowInd][y] << "\t";
		}
		file << "\n\n\n";
	}
}

void Matrix::printFetures( ) {
	std::cout << "Caracteristicas da matriz:\n\n"
		<< "Quantidade de elementos: " << this->countI << " * "
		<< this->countJ << " = " << (this->countI * this->countJ)
		<< "\n" << "Matriz linha...........: " << this->row << "\n"
		<< "Matriz coluna..........: " << this->column << "\n"
		<< "Matriz quadrada........: " << this->square << "\n"
		<< "Ordem da matriz........: " << this->order << "\n"
		<< "Determinante da matriz.: " << this->determ << "\n"
		<< "Matriz diagonal........: " << this->diagonal << "\n"
		<< "Matriz identidade......: " << this->identity << "\n"
		<< "Matriz nula............: " << this->null << "\n\n\n";
}

void Matrix::printFetures(std::ofstream &file) {
	file << "Caracteristicas da matriz:\n\n"
		<< "Quantidade de elementos: " << this->countI << " * "
		<< this->countJ << " = " << (this->countI * this->countJ)
		<< "\n" << "Matriz linha...........: " << this->row << "\n"
		<< "Matriz coluna..........: " << this->column << "\n"
		<< "Matriz quadrada........: " << this->square << "\n"
		<< "Ordem da matriz........: " << this->order << "\n"
		<< "Determinante da matriz.: " << this->determ << "\n"
		<< "Matriz diagonal........: " << this->diagonal << "\n"
		<< "Matriz identidade......: " << this->identity << "\n"
		<< "Matriz nula............: " << this->null << "\n\n";
}

void Matrix::exportMatrixTxt( ) {
	std::ofstream file;
	file.open("despejo_de_matriz.txt", std::ios::app);

	file << "Nome da matriz: " << this->name << "\n\n";
	this->printMatrix(file);
	this->printFetures(file);
	file << "===================================\n\n";

	file.close( );
}

int Matrix::zerosInColumn(std::vector<std::vector<float>>& matrix_, int column_) {
	int zeroCount = 0;

	for (int i = 0; i < matrix_.size( ); i++) {
		if (matrix_[i][column_] == 0) zeroCount++;
	}
	return zeroCount;
}

int Matrix::zerosInLine(std::vector<std::vector<float>>& matrix_, int line_) {
	int zeroCount = 0;

	for (int i = 0; i < matrix_[line_].size( ); i++) {
		if (matrix_[line_][i] == 0) zeroCount++;
	}
	return zeroCount;
}

double Matrix::determinant(int method) {
	//checks if the matrix has been filled
	if (this->matrix.empty( )) return this->determ;

	if (this->order == 0) return this->determ;	//the matrix doesn't have determinant
	else if (this->order == 1) this->determ = this->matrix[0][0];
	else if (method == Gauss) this->determ = this->determinantGauss(this->matrix, this->order);
	else if (method == LaPlace) this->determ = this->determinantLaPlace(this->matrix, this->order);
	else if (method == Chio) this->determ = this->determinantChio(this->matrix, this->order);
}

double Matrix::determinant3x3(std::vector<std::vector<float>>& matrix_) {

	double det = (matrix_[1][0] * matrix_[2][1] - matrix_[1][1] * matrix_[2][0]) * matrix_[0][2];
	det += (matrix_[1][2] * matrix_[2][0] - matrix_[1][0] * matrix_[2][2]) * matrix_[0][1];
	det += (matrix_[1][1] * matrix_[2][2] - matrix_[1][2] * matrix_[2][1]) * matrix_[0][0];

	return det;
}

double Matrix::determinantLaPlace(std::vector<std::vector<float>>& matrix_, int order_) {
	if (order_ == 3) return this->determinant3x3(matrix_);

	double det = 0;
	int orderCofactor = order_ - 1;

	//scrolls through the elements of the last column in ascending order
	for (int lin = 0; lin < order_; lin++) {
		if (matrix_[lin][orderCofactor] == 0) continue;
		
		std::vector<std::vector<float>> cofactor = matrix_;
		//erase unused elements
		cofactor.erase(cofactor.begin( ) + lin);
		for (int i = 0; i < orderCofactor; i++) {
			cofactor[i].erase(cofactor[i].end( ) - 1);
		}

		det += (((lin + orderCofactor) % 2 == 0) ? 1 : -1) * matrix_[lin][orderCofactor]
			* this->determinantLaPlace(cofactor, orderCofactor);
	}
	return det;
}

double Matrix::determinantChio(std::vector<std::vector<float>> matrix_, int order_) {
	if (order_ == 1) return matrix_[0][0];

	double det = 0;
	float divider = 1;
	int orderCofactor = order_ - 1;
	bool changeSing = false;
	std::vector<std::vector<float>> cofactor(orderCofactor, std::vector<float>(orderCofactor));

	if (matrix_[0][0] != 1 and matrix_[0][0] != 0) {
		divider = matrix_[0][0];
		for (int i = 0; i < order_; i++) {
			matrix_[0][i] /= divider;
		}
	} else if (matrix_[0][0] == 0) {
		//change the first element to 1 permultando com a linha x
		int x; float multiplier = 0;
		for (x = 1; x < order_ and matrix_[x][0] != 0; x++) {
			multiplier = -(matrix_[0][0] - 1) / matrix_[x][0];
			break;
		}
		if (x == order_ - 1) return 0.0;	//the first column has all elements iqual to 0
		for (int i = 0; i < order_; i++) {
			matrix_[0][i] += multiplier * matrix_[x][i];
		}
	}
	//reducao da matriz pelo metodo de Chio
	for (int y = 1; y < order_; y++) {
		for (int x = 1; x < order_; x++) {
			cofactor[x - 1][y - 1] = matrix_[x][y] - matrix_[x][0] * matrix_[0][y];
		}
	}

	det = divider * this->determinantChio(cofactor, orderCofactor);
	if (changeSing) det = -det;	//verifica se e necessario trocar o sinal
	return det;
}

double Matrix::determinantGauss(std::vector<std::vector<float>> matrix_, int order_) {
	float multiplier;
	double det = 1;
	int zeroCount = 0;
	bool changeSing = false;

	for (int x = 0; x < order_ - 1; x++) {
		for (int y = x + 1; y < order_; y++) {
			if (matrix_[x][x] == 0) {	//impede a divisao por 0
				auto vectorTemp = matrix_[x];
				matrix_[x] = matrix_[x + 1];
				matrix_[x + 1] = vectorTemp;
				changeSing = !changeSing;
			}
			multiplier = -matrix_[y][x] / matrix_[x][x];
			
			for (int i = x; i < order_; i++) {
				matrix_[y][i] += multiplier * matrix_[x][i];
				if (matrix_[y][i] == 0) zeroCount++;
			}
			if (zeroCount == order_ - x) return 0.0;
			zeroCount = 0;
		}
	}
	for (int i = 0; i < order_; i++) det *= matrix_[i][i];	//calcula o resultado
	if (changeSing) det = -det;	//verifica se e necessario trocar o sinal
	return det;
}

Matrix Matrix::transpose( ) {
	Matrix result(this->name + " transposta", this->countJ, this->countI);

	for (int y = 0; y < result.getJ( ); y++) {
		for (int x = 0; x < result.getI( ); x++) {
			result.populadorMatriz(this->matrix[y][x], x, y);
		}
	}
	result.checkMatrixFetures( );
	return result;
}

float Matrix::getValue(int positionX, int positionY) {
	return this->matrix[positionX][positionY];
}

int Matrix::getI( ) {
	return this->countI;
}

int Matrix::getJ( ) {
	return this->countJ;
}

bool Matrix::getIdentidade( ) {
	return this->identity;
}

bool Matrix::getQuadrada( ) {
	return this->square;
}

bool Matrix::getLinha( ) {
	return this->row;
}

bool Matrix::getColuna( ) {
	return this->column;
}

bool Matrix::getNula( ) {
	return this->null;
}

bool Matrix::getDiagonal( ) {
	return this->diagonal;
}

int Matrix::getOrdem( ) {
	return this->order;
}

double Matrix::getDeterminant( ) {
	return this->determ;
}