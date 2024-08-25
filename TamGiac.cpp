#include <iostream>

using namespace std;

class tamGiac{
	private:
		int a, b, c;
	public:
		void nhap(){
			cout << "A = "; cin >> a;
			cout << "B = "; cin >> b;
			cout << "C = "; cin >> c;
		}
		bool checkTamgiac(){
			if ( a + b > c && a + c > b && b + c > a) return true;
			else return false;
		}
};

int main(){
	tamGiac tamgiac_1;
	tamgiac_1.nhap();
	
	if (tamgiac_1.checkTamgiac() == true){
		cout << "Tam giac hop le!";
	}else{
		cout << "Tam giac khong hop le!";
	}

	return 0;
}
