#include <iostream>

using namespace std;

class VanDongVien{
	private:
		string hoten, monthidau;
		int tuoi;
		float cannang, chieucao;
	public:
		void nhap(int n);
		void xuat();		
};

void VanDongVien::nhap(int n){
	cout << "Nhap so luong: "; cin >> n;
	cin.ignore(); 
	
	for (int i = 0; i < n; i++){	
	cout << "Ho ten: "; getline(cin, hoten);
	cout << "Tuoi: "; cin >> tuoi; cin.ignore();
	cout << "Mon thi dau: ";getline(cin, monthidau);
	cout << "Can nang: "; cin >> cannang;
	cout << "Chieu cao: "; cin >> chieucao;	cin.ignore();
	}
}

void VanDongVien::xuat(){
//	cout << "Ho ten" << "\t" << "Tuoi" << "\t" << "Mon thi dau" << "\t" << "Can nang" << "\t" << "Chieu cao" << endl;	
	cout << hoten << "\t" << tuoi << "\t" << monthidau << "\t" << cannang << "\t" << chieucao ;
}

int main(){
	VanDongVien a[1000];
	int n;
	
	a[0].nhap(n);
	
	for (int i = 0; i < n; i++){
	a[i].xuat();
	}
	
		
	return 0;
}
