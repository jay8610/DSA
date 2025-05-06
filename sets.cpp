#include <iostream>
using namespace std;

class Set {
public:
    int cnt;
    int a[10];

    Set() { cnt = 0; }

    void Insert(int n) {
        cout << "Enter elements for the set: ";
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            if (cnt >= 10) {
                cout << "Set full! Cannot add more." << endl;
                break;
            }
            if (Contain(val) == -1) {
                a[cnt++] = val;
            } else {
                cout << val << " exists. Skipped." << endl;
            }
        }
    }

    void Display() {
        cout << "{ ";
        for (int i = 0; i < cnt; i++) cout << a[i] << " ";
        cout << "}" << endl;
    }

    int Contain(int key) {
        for (int i = 0; i < cnt; i++) {
            if (a[i] == key) return i;
        }
        return -1;
    }

    void Size() { cout << "Size: " << cnt << endl; }

    void Remove() {
        int ele, idx;
        cout << "Enter element to remove: ";
        cin >> ele;
        idx = Contain(ele);
        if (idx != -1) {
            for (int i = idx; i < cnt - 1; i++) a[i] = a[i + 1];
            cnt--;
            cout << ele << " removed." << endl;
        } else {
            cout << ele << " not found!" << endl;
        }
    }

    void Union(Set s1, Set s2) {
        cnt = 0;
        for (int i = 0; i < s1.cnt; i++) AddUnique(s1.a[i]);
        for (int i = 0; i < s2.cnt; i++) AddUnique(s2.a[i]);
    }

    void Intersection(Set s1, Set s2) {
        cnt = 0;
        for (int i = 0; i < s1.cnt; i++) {
            if (s2.Contain(s1.a[i]) != -1) AddUnique(s1.a[i]);
        }
    }

    void Difference(Set s1, Set s2) {
        cnt = 0;
        for (int i = 0; i < s1.cnt; i++) {
            if (s2.Contain(s1.a[i]) == -1) AddUnique(s1.a[i]);
        }
    }

    void Subset(Set s1, Set s2) {
        int matches = 0;
        for (int i = 0; i < s1.cnt; i++) {
            if (s2.Contain(s1.a[i]) != -1) matches++;
        }
        cout << "Set-1 is " << (matches == s1.cnt ? "" : "not ") << "a subset of Set-2." << endl;
    }

private:
    void AddUnique(int val) {
        if (cnt < 10 && Contain(val) == -1) a[cnt++] = val;
    }
};

int main() {
    Set obj, s1, s2, result;
    int choice, n;

    do {
        cout << "\nMenu:\n1.Insert\n2.Display\n3.Search\n4.Size\n5.Remove\n6.Union\n7.Intersection\n8.Difference\n9.Subset\n10.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter number of elements: ";
                cin >> n;
                obj.Insert(n);
                break;
            case 2:
                obj.Display();
                break;
            case 3: {
                int key;
                cout << "Enter key: ";
                cin >> key;
                int idx = obj.Contain(key);
                cout << (idx != -1 ? "Found at index " + to_string(idx) : "Not found") << endl;
                break;
            }
            case 4:
                obj.Size();
                break;
            case 5:
                obj.Remove();
                break;
            case 6:
                cout << "For Union:\n";
                cout << "Set-1 size: ";
                cin >> n;
                s1.Insert(n);
                cout << "Set-2 size: ";
                cin >> n;
                s2.Insert(n);
                result.Union(s1, s2);
                cout << "Union: ";
                result.Display();
                break;
            case 7:
                cout << "For Intersection:\n";
                cout << "Set-1 size: ";
                cin >> n;
                s1.Insert(n);
                cout << "Set-2 size: ";
                cin >> n;
                s2.Insert(n);
                result.Intersection(s1, s2);
                cout << "Intersection: ";
                result.Display();
                break;
            case 8:
                cout << "For Difference (s1 - s2):\n";
                cout << "Set-1 size: ";
                cin >> n;
                s1.Insert(n);
                cout << "Set-2 size: ";
                cin >> n;
                s2.Insert(n);
                result.Difference(s1, s2);
                cout << "Difference: ";
                result.Display();
                break;
            case 9:
                cout << "For Subset check:\n";
                cout << "Set-1 size: ";
                cin >> n;
                s1.Insert(n);
                cout << "Set-2 size: ";
                cin >> n;
                s2.Insert(n);
                result.Subset(s1, s2);
                break;
            case 10:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 10);

    return 0;
}
