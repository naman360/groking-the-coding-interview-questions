/**
 * Given a sorted array, create a new array containing squares of all the number of the input array in the sorted order.

Example 1:

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> squaredArray(vector<int> v)
{

    int i = 0, j = v.size() - 1;
    vector<int> ans(v.size());
    int p = v.size() - 1;
    while (i <= j)
    {
        if (v[i] * v[i] > v[j] * v[j])
        {
            ans[p] = v[i] * v[i];
            i++;
            p--;
        }
        else if (v[i] * v[i] <= v[j] * v[j])
        {
            ans[p] = v[j] * v[j];
            j--;
            p--;
        }
    }
    return ans;
}

int main()
{

    vector<int> v = {2, 3, 4};
    vector<int> ans = squaredArray(v);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}