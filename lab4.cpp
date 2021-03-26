#include <conio.h>
#include <iostream>
#include <list>
#include <sstream>
#include <ostream>
#include <fstream>
using namespace std;


class Product
{
public:
	string name;
	int quantity;
	int buy;
	int sell;
	Product(string name, int quantity, int buy, int sell)
	{
		this->name = name;
		this->quantity = quantity;
		this->buy = buy;
		this->sell = sell;
	}	
};
void printer(list<Product> &list, bool check);
void list_find(list<Product> &list);
void list_append_start(list<Product> &list, Product a);
void list_append_end(list<Product> &list, Product a);
void myfpintf(string path);
void sum_of_product(list<Product>& list);
void list_element_delete(list<Product> &list);
void fscanf(list<Product> a);
void list_append_after(list<Product>& list, Product a);
void inputProduct(Product& p) {
	do {
		cin >> p.quantity >> p.buy >> p.sell;
		cin.clear();
		cin.ignore(32767, '\n');
		if (p.quantity < 1 || p.buy < 1 || p.sell < 1) cout << "Try again!" << endl;
	} while (p.quantity < 1);
	cin >> p.name;
}

bool sortBySell(Product &a, Product &b);

int main()
{
	char key;
	Product milk = Product("Milk", 100, 32, 30);
	Product apple = Product("Apple", 12, 20, 21);
	Product bread = Product("bread", 21, 344, 54);
	string path = "D:\\hello.txt";
	list<Product> list1;
	bool check = 0;
	list1.push_back(milk);
	list1.push_back(apple);
	list1.push_back(bread);
	do {		
		cout << "Hello, here is your menu" << endl << "Type" << endl;		
		cout << "1 to print the list and 2 to print reversed" << endl<<"3 to delete element"<<endl<<"4 to read the file"<<endl;
		cout << "5 to write to file" << endl << "6 to find the element" << endl << "7 to sort the list" << endl<<"8 to create the element like( quantity buy sell name)" <<endl;
		cout << "Type 9 to gain the sum" << endl;
		key = _getch();	
		////9  create element
		if (key == 56) {
			system("cls");
			cout << "Type the element: quantity, buy price, sell price, name" << endl;			
			Product product("", 0, 0, 0);
			inputProduct(product);
			char key2;
			do {				
				cout << "1 to add element in front" << endl << "2 to add element in back and 3 to insert" << endl;
				key2 = _getch();
				if (key2 == 50) list_append_end(list1, product);
				else if (key2 == 49) list_append_start(list1, product);
				else if (key2 == 51) list_append_after(list1, product);
				else cout << "Error try again" << endl;
			} while (key2 != 50 && key2 != 49 && key2 != 51);
			continue;
		}
		switch (key)
		{		
			//1 prints elements
		case 49:
			system("cls");
			printer(list1, true);
			break;	
			//2 prints reversed
		case 50:
			system("cls");
			printer(list1, false);
			break;
			//3 deletes element
		case 51:
			system("cls");
			list_element_delete(list1);
			break;
			//4 writes the file
		case 52:
			system("cls");
			myfpintf(path);
			break;
			//5 reads the file
		case 53:
			system("cls");
			fscanf(list1);
			break;
			//6 find
		case 54:
			system("cls");
			list_find(list1);
			break;
			//7 sort 
		case 55:
			system("cls");
			list1.sort(sortBySell);
			break;
		case 57:
			system("cls");
			sum_of_product(list1);
			break;		
		case 27:
			break;
		default:
			cout << "Error key, try again!" << endl;
			break;
		}
		
	} while (key != 27);
	return 0;
}
void list_append_start(list<Product> &list, Product a) {
	list.push_front(a);
}
void sum_of_product(list<Product>& list) {
	cout << "Type the name of product" << endl;
	string name1;
		cin >> name1;
		cin.clear();
		cin.ignore(32767, '\n');
		for (auto iter : list) {
			if (iter.name == name1)  cout << iter.quantity * iter.sell << endl;;
		}
		cout << "Product with this name doesn`t exist" << endl;	
}
void list_element_delete(list<Product> &list) {
	int a;
	do {
		cout << "Type the number of element, that u want to remove" << endl;
		cin >> a;
		cin.clear();
		cin.ignore(32767, '\n');
		if (a < 0 || a >list.size()) cout << "Error" << endl;
	} while (a < 0 || a >list.size());

	int count = 0;
	for (auto iter = list.begin(); iter != list.end(); iter++) {
		if (count == a) {
			list.erase(iter);
			break;
		}
		count++;
	}
	cout << "Successfully deleted" << endl;
		
		
	}
void list_append_after(list<Product>& list, Product a) {
	int pos;
	do {
		cout << "Type the position where u want to insert element: ";
		cin >> pos;
		cin.clear();
		cin.ignore(32767, '\n');
		if (pos < 0 || pos > list.size()) cout << "Error" << endl;

	} while (pos < 0 || pos > list.size());
	auto iter = list.begin();
	for (int i = 0; i <= pos; i++) {
		iter++;
	}
	list.insert(iter, a);
}
void list_append_end(list<Product> &list, Product a) {
	list.push_back(a);
}
void list_find(list<Product> &list) {
	int a;
	do {
		cout << "Type the number of element, that u want to find" << endl;
		cin >> a;
		cin.clear();
		cin.ignore(32767, '\n');
		if (a < 0 || a >list.size()) cout << "Error" << endl;
	} while (a < 0 || a >list.size());
	if (!list.empty()) {
		int count = 0;
		for (auto iter : list) {
			if (count == a) {
				cout << iter.name << " Amount: " << iter.quantity << " Buy price: " << iter.buy << " Sell price: " << iter.sell << endl;
				break;
			}
			count++;
		}		
	}
	
}
void printer(list<Product> &list, bool check) {
	if (check) for (auto iter : list)
	{
		cout << iter.name <<" Amount: "<<iter.quantity<<" Buy price: "<<iter.buy<<" Sell price: "<<iter.sell<<endl;
	}
	else {
		list.reverse();
		for (auto item : list) {
			cout << item.name << " Amount: " << item.quantity << " Buy price: " << item.buy << " Sell price: " << item.sell << endl;
		}
		list.reverse();
	}
}
bool sortBySell(Product &a, Product &b) {
	return a.sell < b.sell;
}

void fscanf(list<Product> a) {
	ofstream out;
	out.open("D:\\hello.txt"); // окрываем файл для записи
	if (out.is_open())
	{
		for(auto iter : a) out << iter.name <<endl;
	}
	out.close();	
}
void myfpintf(string path) {
	string line;
	ifstream in(path);
	if (in.is_open()) {
		while (getline(in, line)) {
			cout << line << endl;
		}
	}
	in.close();
}
