#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Vehicles{
	private:
		int tocdo;
	public:
		Vehicles(){
			
		}
		Vehicles(int td){
			this->tocdo = td;
		}
		int get_Tocdo(){
			return this->tocdo;
		}
		void set_Tocdo(){
			cin >> this->tocdo;
		}
		virtual void input(){
			cout << "Toc do tieu chuan: "; cin >> this->tocdo;
		}
		virtual void output(){
			cout << this->tocdo << "-";
		}
		virtual int maxSpeed() = 0;
};
 class Ferrari: public Vehicles{
 	private:
 		string mausac;
 		double hesotocdo;
	public:
		Ferrari(){
			
		}
		Ferrari(string mausac, double hesotocdo, int tocdo) : Vehicles(tocdo){
			this->mausac = mausac;
			this->hesotocdo = hesotocdo;
		}
		int maxSpeed(){
			return this->hesotocdo * this->get_Tocdo();
		}
		void input(){
			Vehicles::input();
			cin.ignore();
			cout << "Mau sac: "; getline(cin, this->mausac);
			cout << "He so toc do: ";cin >> this->hesotocdo;
		
		}
		void output(){
			Vehicles::output();
			cout << this->mausac << "-" << this->hesotocdo << "-" << "-" << this->maxSpeed() << endl;
		}
		bool operator > (Ferrari &a){
			return  this->maxSpeed() > a.maxSpeed();
		}		
 };

int main(){
	vector<Vehicles*> phuongtien;
	int n;
	cout << "Nhap so luong phuong tien: ";
	cin >> n;
	for (int i = 0; i < n; i++){
		Vehicles *oto = new Ferrari();
		oto->input();
		phuongtien.push_back(oto);
	}
	for (int i = 0; i < phuongtien.size(); i ++){
		phuongtien[i]->output();
	}
	
	int maxchiso = 0;
	for (int i = 0; i < phuongtien.size(); i++){
		if (phuongtien[i] > phuongtien[maxchiso]){
			maxchiso = i;
		}
	}
	
	cout << "Phuong tien co toc do lon nhat la: " << endl;
	phuongtien[maxchiso]->output();
	return 0;
}

