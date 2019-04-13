#include "Matrix.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

Matrix::Matrix(std::string name_, int i_, int j_): name(name_), i(i_), j(j_) {
	this->matrix = this->allocMatrix(this->matrix, this->i, this->j);
}

Matrix::~Matrix( ) {
}

float **Matrix::allocMatrix(float **matrix_, int i_, int j_) {
	//verifica se o ponteiro esta vazio
	if (matrix_ != nullptr) return matrix_;

	//aloca dianamicamente a memoria, criando um vetor
	matrix_ = (float**)malloc(i_ * sizeof(float*));

	//aloca dinamicamente cada elemento do vetor criando uma matriz
	for (int it = 0; it < i_; it++) {
		matrix_[it] = (float*)malloc(j_ * sizeof(float));
	}
	return matrix_;
}

void Matrix::freeMatrix(float **matrix_, int i_) {
	for (int it = 0; it < i_; it++) {
		free(matrix_[it]);
	}
	free(matrix_);
}

void Matrix::reallocMatrix(int newI, int newJ) {
	this->freeMatrix(this->matrix, this->i);
	this->i = newI;
	this->j = newJ;
	this->matrix = this->allocMatrix(this->matrix, this->i, this->j);
}

//causa erros quando o usuario nao insere um numero
void Matrix::populadorMatriz( ) {
	//verifica se a matriz foi alocada
	if(this->matrix != nullptr) {
		std::cout << "Ocupe a matriz com numeros naturais:\n\n";
		
		for(int x = 0; x < this->i; x++) {
			for(int y = 0; y < this->j; y++) {
				//solicita numeros ao usuario
				std::cout << x << ", " << y << " = ";
				std::cin >> this->matrix[x][y];
			}
		}
		std::cout << "\n\n";
		this->checkMatrixFetures( );
	}
}

void Matrix::populadorMatriz(float value, int x, int y) {
	this->matrix[x][y] = value;
}

void Matrix::checkMatrixFetures( ) {
	this->linha = (this->i == 1) ? true : false;
	this->coluna = (this->j == 1) ? true : false;
	this->quadrada = (this->i == this->j) ? true : false;
	this->ordem = (this->quadrada) ? this->i : false;

	//define como verdade para as verificacoes mudarem se necessario
	this->diagonal = this->identidade = this->nula = true;
	if (!this->quadrada) {
		this->diagonal = this->identidade = false;
	}
	//percorre toda a matriz
	for (int x = 0; x < this->i; x++) {
		for (int y = 0; y < this->j; y++) {
			if ((x != y) and (matrix[x][y] != 0)) {
				//fora da diagonal principal e diferente de 0
				this->diagonal = this->identidade = this->nula = false;
				break;
			} else {
				//dentro da diagonal pricipal:
				if (matrix[x][y] != 1) this->identidade = false;
				if (matrix[x][y] != 0) this->nula = false;
			}
		}
	}
	this->diagonal = (this->nula) ? false : this->diagonal;
}

void Matrix::printMatrix( ) {
	//verifica se a matriz foi alocada
	if(this->matrix != nullptr){
		std::cout << "Visualizacao da matriz:\n\n";

		//indicadores de coluna
		for(int it = 1; it <= this->j; it++) {
			std::cout << "	" << it;
		}

		std::cout << "\n\n\n";
		int tab = 1;
		for(int x = 0; x < this->i; x++, tab++) {
			//indicadores de linha
			std::cout << tab << "	";

			for(int y = 0; y < this->j; y++) {
				//impressao da matriz
				std::cout << this->matrix[x][y] << "	";
			}
			std::cout << "\n\n\n";
		}
	}
}

void Matrix::printMatrix(std::ofstream &file) {
	file << "Visualizacao da matriz:\n\n";

	//indicadores de coluna
	for (int it = 1; it <= this->j; it++) {
		file << "	" << it;
	}

	file << "\n\n\n";
	int tab = 1;
	for (int x = 0; x < this->i; x++, tab++) {
		//indicadores de linha
		file << tab << "	";

		for (int y = 0; y < this->j; y++) {
			//impressao da matriz
			file << this->matrix[x][y] << "	";
		}
		file << "\n\n\n";
	}
}

void Matrix::printFetures( ) {
	std::cout << "Caracteristicas da matriz:\n\n"
		<< "Quantidade de linhas...: " << this->i << "\n"
		<< "Quantidade de colunas..: " << this->j << "\n"
		<< "Quantidade de elementos: " << this->i << " * "
		<< this->j << " = " << (this->i * this->j) << "\n"
		<< "Matriz linha...........: " << this->linha << "\n"
		<< "Matriz coluna..........: " << this->coluna << "\n"
		<< "Matriz quadrada........: " << this->quadrada << "\n"
		<< "Ordem da matriz........: " << this->ordem << "\n"
		<< "Determinante da matriz.: " << this->determ << "\n"
		<< "Matriz diagonal........: " << this->diagonal << "\n"
		<< "Matriz identidade......: " << this->identidade << "\n"
		<< "Matriz nula............: " << this->nula << "\n\n\n";
}

