#include <iostream>

using namespace std;

class Count{
public:
	int number;
	double balance;
	
	double deposit(double value){
		if(value > 0) return balance += value;
	}

	double cash_out(double value){
		if (value > 0) balance -= value;
	}
};

int main (void){
	Count c;
	double value;
	int op;

	c.number = 0001;
	c.balance = 5000.00;

	while(scanf("%d", &op) != 0){
		switch(op){	
			case 1:
			cout << "Whats is value to deposit:" <<endl;
			cin >> value;
			c.deposit(value);

			break;
	
			case 2:
			cout << "Whats is the cash out value:" <<endl;
			cin >> value;
			c.cash_out(value);
			break;

			case 3:
			cout << "ID account:" << c.number << endl;
			cout << "Cash in account: " << c.balance << endl;

			default:
				exit(1);


		}

	}
	return 0;
}