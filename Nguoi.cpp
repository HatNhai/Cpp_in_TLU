#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Nguoi{
	private:
		string ma, hoten, ma_donvi;
		int namsinh;
		float hesoluong;
	public:
		Nguoi(){
			
		}
		Nguoi(string ma, string hoten, string madv, int nam, float hsl){
			this->ma = ma;
			this->hoten = hoten;
			this->ma_donvi = madv;
			this->namsinh = nam;
			this->hesoluong = hsl;
		}
		virtual void nhap(){
			cout << "Ma nguoi: "; getline(cin, this->ma);
			cout << "Ho va ten: "; getline(cin, this->hoten);
			cout << "Ma don vi: "; getline(cin, this->ma_donvi);
			cout << "Nam sinh: "; cin >> this->namsinh;
			cout << "He so luong: "; cin >> this->hesoluong; cin.ignore();
		}
		virtual void xuat(){
			cout << this->ma << "-" << this->hoten << "-" << this->ma_donvi << "-" << this->namsinh << "-" << this->hesoluong << "-";
		}	
};

class GiangVien: public Nguoi{
	private:
		string mon;
		int sogio;
		int sobaibao;
	public:
		GiangVien(){
			
		}
		GiangVien(string ma, string hoten, string madv, int nam, float hsl, string mon, int sogio, int sobaibao) : Nguoi(ma, hoten, madv, nam, hsl){
			this->mon = mon;
			this->sogio = sogio;
			this->sobaibao = sobaibao;
		}
		double tinhLuong(){
			return (this->sogio * 200) + (1200 * 0.25);
		}
		void nhap(){
			Nguoi::nhap();
			cout << "Mon day: "; getline(cin, this->mon);
			cout << "So gio day/thang: "; cin >> this->sogio;
			cout << "So bai bao: "; cin>> this->sobaibao;
		}
		void xuat(){
			Nguoi::xuat();
			cout << this->mon << "-" << this->sogio << "-" << this->sobaibao << endl;
		}		
};

class SinhVien: public Nguoi{
	private:
		string mon_hoc;
		int sotinchi;
		float diemqt;
	public:
		SinhVien(){
			
		}
		SinhVien(string ma, string hoten, string madv, int nam, float hsl, string monhoc, int tinchi, float diem) : Nguoi(ma, hoten, madv, nam, hsl){
			this->mon_hoc = monhoc;
			this->sotinchi = tinchi;
			this->diemqt = diem;
		}
		void nhap(){
			Nguoi::nhap();
			cout << "Mon hoc: "; getline(cin, this->mon_hoc);
			cout << "So tin chi: "; cin >> this->sotinchi;
			cout << "Diem qua trinh: "; cin >> this->diemqt;
		}
		void xuat(){
			Nguoi::xuat();
			cout << this->mon_hoc << "-" << this->sotinchi << "-" << this->diemqt << endl;
		}
		float get_DiemQt(){
			return this->diemqt;
		}	
};

bool KiemTra(GiangVien *a, GiangVien *b){ // su dung con tro
	return a->tinhLuong() < b->tinhLuong();
}

int main(){
	vector<Nguoi*> nguoi;
	vector<GiangVien*> giangvien;
	vector<SinhVien*> sinhvien;
	int n;
	do{
		cout << "Nhap so luong nguoi: "; cin >> n;
	}while( n > 100);
	int type = 0;
	int loai;
	for (int i = 0; i < n; i++){
		cout << "Nhap thong tin (0 - Giang Vien 1 - Sinh Vien): "; cin >> loai; cin.ignore();
		if (loai == type){
			GiangVien *people = new GiangVien();
			people->nhap();
			giangvien.push_back(people);
		}
		else{
			SinhVien *sv = new SinhVien();
			sv->nhap();
			sinhvien.push_back(sv);
		}
	}	
	
	sort(giangvien.begin(), giangvien.end(), KiemTra); //chu y
	cout << "Danh sach giang vien sau khi sap xep giam dan: " << endl;
	for (int i = 0; i < giangvien.size() ; i++){
		giangvien[i]->xuat();
	}	
	
	cout << "Danh sach sinh vien co diem qua trinh < 4: " << endl;
	for (int i = 0; i < sinhvien.size(); i++){
		if (sinhvien[i]->get_DiemQt() < 4){
			sinhvien[i]->xuat();
		}
	}
	
	return 0;
}
