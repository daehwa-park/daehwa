#include<iostream>
#include<math.h>
using namespace std;

#include "Matrix.h"

CMatrix::CMatrix(int row , int column) {
	this->row = row;
	this->column = column;
	p = new double *[row];
	for (int i = 0; i < row; i++) {
		p[i] = new double[column];
	}
}

CMatrix::CMatrix(const CMatrix& c) {
	this->row = c.row;
	this->column = c.column;
	p = new double *[c.row];
	for (int i = 0; i < c.row; i++) {
		p[i] = new double[c.column];
	}
	for (int i = 0; i < c.row; i++) {
		for (int j = 0; j < c.column; j++) {
			this->p[i][j] = c.p[i][j];
		}
	}
}

CMatrix::~CMatrix() {
	for (int i = 0; i < row; i++) {
		delete[] p[i];
	}
	delete[] p;
	
}

void CMatrix::changeDim(int n, int k) {

	for (int i = 0; i < row; i++) {
		delete[] p[i];
	}
	delete[] p;

	p = new double *[n];
	for (int i = 0; i < n; i++) {
		p[i] = new double[k];
	}
	this->row = n;
	this->column = k;

}

void CMatrix::write() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> p[i][j];
		}
	}
}

void CMatrix::show() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << p[i][j] << '	';
		}
		cout << endl;
	}
}

CMatrix CMatrix::operator+(CMatrix c) {
	CMatrix tmp(this->row,this->column);
	if (this->row == c.row && this->column == c.column) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				tmp.p[i][j] = this->p[i][j] + c.p[i][j];
			}
		}
	}
	else
		cout << "행렬의 크기가 같지 않습니다" << endl;
	return tmp;
}

CMatrix CMatrix::operator-(CMatrix c) {
	CMatrix tmp(this->row,this->column);
	if (this->row == c.row && this->column == c.column) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				tmp.p[i][j] = this->p[i][j] - c.p[i][j];
			}
		}
	}
	else
		cout << "행렬의 크기가 같지 않습니다" << endl;
	return tmp;
}

CMatrix CMatrix::operator*(CMatrix c) {
	CMatrix tmp(this->row, c.column);
	if (this->column == c.row) {
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < c.column; j++) {
				tmp.p[i][j] = 0;
				for (int l = 0; l < this->column; l++) {
					tmp.p[i][j] += this->p[i][l] * c.p[l][j];
				}
			}
		}
	}
	else
		cout << "곱셈을 할 수 없습니다." << endl;
	return tmp;
}

CMatrix& CMatrix::operator=(CMatrix c) {
	if (this->row == c.row && this->column == c.column) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				this->p[i][j] = c.p[i][j];
			}
		}
	}
	else
		cout << "행렬의 크기가 같지 않습니다" << endl;
	return *this;
}

void CMatrix::zeroMatrix() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			p[i][j] = 0;
		}
	}
}

void CMatrix::unitMatrix() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if(i == j)
				p[i][j] = 1;
			else
				p[i][j] = 0;
		}
	}
}


void CMatrix::scalarProduct(int n) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			p[i][j] = p[i][j] * n;
		}
	}
}

void CMatrix::scalarProduct(double n) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			p[i][j] = p[i][j] * n;
		}
	}
}

void CMatrix::transpose() {
	CMatrix tmp(row, column);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			tmp.p[j][i] = this->p[i][j];
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			this->p[i][j] = tmp.p[i][j];
		}
	}
}

double CMatrix::trace() {
	double sum = 0;
	if (row == column)
		for (int i = 0; i < row; i++)
			sum += p[i][i];
	else
		cout << "정방행렬이 아닙니다" << endl;
	return sum;
}

double CMatrix::determ2(double *p) {
	double det;
	det = (p[0] * p[3]) - (p[1] * p[2]);
	return det;
}

double CMatrix::determ2() {
	double det;
	det = (p[0][0] * p[1][1]) - (p[0][1] * p[1][0]);
	return det;
}

