/**
 * Problem Statement #
Given an array of positive numbers and a positive number ‘S’, find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0, if no such subarray exists.

Example 1:

Input: [2, 1, 5, 2, 3, 2], S=7
Output: 2
Explanation: The smallest subarray with a sum great than or equal to '7' is [5, 2].

*/

#include <bits/stdc++.h>
using namespace std;

int smallestSum(vector<int> arr, int size, int k)
{

    int mini = 1e9;
    int curr = 0;
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        curr += arr[i];
        while (curr >= k)
        {
            mini = min(i - j + 1, mini);
            curr -= arr[j];
            j++;
        }
    }

    return mini;
}
int main()
{
    vector<int> arr{2, 1, 5, 2, 3, 2};
    int k = 7;
    int ans;
    ans = smallestSum(arr, arr.size(), k);
    cout << ans;
    return 0;
}