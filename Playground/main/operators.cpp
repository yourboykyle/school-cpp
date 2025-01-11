#include <iostream>

using namespace std;

class location {
public:
    location(int=0,int=0);
    void print()const;
    location operator+(location op2);
    location operator-(location op2);
    location operator=(location op2);
    location operator++();
private:
    int longitude;
    int latitude;
};

location::location(int lg, int lt) {
    longitude = lg;
    latitude = lt;
}
void location::print() const {
    cout << longitude << "\t";
    cout << latitude << "\n";
}
location location::operator+(location op2) {
    location temp;
    temp.longitude = longitude + op2.longitude;
    temp.latitude = latitude + op2.latitude;
    return temp;
}
location location::operator-(location op2) {
    location temp;
    temp.longitude = longitude - op2.longitude;
    temp.latitude = latitude - op2.latitude;
    return temp;
}
location location::operator=(location op2) {
    longitude = op2.longitude;
    latitude = op2.latitude;
    return *this;
}
location location::operator++() {
    longitude++;
    latitude++;
    return *this;
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