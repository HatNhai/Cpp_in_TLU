#include <iostream>

using namespace std;

class Employee{
	private:
		string name;
		int paymentPerHour;
	public:
		Employee(string name, int paymentPerHour)
		{
			this->name = name;
			this->paymentPerHour = paymentPerHour;
		}
		void setName(string name)
		{
			cout << "Nhap ten: "; getline(cin, this->name);
		}
		string getName()
		{
			return this->name;
		}
		void setPaymentPerHour(int paymentPerHour)
		{
			cout << "Nhap luong 1 gio: "; cin >> this->paymentPerHour; cin.ignore();
		}
		int getPaymentPerHour()
		{
			return this->paymentPerHour;
		}
		virtual int calculateSalary() = 0;
};

class PartTimeEmployee : public Employee{
	private:
		int workingHours;
	public:
		PartTimeEmployee(string name,int paymentPerHour, int workingHours) : Employee(name, paymentPerHour), workingHours(workingHours){
		}
		int getworkingHours(){
			return this->workingHours;
		}
		int calculateSalary(){
			return getPaymentPerHour() * getworkingHours();
		}	
};

class FullTimeEmployee : public Employee{
	public:
		FullTimeEmployee(string name, int paymentPerHour) : Employee(name, paymentPerHour){
		}
		int calculateSalary(){
			return 8 * getPaymentPerHour();
		}
};

int main(){
	Employee *employee1 = new PartTimeEmployee("Trung", 45000, 7);
	cout << "Name: " << employee1->getName() << endl;
	cout << "Salary per day: " << employee1->calculateSalary() << endl;
	
	Employee *employee2 = new FullTimeEmployee("Linh", 65000);
	cout << "Name: " << employee2->getName() << endl;
	cout << "Salary per day: " << employee2->calculateSalary() << endl;
	
	return 0;
}
