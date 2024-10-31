#include<bits/stdc++.h>

using namespace std;

// 堆排序 以大根堆为例 优先级队列的底层

// 有数字插入进来 向上调整大根堆
// arr[i] = x, x是新来的 往上一直看
// 直到它的父亲不比它大为止
void heapInsert(vector<int>& arr, int i)
{
    while (arr[i] > arr[(i - 1) / 2])
    {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// 某个位置数字改变     
// 如果大于父亲 要向上调整 heapInsert
// 如果小于父亲 要向下调整 heapify
// 往下一直看 直到它的所有孩子都不比它大
void heapify(vector<int>& arr, int i, int heapSize)
{
    int left = i * 2 + 1;
    while (left < heapSize)
    {
        int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
        
        largest = arr[largest] > arr[i] ? largest : i;
        
        if (largest == i) break;
        
        swap(arr[largest], arr[i]);
        
        i = largest;
        left = i * 2 + 1;
    }
}

// 堆排序
// 对已知数组排序
// 1. heapInsert构建大根堆
// 2. 把头位置的数放到最后 size--
// 3. heapify调整新到头的数的位置
// 重复 直到size == 0
void heapSort(vector<int>& arr)
{

    int curSize = arr.size(), cur = 0;

    // 构建大根堆
    while (cur < curSize)
    {
        heapInsert(arr, cur++);
    }

    // 调整
    while (curSize > 1)
    {
        swap(arr[0], arr[--curSize]);
        // 新的数来到头位置 开始向下调整它
        heapify(arr, 0, curSize);
    }

}

