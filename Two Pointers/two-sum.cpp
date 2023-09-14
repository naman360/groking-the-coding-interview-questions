/**
 * Problem Statement #
Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.

Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target.

Example 1:

Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> v, int k)
{
    int i = 0, j = v.size() - 1;
    vector<int> ans;
    while (i < j)
    {
        if (v[i] + v[j] == k)
        {
            ans.push_back(i);
            ans.push_back(j);
            break;
        }
        else if (v[i] + v[j] > k)
        {
            j--;
        }
        else
            i++;
    }
    return ans;
}
int main()
{

    vector<int> v = {2, 5, 9, 11};
    int target = 11;
    vector<int> ans = twoSum(v, target);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}