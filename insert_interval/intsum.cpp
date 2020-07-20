#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

void display(int *a, long long int n)
{
    for (long long int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> intervals = {};
    vector<int> newInterval = {5, 7};
    stack<vector<int>> s;
    stack<vector<int>> temp_stack;
    for (auto it : intervals)
    {
        s.push(it);
    }

    if (!s.empty())
    {
        vector<int> top = s.top();

        while (top[0] > newInterval[0] && !s.empty())
        {
            temp_stack.push(s.top());
            s.pop();
            if (!s.empty())
                top = s.top();
        }
    }

    if (s.empty())
    {
        s.push(newInterval);
    }
    else
        temp_stack.push(newInterval);

    while (!temp_stack.empty())
    {
        if (!s.empty() && temp_stack.top()[0] > s.top()[0] && temp_stack.top()[0] <= s.top()[1])
        {
            vector<int> sTop = s.top();
            vector<int> tTop = temp_stack.top();
            int start = min(sTop[0], tTop[0]);
            int end = max(sTop[1], tTop[1]);
            vector<int> newInt = {start, end};
            s.pop();
            temp_stack.pop();
            s.push(newInt);
        }
        else
        {
            vector<int> item = temp_stack.top();
            s.push(item);
            temp_stack.pop();
        }
    }
    vector<vector<int>> res;
    while (!s.empty())
    {
        res.push_back(s.top());
        s.pop();
    }
    reverse(res.begin(), res.end());
    return 0;
    // return res;
}