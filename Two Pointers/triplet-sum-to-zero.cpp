/**
 * Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

Example 1:

Input: [-3, 0, 1, 2, -1, 1, -2]
Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
Explanation: There are four unique triplets whose sum is equal to zero.
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(vector<int> v)
{

    int i = 0, low, high;
    sort(v.begin(), v.end());

    // -3 -2 -1 -1 0 1 2
    vector<vector<int>> ans;
    while (i <= v.size() - 3)
    {
        int tofind = 0 - v[i];
        low = i + 1, high = v.size() - 1;
        while (low < high)
        {
            if (v[low] + v[high] == tofind)
            {
                vector<int> p;
                p.push_back(v[i]);
                p.push_back(v[low]);
                p.push_back(v[high]);
                ans.push_back(p);
            }
            else if (v[low] + v[high] > tofind)
            {
                high--;
            }
            else
                low++;
        }
        i++;
    }
    return ans;
}

int main()
{

    vector<int> v = {-3, 1, 2, 4};
    vector<vector<int>> ans = triplet(v);
    for (auto v : ans)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}