#ifndef LIST_h
#define LIST_h
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

class List
{
  public:
    List();
    ~List();
    void push_back(int data); // добавление элемента в конец списка
    void pop_front(); // удаление первого элемента из списка
    int getSize() { return size; } // определение текущего размера списка
    void clear(); //удаление данных списка
    int &operator[](const int index); //определение значения по индексу
    void removeCom(int index);
    void pop_back();
    void bubble_sort(); //сортировка пузырьком
  private:
    class Node
    {
      public:
        Node *pNext; //указатель на след узел
        int data; // значение в текущем узле
        Node(int data = 0, Node *pNext = nullptr) // конструктор класса Node
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    Node *head;
    int size;
};
#endif