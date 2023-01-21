#include <iostream>
#include <stack>
#include "Rpn/rpn.h"

using namespace std;
 
int main() {
	string postf;
	cin >> postf;
	cout << Rpn(postf);
}