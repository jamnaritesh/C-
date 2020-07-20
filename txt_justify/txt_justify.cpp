#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void display(int *a, long long int n)
{
    for (long long int i = 0; i < n; i++)
    {
        cout << a[i];
    }

    cout << endl;
}

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<int> cummulitativeSum;
    vector<string> res;
    cummulitativeSum.push_back(words[0].length());
    for (int i = 1; i < words.size(); i++)
    {
        cummulitativeSum.push_back(cummulitativeSum[i - 1] + words[i].length());
    }

    int totalWordSize = cummulitativeSum[cummulitativeSum.size() - 1];

    int lines = totalWordSize % maxWidth + ((totalWordSize % maxWidth == 0) ? 0 : 1);
    vector<vector<string>> justifiedLines;
    int lastIndex = 0;
    for (int i = 1; i < lines + 1; i++)
    {
        int lowerBound = 0;
        vector<string> currentList;
        for (int j = lastIndex; maxWidth * i < cummulitativeSum[j]; j++)
        {
            lowerBound = j;
        }
        lowerBound = lowerBound + 1;

        for (int k = lastIndex; lastIndex < lowerBound; k++)
        {
            currentList.push_back(words[k]);
            lastIndex++;
        }
        // justifiedLines.push_back(c)
    }

    return res;
}

int main()
{
    int x = 16;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    fullJustify(words, x);

    return 0;
}