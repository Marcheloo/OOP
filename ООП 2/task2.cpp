#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include "hashtag.h"
using namespace std;


int main()
{
    string str;
    
    getline(cin, str);

    try{
    cout<<Turn_Hash(str);
    }
    catch(const char* e){
      cout<<e;
    }
    return 0;
}