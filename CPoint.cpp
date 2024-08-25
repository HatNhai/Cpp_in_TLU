#include <iostream>
#include <cmath>

using namespace std;

class CPoint{
	private:
		int x, y;
	public:
		CPoint(){
			
		}
		CPoint(int xx, int yy){
			this->x = xx;
			this->y = yy;
		}
		void nhap(){
			cout << "Nhap x: "; cin >> this->x;
			cout << "Nhap y: "; cin >> this->y;
		}
		void xuat(){
			cout << "(" << this->x << ", " << this->y << ")" << endl;
		}
		void diChuyen(){
			x += 1;
			y += 1;
		}
		double KhoangCach(CPoint &a, CPoint &b){
			CPoint kc;
			kc.x = b.x - a.x;
			kc.y = b.y - b.x;
			return sqrt( (kc.x)*(kc.x) + (kc.y)*(kc.y));
		}
		bool check(CPoint a, CPoint b, CPoint c) {
        double distanceAB = a.KhoangCach(*this, b);
        double distanceAC = b.KhoangCach(*this, c);
        double distanceBC = c.KhoangCach(*this, b);

        return (distanceAB == distanceAC && distanceAC == distanceBC);
    }
							
};



int main(){
	CPoint P1(5, 4);
	CPoint P2;
	P2.nhap();
	
	cout << "Toa do cac diem la: " << endl;
	P1.xuat();
	P2.xuat();
	
	P2.diChuyen();
	cout << "Sau khi dich chuyen diem P2 sang phai 1 don vi: " << endl;
	P2.xuat();
	
	cout << "Khoang cach P1 - P2: ";
    double khoangCach = P1.KhoangCach(P1, P2);
    cout << khoangCach << endl;
	
	CPoint P3;
	P3.nhap();
	
	bool thangHang = P1.check(P1, P2, P3);
    if (thangHang) {
        cout << "Ba diem P1, P2, va P3 thang hang." << endl;
    } else {
        cout << "Ba diem P1, P2, va P3 khong thang hang." << endl;
    }
	
	
	return 0;
}
