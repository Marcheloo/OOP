#include <iostream>
#include <string>
#include "base64.h"
using namespace std;

int main(){
   
   string str;
   getline(cin, str);
   cout << encode(str) << endl;
   str = encode(str);
   cout << decode(str) << endl;
}