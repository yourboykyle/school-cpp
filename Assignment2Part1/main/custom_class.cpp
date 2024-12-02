#include <iostream>
#include <string>

using namespace std;

class BaseClass {
private:
    int id;

protected: // Can only be accessed by derived (child) classes
    string name;

public:
    BaseClass(int id, const string& name) : id(id), name(name) {}
    BaseClass(const BaseClass& other) : id(other.id), name(other.name) {}

    int getId() const { return id; }
    void setId(int newId) { id = newId; }

    void display() const {
        cout << "BaseClass: ID=" << id << ", Name=" << name << endl;
    }
};

class DerivedClass : public BaseClass {
private:
    double value;

public:
    DerivedClass(int id, const string& name, double value)
        : BaseClass(id, name), value(value) {}

    double getValue() const { return value; }
    void setValue(double newValue) { value = newValue; }

    void displayDerived() const {
        cout << "DerivedClass: ID=" << getId() << ", Name=" << name
                  << ", Value=" << value << endl;
    }

    DerivedClass operator+(const DerivedClass& other) const {
        return DerivedClass(getId(), name + "&" + other.name, value + other.value);
    }
};

class UtilityClass {
public:
    static void compare(const BaseClass& obj1, const BaseClass& obj2) {
        if (obj1.getId() == obj2.getId()) {
            cout << "Objects have the same ID." << endl;
        } else {
            cout << "Objects have different IDs." << endl;
        }
    }

    static void describeBase(const BaseClass& obj) {
        obj.display();
    }

    static void describeDerived(const DerivedClass& obj) {
        obj.displayDerived();
    }
};

int main() {
    BaseClass base(1, "BaseObject");
    DerivedClass derived1(2, "DerivedObject1", 10.5);
    DerivedClass derived2(3, "DerivedObject2", 20.5);

    base.display();
    derived1.displayDerived();
    derived2.displayDerived();

    DerivedClass combined = derived1 + derived2;
    combined.displayDerived();

    UtilityClass::compare(base, derived1);
    UtilityClass::describeBase(base);
    UtilityClass::describeDerived(combined);

    return 0;
}