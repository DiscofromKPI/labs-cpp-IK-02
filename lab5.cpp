#include <iostream>
#include <conio.h>
#include <stack>
#include <string>

typedef int i;
using namespace std;
i input();
void print_stack(stack<i> s);
void two_stacks(stack<i> s);
void check_enum();
void main() {
    setlocale(LC_ALL, "Russian");
	stack <i> stack;
	i amount, num;
    cout << "Введите количество элементов в стеке" << endl;
    amount = input();
   
    for (int i = 0; i < amount; i++) {
        cout << "Введите элемент стека " << i << ": ";
        stack.push(input());
    }
    print_stack(stack);
    cout << endl;
    two_stacks(stack);
    cout << endl;
    check_enum();
}
i input() {
    i x;
    do {
        cin >> x;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Error, entered not a number" << endl;
            continue;
        }
        return x;
    } while (true);   
}
void print_stack(stack<i> s) {
    if (s.empty()) return;
    int t = s.top();
    s.pop();
    cout << t << " ";
    print_stack(s);
    s.push(t);    
}
void two_stacks(stack<i> s) {
    stack<i> even;
    stack<i> odd;
    while (!s.empty()) {
        if (s.top() % 2 == 0) {
            even.push(s.top());
            s.pop();
        }
        else {
            odd.push(s.top());
            s.pop();
        }
    }
    cout << "Четный стек: " << endl;   
    while (!even.empty()) {
        int t = even.top();
        cout << t << " ";
        even.pop();
    }
    cout << endl;
    cout << "Нечетный стек: " << endl;
    while (!odd.empty()) {
        int t = odd.top();
        cout << t << " ";
        odd.pop();
    }
    
}
void check_enum() {
    string s;
    stack<char> b;
    cout << "Введите строку: " << endl;
    cin >> s;
    for (auto c = s.begin(); c != s.end(); c++) {
        if (*c == ')' && b.top() == '(' || *c == ']' && b.top() == '[' || *c == '}' && b.top() == '{') b.pop();
        else if (*c == ')' || *c == ']' || *c == '}') {
            cout << "Последовательность неверна!" << endl;
            return;
        }
        else {
            b.push(*c);
        }
    }
    b.empty() ? cout << "Последовательность верна!" : cout << "Последовательность неверна!";
}
