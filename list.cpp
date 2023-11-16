#include "list.h"
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

List ::List()
{
    size = 0;
    head = nullptr;
}

void List ::push_back(int data) // добавление элемента в список
{
    if (head == nullptr) {
        head = new Node(data);
    } else {
        Node *current = this->head;
        while ((current->pNext) != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    size++;
}
int &List ::operator[](const int index)
{
    int cnt = 0;
    Node *current = this->head;
    while (current != nullptr) {
        if (cnt == index) {
            return current->data;
        }             current = current->pNext;
            cnt++;
       
    }
    return current->data;
}

void List ::pop_front()
{
    Node *tmp = head; // запоминаем голову списка
    head = head->pNext; // присваиваем голову след элементу
    delete tmp; // удаление исходной головы
    size--; //уменьшаем размер списка на 1
}

void List ::clear()
{
    while (size != 0) {
        pop_front();
    }
}

void List ::removeCom(int index) // метод удаления элемента по индексу с конца
{
    if (index == 0) {
        pop_back();
    } else if (index == size - 1) {
        pop_front();

    } else {
        Node *previous = this->head;
        for (int i = 0; i < size - index - 2; i++) {
            previous = previous->pNext;
        }
        Node *del = previous->pNext;
        previous->pNext = del->pNext;

        delete del;
        size--;
    }
}

void List ::pop_back()
{
    Node *last = this->head;
    for (int i = 0; i < size - 1; i++) {
        last = last->pNext;
    }
    Node *del = last->pNext;
    last->pNext = nullptr;
    delete del;

    size--;
}
void List ::bubble_sort()
{
    Node *left = this->head; // указатель на голову
    Node *right = left->pNext; // следующий элемент после головы
    Node *tmp = new Node; // временный указатель
    while (
        left->pNext != nullptr) { // обход по всем боксам за исключением последнего правого
        while (right != nullptr) // обход уже по всем боксам
        {
            if ((left->data) > (right->data)) { // Сам алгоритм сортировки,
                                                // сравниваем значения в боксах
                tmp->data = left->data;
                left->data = right->data;
                right->data = tmp->data;
            }
            right =
                right->pNext; // направляем указатель на следующий элемент чтобы
                              // не было зацикливания для внутреннего while
        }
        left = left->pNext; // направляем указатель на следующий элемент чтобы
                            // не было зацикливания для внешнего while
        right = left->pNext; // возвращаем указатель назад
    }
    delete tmp; // чтобы не было утечек памяти, удаляем временную переменную.
}