#include <set>
#include <iostream>
#include <limits>

using namespace std;

class Set {
private:
    set<double> elements;

public:
    Set() {}

    Set(const initializer_list<double>& init) : elements(init) {}

    void addElement(double element) {
        elements.insert(element);
    }

    void deleteElement(double element) {
        elements.erase(element);
    }

    size_t size() const {
        return elements.size();
    }

    Set operator*(const Set& other) const {
        Set result;
        for (const auto& element : elements) {
            if (other.elements.count(element)) {
                result.addElement(element);
            }
        }
        return result;
    }

    Set operator+(const Set& other) const {
        Set result = *this;
        result.elements.insert(other.elements.begin(), other.elements.end());
        return result;
    }

    Set operator-(const Set& other) const {
        Set result;
        for (const auto& element : elements) {
            if (other.elements.find(element) == other.elements.end()) {
                result.elements.insert(element);
            }
        }
        for (const auto& element : other.elements) {
            if (elements.find(element) == elements.end()) {
                result.elements.insert(element);
            }
        }
        return result;
    }

    friend ostream& operator<<(ostream& os, const Set& set) {
        for (const auto& element : set.elements) {
            os << element << ' ';
        }
        return os;
    }

    friend istream& operator>>(istream& is, Set& set) {
        double element;
        while (is >> element) {
            set.addElement(element);
        }
        if (is.fail()) {
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return is;
    }
};

int main() {
    Set set1, set2;
    int choice;
    double element;

    cout << "1. Enter elements for set1 and set2\n"
         << "2. Generate elements for set1 and set2\n"
         << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter elements for set1 (end with non-number): ";
        cin >> set1;
        cout << "Enter elements for set2 (end with non-number): ";
        cin >> set2;
    } else if (choice == 2) {
        set1 = Set{1.0, 2.0, 3.0, 4.0};
        set2 = Set{4.0, 5.0, 6.0, 7.0};
    } else {
        cout << "Invalid choice\n";
        return 0;
    }
        while (true) {
            cout << "\n1. Add element to set1\n"
                 << "2. Add element to set2\n"
                 << "3. Delete element from set1\n"
                 << "4. Delete element from set2\n"
                 << "5. Display set1 and its power\n"
                 << "6. Display set2 and its power\n"
                 << "7. Display intersection of set1 and set2\n"
                 << "8. Display union of set1 and set2\n"
                 << "9. Display difference of set1 and set2\n"
                 << "0. Exit\n"
                 << "Enter your choice: ";
            cin >> choice;



        switch (choice) {
            case 1:
                cout << "Enter element to add to set1: ";
                cin >> element;
                set1.addElement(element);
                break;
            case 2:
                cout << "Enter element to add to set2: ";
                cin >> element;
                set2.addElement(element);
                break;
            case 3:
                cout << "Enter element to delete from set1: ";
                cin >> element;
                set1.deleteElement(element);
                break;
            case 4:
                cout << "Enter element to delete from set2: ";
                cin >> element;
                set2.deleteElement(element);
                break;
            case 5:
                cout << "Set1: " << set1 << '\n';
                cout << "Power of set1: " << set1.size() << '\n';
                break;
            case 6:
                cout << "Set2: " << set2 << '\n';
                cout << "Power of set2: " << set2.size() << '\n';
                break;
            case 7:
                cout << "Intersection: " << (set1 * set2) << '\n';
                break;
            case 8:
                cout << "Union: " << (set1 + set2) << '\n';
                break;
            case 9:
                cout << "Difference: " << (set1 - set2) << '\n';
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
//