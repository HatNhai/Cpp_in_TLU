#include <iostream>

using namespace std;

class Sophuc{
	private:
		int thuc, ao;
	public:
		void getValue(){
			cout << "Nhap phan thuc: ";	cin >> thuc;
			cout << "Nhap phan ao: "; cin >> ao;
		}
		Sophuc operator + (Sophuc a){
			Sophuc tong;
			tong.thuc = this->thuc + a.thuc;
			tong.ao = this->ao + a.ao; 
			return tong;
		}
		Sophuc operator - (Sophuc a){
			Sophuc hieu;
			hieu.thuc = this->thuc - a.thuc;
			hieu.ao = this->ao - a.ao;
			return hieu;
		}
		void display(){
			cout << thuc << "+" << ao << "i" << endl;
		}
};

int main(){
	Sophuc a, b;
	a.getValue();
	b.getValue();
	
	Sophuc tong = a + b;
	tong.display();
	
	Sophuc hieu = a - b;
	hieu.display();
	
	return 0;
}
