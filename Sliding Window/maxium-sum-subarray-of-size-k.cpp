/**
 * Problem Statement #
Given an array of positive numbers and a positive number ‘k’, find the maximum sum of any contiguous subarray of size ‘k’.

Example 1:

Input: [2, 1, 5, 1, 3, 2], k=3
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].
*/

#include <bits/stdc++.h>
using namespace std;

int maximumSumSubbarraySizeEqualsK(vector<int> arr, int size, int k)
{
    vector<int> v;
    int maxi = -1e9;
    int curr = 0;
    for (int i = 0; i < k; i++)
    {
        curr += arr[i];
    }
    maxi = curr;

    for (int i = k; i < size; i++)
    {
        curr = curr - arr[i - k] + arr[i];
        maxi = max(curr, maxi);
    }
    return maxi;
}
int main()
{
    vector<int> arr{2, 3, 4, 1, 5};
    int k = 2;
    int ans;
    ans = maximumSumSubbarraySizeEqualsK(arr, arr.size(), k);
    cout << ans;
    return 0;
}