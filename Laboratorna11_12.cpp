#include <iostream>
#include "Windows.h"
#include <forward_list>
#include<iomanip>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    forward_list<int> numberList;

    //Додаємо цілі числа до списку
    numberList.push_front(12);
    numberList.push_front(10);
    numberList.push_front(11);
    numberList.push_front(7);
    numberList.push_front(27);
    numberList.push_front(4);

    cout << "Початковий список цілих чисел: ";
    for (int number : numberList) {
        cout << number << " ";
    }
    cout << endl;

    //Видалити перший парний елемент, який знаходиться на непарній позиції
    int position = 0;
    auto prev = numberList.before_begin();
    for (auto it = numberList.begin(); it != numberList.end(); ++it, ++position) {
        if (position % 2 == 1 && *it % 2 == 0) {  // Якщо позиція непарна і елемент парний
            numberList.erase_after(prev);         // Видаляємо елемент після prev
            break;
        }
        prev = it;  // Оновлюємо prev, щоб тримати попередній елемент
    }

    cout << "Список після видалення першого парного елемента на непарній позиції: ";
    for (int number : numberList) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}

