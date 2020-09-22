#pragma once

class CMatrix {
	double **p;
	int row, column;
public:
	CMatrix(int row =1, int column=1);
	CMatrix(const CMatrix& c);
	~CMatrix();
	void changeDim(int n,int k);
	void show();
	void write();
	CMatrix operator+(CMatrix c);
	CMatrix operator-(CMatrix c);
	CMatrix operator*(CMatrix c);
	CMatrix& operator=(CMatrix c);
	void zeroMatrix();
	void unitMatrix();
	void scalarProduct(int n);
	void scalarProduct(double n);
	void transpose();
	double trace();
	double determ2(double *p);
	double determ2();
	double determ3();
	void singular();
	void cofactor(CMatrix& c);
	int inverse();
	void dotProduct(CMatrix c);
	void crossProduct(CMatrix c);
	void vecDistance(CMatrix c);
};

