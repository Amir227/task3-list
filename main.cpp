#include "list.h"
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    List lst;
    cout << "Пожалуйста, введите элементы которые хотите записать в список, "
            "нажмите на 'ENTER' чтобы прекратить ввод:"
         << endl;
    int value;
    int index;
    for (int i = 0; cin >> value; i++) {
        lst.push_back(value);
        if (cin.get() == '\n') {
            break;
        }
    }
    cout << "Пожалуйста, введите индекс с конца элемента, который хотите "
            "удалить:"
         << endl;
    cin >> index;

    cout << "Элементы списка до удаления: " << endl;
    for (int i = 0; i < lst.getSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;
    cout << "Размер списка:" << lst.getSize() << endl;

    cout << "Элементы списка после удаления: " << endl;
    lst.removeCom(index);
    for (int i = 0; i < lst.getSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;
    cout << "Размер списка:" << lst.getSize() << endl;
    cout << endl;
    cout << "Сортировка пузырьком: " << endl;
    lst.bubble_sort();
    for (int i = 0; i < lst.getSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;
    return 0;
}

List ::~List()
{
    clear();
}