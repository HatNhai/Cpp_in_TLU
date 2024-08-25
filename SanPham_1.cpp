#include <iostream>
#include <vector>

using namespace std;

class SanPham{
	private:
		string ten, nhasx;
	public:
		SanPham(){
			
		}
		SanPham(string name, string nsx){
			this->ten = name;
			this->nhasx = nsx;
		}
		string get_ten(){
			return this->ten;
		}
		string get_nhasx(){
			return this->nhasx;
		}
		void set_ten(){
			getline(cin, this->ten);
		}
		void set_nhasx(){
			getline(cin, this->nhasx);
		}
		virtual void nhap(){
			cout << "Ten san pham: ";set_ten();
			cout << "Nha san xuat: ";set_nhasx();
		}
		virtual void xuat(){
			cout << this->ten << "-" << this->nhasx;
		}
		virtual long int thanhToan() = 0;
};

class BanLe: public SanPham{
	private:
		long int gia;
		int soluong;
	public:
		BanLe(){
			
		}
		BanLe(string name, string nsx, long int price, int quantity): SanPham(name, nsx){
			this->gia = price;
			this->soluong = quantity;
		}
		void nhap(){
			SanPham::nhap();
			cout << "Gia ban le: "; cin >> this->gia;
			do{
				cout << "So luong le: "; cin >> this->soluong;
			}while(this->soluong > 10);
		}
		void xuat(){
			SanPham::xuat();
			cout << "-" << this->gia << "-" << this->soluong << "-" << this->thanhToan() << endl;
		}
		long int thanhToan(){
			return this->gia * this->soluong; 
		}
};

class BanSi: public SanPham{
	private:
		long int gia_si;
		int soluong_si;
	public:
		BanSi(){
			
		}
		BanSi(string name, string nsx, long int price_2, int quantity_2) : SanPham(name, nsx){
			this->gia_si = price_2;
			this->soluong_si = quantity_2;
		}
		void nhap(){
			SanPham::nhap();
			cout << "Gia ban si: "; cin >> this->gia_si;
			do{
				cout << "So luong si: "; cin >> this->soluong_si;
			}while(this->soluong_si > 10);
		}
		void xuat(){
			SanPham::xuat();
			cout << "-" << this->gia_si << "-" << this->soluong_si << "-" << this->thanhToan() << endl;
		}
		long int thanhToan(){
			return this->gia_si * this->soluong_si;
		}
};

int main(){
	vector<SanPham*> sanpham;
	int n;
	cout << "Nhap so luong san pham: "; cin >> n;
	int type = 0, loai;
	for(int i = 0; i < n; i++){
		cout << "Nhap thong tin(0 - Ban le, 1 - Ban si): "; cin >> loai;cin.ignore();
		if (type == loai){
			SanPham *banle = new BanLe();
			banle->nhap();
			sanpham.push_back(banle);
		}
		else{
			SanPham *bansi = new BanSi();
			bansi->nhap();
			sanpham.push_back(bansi);
		}
	}
	
	cout << "---Danh sach hoa don---" << endl;
	for (int i = 0; i < sanpham.size(); i++){
		sanpham[i]->xuat();
	}
	
	int chiso = 0;
		for (int i = 0; i < sanpham.size(); i++){
			if (sanpham[i]->thanhToan() < sanpham[0]->thanhToan()){
				chiso = i;
			}
		}
	cout << "===" << endl;
	sanpham[chiso]->xuat();
	
	return 0;
}
