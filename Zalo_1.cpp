#include <iostream>


using namespace std;

class TaiLieu{
	private:
		string ten;
		int nam;
		long int gia;
	public:
		virtual void nhap(){
			cout << "Ten tai lieu: "; getline(cin, this->ten);
			cout << "Nam xuat ban: "; cin >> this->nam;
			cout << "Don gia: "; cin >> this->gia;
		}
		void xuat(){
			cout << this->ten << "-" << this->nam << "-" << this->gia << "-";
		}
};

class Sach: public TaiLieu{
	private:
		int soluong;
		long int gia_ban;
	public:
		int get_Soluong(){
			return this->soluong;
		}
		void nhap_1(){
			TaiLieu::nhap();
			cout << "So luong ban: "; cin >> this->soluong;
			cout << "Gia ban: "; cin >> this->gia_ban; cin.ignore();
		}
		void xuat_1(){
			TaiLieu::xuat();
			cout << this->soluong << "-" << this->gia_ban << "-" << this->thanhTien() << endl;
		}
		long int thanhTien(){
			return this->soluong * this->gia_ban;
		}
};

int main(){
	TaiLieu tailieu[100];
	Sach book[100];
	int n;
	cout << "Nhap so luong sach: "; cin >> n; cin.ignore();
	for (int i = 0; i < n; i++){
		cout << "Nhap vao sach so " << i + 1 << ": " << endl;
		book[i].nhap_1();
		book[i].thanhTien();
	}
	
	cout << "================" << endl;
	for (int i = 0; i < n; i++){
		cout << i + 1 << "-";
		book[i].xuat_1();
	}
	
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (book[i].thanhTien() > book[j].thanhTien()){
				Sach temp = book[i];
				book[i] = book[j];
				book[j] = temp;
			}
		}	
	}
	
	cout << "\nDanh sach theo tu tu tang dan: " << endl;
	for (int i = 0; i < n; i++){
		book[i].xuat_1();
	}
	
	cout << "\nTai lieu co so luong ban nhieu nhat la: " << endl;
	int max = book[0].get_Soluong();
	for (int i = 0; i < n; i++){
		if (book[i].get_Soluong() > max){
			max = book[i].get_Soluong();
			book[i].xuat_1();
		}	
		
	}
		
	return 0;
}
