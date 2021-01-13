#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;


void findSmallest(int numRows, int numCols, vector<vector<string>>debts);

int main()
{
    int r = 5;
    int c = 3;
    
    vector<vector<string>>input = {
                        {"Alex", "Blake", "2"},
                        {"Blake", "Alex", "2"},
                        {"Casey", "Alex", "5"},
                        {"Blake", "Casey", "7"},
                        {"Alex", "Blake", "4"},
                        {"Alex", "Casey", "4"}
    };
    
    /*
     1.
     {"Alex", "Blake", "29"},
     {"Blake", "Alex", "3"},
     {"Casey", "Alex", "7"},
     {"Casey", "Alex", "4"},
     {"Casey", "Alex", "2"}
     
     2.
     {"Alex", "Blake", "2"},
                           {"Blake", "Alex", "2"},
                           {"Casey", "Alex", "5"},
                           {"Blake", "Casey", "7"},
                           {"Alex", "Blake", "4"},
                           {"Alex", "Casey", "4"}
     */
//
//    vector<string>res = findSmallest(r, c, input);
//    for(int i = 0; i < res.size(); i++)
//    {
//        cout << res[i] << endl;
//    }
    findSmallest(r, c, input);
    
    return 0;
}

void findSmallest(int numRows, int numCols, vector<vector<string>>debts)
{
    unordered_map<string, int>lenderMap;
    vector<string>res;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>>pq;
    
    for(int i = 0; i < debts.size(); i++)
    {
        lenderMap[debts[i][1]] += stoi(debts[i][2]);
    }
 
    
    for(int i = 0; i < debts.size(); i++)
    {
        if(lenderMap.find(debts[i][0]) != lenderMap.end())
        {
            lenderMap[debts[i][0]] -= stoi(debts[i][2]);
        } else {
            lenderMap[debts[i][0]] -= stoi(debts[i][2]);
        }
    }
    
    for(auto it = lenderMap.begin(); it != lenderMap.end(); it++)
    {
        pq.push({it->second, it->first});
    }
    
    
    int temp = pq.top().first;

    // check if atleast one negative values exists
    if(temp < 0)
    {
        while(temp == pq.top().first)
        {
            
            res.push_back(pq.top().second);
            pq.pop();
        }
    }
    // if same negative values return in sorted order
    if(res.size() > 0)
    {
        sort(res.begin(), res.end());
    }
    
    if(res.size() == 0)
    {
        res.push_back("Nobody has a negative balance");
        cout << res[0];
//        return res;
    } else {
        for(int i = 0; i < res.size(); i++)
        {
            cout << res[i] << endl;
        }
//        return res;
    }
}
