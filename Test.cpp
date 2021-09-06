#include "jrbgraph.hpp"
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;
void showlist(list <string> g)
{
    list <string> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout<<'\t'<<*it;
    cout<<'\n';
}
int main()
{
	int i,n;
	char output[10][10];
    Graph g = createGraph();
    addEdge_str(g, "A", "D", 7);
	addEdge_str(g, "A", "E", 7);
	addEdge_str(g, "A", "C", 4);
	addEdge_str(g, "A", "B", 3);
	addEdge_str(g, "E", "D", 11);
	addEdge_str(g, "C", "E", 9);
	addEdge_str(g, "E", "F", 2);
	addEdge_str(g, "C", "F", 8);
	addEdge_str(g, "B", "C", 3);
	addEdge_str(g, "B", "F", 12);
	
	n = getAdjacentVertices_str (g, "A", output);
    printf("Number of adjacent vertices : %d\n",n);
    if (n==0) printf("No adjacent vertices of node \n");
    else {   
       printf("Adjacent vertices of node A:");
       for (i=0; i<n; i++) printf("%5s", output[i]);
    } 
    printf("\n");
    PRIM(g,"A");
    PRIM(g,"E");
    return 0;
}
/*
int main()
{
	int i,n;
	char output[10][10];
    Graph g = createGraph();
    addEdge_str(g, "HNL", "LAX", 2555);
	addEdge_str(g, "LAX", "SFO", 337);
	addEdge_str(g, "LAX", "ORD", 1743);
	addEdge_str(g, "LAX", "DFW", 1233);
	addEdge_str(g, "SFO", "ORD", 1843);
	addEdge_str(g, "ORD", "PVD", 849);
	addEdge_str(g, "ORD", "DFW", 802);
	addEdge_str(g, "DFW", "LGA", 1387);
	addEdge_str(g, "DFW", "MIA", 1120);
	addEdge_str(g, "LGA", "PVD", 142);
	addEdge_str(g, "LGA", "MIA", 1099);
	addEdge_str(g, "MIA", "PVD", 1205);

    
	n = getAdjacentVertices_str (g, "LAX", output);
    printf("Number of adjacent vertices : %d\n",n);
    if (n==0) printf("No adjacent vertices of node \n");
    else {   
       printf("Adjacent vertices of node LAX:");
       for (i=0; i<n; i++) printf("%5s", output[i]);
    } 
    printf("\n");
    
    //printf("\nBFS tu HN\n");
    //BFS(g, "HN");
    printf("Cac dinh hien co tren do thi: \n");
    list<string> vertexes = getAllVertexes(g);
    showlist(vertexes);
    printf("\n");
    
    printf("\nDFS tu HNL\n");
	DFS(g, "HNL");
    
	printf("\nBFS tu HNL\n");
    BFS(g, "HNL");
    printf("\nDuong di ngan nhat tu HNL toi PVD\n");
    dijkstra(g,"HNL","PVD");
	return 0;
}
*/
/*
int main()
{
    map<char*,int> first;
  
  //initializing
  first["HN"]=10;
  first["HP"]=20;

   map<char*, int>::iterator it;
   for(it=first.begin(); it!=first.end(); ++it){
      cout << it->first << " => " << it->second << '\n';
   }
}*/
