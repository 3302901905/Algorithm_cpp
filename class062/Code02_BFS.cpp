#include <bits/stdc++.h>

using namespace std;

// 使用队列来保存带访问的节点 
// 在同一层的节点全部访问完 直到没有更多的节点可以访问

// 示例图的邻接表表示
// vector<vector<int>> graph = {
//     {1, 2},    // 节点 0 的邻居
//     {0, 3, 4}, // 节点 1 的邻居
//     {0},       // 节点 2 的邻居
//     {1},       // 节点 3 的邻居
//     {1}        // 节点 4 的邻居
// };
void BFS(int node, vector<bool>& visited, vector<vector<int>>& graph)
{
    queue<int> q;
    vector<bool> visited(graph.size(), false); 
    q.push(node);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // 遍历所有相邻节点
        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }

    }


}



