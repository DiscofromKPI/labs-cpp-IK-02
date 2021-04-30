#include <iostream>
#include <cmath>

using namespace std;


#define M_PI 3.14159265358979323846
class circle {
public:
    double r;
    int x;
    int y;
    double S = M_PI* pow(r, 2);
    void input() {
        cout << "Input radius" << endl;
        cin >> r;
        cout << "type the position x and y" << endl;
        cin >> x >> y;
    }
    void Show_square() {        
        cout << "Square of the circle = " << S << endl;
    }
    void length_circle() {
        cout << "Length of the circle = " << 2 * M_PI * r << endl;
    }
    void show_circle() {
        cout << "Radius of the circle = " << r << " And the position of circle is ( " << x << ";" << y << " )" << endl;
    }
    circle(double r, int x, int y) {
        this->r = r;
        this->x = x;
        this->y = y;
    }
    circle(){} //constructor

    ~circle() {  //deconstructor
        (void)0;
    }
    
    circle operator +(const circle& c) {
        circle circle;
        circle.x = this->x;
        circle.y = this->y;
        circle.S = this->S + c.S;
        return circle;
    }
    circle operator -(const circle& c) {
        circle circle;
        circle.x = this->x;
        circle.y = this->y;
        circle.S = this->S - c.S;
        return circle;
    }
    double operator *( double t) {       
        return this->r * t;
    }
    double operator /(double t) {
        return this->r / t;
    }
    circle& operator ++() {
        x++;
        return *this;
    }
    circle& operator--() {
        x--;
        return *this;
    }
    circle operator++(int) {
        y++;
        return *this;
    }
    circle operator --(int) {
        y--;
        return *this;
    }
    bool operator ==( circle &c1) {
        return c1.S == this->S;
    }
    bool operator !=(circle &c1) {
        return c1.S != this->S;
    }
    bool operator >(circle &c1) {
        return this->S > c1.S;
    }
    bool operator <(circle &c1) {
        return this->S < c1.S;
    }
};
int main()
{
    circle circle1;
    circle c2(11, 2, 3);
    circle c3(23, 5, 6);
    circle1.input();
    circle1.show_circle();
    circle1.Show_square();
    circle1.length_circle();

    circle result = c2 + c3;
    cout << "Square of sum" << endl;
    result.Show_square();
    
    cout << "Prefix ++ " << ++c2.x << endl;
    
    cout << "Postfix ++ " << c2++.x << endl;

    cout << "Postfix -- " << c2--.x << endl;

    cout << "Prefix -- " << c2--.x << endl;

    cout << "Operator < " << (c2 < c3) << endl;

    cout << "Operator > " << (c2 > c3) << endl;

    cout << "Operator == " << (c2 == c3) << endl;

    cout << "Operator != " << (c2 != c3) << endl;

    cout << "Operator * " << (c2 * 3) << endl;

    cout << "Operator / " << (c2 / 3) << endl;
    circle minus = c2 - c3;
    cout << "Operator - " <<endl;
    minus.Show_square();
}
