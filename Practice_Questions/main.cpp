#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<string>smallest(int row, int col, vector<vector<string>>debts);

int main()
{
// ch ()
    vector<vector<string>>input ={{"Alex", "Blake", "7"},
                                    {"Blake", "Alex", "7"},
        {"Casey", "Alex", "5"},
        {"Blake", "Casey", "7"},
        {"Alex", "Blake", "4"},
        {"Alex", "Casey", "4"}};
     vector<string>res = smallest(5, 3, input);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }

    
    return 0;
}

vector<string> smallest(int row, int col, vector<vector<string>>debts)
{
    vector<string>res;
    unordered_map<string, vector<int>>lenderMap;
    
    for(int i = 0; i < row; i++)
    {
        lenderMap[debts[i][1]].push_back(stoi(debts[i][2]));
    }
    
    unordered_map<string, int>newLenderMap;
    
    for(auto it = lenderMap.begin(); it != lenderMap.end(); it++)
    {
        int sum = 0;
        for(int i = 0; i < it->second.size(); i++)
        {
            sum += it->second[i];
        }
        newLenderMap[it->first] = sum;
    }

    for(int i = 0; i < debts.size(); i++)
    {
        if(newLenderMap.find(debts[i][0]) != newLenderMap.end())
        {
            newLenderMap[debts[i][0]] -= stoi(debts[i][2]);
        }
    }
    
    for(auto it = newLenderMap.begin(); it != newLenderMap.end(); it++)
    {
        if(it->second < 0)
        {
            res.push_back(it->first);
        }
    }
    
    unordered_set<string>tempSet;
    for(int i = 0; i < debts.size(); i++)
    {
       if(newLenderMap.find(debts[i][0]) == newLenderMap.end() && tempSet.find(debts[i][0]) == tempSet.end())
       {
           tempSet.insert(debts[i][0]);
       }
    }
    
    for(auto it = tempSet.begin(); it != tempSet.end(); it++)
    {
        res.push_back(*it);
    }
    
    sort(res.begin(), res.end());
    
    if(res.size()==0)
    {
        res.push_back("Sorry no negative found");
        return res;
    } else {
        return res;
    }
     
}
