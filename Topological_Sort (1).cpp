#include<bits/stdc++.h>
using namespace std;

vector < int > graph[105];
bool visited[105];

stack<int> result;

void dfs(int source){

    visited[source] = true;
    for (int i = 0; i < graph[source].size(); i++){
        int next = graph[source][i];
        if (visited[next] == 0)
            dfs(next);
    }
    // all children explored
    result.push(source); // newly included
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 0; i < nodes; i++){
        if (visited[i] == 0){
//            cout<<i<<"th node "<<visited[i]<<" called dfs"<<endl;
            dfs(i);
        }

    }

    //reverse(result.begin(), result.end());
    cout << "Topological order: ";
    //cout<<result.size()<<endl;

// Print contents of stack
    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
    return 0;
}
