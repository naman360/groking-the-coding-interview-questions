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

// Comments same as string-anagrams.cpp
#include <bits/stdc++.h>
using namespace std;

bool permutation(string s, string p)
{
    unordered_map<char, int> mp;
    int j = 0;
    for (int i = 0; i < p.size(); i++)
    {
        mp[p[i]]++;
    }

    bool ans = false;
    int matched = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp.find(s[i]) != mp.end())
        {
            mp[s[i]]--;
            if (mp[s[i]] == 0)
                matched++;
        }
        if (matched == mp.size())
            return true;
        if (i - j + 1 >= p.size())
        {
            if (mp.find(s[j]) != mp.end())
            {
                mp[s[j]]++;
                if (mp[s[j]] == 1)
                    matched--;
            }
            j++;
        }
    }
    return false;
}
int main()
{
    string s = "ppmqmp";
    string p = "pmq";
    cout << permutation(s, p);
    return 0;
}