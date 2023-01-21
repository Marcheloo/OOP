#include "hashtag.h"
#include <string>
using namespace std;

string Turn_Hash(string str) {

    bool flag = true;
    string hash = "#";

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ' && str[i] != ',')
            if (flag)
            {
                hash += (char)toupper(str[i]);
                flag = false;
            }
            else
                hash += str[i];
        else
            flag = true;
    }

    if (hash == "#")
        throw "Exception";

    if (hash.size() > 100)
        throw "Exception";

    return hash;


};