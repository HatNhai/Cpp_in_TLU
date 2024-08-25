#include <iostream>
#include <vector>

using namespace std;

class Hangxe{
	private:
		string mahangxe, tenhangxe, nuoc, nam;
	public:
		string getMahangxe(){
			return this->mahangxe;
		}
		string getTenhangxe(){
			return this->tenhangxe;
		}
		string getNuoc(){
			return this->nuoc;
		}
		string getNam(){
			return this->nam;
		}
		friend istream & operator >> (istream& in, Hangxe &a){
			cout << "Ma hang xe: "; getline(in, a.mahangxe);
			cout << "Ten hang xe: "; getline(in, a.tenhangxe);
			cout << "Nuoc: "; getline(in, a.nuoc);
			cout << "Nam: "; getline(in, a.nam);
			return in;
		}
		friend ostream & operator  << (ostream & out, Hangxe a){
			out << a.mahangxe << "-" << a.tenhangxe << "-" << a.nuoc << "-" << a.nam << endl;
			return out;
		}
};

class PhuongTien{
	private:
		string ma, ten, loai;
		long long gia;
		int hang;
		Hangxe hang_xe;
		
	public:
		string getMa(){
			return this->ma;
		}
		string getTenpt(){
			return this->ten;
		}
		string getLoai(){
			return this->loai;
		}
		long long getGia(){
			return this->gia;
		}
		int getHang(){
			return this->hang;
		}
		Hangxe getHang_xe(){
			return this->hang_xe;
		}
		
		void nhap(Hangxe hang_xe[]){
			cout << "Ma ptgt: "; getline(cin, ma);
			cout << "Ten ptgt: "; getline(cin, ten);
			cout << "Loai ptgt: "; getline(cin, loai);
			cout << "Gia: "; cin >> gia;
			cout << "Chi so hang xe: "; cin >> hang; 
			this->hang_xe = hang_xe[hang];
			cin.ignore();
		}
		
		PhuongTien operator + (PhuongTien &pt){
			PhuongTien tong;
			tong.gia = this->gia + pt.gia;
			return tong;
		}
};

class Oto : public PhuongTien{
	private:
		string tencar, mauxe, nhienlieu;
		int namsx;
	public:
		string getTen(){
			return this->tencar;
		}
		int getNam(){
			return this->namsx;
		}
		string getMau(){
			return this->mauxe;
		}
		string getNhienlieu(){
			return this->nhienlieu;
		}
		friend istream& operator >> (istream&in, Oto &a){
			cout << "Ten xe chi tiet: "; getline(in, a.tencar);
			cout << "Nam san xuat: "; in >> a.namsx; in.ignore();
			cout << "Mau xe: "; getline(in, a.mauxe);
			cout << "Nhien lieu: "; getline(in, a.nhienlieu);
			return in;
		}
		void output_1(){
			cout << getMa() << "-" << tencar << "-" << namsx << "-" << getHang_xe().getTenhangxe() << "-" << getGia() << "-" << mauxe << endl; 
		}
		long long giaOto(){
			long long phiDk = 0.072 * getGia() + 500000 + 340000 + 480000 + 2160000;
			return getGia() + phiDk;
		}		
};

class Xemay : public PhuongTien{
	private:
		string ten, mau, nhienlieu;
		int nam;
	public:
		string getTenxm(){
			return this->ten;
		}
		string getMauxm(){
			return this->mau;
		}
		int getNamxm(){
			return this->nam;
		}
		string getNhienlieuxm(){
			return this->nhienlieu;
		}
		friend istream& operator >> (istream& in, Xemay &x){
			cout << "Ten xe chi tiet: "; getline(in, x.ten);
			cout << "Nam: "; in >> x.nam; in.ignore();
			cout << "Mau: "; getline(in, x.mau);
			cout << "Nhien lieu: "; getline(in, x.nhienlieu);
			return in;
		}
		void output_2(){
			cout << getMa() << "-" << ten << "-" << nam << "-" << getHang_xe().getTenhangxe() << "-" << getG+ia() << "-" << mau << endl;
		}
		long long giaXemay(){
			return getGia() + 500000;
		}

};

int main(){
		Hangxe hangxe[100];
		int n;
		cout << "Nhap sl hang xe: "; cin >> n;	
		cin.ignore();
		for (int i = 0; i < n; i++){
			cin >> hangxe[i];
		}
		
		Oto oto[100];
		Xemay xemay[100];
		
		int m;
		cout << "Nhap sl ptgt: "; cin >> m;
		
		int type = 0;
		long long tong = 0;
		for(int i = 0; i < m; i++){
			cout << "Loai xe (0 - Oto hay 1 - Xe may): ";
			cin >> type;
			cin.ignore();
			if (type == 0){
				oto[i].nhap(hangxe);
				cin >> oto[i];
				tong += oto[i].giaOto();
			}
			else if (type == 1){
				xemay[i].nhap(hangxe);
				cin >> xemay[i];
				tong += xemay[i].giaXemay();
			}	
		}
		
		cout << "Danh sach hoa don: " << endl;
		for (int i = 0; i < m; i++){
			if (oto[i].getTenpt() == "O To" || oto[i].getTenpt() == "o to" || oto[i].getTenpt() == "O to") oto[i].output_1();
			else if (xemay[i].getTenpt() == "Xe may" || xemay[i].getTenpt() == "xe may" || xemay[i].getTenpt() == "Xe May") xemay[i].output_2();
		}
		
		cout << "===" << endl;
		cout << tong;
		
		
	return 0;
}
