#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<string> smallerTrade(vector<vector<string>>countries);

int main()
{
    vector<vector<string>>input = {{"US", "China", "2"},
                                    {"China", "US", "2"},
                                    {"Japan", "US", "5"},
                                    {"China", "Japan","7"},
                                    {"US", "China", "4"},
                                    {"US", "Japan", "4"}
    };
    
   vector<string>res = smallerTrade(input);
    
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    
    return 0;
}

vector<string> smallerTrade(vector<vector<string>>countries)
{
    unordered_map<string, int>map;
    vector<string>res;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>>pq;
    
    for(int i = 0; i < countries.size(); i++)
    {
        map[countries[i][1]] += stoi(countries[i][2]);
    }
    
    for(int i = 0; i < countries.size(); i++)
    {
        if(map.find(countries[i][0]) != map.end())
        {
            map[countries[i][0]] -= stoi(countries[i][2]);
        }
    }
   
    for(auto it = map.begin(); it!=map.end(); it++)
    {
        pq.push({it->second, it->first});
    }
    
    while(!pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
}
