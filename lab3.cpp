#include <list>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>
#define M_PI 3.14159265358979323846
using namespace std;
typedef double d;
int input(int a);

int main()
{
    //sin(x) ^ 2
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    list<d> list1;
    list<d> listx;
    ofstream out;          // поток для записи
    out.open("D:\\lab3.txt"); // окрываем файл для записи

    for (double i = 0; i < (M_PI / 4); i += (M_PI / 40)) 
    {
        list1.push_back(sin(i * i));
        listx.push_back(i);
        if (out.is_open())
        {
            out << fixed << setprecision(6) << i;
            out << "\t";
            out << fixed << setprecision(6) << sin(i * i) << endl;
        }

    }
    string line;
    ifstream file("D:\\lab3.txt");
    if (file.is_open())
    {
        cout << "X\t\tY" << endl;
        while (getline(file, line))
        { 
            cout << line << endl;
        }
    } 
    file.close();// закрываем файл
    cout << endl;

    list<d> list2;
    auto iter = list1.begin();
    while (iter != list1.end()) list2.push_back(pow(sin((*iter++ + *iter++) / 2), 2));

    iter = list1.begin();
    while (iter != list1.end()) listx.push_back((*iter++ + *iter++) / 2);
            
    cout << "Масив після додавання елементів: " << endl;
    list1.insert(list1.end(), list2.begin(), list2.end());
    iter = list1.begin();
    while (iter != list1.end())    
    {
        cout << *iter++ << endl;
    }
   
    int a, b;
    auto iter1 = list1.begin();
    auto iter2 = list1.begin();
    cout << "Від якої вершини видаляти?" << endl;
    a = input(list1.size());
    cout << "До якої вершини видаляти?" << endl;
    b = input(list1.size());
    
    for (int i = 0; i < a; i++) iter1++;
    for (int i = 0; i < b; i++) iter2++;

    list1.erase(iter1, iter2);

    iter1 = listx.begin();
    iter2 = listx.begin();

    for (int i = 0; i < a; i++) iter1++;
    for (int i = 0; i < b; i++) iter2++;
    listx.erase(iter1, iter2);

    iter1 = list1.begin();
    iter2 = listx.begin();
    cout << "X\t\tY" << endl;
    while(iter1 != list1.end()) 
    {
        cout << fixed << setprecision(6)<< *iter2++;
        cout << "\t";
        cout << fixed << setprecision(6) << *iter1++;
        cout << endl;
        
    }
    
    
}
int input(int a) {
    int x;
    do {
        cin >> x;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Помилка, введено не число" << endl;
            continue;
        }
        if (x < 0 || x > a - 1) {
            cout << " Введіть коректне число!" << endl;
            continue;
        }
        return x;
    } while (true);
    
}
