/**
 * Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.

Example 1:

Input: [1, 2, 5, 3, 7, 10, 9, 12]
Output: 5
Explanation: We need to sort only the subarray [5, 3, 7, 10, 9] to make the whole array sorted
*/
#include <bits/stdc++.h>
using namespace std;

int minwindowsort(vector<int> v)
{
    int start = 0, end = v.size() - 1;
    while (start < v.size() && v[start] < v[start + 1])
    {
        start++;
    }
    if (start == v.size() - 1)
        return 0;
    while (end < v.size() && v[end - 1] < v[end])
    {
        end--;
    }
    int mini = 1e9, maxi = -1e9;
    for (int i = start + 1; i < end; i++)
    {
        mini = min(mini, v[i]);
        maxi = max(maxi, v[i]);
    }
    while (v[start] > mini && start >= 0)
    {
        start--;
    }
    while (v[end] < maxi && end < v.size())
    {
        end++;
    }
    return end - start - 1;
}

int main()
{

    vector<int> v{1, 3, 2, 0, -1, 7, 10};

    cout << minwindowsort(v);
    return 0;
}