void Matrix::printFetures(std::ofstream &file) {
	file << "Caracteristicas da matriz:\n\n"
		<< "Quantidade de linhas...: " << this->i << "\n"
		<< "Quantidade de colunas..: " << this->j << "\n"
		<< "Quantidade de elementos: " << this->i << " * "
		<< this->j << " = " << (this->i * this->j) << "\n"
		<< "Matriz linha...........: " << this->linha << "\n"
		<< "Matriz coluna..........: " << this->coluna << "\n"
		<< "Matriz quadrada........: " << this->quadrada << "\n"
		<< "Ordem da matriz........: " << this->ordem << "\n"
		<< "Determinante da matriz.: " << this->determ << "\n"
		<< "Matriz diagonal........: " << this->diagonal << "\n"
		<< "Matriz identidade......: " << this->identidade << "\n"
		<< "Matriz nula............: " << this->nula << "\n\n";
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

double Matrix::determinant( ) {
	//verifica se a matriz foi alocada
	if (this->matrix == nullptr) return this->determ;

	if (this->ordem > 3)
		this->determ = this->determinant(this->matrix, this->ordem);
	else if (this->ordem == 3)
		this->determ = this->determinant3x3(this->matrix);
	else if (this->ordem == 2)
		this->determ = (this->matrix[0][0] * this->matrix[1][1]) - (this->matrix[0][1] * this->matrix[1][0]);
	else if (this->ordem == 1)
		this->determ = this->matrix[0][0];

	//se todos derem falso nao e possivel calcular a determinante
	return this->determ;
}

double Matrix::determinant(float **matrix_, int ordem_) {
	double det;
	
	if (ordem_ > 3)
		det = (matrix_[0][0] == 1) ? this->determinantChio(matrix_, ordem_) : this->determinantLaPlace(matrix_, ordem_);
	else det = this->determinant3x3(matrix_);

	return det;
}

double Matrix::determinant3x3(float **matrix_) {

	double det = (matrix_[1][1] * matrix_[2][2] - matrix_[1][2] * matrix_[2][1]) * matrix_[0][0];
		  det += (matrix_[1][2] * matrix_[2][0] - matrix_[1][0] * matrix_[2][2]) * matrix_[0][1];
		  det += (matrix_[1][0] * matrix_[2][1] - matrix_[1][1] * matrix_[2][0]) * matrix_[0][2];

	return det;
}

double Matrix::determinantLaPlace(float **matrix_, int ordem_) {
	double det = 0;
	int ordemCofator = ordem_ - 1;
	//percorre os elementos da ultima coluna em ordem crescente
	for (int lin = 0; lin < ordem_; lin++) {
		//caso igual a zero, nao sera calculado
		if (matrix_[lin][ordemCofator] == 0) continue;

		float **cofator = nullptr;
		cofator = this->allocMatrix(cofator, ordemCofator, ordemCofator);

		//ciclo de passagem de valores para o cofator
		for (int x = 0, x_ = 0 ; x < ordemCofator; x++, x_++) {
			for (int y = 0; y < ordemCofator; y++) {
				if (x_ == lin) x_++;
				cofator[x][y] = matrix_[x_][y];
			}
		}
		det += pow(-1, lin + ordemCofator) * matrix_[lin][ordemCofator] * this->determinant(cofator, ordemCofator);
		//libera a memoria do cofator
		this->freeMatrix(cofator, ordemCofator);
	}
	return det;
}

double Matrix::determinantChio(float **matrix_, int ordem_) {
	double det = 0;
	int ordemCofator = ordem_ - 1;
	float **cofator = nullptr;
	cofator = this->allocMatrix(cofator, ordemCofator, ordemCofator);

	for (int y = 1; y < ordem_; y++) {
		for (int x = 1; x < ordem_; x++) {
			cofator[x - 1][y - 1] = matrix_[x][y] - matrix_[x][0] * matrix_[0][y];
		}
	}
	det = this->determinant(cofator, ordemCofator);
	
	//libera a memoria do cofator
	this->freeMatrix(cofator, ordemCofator);

	return det;
}

Matrix Matrix::transpose( ) {
	Matrix res(this->name + " transposta", this->j, this->i);

	for (int y = 0; y < res.getJ( ); y++) {
		for (int x = 0; x < res.getI( ); x++) {
			res.populadorMatriz(this->matrix[y][x], x, y);
		}
	}
	res.checkMatrixFetures( );

	return res;
}

float Matrix::getValue(int x, int y) {
	return this->matrix[x][y];
}

int Matrix::getI( ) {
	return this->i;
}

int Matrix::getJ( ) {
	return this->j;
}

bool Matrix::getIdentidade( ) {
	return this->identidade;
}

bool Matrix::getQuadrada( ) {
	return this->quadrada;
}

bool Matrix::getLinha( ) {
	return this->linha;
}

bool Matrix::getColuna( ) {
	return this->coluna;
}

bool Matrix::getNula( ) {
	return this->nula;
}

bool Matrix::getDiagonal( ) {
	return this->diagonal;
}

int Matrix::getOrdem( ) {
	return this->ordem;
}

double Matrix::getDeterminant( ) {
	return this->determ;
}