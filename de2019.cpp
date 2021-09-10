#include "jrbgraph.hpp"
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <bits/stdc++.h> //thu vien de dung stringstream

using namespace std;
void readFile(string webPages, string pageConnect, Graph g, int chose)
{
    char input[1000];
    string text;
    int line = 0, lineNumber = 1, step = 0, max = 0, min = 9999;
    map<int, string> listUrl;
    map<int, int> connectNumber;

    string word;
    string words[2];
    string id;
    string ids[2];

    //DOC FILE WEBPAGES.TXT
    std::ifstream f(webPages, ios::in);

    if (f.is_open())
    {
        while (!f.eof())
        {
            if (line > lineNumber)
                break;
            else
            {
                f.getline(input, 1000);
                if (line == 0)
                {
                    text += input;
                    lineNumber = atoi(text.c_str());
                }
                if (line > 0)
                {
                    stringstream ss(input);
                    step = 0;
                    while (ss >> word)
                    {
                        words[step] = word;
                        step += 1;
                    }
                    listUrl.insert(pair<int, string>(atoi(words[1].c_str()), words[0]));
                }
                line += 1;
            }
        }
        //in id va url cua web
        cout << "so luong Web Page: " << lineNumber << endl;
        map<int, string>::iterator it;
        for (it = listUrl.begin(); it != listUrl.end(); it++)
        {
            cout << it->first << ": " << it->second << endl;
        }
    }
    else
    {
        cout << "file " << webPages << " is not found" << endl;
    }

    //DOC FILE pageconnections.TXT
    line = 0;
    lineNumber = 1;
    std::ifstream f1(pageConnect, ios::in);

    if (f1.is_open())
    {
        while (!f1.eof())
        {
            if (line > lineNumber)
                break;
            else
            {
                f1.getline(input, 1000);
                if (line == 0)
                {
                    text += input;
                    lineNumber = atoi(text.c_str());
                }
                if (line > 0)
                {
                    // cout << input << endl;
                    stringstream dd(input);
                    step = 0;
                    while (dd >> id)
                    {
                        ids[step] = id;
                        step += 1;
                        if (step > 1)
                        {
                            addEdge_int(g, atoi(ids[0].c_str()), atoi(ids[step].c_str()), 1);
                            // cout<<step<<endl;
                        }
                    }

                    connectNumber.insert(pair<int, int>(atoi(ids[0].c_str()), step - 1));
                    if (max < connectNumber[atoi(ids[0].c_str())])
                    {
                        max = connectNumber[atoi(ids[0].c_str())];
                    }
                    if (min > connectNumber[atoi(ids[0].c_str())])
                    {
                        min = connectNumber[atoi(ids[0].c_str())];
                        // cout << "Page co : " << min << endl;
                    }
                }
                line += 1;
            }
        }

        //in id va url cua web
        map<int, int>::iterator ii;
        cout << "Page co it lien ket nhat la: " << endl;

        for (ii = connectNumber.begin(); ii != connectNumber.end(); ii++)
        {
            // cout << ii->first.c_str() << ": " << ii->second << endl;
            if (ii->second == min)
                cout << listUrl[ii->first] << endl;
        }
        cout << "Page co it lien nhieu nhat la: " << endl;

        for (ii = connectNumber.begin(); ii != connectNumber.end(); ii++)
        {
            if (ii->second == max)
                cout << listUrl[ii->first] << endl;
        }
    }
    else
    {
        cout << "file " << pageConnect << " is not found" << endl;
    }
    f.close();
    f1.close();
}
int main()
{
    int i, n, chose;
    int *output;
    Graph g = createGraph();
    while (1)
    {
        printf("================ MENU ==============\n 1. Doc file data \n 2. Thuc hien PageRank 1 lan\n 3. Thuc hien PageRank m lan\n 4. Spam bot\n 5. Khoang cach 2 page\n 6. Thoat\n =======================================\n");
        scanf("%d", &chose);
        switch (chose)
        {
        case 1:
            readFile("./Data/webpages.txt", "./Data/pageConnections.txt", g, 1);
            break;
        case 2:
            int idPage;
            cin >> idPage;
            cout << idPage << endl;
            n = getAdjacentVertices_int(g, idPage, output);
            printf("Number of adjacent vertices : %d\n", n);
            if (n == 0)
                printf("No adjacent vertices of node \n");
            else
            {
                printf("Adjacent vertices of node A:");
                for (i = 0; i < n; i++)
                    printf("%5s", output[i]);
            }
            break;
        case 3:
            printf("day la 3");
            break;
        case 4:
            printf("day la 4");
            break;
        case 5:
            printf("day la 5");
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("chon sai, vui long chon lai");
            break;
        }
    }
}