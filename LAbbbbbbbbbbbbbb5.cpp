istream & operator >> (istream &in, Xemay &a) {
	getline(in, a.tenbike);
	getline(in, a.nambike);
	getline(in, a.maubike);
	getline(in, a.nlbike);
	return in;
}
ostream & operator << (ostream &out, Xemay a) {
	out << a.getMa2() << "-" << a.getTenbike() << "-" << a.getNambike() << "-" << a.getHangxe() << "-" << a.getGia() << "-" << a.getMaubike() << endl;
	return out;
}

int main(){
    PTGT ds[100];
    Oto Car[100];
    Xemay Bike[100];
    int n, dshangxe, type = 0, j = 0, k = 0;
    long long res = 0;
    
    cin >> dshangxe;
    cin.ignore();
    Hangxe hangxe[dshangxe];
    for(int i = 0; i < dshangxe; i++) {
    	hangxe[i].NhapHx();
	}
	
	cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> type;
    	cin.ignore();
    	
        if(type == 0){
            Car[j].NhapPt(hangxe);
            Car[j].NhapOto();
            ds[i] = Car[j];
            j++;
        } else{
            Bike[k].NhapPt(hangxe);
            Bike[k].Nhapbike();
            ds[i] = Bike[k];
            k++;
        }
    }
    for(int i = 0; i < j; i++) {
		Car[i].HienThi();
		res += Car[i].giaOto();
    	for(int m = i; m < k; m++) {
    		Bike[m].HienThi();
    		res += Bike[m].giaXemay();
		} 
	}
	cout << "====\n";
	cout << res;
    
    return 0;
}
