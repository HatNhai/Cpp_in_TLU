#include <iostream>

using namespace std;

class Matrix{
	private:
		int m, n;
		double e[100][100];
	public:
		Matrix(){
			this->m = 0;
			this->n = 0;
		}
		Matrix (const Matrix &a){
			m = a.m;
			n =a.n;
		}
		void nhap(){
			cin >> this->m;
			cin >> this->n;
			for (int i = 0; i < m; i++){
				for (int j = 0; j < n; j++){
					cin >> e[i][j];
				}
			}
		}
		void xuat(){
			for (int i = 0; i < m; i++){
				for (int j = 0; j < n; j++){
					cout << e[i][j] << " ";
				}
				cout << endl;
			}
		}
		int Cong(const Matrix &a);
		
		Matrix Nhan(const Matrix &a, int k){
			Matrix kq;
			kq.m = this->m;
			kq.n = this->n;
			for (int i = 0; i < m; i++){
				for (int j = 0; j < n; j++){
					kq.e[i][j] = k * e[i][j];
				}
			}
			return kq;
		}
	
};

int main(){
	Matrix e;
	e.nhap();
	e.xuat();
	
	int k;
	cin >> k;
	Matrix kq = e.Nhan(e, k);
	kq.xuat();
	
	return 0;
}
