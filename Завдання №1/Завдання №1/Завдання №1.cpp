#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

// Типи для вводу та виводу
typedef istream_iterator<int> ptin;
typedef ostream_iterator<int> ptout;

// Функція для виведення списку з поясненням
template<typename Iterator>
void ShowLine(Iterator begin, Iterator end, const string& label) {
    cout << label;
    for (auto it = begin; it != end; ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {

    setlocale(LC_ALL, "ukr");

    // Зчитування списку з консолі
    list<int> L((ptin(cin)), ptin());

    // Вивід початкового списку
    ShowLine(L.begin(), L.end(), "Список до обробки: ");

    // Обхід у зворотному порядку
    auto rfirst = L.rbegin();
    auto rlast = L.rend();

    // Знаходження першої (тобто останньої у звичайному порядку) пари однакових сусідів
    auto rit = adjacent_find(rfirst, rlast);

    if (rit != rlast) {
        // Створюємо звичайний (прямий) ітератор з реверсного:
        // rit.base() - вказує на елемент ПІСЛЯ rit
        auto insert_pos = rit.base(); // позиція другого елемента з пари

        // Вставляємо нове значення перед другим однаковим
        L.insert(insert_pos, *rit);
    }

    // Вивід фінального списку
    ShowLine(L.begin(), L.end(), "Список після обробки: ");

    return 0;
}
