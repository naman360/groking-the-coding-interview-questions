/**
 * Problem Statement #
Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices. Write a function to return the count of such triplets.

Example 1:

Input: [-1, 0, 2, 3], target=3
Output: 2
Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]
*/
#include <bits/stdc++.h>
using namespace std;

int triplet(vector<int> v, int target)
{
    // cout << "Hello";
    sort(v.begin(), v.end());
    int i = 0;
    int count = 0;
    while (i < v.size())
    {
        int low = i + 1, high = v.size() - 1;
        while (low < high)
        {
            int sum = v[i] + v[low] + v[high];
            if (sum >= target)
            {
                high--;
            }
            else
            {
                count += (high - low); // include all elments in window because if we decrease high till ow all sum will be lesser than target
                low++;
            }
        }
        i++;
    }
    return count;
}

int main()
{

    vector<int> v{-1, 0, 2, 3};
    int target = 3;
    int ans = triplet(v, target);
    cout << ans;
    return 0;
}