#include <iostream>
#include <string>
#include <ostream>
#include "RingBuff.h"
using namespace std;

list* init(int size) {

    list* buffer = new list();
    buffer->size = size;

    for (int i = 0; i < buffer->size; i++) {
        node* new_el = new node();
        new_el->next = nullptr;
        if (buffer->last != nullptr) {
            buffer->last->next = new_el;
            buffer->last = new_el;
        }
        else {
            buffer->head = new_el;
            buffer->last = new_el;
        }
    }
    buffer->last->next = buffer->head;
    buffer->last = buffer->head;
    return buffer;
};

void add(list* buffer, int value) {
    node* curr_el = buffer->last;
    curr_el->value = value;
    buffer->last = curr_el->next;
};

void print(list* buffer, ostream& os) {

    node* curr_el = buffer->head;

    for (int i = 0; i < buffer->size; i++) {
        if (curr_el->value != 0) {
            os << curr_el->value << " ";
            curr_el = curr_el->next;
        }
    }
}