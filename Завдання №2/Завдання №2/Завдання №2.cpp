#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    typedef istream_iterator<int> ptin;
    typedef ostream_iterator<int> ptout;

    // Зчитування першого рядка (для множини A)
    string lineA;
    getline(cin, lineA);
    istringstream issA(lineA);
    multiset<int> A((ptin(issA)), (ptin()));

    // Зчитування другого рядка (для множини B)
    string lineB;
    getline(cin, lineB);
    istringstream issB(lineB);
    multiset<int> B((ptin(issB)), (ptin()));

    // Копіюємо A у вектор для обробки
    vector<int> vecA(A.begin(), A.end());
    sort(vecA.begin(), vecA.end());

    // Перебираємо всі елементи з B і видаляємо їх по одному з vecA
    for (int b : B) {
        auto it = lower_bound(vecA.begin(), vecA.end(), b);
        auto itEnd = upper_bound(vecA.begin(), vecA.end(), b);

        if (it != itEnd) {
            vecA.erase(it); // видаляємо одне входження
        }
    }

    // Виводимо результат
    copy(vecA.begin(), vecA.end(), ptout(cout, " "));
    cout << endl;

    return 0;
}
