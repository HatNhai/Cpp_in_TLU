#include <iostream>
#include <vector>

using namespace std;

class NguoiBenh{
	private:
		string hoten, diachi;
		int namsinh;
	public:
		virtual void nhap(){
			cout << "Ho va ten: "; getline(cin, this->hoten);
			cout << "Dia chi: "; getline(cin, this->diachi);
		}
		virtual void xuat(){
			cout << this->hoten << "-" << this->diachi << "-";
		}
		int getNam(){
			return this->namsinh;
		}
		virtual int soTuoi() = 0;
};

class BenhAn: public NguoiBenh{
	private:
		string ma, tenba;
		long int sotien;
	public:
		void nhap(){
			NguoiBenh::nhap();
			cout << "Ma benh an: "; getline(cin, this->ma);
			cout << "Ten benh an: ";getline(cin, this->tenba);
			cout << "So tien benh an: ";cin >> this->sotien;cin.ignore();
		}
		void xuat(){
			NguoiBenh::xuat();
			cout << this->ma << "-" << this->tenba << "-" << this->sotien << this->soTuoi() << endl;
		}
		int soTuoi(){
			return 2023 - this->getNam();
		}
};

int main(){
	vector<NguoiBenh*> nguoibenh;
	int n;
	cout << "Nhap so luong nguoi benh: "; cin >> n;cin.ignore();
	for (int i = 0; i < n; i++){
		NguoiBenh *patient = new BenhAn();
		patient->nhap();
		patient->soTuoi();
		nguoibenh.push_back(patient);
	}
	for (int i = 0; i < nguoibenh.size(); i++){
		nguoibenh[i]->xuat();
	}
	
	int min = nguoibenh[0]->soTuoi();
	int chiso = 0;
	for (int i = 0; i < nguoibenh.size(); i++){
		if (nguoibenh[i]->soTuoi() < min){
			min = nguoibenh[i]->soTuoi();
			chiso = i;	
		}
	}
	
	cout << "===" << endl;
	nguoibenh[chiso]->xuat();
	 
	
	return 0;
}
