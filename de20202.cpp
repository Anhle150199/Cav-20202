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
    int i, n, chose, k = 0;
    bool check;
    char output[10][10];
    Graph g = createGraph();
    list<string> vertexes;
    list<string>::iterator it1;

    char input[1000];
    string listFile;
    string text;
    int line = 0, lineNumber = 1, step = 0, max = 0, step1 = 0;
    map<int, string> list;

    string word;
    string words[100], people[1000];
    char node1[1000], node2[1000], node3[1000];

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
                    // cout << input << endl;

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
                    if (step > max)
                    {
                        max = step - 1;
                        people[step1] = words[0];
                        step1 += 1;
                    }
                    listFile += input;
                    listFile += "\n";
                }
                line += 1;
            }
        }
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
        {
            printf("Danh sach nguoi tiep xuc gan: \n");
            vertexes = getAllVertexes(g);
            showlist(vertexes);
            printf("\n");
        }

        break;
        case 2:
        {
            cout << lineNumber << endl;
            cout << listFile << endl;
        }

        break;
        case 3:
        {
            cin.ignore();
            string n1, n2;
            int x = 1;

            cout << "nhap ten nguoi thu nhat: " << endl;
            cin >> n1;
            const char *tmp1 = n1.c_str();
            cout << "nhap ten nguoi thu hai: " << endl;
            cin >> n2;
            const char *tmp2 = n2.c_str();
            char *name1 = strdup(tmp1);
            char *name2 = strdup(tmp2);
            n = getAdjacentVertices_str(g, name1, output);
            if (n == 0)
                printf("No adjacent vertices of node \n");
            else
            {
                printf("Tinh trang: ");
                // cout << n<<endl;
                for (i = 0; i <= n; i++)
                {
                    // cout<< output[i] <<endl;
                    if (output[i][0] == name2[0])
                    {
                        cout << "Co tiep xuc gan" << endl;
                        x = 0;
                        break;
                    }
                }
            }

            if (x == 1)
                printf(" Khong  tiep xuc\n");
        }
        break;
        case 4:
        {
            cin.ignore();
            string n1;
            int x;

            cout << "nhap ten : " << endl;
            cin >> n1;
            const char *tmp1 = n1.c_str();
            char *name1 = strdup(tmp1);
            n = getAdjacentVertices_str(g, name1, output);
            if (n == 0)
                printf("Khong co nguoi tiep xuc gan \n");
            else
            {
                printf(" Danh sach tiep xuc gan: ");
                for (i = 0; i < n; i++)
                    printf("%5s", output[i]);
            }
            cout << endl;
        }
        break;

        case 5:
        {
            int aa;
            cout << "nhung nguoi tiep xuc nhieu nhat: " << endl;
            for (i = 0; i < step1; i++)
            {
                const char *tmp = people[i].c_str();
                char *name = strdup(tmp);
                aa = getAdjacentVertices_str(g, name, output);

                if (aa == max)
                    cout << name << endl;
            }
        }
        break;
        case 6:
        {
            cin.ignore();
            string n1;
            int x;
            char out[10][10];

            cout << "nhap ten : " << endl;
            cin >> n1;
            const char *tmp1 = n1.c_str();
            char *name1 = strdup(tmp1);
            n = getAdjacentVertices_str(g, name1, output);
            if (n == 0)
                printf("Khong co F1 \n");
            else
            {
                printf(" Danh sach F1: ");
                for (i = 0; i < n; i++)
                    printf("%5s", output[i]);
                cout << endl;
                printf(" Danh sach F2: ");
                for (i = 0; i < n; i++)
                {
                    x = getAdjacentVertices_str(g, output[i], out);
                    if (x == 0)
                        continue;
                    else
                    {
                        for (i = 0; i < x; i++)
                            printf("%5s", out[i]);
                    }
                }
                cout << endl;
            }
        }
        break;
        case 7:
        {
            int x;
            string name;
            cout << "Nhap so nguoi tiep xuc: " << endl;
            cin >> x;
            cout << "Nhap ten nguoi moi" << endl;
            cin >> name;
            const char *tmp1 = name.c_str();
            char *name1;
            char *name2;
            name1 = strdup(tmp1);
            cout << "nhap ten nguoi tiep xuc" << endl;
            for (i = 1; i <= x; i++)
            {
                cin >> name;
                const char *tmp1 = name.c_str();
                name2 = strdup(tmp1);
                // cout << name2 << endl;
                addEdge_str(g, name1, name2, 1);
                addEdge_str(g, name2, name1, 1);
            }
            cout << "Nhap thanh cong" << endl;
        }
        break;
        case 8:
        {
            cin.ignore();
            string n1, n2;
            int x;

            cout << "nhap ten nguoi thu nhat: " << endl;
            cin >> n1;
            const char *tmp1 = n1.c_str();
            cout << "nhap ten nguoi thu hai: " << endl;
            cin >> n2;
            const char *tmp2 = n2.c_str();
            char *name1 = strdup(tmp1);
            char *name2 = strdup(tmp2);

            addEdge_str(g, name1, name2, 1);
            cout << " da them " << name1 << "va " << name2 << endl;
        }
        break;

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