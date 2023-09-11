/**
 * Given a string and a pattern, find out if the string contains any permutation of the pattern.

Permutation is defined as the re-arranging of the characters of the string. For example, “abc” has the following six permutations:

abc
acb
bac
bca
cab
cba
If a string has ‘n’ distinct characters it will have
�
!
n! permutations.

Example 1:

Input: String="oidbcaf", Pattern="abc"
Output: true
Explanation: The string contains "bca" which is a permutation of the given pattern.
*/
#include <bits/stdc++.h>
using namespace std;

bool permutation(string s, string p)
{
    unordered_map<char, int> mp;
    int j = 0;
    for (int i = 0; i < p.size(); i++)
    {
        mp[p[i]]++;
        // cout << p[i] << " ";
    }

    bool ans = false;
    int matched = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp.find(s[i]) != mp.end())
        {
            mp[s[i]]--;
            matched++; // find out how many elements which are in p are matched with the characters in string s
        }
        if (matched == p.size())
            return true;
        if (i - j + 1 >= p.size()) // if window size > pattern size we need to shrink window and decrement matched and increase freq of selected character if it is in the map (= is for ensuring that window length does not exceeds p length)
        {
            if (mp.find(s[j]) != mp.end())
            {
                matched--;
                mp[s[j]]++;
            }
            j++;
        }
    }
    return false;
}
int main()
{
    string s = "bcdxabcdy";
    string p = "bcdyabcdx";
    cout << permutation(s, p);
    return 0;
}