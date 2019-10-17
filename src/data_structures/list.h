#ifndef LIST_H
#define LIST_H

#include <functional>

template<typename T>
struct list_node {
    T value;
    list_node* next = nullptr;
};

template<typename T>
class list {
public:

public:
    list_node* top;
};

template<typename T>
void Iterate(list_node<T>* top, std::function<void(T)> fun) {
    while(top != nullptr) {
        fun(top.value);
        top = top.next;
    }
} 

template<typename T>
list_node* FindCell(list_node<T>* top, T target) {
    while(top != nullptr) {
        if(top.value == target) return top;
        top = top.next;
    }

    return nullptr;
}

/// Находит ячейку предшествующую целевой
/// Для списков без ограничителя
template<typename T>
list_node* FindCellBefore(list_node<T>* top, T value) {
    if(top == nullptr) return nullptr;

    while(top.next != nullptr) {
        if(top.next.value == target) return top;
        top = top.next;
    }

    return nullptr;
}


/// Для списков с ограничителем
template<typename T>
list_node* FindCellBefore(list_node<T>* top, T value) {
    while(top.next != nullptr) {
        if(top.next.value == target) return top;
        top = top.next;
    }

    return nullptr;
}



#endif //LIST_H