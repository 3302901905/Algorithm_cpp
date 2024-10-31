#include<bits/stdc++.h>

using namespace std;

class solution 
{
public:

    priority_queue<double, vector<double>> q;

    int minOperations(vector<int>& nums, int x)
    {
        int n = nums.size();
        double sum = 0;
        for (int num : nums)
        {
            q.push(num);
            sum += num;
        }
        sum /= 2;
        int ans = 0;
        double cur = 0;
        while (cur < sum)
        {
            double top = q.top() / 2;
            q.pop();
            q.push(top);
            cur += top;
            ans++;
        }

        return ans;
        
    }

    int minOperations2(vector<int>& nums, int x)
    {
        int n = nums.size();
        vector<long> heap(n, 0);
        long sum = 0;
        for (int i = n - 1; i >= 0; ++i)
        {
            heap[i] = (long)(nums[i] << 20);
            sum += heap[i];
            heapify(heap, i);
        }
        sum /= 2;
        int ans = 0;
        long cur = 0;
        while (cur < sum)
        {
            heap[0] /= 2;
            cur += heap[0];
            ans++;
            heapify(heap, 0);
        }
        
        return ans;

    }

    void heapify(vector<long>& heap, int i)
    {
        int left = 2 * i + 1;
        while (left < heap.size())
        {
            int largest = left + 1 < heap.size() && heap[left + 1] > heap[left] ? left + 1 : left;
            largest = heap[largest] > heap[i] ? largest : i;
            if (largest == i) break;
            swap(heap[largest], heap[i]);
            i = largest;
            left = 2 * i + 1;
        }
    }



};