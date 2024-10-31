#include<bits/stdc++.h>

using namespace std;

class solution 
{
public:

    int completeCircuit(vector<int>& gas, vector<int>& cost)
    {
        int n = gas.size();
        vector<int> diff(n, 0);
        for (int i = 0; i < n; i++)
        {
            diff[i] = gas[i] - cost[i];
        }
        for (int l = 0, r = 0, sum; l < n; l = r + 1, r = l)
        {
            // l = 0, r = 0 窗口没东西
            // l ~ r - 1: r是 即将进来的东西
            sum = 0;
            // 累加和 加上 即将进来的东西的累加和是否还大于等于0
            // 就是能不能向右扩
            while (sum + diff[r % n] >= 0)
            {
                if (r - l + 1 == 0)
                {
                    return l;
                } 
                sum += diff[r % n];
                r++;
            }
        }

        return -1;

    }
};

int main()
{
	solution s;
	vector<int> gas(6, 0);
	vector<int> cost(6, 0);
	for (int i = 0; i < 6; ++i)
	{
		cin >> gas[i];
	}	
	for (int i = 0; i < 6; ++i)
	{
		cin >> cost[i];
	}
	
	int res = s.completeCircuit(gas, cost);
	cout << res << endl;
	
	return 0;
} 
