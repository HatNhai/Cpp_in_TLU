#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TaiLieu{
	private:
		string ten;
		int nam;
		long int gia;
	public:
		TaiLieu(){
			ten = "";
			nam = 0;
			gia = 0;
		}
		virtual void nhap(){
			cout << "Ten tai lieu: "; getline(cin, this->ten);
			cout << "Nam xuat ban: "; cin >> this->nam;
			cout << "Don gia: "; cin >> this->gia;
		}
		virtual void xuat(){
			cout << this->ten << "-" << this->nam << "-" << this->gia << "-";
		}
		virtual int get_Soluong() = 0;
		
		virtual long int thanhTien() = 0;
};

class Sach: public TaiLieu{
	private:
		int soluong;
		long int gia_ban;
	public:
		Sach(){
			soluong = 0;
			gia_ban = 0;
		}
		int get_Soluong(){
			return this->soluong;
		}
		void nhap(){
			TaiLieu::nhap();
			cout << "So luong ban: "; cin >> this->soluong;
			cout << "Gia ban: "; cin >> this->gia_ban; cin.ignore();
		}
		void xuat(){
			TaiLieu::xuat();
			cout << this->soluong << "-" << this->gia_ban << "-" << this->thanhTien() << endl;
		}
		long int thanhTien(){
			return this->soluong * this->gia_ban;
		}
};

bool sapXep(TaiLieu *a, TaiLieu *b){
	return a->thanhTien() > b->thanhTien();
}

int main(){
	vector<TaiLieu*> tailieu;
	int n;
	cout << "Nhap so luong sach: "; cin >> n; cin.ignore();
	
	for (int i = 0; i < n; i++){
		TaiLieu *book = new Sach(); //Su dung con tro linh hoat duoc o day
		book->nhap();
		book->thanhTien();
		tailieu.push_back(book);
	}
	
	for (int i = 0; i < tailieu.size(); i++){
		cout << i + 1 << "-";
		tailieu[i]->xuat();
	}
	
	//Sap xep theo thu tu tang dan
	sort(tailieu.begin(), tailieu.end(), sapXep);
	cout << "\nDanh sach sap xep tang dan theo gia: " << endl;
	for (int i = 0; i < tailieu.size(); i++){
		cout << i + 1 << "-";
		tailieu[i]->xuat();
	}
	
	//Tim max min
	int chiso = 0;
	for (int i = 1; i < tailieu.size(); i++){
		if (tailieu[i]->get_Soluong() > tailieu[0]->get_Soluong()){
			chiso = i;
		}
	}
	cout << "\nDanh sach co luot ban cao nhat la: " << endl;
	tailieu[chiso]->xuat();
	
	
	return 0;
}

