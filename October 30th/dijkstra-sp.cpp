//?DIJKSTRA ALGORITHM Shortest path

#include<iostream>
#include<vector>

using namespace std;

vector<int>dijkstra(vector<int>graph[],int V,int src)
{
  vector<int>dist(V,9999);
  dist[src]=0;
  vector<bool>fin(V,false);

  for(int count=0;count<V-1;count++){

    int u=-1;
    for (int i = 0; i < V; i++)
    {
      if (!fin[i] && (u==-1 || dist[i]<dist[u]))
      {
        u=i;
      }
    }
      fin[u]=true;

      for(int v=0;v<V;v++){
        if (graph[u][v]!=0 && fin[v]==false)
        {
          dist[v]=min(dist[v],dist[u]+graph[u][v]);
        }
        
      }
      
    
    
  }
return dist;
}

int main() {
    int V = 5;

    vector<int> graph[5] = {
        {0, 2, 0, 6, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 3},
        {0, 0, 4, 0, 1},
        {0, 0, 0, 2, 0}
    };

    int src = 0;

    vector<int> distances = dijkstra(graph, V, src);

    cout << "Shortest distances from vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
