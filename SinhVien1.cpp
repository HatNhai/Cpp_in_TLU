#include <iostream>

using namespace std;

class SinhVien{
	private:
		int msv;
		string hoten;
		float diemgk, diemck;
	public:
		void input(){
			cin >> this->msv; cin.ignore();
			getline(cin, this->hoten);
			cin >> this->diemgk; 
			cin >> this->diemck;
		}
		void out(){
			cout << this->msv << "-" << this->hoten << "-" << this->diemgk << "-" << this->diemck << endl;
		}
		float get_DiemGk(){
			return this->diemgk;
		}
		float get_DiemCk(){
			return this->diemck;
		}
};
int main(){
	SinhVien a;
	a.input();
	a.out();
	a.get_DiemGk();
	a.get_DiemCk();
	
	return 0;
}
