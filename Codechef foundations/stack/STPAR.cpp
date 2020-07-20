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
    int T;
    stack<int> s;
    cin >> T;
    int temp;
    while (T--)
    {
        cin >> temp;
        if (s.empty())
            s.push(temp);
        else if (s.top() > temp)
            s.push(temp);
        else
        {
            s.pop();
        }
    }

    int top = s.top();
    while (!s.empty())
    {
        s.pop();
        if (top > s.top())
        {
            cout << "NO" << endl;
            break;
        }
        top = s.top();
    }

    cout << "YES" << endl;

    return 0;
}