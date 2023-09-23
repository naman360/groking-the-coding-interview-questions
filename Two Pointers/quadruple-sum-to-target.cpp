/**
 * Given an array of unsorted numbers and a target number, find all unique quadruplets in it, whose sum is equal to the target number.

Example 1:

Input: [4, 1, 2, -1, 1, -3], target=1
Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
Explanation: Both the quadruplets add up to the target.
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> foursum(vector<int> v, int target)
{
    sort(v.begin(), v.end());
    int low, high;
    vector<vector<int>> ans;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            low = j + 1, high = v.size() - 1;
            while (low < high)
            {
                int sum = v[i] + v[j] + v[low] + v[high];
                if (sum == target)
                {
                    vector<int> p = {v[i], v[j], v[low], v[high]};
                    ans.push_back(p);
                    low++, high--;
                }
                else if (sum < target)
                    low++;
                else
                    high--;
            }
        }
    }
    return ans;
}

int main()
{

    vector<int> v{4, 1, 2, -1, 1, -3};
    int target = 1;
    vector<vector<int>> ans = foursum(v, target);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}