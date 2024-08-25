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
		
		friend istream & operator >> (istream& in, Hangxe &a){
			cout << "Ma hang xe: "; getline(in, a.mahangxe);
			cout << "Ten hang xe: "; getline(in, a.tenhangxe);
			cout << "Nuoc: "; getline(in, a.nuoc);
			cout << "Nam: "; getline(in, a.nam);
			return in;
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
		int getHang(){
			return this->hang;
		}
		long long getGia(){
			return this->gia;
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
		virtual void hienThi() = 0;	
};

class Oto : public PhuongTien,public Hangxe {
	private:
		string tencar, mauxe, nhienlieu;
		int namsx;
	public:
		friend istream& operator >> (istream&in, Oto &a){
			cout << "Ten xe chi tiet: "; getline(in, a.tencar);
			cout << "Nam san xuat: "; in >> a.namsx; in.ignore();
			cout << "Mau xe: "; getline(in, a.mauxe);
			cout << "Nhien lieu: "; getline(in, a.nhienlieu);
			return in;
		}
		void hienThi(){
			cout << getMa() << "-" << tencar << "-" << namsx << "-" << getHang_xe().getTenhangxe() << "-" << getGia() << "-" << mauxe << endl; 
		}			
};

class Xemay : public PhuongTien, public Hangxe {
	private:
		string ten, mau, nhienlieu;
		int nam;
	public:
		friend istream& operator >> (istream& in, Xemay &x){
			cout << "Ten xe chi tiet: "; getline(in, x.ten);
			cout << "Nam: "; in >> x.nam; in.ignore();
			cout << "Mau: "; getline(in, x.mau);
			cout << "Nhien lieu: "; getline(in, x.nhienlieu);
			return in;
		}
		void hienThi(){
			cout << getMa() << "-" << ten << "-" << nam << "-" << getHang_xe().getTenhangxe() << "-" << getGia() << "-" << mau << endl;
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
		
		int m;
		cout << "Nhap sl phuong tien: "; cin >> m; cin.ignore();
		
		PhuongTien *ds_pt[100];
		
		for (int i = 0; i < m; i++){
			int type;
			cout << "Loai xe (0 - Oto hay 1 - Xe may): ";
			cin >> type;
			cin.ignore();
			
			if (type == 0){
				ds_pt[i] = new Oto();
				ds_pt[i]->nhap(hangxe);	
				//Nhap tiep thong tin cua Oto
				
			}
			else if (type == 1){
				ds_pt[i] = new Xemay();	
				ds_pt[i]->nhap(hangxe);
				//Nhap tiep thong tin cua Xemay	
			}
		}
		
		for (int i = 0; i < m; i++){
			ds_pt[i]->hienThi();
		}
		
	return 0;
}
