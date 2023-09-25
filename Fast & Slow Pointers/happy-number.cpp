/**
 * Any number will be called a happy number if, after repeatedly replacing it with a number equal to the sum of the square of all of its digits, leads us to number ‘1’. All other (not-happy) numbers will never reach ‘1’. Instead, they will be stuck in a cycle of numbers which does not include ‘1’.

Example 1:

Input: 23
Output: true (23 is a happy number)
Explanations: Here are the steps to find out that 23 is a happy number:
*/
#include <bits/stdc++.h>
using namespace std;

int square(int num)
{
    int ans = 0;
    while (num)
    {
        int re = num % 10;
        ans += re * re;
        num /= 10;
    }
    return ans;
}
int find(int num)
{
    int slow = num, fast = num;
    do
    {
        slow = square(slow);
        fast = square(square(fast));
    } while (slow != fast);
    return slow == 1;
}
int main()
{
    int num = 23;
    cout << find(num);
    return 0;
}