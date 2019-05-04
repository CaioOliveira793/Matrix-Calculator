#include <iostream>
#include <cstdlib>
#include <ctime>

#include "..\Matrix\Matrix.h"

#define ORDEM 3

int main( ) {
	Matrix m1("nome", ORDEM, ORDEM);
	srand(time(NULL));
	for (int x = 0; x < ORDEM; x++) {
		for (int y = 0; y < ORDEM; y++) {
			m1.populadorMatriz(rand( ) % 10, x, y);
			//m1.populadorMatriz(x + y, x, y);
		}
	}
	//m1.populadorMatriz( );
	m1.checkMatrixFetures( );
	m1.printMatrix( );
	std::cin.get( );
	
	std::cout << "\nDerterminante = " << m1.determinant(Matrix::Gauss) << "\n\n";
	std::cin.get( );
}