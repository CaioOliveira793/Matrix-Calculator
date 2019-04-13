#include "Matrix.h"
#include <math.h>

Matrix soma(std::string newName, Matrix &m1, Matrix &m2) {
	//verifica se m1 e do mesmo tamanho de m2
	if((m1.getI( ) == m2.getI( )) and (m1.getJ( ) == m2.getJ( ))) {
		int i = m1.getI( ), j = m1.getJ( );	//cache do tamanho de res
		Matrix res(newName, i, j);

		for(int x = 0; x < i; x++) {
			for(int y = 0; y < j; y++) {
				//soma os valores de m1 e m2 e guarda em res
				res.populadorMatriz((m1.getValue(x, y) + m2.getValue(x, y)), x, y);
			}
		}
		res.checkMatrixFetures( );
		return res;
	} else {
		Matrix res("Soma impossivel", 1, 1);
		return res;
	}
}

Matrix soma(std::string newName, Matrix &m1, float &n2) {
	int i = m1.getI( ), j = m1.getJ( );	//cache do tamanho de res
	Matrix res(newName, i, j);

	for(int x = 0; x < i; x++) {
		for(int y = 0; y < j; y++) {
			//soma os valores de m1 e n2 e guarda em res
			res.populadorMatriz((m1.getValue(x, y) + n2), x, y);
		}
	}
	res.checkMatrixFetures( );
	return res;
}

Matrix subtracao(std::string newName, Matrix &m1, Matrix &m2) {
	//verifica se m1 e do mesmo tamanho de m2
	if((m1.getI( ) == m2.getI( )) and (m1.getJ( ) == m2.getJ( ))) {
		int i = m1.getI( ), j = m1.getJ( );	//cache do tamanho de res
		Matrix res(newName, i, j);

		for(int x = 0; x < i; x++) {
			for(int y = 0; y < j; y++) {
				//subtrai os valores de m1 e m2 e guarda em res
				res.populadorMatriz((m1.getValue(x, y) - m2.getValue(x, y)), x, y);
			}
		}
		res.checkMatrixFetures( );
		return res;
	} else {
		Matrix res("Subtracao impossivel", 1, 1);
		return res;
	}
}

Matrix subtracao(std::string newName, Matrix &m1, float &n2) {
	int i = m1.getI( ), j = m1.getJ( );	//cache do tamanho de res
	Matrix res(newName, i, j);

	for(int x = 0; x < i; x++) {
		for(int y = 0; y < j; y++) {
			//subtrai os valores de m1 e n2 e guarda em res
			res.populadorMatriz((m1.getValue(x, y) - n2), x, y);
		}
	}
	res.checkMatrixFetures( );
	return res;
}

Matrix multiplicacao(std::string newName, Matrix &m1, Matrix &m2) {
	//verificacao se pode ser multiplicado
	if (m1.getJ( ) == m2.getI( )) {
		//cache dos valores i, j dos obj m1 e m2
		int m1I = m1.getI( ), m2I = m2.getI( ), m2J = m2.getJ( );
		Matrix res(newName, m1I, m2J);

		float elemento = 0;
		for (int x = 0; x < m1I; x++) {
			for (int y = 0; y < m2J; y++) {
				for (int i = 0; i < m2I; i++) {
					elemento += m1.getValue(x, i) * m2.getValue(i, y);
				}
				res.populadorMatriz(elemento, x, y);
				elemento = 0;
			}
		}
		res.checkMatrixFetures( );
		return res;
	} else {
		Matrix res("Multiplicacao impossivel", 1, 1);
		return res;
	}
}

Matrix multiplicacao(std::string newName, Matrix &m1, float &n2) {
	int i = m1.getI( ), j = m1.getJ( );	//cache do tamanho de res
	Matrix res(newName, i, j);

	for(int x = 0; x < i; x++) {
		for(int y = 0; y < j; y++) {
			//multiplica os valores de m1 e n2 e guarda em res
			res.populadorMatriz((m1.getValue(x, y) * n2), x, y);
		}
	}
	res.checkMatrixFetures( );
	return res;
}

Matrix divisao(std::string newName, Matrix &m1, float &n2) {
	int i = m1.getI( ), j = m1.getJ( );	//cache do tamanho de res
	Matrix res(newName, i, j);

	for(int x = 0; x < i; x++) {
		for(int y = 0; y < j; y++) {
			//divide os valores de m1 e n2 e guarda em res
			res.populadorMatriz((m1.getValue(x, y) / n2), x, y);
		}
	}
	res.checkMatrixFetures( );
	return res;
}

Matrix potencia(std::string newName, Matrix &m1, float &n2) {
	int i = m1.getI( ), j = m1.getJ( );	//cache do tamanho de res
	Matrix res(newName, i, j);

	for(int x = 0; x < i; x++) {
		for(int y = 0; y < j; y++) {
			//calcula os valores de m1 e n2 e guarda em res
			res.populadorMatriz((powf(m1.getValue(x, y), n2)), x, y);
		}
	}
	res.checkMatrixFetures( );
	return res;
}