double CMatrix::determ3() {
	double m[4];
	int k = 0;
	double sum = 0;
	for (int n = 0; n < 3; n++) {
		for (int i = 1; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if ( j == n)
					continue;
				m[k] = p[i][j];
				k++;
				if (k == 4)
					k = 0;
			}
		}
		if (n == 1)
			sum = sum - (p[0][n] * determ2(m));
		else
			sum = sum + (p[0][n] * determ2(m));
	}
	return sum;
}

void CMatrix::singular() {
	if (row == 2 && column == 2) {
		if (determ2() == 0)
			cout << "특이행렬 입니다." << endl;
		else
			cout << "특이행렬이 아닙니다." << endl;
	}
	if (row == 3 && column == 3) {
		if (determ3() == 0)
			cout << "특이행렬 입니다." << endl;
		else
			cout << "특이행렬이 아닙니다." << endl;
	}
}

void CMatrix::cofactor(CMatrix& c) {
	double m[4];
	CMatrix tmp(row, column);
	int z = 0;
	for (int k = 0; k < row; k++) {
		for (int n = 0; n < column; n++) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					if (i == k || j == n)
						continue;
					m[z] = p[i][j];
					z++;
					if (z == 4)
						z = 0;
				}
			}
			tmp.p[k][n] = determ2(m);
		}
	}

	c = tmp;
}

int CMatrix::inverse() {
	if (row == 2 && column == 2) {
		double det;
		det = determ2();
		if (det == 0) {
			cout << "이 행렬을 특이행렬 입니다. 역함수가 없습니다." << endl;
			return 1;
		}
		double k = (double)1 / ((p[0][0] * p[1][1]) - (p[0][1] * p[1][0]));
		double t = p[0][0];
		p[0][0] = p[1][1];
		p[0][1] = -p[0][1];
		p[1][0] = -p[1][0];
		p[1][1] = t;

		this->scalarProduct(k);
	}
	if (row == 3 && column == 3) {
		double detA;
		detA = determ3();
		if (detA == 0) {
			cout << "이 행렬을 특이행렬 입니다. 역함수가 없습니다." << endl;
			return 1;
		}
		this->cofactor(*this);
		this->transpose();

		this->scalarProduct((double)1 / detA);
	}
	return 0;
}

void CMatrix::dotProduct(CMatrix c) {
	if (this->column != 1 && c.column != 1) {
		cout << "벡터가 아닙니다." << endl;
		return;
	}
	double dotP =0;

	CMatrix tmp(1,this->row);
	
	for (int i = 0; i < this->row; i++) {
		tmp.p[0][i] = this->p[i][0];
	}

	for (int i = 0; i < this->row; i++) {
		dotP += (tmp.p[0][i] * c.p[i][0]);
	}
	

	cout << "내적의 값은 " <<dotP << "입니다." << endl;

}

void CMatrix::crossProduct(CMatrix c) {
	if (this->column != 1 && c.column != 1) {
		cout << "벡터가 아닙니다." << endl;
		return;
	}
	CMatrix croP(this->row, c.row);
	CMatrix tmp(1, this->row);
	for (int i = 0; i < this->row; i++) {
		tmp.p[0][i] = c.p[i][0];
	}
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < c.row; j++) {
			croP.p[i][j] = (this->p[i][0] * tmp.p[0][j]);
		}
	}
	cout << "외적의 행렬은" << endl;
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < c.row; j++) {
			cout << croP.p[i][j] << "	";
		}
		cout << endl;
	}
	cout << "입니다." << endl;
}

void CMatrix::vecDistance(CMatrix c) {
	CMatrix tmp(this->row);
	double sum = 0;
	for (int i = 0; i < this->row;i++) {
		tmp.p[i][0] = (this->p[i][0] - c.p[i][0]);
	}
	for (int i = 0; i < this->row; i++) {
		sum += (tmp.p[i][0] * tmp.p[i][0]);
	}

	cout << "두 벡터간의 거리는 " << sqrt(sum) << "입니다." << endl;
}