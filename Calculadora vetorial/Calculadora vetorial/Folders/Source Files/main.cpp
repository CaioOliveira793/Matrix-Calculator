#include <iostream>
#include <cstdlib>
#include <queue>

#include "..\Matrix\Matrix.h"

#define ordem 12

int main( ) {
	//Matrix m1("nome", ordem, ordem);
	//for (int x = 0; x < ordem; x++) {
	//	for (int y = 0; y < ordem; y++) {
	//		m1.populadorMatriz(x + 2 * y - 7, x, y);
	//	}
	//}

	Matrix m1("A", 2, 4);
	m1.populadorMatriz( );

	m1.checkMatrixFetures( );
	m1.printMatrix( );
	system("pause");

	Matrix m1T = m1.transpose( );
	m1T.printMatrix( );

	//m1.checkMatrixFetures( );
	//m1.printMatrix( );
	//m1.determinant( );
	//std::cout << "\nDerterminante = " << m1.getDeterminant( ) << "\n\n";
	
	system("pause");
}

void function( ) {
	std::queue<Matrix> nome;
	Matrix algo("nome", 2, 3);

	nome.push(algo);
}