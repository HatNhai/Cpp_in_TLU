#include <iostream>

using namespace std;

int gcd(int a, int b){ //Ham tinh uoc so chung lon nhat
	if (b == 0) return a;
	return gcd(b, a % b);
}

class PhanSo{
	private:
		int tu, mau;
	public:
		PhanSo();
		friend istream& operator >> (istream&, PhanSo &);
		friend ostream& operator << (ostream&, PhanSo &);
		void rutgon();
};

PhanSo::PhanSo(){
	this->tu = tu;
	this->mau = mau;
}

istream& operator >> (istream& in, PhanSo &a){
	in >> a.tu >> a.mau;
	return in;
}

ostream& operator << (ostream& out, PhanSo &a){
	out << a.tu << "/" << a.mau << endl;
	return out;
}

void PhanSo::rutgon(){
	int g = gcd(tu, mau);
	tu = tu / g;
	mau = mau / g;
}

int main(){
	 PhanSo a;
	 cin >> a;
	 a.rutgon();
	 cout << a;
	return 0;
}
