#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;
typedef double d;
double input();
double approximate(double x, int &iter);
int main() {
    do {
        d x1, exactlynum, x2, step, sum, result = 0;

        cout << "Type the x1" << endl;
        x1 = input();
        do {
            cout << "Type the x2" << endl;
            x2 = input();
            if(x2 <= x1) cout << "Error, Type the x2 > x1" << endl;
        }while(x2 <= x1);
        step = (x2 - x1) / 10;

        int iter = 0;
        cout << "x\t" <<"precise\t"<<"\t"<<"approximate\t"<<"number of iterations\t"<<"tweak"<<endl;
        for(; x1 < x2; x1 += step){
            cout<<x1<<"\t"<<atan(x1)<<"\t"<<approximate(x1, iter)<<"\t"<<"\t"<<iter<<"\t"<<atan(x1) - approximate(x1, iter)<<endl;
        }
    }while(getch() != 27);
    return 0;
}
double input(){
    double x;
    do {
        cin >> x;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Error, entered not a number" << endl;
        }
        if(x >= -1){
            cout << "Error, type the number < -1 "<< endl;
        }
    }while(x >= -1 || cin.fail());
    return x;
}
double approximate(double x, int &iter){
    d sum, result = 0;
    int n = 0;
    do{
        sum = (pow(-1, n)) / (((2 * n) + 1) * pow(x, 2 * n + 1));
        iter++;
        n++;
        result += sum;
    }while((atan(x) - sum) >= 0.001);
    return result;
}
