#pragma once

#include <ostream>
using namespace std;

struct node
{
	int value;
	struct node* next;
};

struct list
{
	node* head = nullptr;
	node* last = nullptr;
	int size;
};

list* init(int size);

void add(list* buffer, int value);

void print(list* buffer, ostream& os);