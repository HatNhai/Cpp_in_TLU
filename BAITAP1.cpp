#include <iostream>

using namespace std;

class Person{
	private:
		string name, address;
	public:
		Person(string name, string address){
			this->name = name;
			this->address = address;
		}
		
		void setName(){
			cout << "Name: "; getline(cin, name);
		}
		
		string getNam(){
			return this->name;
		}
		
		void setAddress(){
			cout << "Address: "; getline(cin, address);
		}
		
		string getAddress(){
			return this->address;
		}
		
		virtual void xuat(){
			cout << this->name << "-" << this->address << "-";
		}
};

class Employee : public Person{
	private:
		int salary;
	public:
		Employee(string name, string address, int salary) : Person(name, address){
			this->salary = salary;
		}
		void xuat(){
			Person::xuat();
			cout << this->salary << endl;
		}
};

class Customer : public Person{
	private:
		int balance;
	public:
		Customer(string name, string address, int balance) : Person(name, address){	
			this->balance = balance;
		}
		void xuat(){
			Person::xuat();
			cout << this->balance << endl;
		}		
};

int main(){
	Person *employee1 = new Employee("Nguyen Van A", "Ha Noi", 1000000);
	Person *customer1 = new Customer("Nguyen Van B", "Ho Chi Minh", 2000000);
	employee1->xuat();
	customer1->xuat();	
	
	return 0;
}
