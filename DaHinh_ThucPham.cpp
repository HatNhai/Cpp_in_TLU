#include <iostream>
#include <iostream>
#include <string>
using namespace std;

class thucpham{
	private:
		string ten;
		float gia;
	public:
		thucpham(){
		}
		thucpham(string Ten, float Gia)
		{
			this->ten = Ten; this->gia = Gia; 
		}
		string getTen()
		{
			return this->ten;
		}	
		virtual void nhap()
		{
			cout<< "Ten san pham: "; getline(cin, this->ten);
			cout<< "Gia san pham: "; cin>> this->gia;
			
		}
		virtual void xuat(){
			cout<< " San pham: "<< ten<<"; gia: "<< gia<<endl;
		}
};

class TPHOP : public thucpham{
	private:
		int soluong;
	public:
		TPHOP():thucpham(){
			soluong = 0;
		}
		TPHOP(string Ten, float Gia, int Soluong) : thucpham(Ten,Gia){
			soluong = Soluong;
		}
		void nhap(){
			thucpham::nhap();
			cout<< "so luong "; cin>>soluong; cin.ignore();
		}
		void xuat() {
			thucpham::xuat();
			cout<< "so luong = " << soluong<<endl;
		}
};
class TPKHOP: public thucpham{
	private:
		int khoiluong;
	public:
		TPKHOP():thucpham(){
			khoiluong = 0;
		}
		TPKHOP(string Ten, float Gia, int Khoiluong):thucpham(Ten,Gia){
			khoiluong = Khoiluong;
		}
		void nhap(){
			thucpham::nhap();
			cout<< " Khoi luong "; cin>>khoiluong;
		}
		void xuat() 
		{
			thucpham::xuat();
			cout<< " Khoi luong = " << khoiluong<<endl;
		}
};

void hienthi_danhsach(thucpham *pointer,int n)
{
	int i;
	for(i=0; i< n; i++)
		(pointer+i)->xuat();
}

void nhap_danhsach(thucpham *pointer,int n)
{
	int i;
	for(i=0; i< n; i++)
		(pointer+i)->nhap();
}

int main(int argc, char** argv) {
	TPHOP dstph[100];
	int n = 2;
	int i;
	thucpham *pointer; // con tro thuoc lop cha
	pointer = dstph; // tro vao dia chi doi tuong thuoc lop con
	nhap_danhsach(pointer,n);
	pointer = dstph;
	
	cout << "===" << endl;
	hienthi_danhsach(pointer,n);
		
	return 0;
}


