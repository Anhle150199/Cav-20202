#include "jrbgraph.hpp"
#include <stdio.h>
#include <iostream>
#include <list>
#include <iterator>
#include <map>
#include <string>
#include <fstream>
#include <bits/stdc++.h> //thu vien de dung stringstream

using namespace std;

void showlist(list<string> g)
{
    list<string>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}
int main()
{
    int i, n, chose;
    bool check;
    char output[10][10];
    Graph g = createGraph();
    list<string> vertexes;
    list<string>::iterator it1;

    char input[1000];
    char *name1, *name2;
    string listFile;
    string text;
    int line = 0, lineNumber = 1, step = 0, max =0;
    map<int, string> list;

    string word;
    string words[100];
    char node1[1000], node2[1000];

    std::ifstream f("./Data/tiepXucGan.txt", ios::in);

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
                    cout << input << endl;

                    lineNumber = atoi(text.c_str());
                }
                if (line > 0)
                {

                    stringstream ss(input);
                    step = 0;
                    while (ss >> word)
                    {
                        words[step] = word;
                        if (step == 0)
                        {
                            words[0].copy(node1, words[0].size());
                            node1[words[0].size()] = '\0';
                        }
                        if (step > 0)
                        {
                            words[step].copy(node2, words[step].size() + 1);
                            node2[words[step].size()] = '\0';

                            addEdge_str(g, node1, node2, step);
                        }
                        step += 1;
                    }
                    //         list.insert(pair<int, string>(atoi(words[1].c_str()), words[0]));
                    listFile += input;
                    listFile += "\n";
                }
                line += 1;
            }
        }
        //in id va url cua web
        // cout << "so luong Web Page: " << lineNumber << endl;
        // map<int, string>::iterator it;
        // for (it = list.begin(); it != list.end(); it++)
        // {
        //     cout << it->first << ": " << it->second << endl;
        // }
    }
    else
    {
        cout << "file is not found" << endl;
    }

    while (1)
    {
        printf("=============Menu=============\n1. Danh sach nguoi co tiep xuc gan\n2. Danh sach tiep xuc gan\n3. Kiem tra tiep xuc gan 2 nguoi\n4. Danh sach tiep xuc gan cua 1 nguoi\n5. Nguoi tiep xuc nhieu nhat\n6. Nhap F0\n7. Them nguoi tiep xuc gan\n8. Bo sung tiep xuc gan\n9. Ghi file danh sach\n10. Thoat\n==========================\n");
        scanf("%d", &chose);
        switch (chose)
        {
        case 1:
            printf("Danh sach nguoi tiep xuc gan: \n");
            vertexes = getAllVertexes(g);
            showlist(vertexes);
            printf("\n");
            break;
        case 2:
            cout << lineNumber << endl;
            cout << listFile << endl;
            break;
        case 3:
            check = false;
            cout << "nhap ten nguoi thu nhat: " << endl;
            cin >> name1;
            cout << "nhap ten nguoi thu hai: " << endl;
            cin >> name2;
            n = getAdjacentVertices_str(g, name1, output);
            if (n == 0)
                cout << name1 << " va " << name2 << "khong tiep xuc gan" << endl;
            else
            {
                for (i = 0; i < n; i++)
                {
                    if (strcmp(name2, output[i]) == 0)
                    {
                        cout << name1 << " va " << name2 << " tiep xuc gan" << endl;
                        check = true;
                        break;
                    }
                }
                if (check == false)
                {
                    cout << name1 << " va " << name2 << " khong tiep xuc gan" << endl;
                }
            }
            break;
        case 4:
            cout << "nhap ten nguoi can check: " << endl;
            cin >> name1;
            n = getAdjacentVertices_str(g, name1, output);
            if (n == 0)
                cout << name1 << "khong co trong danh sach" << endl;
            else
            {
                cout<< "danh sach tiep xuc gan voi "<< name1<< endl;
                for (i = 0; i < n; i++)
                {
                    printf("%5s", output[i]);
                }
            }
            cout << endl;
            break;

        case 5:

        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            cout << "Shut down ..." << endl;
            exit(0);
            dropGraph(g);
            break;
        default:
            cout << "Chon sai, chon lai" << endl;
            break;
        }
    }
    return 0;
}