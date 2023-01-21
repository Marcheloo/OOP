#include <iostream>
#include <cmath>
#include <stack>
#include <climits>
#include "Rpn/rpn.h"
using namespace std;

int Num_scan(char ch) {
    int value;
    value = ch;
    return int(value - '0');
}

int oper(int a, int b, char op) {
    if (op == '+')
        return b + a;
    else if (op == '*')
        return b * a;
    else
        return INT_MIN;
}
int Rpn(string postfix) {
    int a, b;
    stack<int> stack;
    string::iterator iter;
    for (iter = postfix.begin(); iter != postfix.end(); iter++) {
        if (*iter < '0' || *iter>'9') {
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            stack.push(oper(a, b, *iter));
        }
        else if (*iter > '0' && *iter < '9') {
            stack.push(Num_scan(*iter));
        }
    }
    return stack.top();
}