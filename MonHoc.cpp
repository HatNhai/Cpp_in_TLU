#include <iostream>
#include <vector>

using namespace std;

class MonHoc{
	private:
		string ma_mh, ten_mh;
		int sotinchi;
	public:
		MonHoc(){
			this->ma_mh = "";
			this->ten_mh = "";
			this->sotinchi = 0;
		} 
		MonHoc(string mmh, string tmh, int stc){
			this->ma_mh = mmh;
			this->ten_mh = tmh;
			this->sotinchi = stc;
		}
		string get_ma(){
			return this->ma_mh;
		}
		string get_ten(){
			return this->ten_mh;
		}
		int get_sotinchi(){
			return this->sotinchi;
		}
		virtual void input(){
			cout << "Ma mon hoc: ";getline(cin, this->ma_mh);
			cout << "Ten mon hoc: ";getline(cin, this->ten_mh);
			cout << "So tin chi: "; cin >> this->sotinchi; cin.ignore();
		}
		virtual void output(){
			cout << this->ma_mh << "-" << this->ten_mh << "-" << this->sotinchi << "-";
		}	
};

class ToanHoc : public MonHoc{
	private: 
		string kieu_hoc;
	public:
		ToanHoc(){
			this->kieu_hoc = "";
		}
		ToanHoc(string mmh, string tmh, int stc, string kh) : MonHoc(mmh, tmh, stc){
			this->kieu_hoc = kh;
		}
		string get_Kieuhoc(){
			return this->kieu_hoc;
		}
		void input(){
			MonHoc::input();
			cout << "Kieu hoc (ly thuyet - thuc hanh): ";getline(cin, this->kieu_hoc);
		}
		void output(){
			MonHoc::output();
			cout << this->kieu_hoc;
		}
		
		friend bool operator != (MonHoc &a,MonHoc &b) {
			return a.get_ma() != b.get_ma();	
		}		
};

int main(){
	vector<MonHoc*> monhoc;
	int n; 
	cout << "Nhap so luong mon toan: "; cin >> n; cin.ignore();
	for (int i = 0; i < n; i++){
		ToanHoc *maths = new ToanHoc();
		maths->input();
		monhoc.push_back(maths);	
	}
	cout << "===" << endl;
	for (int i = 0; i < monhoc.size(); i++){
		monhoc[i]->output();
		cout << endl;
	}
	
	
	cout << "Nhap doi tuong moi: " << endl;
	ToanHoc *moi = new ToanHoc();
	moi->input();
	monhoc.push_back(moi);
	for (int i = 0; i < monhoc.size(); i++){
		if (moi[i].get_ma() != monhoc[i]->get_ma()){
			cout << "Doi tuong hop le";
			monhoc.push_back(moi);
		}else{
			cout << "Doi tuong khong hop le!";
		}
	} 
	
	
	
	
	return 0;
}
