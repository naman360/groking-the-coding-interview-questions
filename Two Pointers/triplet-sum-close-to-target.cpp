/**
 * Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close to the target number as possible, return the sum of the triplet. If there are more than one such triplet, return the sum of the triplet with the smallest sum.

Example 1:

Input: [-2, 0, 1, 2], target=2
Output: 1
Explanation: The triplet [-2, 1, 2] has the closest sum to the target.
*/
#include <bits/stdc++.h>
using namespace std;

int triplet(vector<int> v, int target)
{
    // cout << "Hello";

    int i = 0, low, high;
    sort(v.begin(), v.end());
    // -3 -2 -1 -1 0 1 2
    int ans, mini = 1e9;
    while (i < v.size())
    {
        int low = i + 1, high = v.size() - 1;
        while (low < high)
        {
            int sum = v[i] + v[low] + v[high];

            if (sum <= target)
                low++;
            else if (sum > target)
                high--;

            // mini = min(mini, target - sum);
            if (mini > fabs(target - sum))
            {
                mini = target - sum;
                ans = sum;
            }
        }
        i++;
    }
    return ans;
}

int main()
{

    vector<int> v{1, 0, 1, 1};
    int target = 1000;
    int ans = triplet(v, target);
    cout << ans;
    return 0;
}