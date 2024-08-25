#include <iostream>
#include <vector>
using namespace std;

class Thucpham{
	private:
		string ten;
		double gia;
		double thanhtien;
	public:
		void setTen(string ten){
			this->ten = ten;
		}
		string getTen(){
			return this->ten;
		}
		void setGia(double gia){
			this->gia = gia;
		}
		double getGia(){
			return this->gia;
		}
		void setThanhtien(double thanhtien){
			this->thanhtien = thanhtien;
		}
		double getThanhtien(){
			return this->thanhtien;
		}
//		friend Thucpham operator + (Thucpham a , Thucpham b){
//			Thucpham kq;
//			kq.getThanhtien() = a.getGia() + b.getGia();
//			return kq;
//		}
		void nhapTP(){
            cout << "Ten sp: "; getline(cin, ten);
            cout << "Gia: "; cin >> gia; cin.ignore();
		}
		
		void xuatTP(){
			cout << this->ten << "-" << this->gia << "-";
		}
};

class TPHOP : public Thucpham{
	private:
		int sohop;
	public:

		void setSohop(int sohop){
			this->sohop = sohop;
		}
		int getSohop(){
			return this->sohop;
		}
		friend istream& operator >> (istream &in, TPHOP &a){
			a.nhapTP();
			cout << "Nhap so hop: "; in >>  a.sohop; in.ignore();
			a.setThanhtien(a.sohop*a.getGia());
			return in;
		}
		friend ostream& operator << (ostream &out, TPHOP a){
			a.xuatTP();
			out << a.sohop << endl;
		} 
};

class TPKHOP : public Thucpham{
	private:
		double khoiluong;
	public:
	    TPKHOP(){
	    	this->khoiluong = khoiluong;
		}
		void setKhoiluong(double khoiluong){
			this->khoiluong = khoiluong;
		}
		double getKhoiluong(){
			return this->khoiluong;
		}
		friend istream& operator >> (istream &in, TPKHOP &a){
			a.nhapTP();
			cout << "Nhap khoi luong: "; in >> a.khoiluong;
			a.setThanhtien(a.khoiluong*a.getGia());
			return in;
		}
		friend ostream& operator << (ostream &out, TPKHOP a){
			a.xuatTP();
			out << a.khoiluong << endl;
		}
};

int main(){
	int n;
	cout << "Nhap so luong thuc pham: "; 
	cin >>n; 
	vector <Thucpham> thucpham(n);
	
	int type = 0;
	
	for (int i = 0; i < n; i++){
	cout << "Nhap loai thuc pham (0 - do hop, 1 - do khong hop): "; 
	cin >> type;
	cin.ignore();
		if (type == 0){
			TPHOP tphop_item;
			cin >> tphop_item;
			thucpham[i] = tphop_item;
		}
		else{
			TPKHOP tpkhop_item;
			cin >> tpkhop_item;
			thucpham[i] = tpkhop_item;
		}
	}
	
	
	
	
	return 0;
}

