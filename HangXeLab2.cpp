#include <iostream>
#include <vector>

using namespace std;

class HangXe{
	private: 
		string ma, ten, nuoc;
		int nam;
	public:
		HangXe(){
			
		}
		HangXe(string id, string name, string country, int year){
			this->ma = id;
			this->ten = name;
			this->nuoc = country;
			this->nam = year;
		}
		string get_Ma(){
			return this->ma;
		}
		string get_Ten(){
			return this->ten;
		}
		string get_Nuoc(){
			return this->nuoc;
		}
		int get_Nam(){
			return this->nam;
		}
		void setMa(string id){
			this->ma = id;
		}
		void setTen(string name){
			this->ten = name;
		}
		void setNuoc(string country){
			this->nuoc = country;
		}
		void setNam(int year){
			this->nam = year;
		}
		void nhap(){
			cout << "Ma hang xe: ";getline(cin, this->ma);
			cout << "Ten hang xe: "; getline(cin, this->ten);
			cout << "Nuoc: "; getline(cin, this->nuoc);
			cout << "Nam thanh lap: "; cin >> this->nam; cin.ignore();
		}
		void xuat(){
			cout << this->ma << "-" << this->ten << "-" << this->nuoc << "-" << this->nam;
		}		
};

class Oto{
	private:
		string ma_oto, ten_oto, mau;
		int namsx;
		long int gia;
		HangXe hang;
		int chiso;
	public:
		Oto(){
			
		}
		Oto(string ma, string ten, int nam, HangXe hang, long int gia, string mau){
			this->ma_oto = ma;
			this->ten_oto = ten;
			this->namsx = nam;
			this->hang = hang;
			this->gia = gia;
			this->mau = mau;
		}
		string getMa(){
			return this->ma_oto;
		}
		string getTen(){
			return this->ten_oto;
		}
		int getNam(){
			return this->namsx;
		}
		long int getGia(){
			return this->gia;
		}
		string getMau(){
			return this->mau;
		}
		void setMa(string id){
			this->ma_oto = id;
		}
		void setTen(string name){
			this->ten_oto = name;
		}
		void setNam(int year){
			this->namsx = year;
		}
		void setGia(long int gia){
			this->gia = gia;
		}
		void setMau(string mau){
			this->mau = mau;
		}
		void input(){
			cout << "Ma xe oto: "; getline(cin, this->ma_oto);
			cout << "Ten xe oto: "; getline(cin, this->ten_oto);
			cout << "Nam san xuat: "; cin >> this->namsx;
			cout << "Nhap chi so hang xe: "; cin >> chiso;
			cout << "Gia niem yet: "; cin >> this->gia; cin.ignore();
			cout << "Mau xe: ";getline(cin, this->mau);
		}
		void output(HangXe &hangxe){
			cout << this->ma_oto << "-" << this->ten_oto << "-" << this->namsx << "-" << hangxe.get_Ten() << "-" << this->gia << "-" << this->mau << endl;
		}
};

int main(){

	int n;
	cout << "Nhap so luong hang xe: "; cin >> n; cin.ignore();
	vector<HangXe> hangxe(n);
	for (int i = 0; i < n; i++){
		hangxe[i].nhap();
	}
	
	int m;
	cout << "Nhap so luong xe o to: "; cin >> m; cin.ignore();
	vector<Oto> oto(m);
	for (int i = 0; i < m; i++){
		oto[i].input();
	}
	
	for (int i = 0; i < m; i++){
		oto[i].output(hangxe[i]);
	}
	
	return 0;
}
