#include <iostream>

using namespace std;

class hocSinh{
	private:
		string mahs, tenhs, diachi;
		float toan, van, anh;
	public:
		void nhap(){
			cout << "Ma hoc sinh: ";getline(cin, this->mahs);
			cout << "Ten hoc sinh: ";getline(cin, this->tenhs);
			cout << "Dia chi: ";getline(cin, this->diachi);
			cout << "Diem toan: "; cin >> this->toan;
			cout << "Diem van: "; cin >> this->van;
			cout << "Diem anh: "; cin >> this->anh; cin.ignore();
		}
		float diemTrungBinh(){
			return (this->toan + this->van + this->anh) / 3;
		}
		void xuat(){
			cout << this->mahs << "-" << this->tenhs << "-" << this->diachi;
		}
};

int main(){
	int n;
	cout << "Nhap so luong hoc sinh: "; cin >> n;cin.ignore();
	hocSinh student[100];
	
	for (int i = 0; i < n; i++){
		student[i].nhap();
	}
	
	float max = student[0].diemTrungBinh();
	int Maxchiso = 0;
	for (int i = 0; i < n; i++){
		if (student[i].diemTrungBinh() > max){
			max = student[i].diemTrungBinh();
			Maxchiso = i;
		}
	}
	
	cout << "Hoc sinh co diem trung binh cao nhat la: ";
	student[Maxchiso].xuat();
	
	return 0;
}
