#include <iostream>

using namespace std;

class MayIn{
	private:
		float trongluong;
		string hangsx;
		int namsx;
		int tocdo;
		int soluong;
		long long gia;
	public:
		MayIn(){
			this->trongluong = 0.0;
			this->hangsx = "";
			this->namsx = 0;
			this->tocdo = 0;
			this->soluong = 0;
			this->gia = 0;
		}
		MayIn(float tl, string hsx, int nsx, int td, int sl, long long gia){
			this->trongluong = tl;
			this->hangsx = hsx;
			this->namsx = nsx;
			this->tocdo = td;
			this->soluong = sl;
			this->gia = gia;
		}
		~MayIn(){
		}
		float getTrongluong(){
			return this->trongluong;
		}
		string getHangsx(){
			return this->hangsx;
		}
		int getNamsx(){
			return this->namsx;
		}
		int getTocdo(){
			return this->tocdo;
		}
		long long getGia(){
			return this->gia;
		}
		int getSoluong(){
			return this->soluong;
		}
		void nhap(){
			cout << "Trong luong: "; cin >> this->trongluong; cin.ignore();
			cout << "Hang san xuat: "; getline(cin, this->hangsx);
			cout << "Nam san xuat: "; cin >> this->namsx;
			cout << "Toc do: "; cin >> this->tocdo;
			cout << "So luong: "; cin >> this->soluong;
		}
		MayIn operator + (MayIn &mayin){
			MayIn tong;
			tong.gia = this->gia + mayin.gia;
			return tong;
		}			
};

class MayInKim : public MayIn{
	private:
		int matdokim;
		long long gia_2;
	public:
		MayInKim(){
			this->matdokim = 0;
			this->gia_2 = 0;
		}
		MayInKim(int matdok, long long price){
			this->matdokim = matdok;
			this->gia_2 = price;
		}
		~MayInKim(){
			
		}
		int get_Matdokim(){
			return this->matdokim;
		}
		long long get_Gia2(){
			return this->gia_2;
		}
		void nhap(){
			MayIn::nhap();
			cout << "Mat do kim: "; cin >> this->matdokim;
			cout << "Gia 1 to in: "; cin >> this->gia_2;
		}
		long long giaInKim(){
			return this->get_Gia2() * this->getSoluong();
		}
};

class MayInLaser : public MayIn{
	private:
		float do_phan_giai;
		long long gia_1;
	public:
		MayInLazer(){
			this->do_phan_giai = 0.0;
			this->gia_1 = 0;
		}
		MayInLazer(float dophangiai, long long gia1){
			this->do_phan_giai = dophangiai;
			this->gia_1 = gia1;
		}
		
		long long getGia_1(){
			return this->gia_1;
		}
		
		~MayInLaser(){	
		}
		
		void nhap(){
			MayIn::nhap();
			cout << "Do phan giai: "; cin >> this->do_phan_giai;
			cout << "Gia 1 to: "; cin >> this->gia_1;
		}	
			
		long long giaInLaser(){
			return this->getGia_1() * this->getSoluong();
		}
};

int main(){
	int n;
	cout << "Nhap so luong may in: "; cin >> n;
	cin.ignore();
	
	MayIn print_machine[100];
	MayInKim kim[100];
	MayInLaser laser[100];
	long long tong = 0;
	
	for (int i = 0; i < n; i++){
		int type = 0;
		int loai;
		cout << "Nhap loai may in (0 - May Kim 1 - May Laser): "; cin >> loai;
		if (type == loai){
			kim[i].nhap();
			tong += kim[i].giaInKim();
			//Nhap thong tin may in kim
		}else{
			laser[i].nhap();
			tong += laser[i].giaInLaser();
			//Nhap thong tin may in laser
		}
	}
	cout << "===" << endl;
	cout << "Tong hoa don can thanh toan: " << tong;
	
	return 0;
	
}
