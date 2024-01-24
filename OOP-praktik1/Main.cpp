#include <iostream>


class Cassa {
private:
	int money_;

public:

	Cassa():money_(0){}

	int CurrentMoney() {
		return money_;
	}

	void CashIn(int money) {
		this->money_ += money;
	}
	
	void CashOut(int money) {
		if (money > money_) {
			std::cerr << "Not enough money\n";
			return;
		}

		this->money_ -= money;
	}

	int Exchenge(int ticket, int money) {
		if (money < ticket) {
			std::cerr << "Not enough money for operation\n";
			return money;
		}
		if (money_ < money - ticket) {
			std::cerr << "Not enough money for return change\n";
			return money;
		}
		money_ += ticket;
		return money - ticket;
	}

};

int main() {
	setlocale(0, "");
	
	Cassa var1;
	Cassa var2;
	
	var1.CashIn(1000);

	std::cout << "First cassa has " << var1.CurrentMoney() << std::endl;
	std::cout << "Second cassa has " << var2.CurrentMoney() << std::endl;

	var1.CashOut(2000);
	std::cout << "First cassa has " << var1.CurrentMoney() << std::endl;
	var1.CashOut(200);
	std::cout << "First cassa has " << var1.CurrentMoney() << std::endl;

	var2.CashOut(20);
	std::cout << "Second cassa has " << var2.CurrentMoney() << std::endl;
	var2.CashOut(20);
	std::cout << "Second cassa has " << var2.CurrentMoney() << "\n\n";


	int change = 0;
	std::cout << "Second cassa has " << var2.CurrentMoney() << std::endl;
	change = var2.Exchenge(100, 20);
	std::cout << "Second cassa has " << var2.CurrentMoney() << std::endl;
	std::cout << "change is - " << change << "\n\n";

	std::cout << "Second cassa has " << var2.CurrentMoney() << std::endl;
	change = var2.Exchenge(100, 120);
	std::cout << "Second cassa has " << var2.CurrentMoney() << std::endl;
	std::cout << "change is - " << change << "\n\n";

	std::cout << "Second cassa has " << var2.CurrentMoney() << std::endl;
	change = var2.Exchenge(100, 100);
	std::cout << "Second cassa has " << var2.CurrentMoney() << std::endl;
	std::cout << "change is - " << change << "\n\n";

	std::cout << "Second cassa has " << var2.CurrentMoney() << std::endl;
	change = var2.Exchenge(10, 20);
	std::cout << "Second cassa has " << var2.CurrentMoney() << std::endl;
	std::cout << "change is - " << change << "\n\n";

	return 0;
}