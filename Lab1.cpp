#include <iostream>

using namespace std;

class SinhVienCSE224{
	private:
		string ma, hoten;
		float diemcc, diembaitap, diemgiuaky, diemcuoiky;
	public:
		SinhVienCSE224(){
		}
		SinhVienCSE224(string m, string ht, float dcc, float dbt, float dgk, float dck){
			this->ma = m;
			this->hoten = ht;
			this->diemcc = dcc;
			this->diembaitap = dbt;
			this->diemgiuaky = dgk;
			this->diemcuoiky = dck;
		}
		float get_ChuyenCan(){
			return this->diemcc;
		}
		float get_Baitap(){
			return this->diembaitap;
		}
		float get_Diemgk(){
			return this->diemgiuaky;
		}
		float get_Diemck(){
			return this->diemcuoiky;
		} 
		void nhap(){
			cout << "Ma sinh vien: "; getline(cin, this->ma);
			cout << "Ho ten: "; getline(cin, this->hoten);
			cout << "Diem chuyen can: ";cin >> this->diemcc;
			cout << "Diem bai tap: "; cin >> this->diembaitap;
			cout << "Diem giua ky: "; cin >> this->diemgiuaky;
			cout << "Diem cuoi ky: "; cin >> this->diemcuoiky; cin.ignore();
		}
		void xuat(){
			cout << this->ma << "-" << this->hoten << "-" << this->diemcc << "-" << this->diembaitap << "-" << this->diemgiuaky << "-" << this->diemcuoiky << endl;
		}
		
		float tinhDiem(){
			return (this->get_ChuyenCan() * 0.1 + this->get_Baitap() * 0.15 + this->get_Diemgk() * 0.25) + this->get_Diemck() * 0.5;
		}
};

int main(){
	SinhVienCSE224 sv[100];
	int n;
	cout << "Nhap so luong sinh vien: "; cin >> n; cin.ignore();
	
	for (int i = 0; i < n; i++){
		sv[i].nhap();
		sv[i].tinhDiem();
	}
	
	for (int i = 0; i < n; i++){
		sv[i].xuat();
	}
	
	int demA = 0, demB = 0, demC = 0, demD = 0, demF = 0;
	for (int i = 0; i < n; i++){
		if (sv[i].tinhDiem() >= 9.0){
			demA++;
		}
		else if (sv[i].tinhDiem() >= 8.0){
			demB++;	
		}
		else if (sv[i].tinhDiem() >= 7.0){
			demC++;	
		}
		else if (sv[i].tinhDiem() >= 5.0){
			demD++;
		}
		else{
			demF++;	
		}	
	}
	cout << demA << endl;
	cout << demB << endl;
	cout << demC << endl;
	cout << demD << endl;
	cout << demF << endl;
	
	
	return 0;
}
