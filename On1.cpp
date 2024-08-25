#include <iostream>

using namespace std;

class PhuongTienGiaoThong{
    private:
        string hang;
        string ten;
        int nam;
        float vantoc;
    public:
        PhuongTienGiaoThong(){
            this->hang = "";
            this->ten = "";
            this->nam = 0;
            this->vantoc = 0.0;
        }
        void nhap(){
            cout << "Hang xe: "; getline(cin, this->hang);
            cout << "Ten xe: "; getline(cin, this->ten);
            cout << "Nam san xuat: "; cin >> this->nam;
            cout << "Van toc: "; cin >> this->vantoc;
        }
        void xuat(){
            cout << this->hang << "-" << this->ten << "-" << this->nam << "-" << this->vantoc;
        }
};

class Oto : public PhuongTienGiaoThong{
    private:
    int so_cho_ngoi;
    string kieu_dong_co;
    public:
    Oto(){
        this->so_cho_ngoi = 0;
        this->kieu_dong_co = "";
    }
    void nhap(){
        PhuongTienGiaoThong::nhap;
        cout << "So cho ngoi: "; cin >> this->so_cho_ngoi;
        cout << "Kieu dong co: ";getline(cin, this->kieu_dong_co);
    }
    void xuat(){
        PhuongTienGiaoThong::xuat;
        cout << "-" << this->so_cho_ngoi << "-" << this->kieu_dong_co << endl;
    }
};

int main(){



    return 0;
}