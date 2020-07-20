#include <iostream>
using namespace std;

int main()
{
    long long int input, c, total;
    int n, t;

    cin >> t;

    while (t--)
    {
        cin >> n >> c;
        total = 0;
        while (n--)
        {
            cin >> input;
            total += input;
        }
        if (total > c)
        {
            cout << "No" << endl;
        }
        else
        {

            cout << "Yes" << endl;
        }
    }

    return 0;
}