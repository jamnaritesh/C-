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
    cin >> T;
    stack<int> s;
    long long int n;
    int a[100];
    while (T--)
    {
        long long int i = 0;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (i = n - 1; i > 0; i--)
        {
            if (i == n - 1)
            {
                s.push(a[i]);
            }
            else
            {
                if (a[i] < a[i + 1])
                {
                    int temp = a[i + 1];
                    a[i + 1] = a[i];
                    a[i] = temp;
                    queue<int> p;
                    while (s.top() <= a[i + 1])
                    {
                    }
                    sort(a + i + 1, a + n);
                    display(a, n);
                    break;
                }
            }
        }

        if (i == 0)
        {
            cout << -1 << endl;
        }
    }

    return 0;
}
