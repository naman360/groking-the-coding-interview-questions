/**
 * Problem Statement #
Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s, find the length of the longest contiguous subarray having all 1s.

Example 1:

Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
Output: 6
Explanation: Replace the '0' at index 5 and 8 to have the longest contiguous subarray of 1s having length 6.
*/
#include <bits/stdc++.h>
using namespace std;

int longestSubstring(vector<int> v, int k)
{
    int maxi = -1e9;
    int j = 0;
    unordered_map<int, int> mp;
    int maxOcc = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
            maxOcc++;

        if (i - j + 1 - maxOcc > k)
        {
            if (v[j] == 1)
                maxOcc--;
            j++;
        }
        maxi = max(i - j + 1, maxi);
    }
    return maxi;
}
int main()
{
    vector<int> arr{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1};
    int k = 3;
    cout << longestSubstring(arr, k);
    return 0;
}