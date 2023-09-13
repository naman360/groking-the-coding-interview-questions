/**
 * Given a string and a list of words, find all the starting indices of substrings in the given string that are a concatenation of all the given words exactly once without any overlapping of words. It is given that all words are of the same length.

Example 1:

Input: String="catfoxcat", Words=["cat", "fox"]
Output: [0, 3]
Explanation: The two substring containing both the words are "catfox" & "foxcat".
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> wordsConcatenation(string s, vector<string> p)
{
    unordered_map<string, int> mp;
    int j = 0;
    for (int i = 0; i < p.size(); i++)
    {
        mp[p[i]]++;
    }
    int wordlen = p[0].length(), total = p.size();
    vector<int> v;
    for (int i = 0; i <= s.size() - wordlen * total; i++)
    {
        unordered_map<string, int> seen;
        for (int j = 0; j < total; j++)
        {
            int start = i + j * wordlen;
            string sub = s.substr(start, wordlen);
            if (mp.find(sub) == mp.end())
                break;
            seen[sub]++;
            if (seen[sub] > mp[sub])
                break;
            if (j + 1 == total)
                v.push_back(i);
        }
    }

    return v;
}
int main()
{
    string s = "catcatfoxfox";
    vector<string> v = {"cat", "fox"};
    vector<int> ans = wordsConcatenation(s, v);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}