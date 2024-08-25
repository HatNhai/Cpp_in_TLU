#include <iostream>
#include <vector>

using namespace std;

class hangHoa{
	private:
		string ma, nguoi_mua, hang_hoa, ngay;
		int soluong;
	public:
		virtual void nhap(){
			cout << "Ma don hang: ";getline(cin, this->ma);
			cout << "Thong tin nguoi mua: "; getline(cin, this->nguoi_mua);
			cout << "Ngay mua hang: ";getline(cin, this->ngay);
			cout << "Danh sach mat hang: ";getline(cin, this->hang_hoa);
			cout << "So luong: "; cin >> this->soluong;
		}
		int getSoluong(){
			return this->soluong;
		}
		virtual long long thanhTien() = 0;	
};

class Noi_dia : public hangHoa{
	private:
		long long gia;
	public:
		void nhap(){
			hangHoa::nhap();
			cout << "Nhap gia hang noi dia: "; 
			cin >> this->gia;
		}
		
		long long thanhTien(){
			return this->getSoluong() * this->gia + (0.05 * this->gia);
		}
};

class Nhap_khau : public hangHoa{
	private:
		long long gia_1;
	public:
		void nhap(){
			hangHoa::nhap();
			cout << "Nhap gia hang nhap khau: "; 
			cin >> this->gia_1;
		}
		
		long long thanhTien(){
			return  this->getSoluong() * this->gia_1  * 0.9 + (0.05 * this->gia_1);
		}		
};

int main(){
	int n;
	cout << "Nhap sl don hang: ";
	cin >> n; cin.ignore();
	vector<hangHoa*> hanghoa;
	
	int type = 0;
	for (int i = 0; i < n; i++){
		int chiso;
		cout << "Nhap (0 - Hang noi dia, 1 - Hang nhap khau): "; 
		cin >> chiso;
		cin.ignore();
		if (chiso == type){
			hangHoa* sanpham = new Noi_dia();
			sanpham->nhap();
			hanghoa.push_back(sanpham);		
		}else{
			hangHoa* sanpham = new Nhap_khau();
			sanpham->nhap();
			hanghoa.push_back(sanpham);
		}
	}
		long long tong;
		for (int i = 0; i < hanghoa.size(); i++){
			tong = hanghoa[i]->thanhTien();
		}
		cout << "Tong don hang: " << tong << endl;
	
	return 0;
}
