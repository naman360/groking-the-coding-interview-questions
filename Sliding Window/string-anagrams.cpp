/**
 * Given a string and a pattern, find all anagrams of the pattern in the given string.

Anagram is actually a Permutation of a string. For example, “abc” has the following six anagrams:

abc
acb
bac
bca
cab
cba
Write a function to return a list of starting indices of the anagrams of the pattern in the given string.

Example 1:

Input: String="ppqp", Pattern="pq"
Output: [1, 2]
Explanation: The two anagrams of the pattern in the given string are "pq" and "qp".

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> anagram(string s, string p)
{
    vector<int> ans;
    unordered_map<char, int> mp;
    for (int i = 0; i < p.size(); i++)
    {
        mp[p[i]]++;
    }
    int matched = 0, j = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (mp.find(s[i]) != mp.end())
        {

            mp[s[i]]--;
            if (mp[s[i]] == 0)
            {
                matched++; // all unique characters exhausted
            }
        }
        if (matched == mp.size()) // if unique char count is equal to the maap size hence the pattern then push starting index
        {
            ans.push_back(j);
        }
        if (i - j + 1 >= p.size()) // if window>=pattern size
        {
            if (mp.find(s[j]) != mp.end()) // if leftmost element to be removed is in map
            {

                mp[s[j]]++;        // remove it by incrementing count
                if (mp[s[j]] == 1) // and if it becomes 1 hence it is not now fully exhausted
                    matched--;     // hence decrement match
            }
            j++; // shrink window
        }
    }
    return ans;
}
int main()
{
    string s = "ppppqp";
    string p = "pppq";
    vector<int> v = anagram(s, p);

    for (auto num : v)
    {
        cout << num << " ";
    }
    return 0;
}