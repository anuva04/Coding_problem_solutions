#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
    void fillOrder(int v, bool visited[], stack<int>& Stack);
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int v);
    void addEdge(int u, int v);
    void scc();
    Graph getTranspose();
};

Graph::Graph(int v){
    this->V = v;
    adj = new list<int>[V];
}

void Graph::DFSUtil(int v, bool visited[]){
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for(i=adj[v].begin(); i!=adj[v].end(); ++i){
        if(!visited[*i]) DFSUtil(*i, visited);
    }
}

Graph Graph::getTranspose(){
    Graph g(V);
    for(int v=0; v<V; v++){
        list<int>::iterator i;
        for(i=adj[v].begin(); i!=adj[v].end(); ++i) g.adj[*i].push_back(v);
    }
    return g;
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::fillOrder(int v, bool visited[], stack<int>& Stack){
    visited[v] = true;
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i){
        if(!visited[*i]) fillOrder(*i, visited, Stack);
    }
    Stack.push(v);
}

void Graph::scc(){
    stack<int> Stack;
    bool *visited = new bool[V];
    for(int i=0; i<V; i++) visited[i] = false;
    for(int i=0; i<V; i++)
        if(!visited[i]) fillOrder(i, visited, Stack);
    Graph gr = getTranspose();
    for(int i=0; i<V; i++) visited[i] = false;
    while(!Stack.empty()){
        int v = Stack.top();
        Stack.pop();
        if(!visited[v]){
            gr.DFSUtil(v, visited);
            cout << endl;
        }
    }
}

int main(){
    int numNodes; cin>>numNodes;
    Graph g(numNodes);
    int numEdges; cin>>numEdges;
    while(numEdges--){
        int u, v; cin>>u>>v;
        g.addEdge(u,v);
    }
    g.scc();
    return 0;
}