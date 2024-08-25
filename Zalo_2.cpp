#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SanPham{
	protected:
		string tensp;
		int nam;
		long int gia;
	public:
		virtual void nhap(){
			cout << "Ten san pham: "; getline(cin, this->tensp);
			cout << "Nam san xuat: "; cin >> this->nam;
			cout << "Gia thanh: "; cin >> this->gia;
		}
		virtual void xuat(){
			cout << this->tensp << "-" << this->nam << "-" << this->gia;
		}
		long int get_Gia(){
			return this->gia;
		}
		virtual long int thanhTien() = 0;
		virtual long int tinhLai() = 0;
};

class HoaDon : public SanPham{
	protected: 
		int soluong;
		long int giaban;
	public:
		void nhap(){
			SanPham::nhap();
			cout << "So luong ban: ";cin >> this->soluong;
			cout << "Gia ban: "; cin >> this->giaban; cin.ignore();
		}
		void xuat(){
			SanPham::xuat();
			cout << "-" << this->soluong << "-" << this->giaban  <<"-" << this->thanhTien() << "-" << this->tinhLai() << endl;
		}
		long int thanhTien(){
			return this->soluong * this->giaban;
		}
		long int tinhLai(){
			return (this->giaban - this->get_Gia()) * this->soluong;
		}
};

bool soSanh(SanPham *a, SanPham *b){
	return a->tinhLai() > b->tinhLai();
}

int main(){
	vector<SanPham*> sanpham;
	int n;
	cout << "Nhap so luong san pham: "; cin >> n; cin.ignore();
	for (int i = 0; i < n; i++){
		SanPham *hoadon = new HoaDon();
		hoadon->nhap();
		sanpham.push_back(hoadon);
	}
	cout << "----Danh sach hoa don---" << endl;
	for (int i = 0; i < sanpham.size(); i++){
		cout << i + 1 << "-";
		sanpham[i]->xuat();
	}
	
	sort(sanpham.begin(), sanpham.end(), soSanh);
	cout << "---Danh sach sau khi sap xep---" << endl;
	for (int i = 0; i < sanpham.size(); i++){
		cout << i + 1 << "-";
		sanpham[i]->xuat();
	}
	
	return 0;
}
