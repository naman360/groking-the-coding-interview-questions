/**
 * Problem Statement #
Given an array of sorted numbers, remove all duplicates from it. You should not use any extra space; after removing the duplicates in-place return the new length of the array.

Example 1:

Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after removing the duplicates will be [2, 3, 6, 9].
*/
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> v)
{
    int i = 1, nextNonDuplicate = 1;
    while (i < v.size())
    {
        if (v[nextNonDuplicate - 1] != v[i])
        {
            v[nextNonDuplicate] = v[i];
            nextNonDuplicate++;
        }
        i++;
    }
    return nextNonDuplicate;
}

int main()
{

    vector<int> v = {2, 2, 2, 11};
    cout << removeDuplicates(v);
    return 0;
}