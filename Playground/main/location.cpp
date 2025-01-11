#include <iostream>
#include <string>

using namespace std;

class location {
public:
    location(int=0,int=0);
    void print()const;
    friend location operator+(location op1, location op2);
    friend location operator-(location op1, location op2);
    friend location operator++(location op1);
    friend location operator--(location op1);
private:
    int longitude;
    int latitude;
};

location::location(int lg, int lt) {longitude = lg;
    latitude = lt;
}
void location::print() const {
cout << longitude << "\t";
cout << latitude << "\n";
}

// Friend functions
location operator+(location op1, location op2) {
    location temp;
    temp.longitude = op1.longitude + op2.longitude;
    temp.latitude = op1.latitude + op2.latitude;
    return temp;
}
location operator-(location op1, location op2) {
    location temp;
    temp.longitude = op1.longitude - op2.longitude;
    temp.latitude = op1.latitude - op2.latitude;
    return temp;
}
location operator++(location op1) {
    op1.longitude++;
    op1.latitude++;
    return op1;
}
location operator--(location op1) {
    op1.longitude--;
    op1.latitude--;
    return op1;
}


int main() {
    location ob1(10, 20), ob2(5, 30);
    ob1.print();
    ob2.print();
    ob1 = ob1 + ob2;
    ob1.print();
    ob1 = ob1 - ob2;
    ob1.print();
    ++ob1;
    ob1.print();
    ob1 = ob2;
    ob1.print();

    return 0;
}