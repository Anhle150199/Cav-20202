#include "jrb.hpp"
#include <list>
#include <iterator>
using namespace std;
typedef JRB Graph;

Graph createGraph();
void addEdge_int(Graph graph, int v1, int v2, int weight);
void addEdge_str(Graph graph, char* v1, char* v2, int weight);
int getAdjacentVertices_int (Graph graph, int v, int* output);
int getAdjacentVertices_str (Graph graph, char* v, char output[10][10]);
// tra ve trong so canh v1,v2
int getEdgeWeight_str(Graph graph, char* v1, char* v2); 
//tra ve cac dinh hien co tren do thi
list<string> getAllVertexes(Graph graph);

// duyet do thi theo chieu rong, dinh bat dau là start
void BFS(Graph graph, char* start);// duyet theo chieu rong
void DFS(Graph graph, char* start); // duyet theo chieu sau
void dropGraph(Graph graph);
void dijkstra(Graph graph, char* start, char* end);

void PRIM(Graph graph, char* start);

