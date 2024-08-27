#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> bfs(const vector<vector<int>>& adjacency_matrix, int startnode) {
    int numnode =adjacency_matrix.size();
    vector<bool>visited(numnode, false);
    vector<int>traversal_order;
    queue<int>queue;
    queue.push(startnode);
    visited[startnode] = true;
    while (!queue.empty()) {
        int current_node = queue.front();
        queue.pop();
        traversal_order.push_back(current_node);
        for (int neighbour = 0; neighbour < numnode; ++neighbour) {
            if (adjacency_matrix[current_node][neighbour] == 1 && !visited[neighbour]) {
                queue.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
    return traversal_order;
}

vector<int> dfs(const vector<vector<int>>& adjacency_matrix, int startnode) {
    int numnode= adjacency_matrix.size();
    vector<bool>visited(numnode, false);
    vector<int>traversal_order;
    stack<int>stack;
    stack.push(startnode);
    visited[startnode] = true;
    while (!stack.empty()) {
        int current_node=stack.top();
        stack.pop();
        traversal_order.push_back(current_node);
        
        for (int neighbour = numnode - 1; neighbour >= 0; --neighbour) {
            if (adjacency_matrix[current_node][neighbour] == 1 && !visited[neighbour]) {
                stack.push(neighbour);
                visited[neighbour]=true;
            }
        }
    }
    return traversal_order;
}

int main() {
    vector<vector<int>> adjacency_matrix = {
        {0,1,0,1,0},
        {1,0,1,0,0},
        {0,1,0,1,1},
        {1,0,1,0,1},
        {0,0,1,1,0}
    };

    vector<int> dfs_result = dfs(adjacency_matrix, 0);
    cout<<"DFS Traversal:";
    for (int node : dfs_result) {
        cout << " " << node;
    }
    cout << endl;
    vector<int> bfs_result = bfs(adjacency_matrix, 0);
    cout <<"BFS Traversal:";
    for (int node:bfs_result) {
        cout << " " << node;
    }
    cout << endl;
    return 0;
}

