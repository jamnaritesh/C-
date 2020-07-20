
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums = {-1, 0, 1, 0};
    vector<vector<int>> res;
    set<vector<int>> resSet;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() && nums.size() >= 3; i++)
    {

        vector<int> triplet; //resSetultSet for twosum

        int first = nums[i];
        triplet.push_back(first);

        int twoSumNeeded = 0 - first;

        for (int j = i + 1; j < nums.size(); j++)
        {

            if (i == j)
                continue;
            bool foundElement = false;
            int second = nums[j];
            int third = -(first + second);

            vector<int>::iterator lb = lower_bound(nums.begin(), nums.end(), third);
            int lbIndex = distance(nums.begin(), lb);

            if (lbIndex < nums.size() && *lb == third)
            {
                // verify that you're not choosing first and second again

                if (lbIndex != j && lbIndex != i)
                {

                    triplet.push_back(second);
                    triplet.push_back(third);
                    sort(triplet.begin(), triplet.end());
                    resSet.insert(triplet);
                    triplet.clear();
                    triplet.push_back(first);
                }
                else
                {
                    int greatest = max(i, j);
                    if (greatest + 1 < nums.size() && nums[greatest + 1] == third)
                    {
                        triplet.push_back(second);
                        triplet.push_back(third);
                        sort(triplet.begin(), triplet.end());
                        resSet.insert(triplet);
                        triplet.clear();
                        triplet.push_back(first);
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                continue; // can't find third element
            }
        }
        while (i < nums.size() && nums[i] == nums[i + 1])
            i++;
    }
    for (vector<int> it : resSet)
        res.push_back(it);
    return 0;
}
