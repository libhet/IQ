#ifndef LIST_H
#define LIST_H

#include <functional>
#include <limits>

struct list_node {
    int value;
    list_node* next = nullptr;
};

/// Список с ограничителем
class List {
public:
    static const int border_value = std::numeric_limits<int>::max();

public:
    List() {
        top = new list_node();
        top->value = border_value;
    }

    void append(const int& value) {
        list_node* new_node = new list_node();

        new_node->value = value;

        /// Поиск подходящего места вставки нового элемента
        list_node* current = top;
        while(current->next != nullptr) {
            current = current->next;
        }
        
        current->next = new_node;
    }

public:
    list_node* top = nullptr;
};


void Iterate(list_node* top, std::function<void(int)> fun) {
    while(top != nullptr) {
        fun(top->value);
        top = top->next;
    }
} 


list_node* FindCell(list_node* top, int target) {
    while(top != nullptr) {
        if(top->value == target) return top;
        top = top->next;
    }

    return nullptr;
}

/// Находит ячейку предшествующую целевой
/// Для списков без ограничителя
list_node* FindCellBefore(list_node* top, int target) {
    if(top == nullptr) return nullptr;

    while(top->next != nullptr) {
        if(top->next->value == target) return top;
        top = top->next;
    }

    return nullptr;
}


/// Для списков с ограничителем
list_node* FindCellBeforeL(list_node* top, int target) {
    while(top->next != nullptr) {
        if(top->next->value == target) return top;
        top = top->next;
    }

    return nullptr;
}



#endif //LIST_H