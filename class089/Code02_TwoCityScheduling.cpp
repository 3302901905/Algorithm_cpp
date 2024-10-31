#include<bits/stdc++.h>

using namespace std;

int twoCitySchedCost(vector<vector<int>>& costs) {
    int n = costs.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += costs[i][0];
    }
    sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b){
        return a[1] - a[0] < b[1] - b[0];
    });

    for(int i = 0; i < n/2; i++){
        ans += costs[i][1] - costs[i][0];
    }

    return ans;
    
}

