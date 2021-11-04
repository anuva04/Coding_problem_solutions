#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

class Edge {
    public:
        int src, dest, weight;
};

class Graph {
    public:
        int V, E;
        Edge* edge;
};

Graph* createGraph(int V, int E){
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

class subset {
    public :
        int parent;
        int rank;
};

int find(subset subsets[], int i){
    if(subsets[i].parent != i) subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if(subsets[xroot].rank < subsets[yroot].rank) subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank) subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int comp(const void* a, const void* b){
    Edge* a1  = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

void kruskalMst(Graph* graph){
    int V = graph->V;
    Edge result[V];
    int e = 0, i = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), comp);
    subset* subsets = new subset[(V*sizeof(subset))];
    for(int v=0; v<V; v++){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while(e<V-1 && i<graph->E){
        Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if(x!=y){
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    int minCost = 0;
    for(int i=0; i<e; i++){
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
        minCost += result[i].weight;
    }
    cout << "Min Cost = " << minCost << endl;
}

int main(){
    int v, e; cin>>v>>e;
    Graph* graph = createGraph(v,e);
    for(int i=0; i<e; i++){
        int src, dest, weight;
        cin>>src>>dest>>weight;
        graph->edge[i].src = src;
        graph->edge[i].dest = dest;
        graph->edge[i].weight = weight;
    }
    kruskalMst(graph);
    return 0;
}