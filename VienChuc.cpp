#include <iostream>
#include <vector>

using namespace std;

class VienChuc{
	private:
		string ma, hoten;
		int nam;
		float hesoluong;
	public:
		VienChuc(){
			this->ma = "";
			this->hoten = "";
			this->nam = 0;
			this->hesoluong = 0.0;
		}
		VienChuc(string id, string ht, int year, float hsl){
			this->ma = id;
			this->hoten = ht;
			this->nam = year;
			this->hesoluong = hsl;
		}
		void nhap(){
			cout << "Ma vien chuc: "; getline(cin, this->ma);
			cout << "Ho va ten: "; getline(cin, this->hoten);
			cout << "Nam sinh: "; cin >> this->nam;
			cout << "He so luong: "; cin >> this->hesoluong; cin.ignore();
		}
		virtual void xuat(){
			cout << this->ma << "-" << this->hoten << "-" << this->nam << "-" << this->hesoluong << "-";
		}
		float getHe_so_luong(){
			return this->hesoluong;
		}
		virtual long long tinhLuong() = 0;		
};

class CBHanhChinh : public VienChuc{
	private:
		string chuc_danh;
		long long phucap_antrua;
	public:
		CBHanhChinh(){
			this->chuc_danh = "";
			this->phucap_antrua = 0;
		}
		CBHanhChinh(string cd, long long pc){
			this->chuc_danh = cd;
			this->phucap_antrua = pc;
		}
		void nhap_1(){
			VienChuc::nhap();
			cout << "Chuc danh: "; getline(cin, this->chuc_danh);
			cout << "Phu cap an trua: "; cin >> this->phucap_antrua;
		}
		void xuat(){
			VienChuc::xuat();
			cout << this->chuc_danh << "-" << this->phucap_antrua << endl;
		}
		long long tinhLuong(){
			return this->getHe_so_luong() * 2000000 + this->phucap_antrua;
		}	
};

class GiaoVien : public VienChuc{
	private:
		string mon_day, trinh_do;
		int nam_day;
	public:
		GiaoVien(){
			this->mon_day = "";
			this->trinh_do = "";
			this->nam_day = 0;
		}
		GiaoVien(string md, string td, int nd){
			this->mon_day = md;
			this->trinh_do = td;
			this->nam_day = nd;
		}
		void nhap_2(){
			VienChuc::nhap();
			cout << "Mon day: ";getline(cin, this->mon_day);
			cout << "Trinh do chuyen mon: "; getline(cin, this->trinh_do);
			cout << "Nam day: "; cin >> this->nam_day;
		}
		void xuat(){
			VienChuc::xuat();
			cout << this->mon_day << "-" << this->trinh_do << "-" << this->nam_day << endl;
		}
		long long tinhLuong(){
			return this->getHe_so_luong() * 2000000 * (130 + this->nam_day) / 100;
		}		
};
int main(){
	vector<VienChuc*> vienchuc; 
	int type = 0;	
	long long tong = 0;
	int n;
	
	cout << "Nhap so luong vien chuc: ";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++){
		cout << "Nhap vien chuc (0 - CB_HanhChinh, 1 - GiaoVien): "; cin >> type; cin.ignore();
		if (type == 0){
			CBHanhChinh *canbo = new CBHanhChinh(); 
			canbo->nhap_1();
			vienchuc.push_back(canbo);
		}
		else{
			GiaoVien *gv = new GiaoVien();
			gv->nhap_2();
			vienchuc.push_back(gv);
		}
	}
	
	cout << "===" << endl;
	for (int i = 0; i < vienchuc.size() ; i++){
		vienchuc[i]->xuat();
	}
	
	//Tim vien chuc co luong cao nhat
	int maxchiso = 0;
	for (int i = 0; i < vienchuc.size(); i++){
		if (vienchuc[i]->tinhLuong() > vienchuc[0]->tinhLuong()){
			maxchiso = i;
		}
	}
	cout << "===" << endl;
	cout << "Vien chuc co luong cao nhat truong: " << endl;
	vienchuc[maxchiso]->xuat();
	
	return 0;
}
