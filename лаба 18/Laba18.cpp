#include "hashmap.h"


int main() {
	hashmap<int> table(5);
	table.insert("Yarik", 1488);
	table.insert("Sergey Bobko", 1337);
	table.insert("Irina Soboleva", 1945);
	table.insert("Mikhail", 1941);
	table.insert("Berdunov", 47);
	table.insert("Daniil", 5051);

	std::cout << table << std::endl;
	try {
		table.erase("Mikhail");
		std::cout << table << std::endl;
		table.erase("Bobik");
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::string h = "Mikhail";
	std::pair<int, bool>check = table.find(h);
	std::cout << "Serch element by key -> " << h <<std::endl;
	if (check.second == 0) {
		std::cout << "Bool->: " << check.second << ". Element doesn't exist:(";
	}
	else {

		std::cout<<"---------------"<<std::endl << "Bool-> " << check.second << ". Element exist:)" << std::endl;
		std::cout << "Value of this element-> " << check.first << std::endl << "---------------" << std::endl;
	}
	std::cout<<std::endl <<"----------------------------------------------------------------"<< std::endl;



	hashmap<char> table1(5);
	table1.insert("Yarik", 'r');
	table1.insert("Sergey Bobko", 'a');
	table1.insert("Irina Soboleva", 'b');
	table1.insert("Mikhail", 'h');
	table1.insert("Berdunov", 'Y');
	table1.insert("Daniil", 'E');

	std::cout << table1 << std::endl;
	try {
		table1.erase("Mikhail");
		std::cout << table1 << std::endl;
		table1.erase("Bobik");
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::string he = "Yarik";
	std::pair<char, bool>check1 = table1.find(he);
	std::cout << "Serch element by key -> " << he << std::endl;
	if (check1.second == 0) {
		std::cout << "Bool->: " << check1.second << ". Element doesn't exist:(";
	}
	else {

		std::cout << "---------------" << std::endl << "Bool-> " << check1.second << ". Element exist:)" << std::endl;
		std::cout << "Value of this element-> " << check1.first << std::endl << "---------------" << std::endl;
	}
	getchar();
	getchar();
	return 0;

}