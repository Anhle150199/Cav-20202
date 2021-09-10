#include "jrbgraph.hpp"
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <bits/stdc++.h> //thu vien de dung stringstream
// int edit(char aaa[10][10])
// {
//     aaa[1] = "111";
//     aaa[] return 1;
// }
int main(int argc, char **argv)
{
    int i, xxx;
    char aaa[10][10];

    string console[20];
    for (i = 1; i < argc; i++)
    {
        console[i] = argv[i];
    }

    string chose = console[1];
        char x1[1111];

    chose.copy(x1, chose.size() + 1);
    x1[chose.size()] = '\0';

    cout << x1 << endl;
    if (chose == "-t")
    {
        xxx = 12;
        // strcpy(x1, chose);

        // int a = edit(aaa);
        cout << xxx << endl;
    }
    else if (chose == "-s")
    {
        cout << "day la -s : doc file" << endl;
    }
    else
    {
        cout << "cau lenh sai" << endl;
    }

    return 0;
}