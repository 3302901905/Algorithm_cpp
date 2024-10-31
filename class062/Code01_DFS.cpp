#include <bits/stdc++.h>

using namespace std;

// 递归方式
// 使用栈来保存带访问的节点 
// 尽可能的深入一个分支直到没有更多的节点可以访问 然后回溯
// 通常用来解决连通性问题 和 路径查找 拓扑排序

// 示例图的邻接表表示
// vector<vector<int>> graph = {
//     {1, 2},    // 节点 0 的邻居
//     {0, 3, 4}, // 节点 1 的邻居
//     {0},       // 节点 2 的邻居
//     {1},       // 节点 3 的邻居
//     {1}        // 节点 4 的邻居
// };
void DFS_Recursion(int node, vector<bool>& visited, vector<vector<int>>& graph)
{
    // 访问当前节点
    visited[node] = true;
    // 对当前节点想要做的一些逻辑... 此处是打印
    cout << node << " ";

    // 遍历所有相邻节点
    for (int neighbor : graph[node])
    {
        // 如果相邻节点未被访问过
        if (!visited[neighbor])
        {
            DFS_Recursion(neighbor, visited, graph);
        }
    }

}

// 手动压栈实现
void DFS(int node, const vector<vector<int>>& graph)
{
    stack<int> s;
    vector<bool> visited(graph.size(), false);
    s.push(node);

    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (!visited[node])
        {
            visited[node] = true;
            // 逻辑处理 此处是打印
            cout << node << " ";

            // 将所有未访问邻居压栈
            for (int neighbor : graph[node])
            {
                if (!visited[neighbor])
                {
                    s.push(neighbor);
                }
            }

        }
    }


}



