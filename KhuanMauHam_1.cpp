#include <iostream>

using namespace std;

template<class T>
class Pair{
    public:
        Pair(): first(T()), second(T()) {}
        Pair(T firstValue,T secondValue){
            this->first = firstValue;
            this->second = secondValue;
        }
        void setFirst(T newValue){
            this->first = newValue;
        }
        void setSecond(T newValue){
            this->second = newValue;
        }
        T getFirst() const{return first;}
        T getSecond() const{return second;}
    private:
        T first;
        T second;
};
int main(){
    Pair<int> pair;
    int temp;
    cout<<"Nhap so thu nhat: "; cin>>temp;
    pair.setFirst(temp);
    
    cout<<"Nhap so thu hai: "; cin>>temp;
    pair.setSecond(temp);
    
    cout<<"Cac so da nhap nhap la: "<<pair.getFirst()<<" "<<pair.getSecond();
    return 0;
}

