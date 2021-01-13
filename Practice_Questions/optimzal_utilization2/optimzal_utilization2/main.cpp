#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

vector<vector<int>> optimal(vector<vector<int>>& a, vector<vector<int>>& b, int target)
{
    std::sort(a.begin(), a.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1];});
    std::sort(b.begin(), b.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1];});

    auto aptr = a.begin();
    auto bptr = b.rbegin();

    int minSum = -1 * __INT_MAX__;
    vector<vector<int>> res;

    while(aptr != a.end() && bptr != b.rend())
    {
        int sum = (*aptr)[1] + (*bptr)[1];
        if(sum > target)
        {
            //decrement bptr
            ++bptr;
        }
        else
        {
            //sum <= to target which is what we want
            if(sum > minSum)
            {
                res.clear();
            }
            res.push_back({(*aptr)[0], (*bptr)[0]});
            minSum = sum;
            ++aptr;
        }
    }
    return res;
}

void test(vector<vector<int>> a, vector<vector<int>> b, int target)
{
    vector<vector<int>> res = optimal(a, b, target);
    for(auto i = res.begin(); i != res.end(); ++i)
    {
        for(auto j = (*i).begin(); j != (*i).end(); ++j)
            cout << ' ' << *j;
        cout << '\n';
    }

    cout << endl;
}

int main()
{
    test({{1, 2}, {2, 4}, {3, 6}}, {{1, 2}}, 7);
    test({{1, 3}, {2, 5}, {3, 7}, {4, 10}}, {{1, 2}, {2, 3}, {3, 4}, {4, 5}}, 10);
    test({{1, 8}, {2, 7}, {3, 14}}, {{1, 5}, {2, 7}, {3, 14}}, 20);
    return 0;
}
