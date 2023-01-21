#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include "base64.h"
using namespace std;

const string alphavit = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


string Bin_turn(int input, int num) {
    int check = 0;
    string bin_input = "";

    while (input > 0) {
        bin_input += to_string(input % 2);
        input /= 2;
        check++;
    }

    while (check < num) {
        bin_input += "0";
        check++;
    }

    reverse(bin_input.begin(), bin_input.end());

    return bin_input;
}


string Encode_make_bin(string str) {
    string new_str_bin = "";

    for (int i = 0; i < str.size(); i++)
        new_str_bin += Bin_turn(str[i] - '0' + 48, 8);
    return new_str_bin;
}

char convert(string str) {
    int dec = 0, i = 0, rem;
    int n = stoi(str);

    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}

string Decode_make_bin(string str) {
    int index;
    int flag = 0;
    string new_string = "";

    while (str[str.size() - 1] == '=') { str.erase(str.size() - 1, 1); flag++; }

    for (int i = 0; i < str.size(); i++) {
        index = alphavit.find(str[i]);
        new_string += Bin_turn(index, 6);
    }

    if (flag == 1)  new_string.erase(new_string.size() - 1, 2);
    if (flag == 2)  new_string.erase(new_string.size() - 1, 4);

    return new_string;
}

string encode(string str) {
    string bin = Encode_make_bin(str);
    string six_bites = "";
    string final_string = "";

    int a = bin.size() % 6;
    if (a == 2) bin += "0000";
    else if (a == 4) bin += "00";

    for (int i = 0; i < bin.size(); i++) {
        if ((i + 1) % 6 != 0) {
            six_bites += bin[i];
        }
        else {
            six_bites += bin[i];
            final_string += alphavit[convert(six_bites)];
            six_bites = "";
        }
    }

    if (a == 2) final_string += "==";
    else if (a == 4) final_string += "=";

    return final_string;
}


string decode(string str) {
    string bin = Decode_make_bin(str);
    string eight_bites = "";
    string final_string = "";
    int a = bin.size();
    for (int i = 0; i < bin.size(); i++) {
        if ((i + 1) % 8 != 0) {
            eight_bites += bin[i];
        }
        else {
            eight_bites += bin[i];
            final_string += char(convert(eight_bites));
            eight_bites = "";
        }
    }

    return final_string;
}