#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void cutOffRank(int cutRank, vector<int>scores);

int main()
{
    int cutOff = 4;
    vector<int>arr = {2, 2, 3, 4, 5};
    
    cutOffRank(cutOff, arr);
    
    
    
    return 0;
}


void cutOffRank(int cutRank, vector<int>scores)
{
    sort(scores.begin(), scores.end(), greater<int>());
//    vector<int>rank;
    unordered_map<int, int>map;
    for(int i = 0; i <= scores.size(); i++)
    {
        if(map.find(scores[i]) == map.end())
        {
            
        }
        
    }
    
//    unordered_map<int, vector<int>>map;
//
//    for(int i = 1; i <= scores.size(); i++)
//    {
//        map[i].push_back(scores[i]);
//    }
//
//    for(auto it = map.begin(); it != map.end(); it++)
//    {
//        cout << it->first << ": ";
//        for(int i = 0; i < it->second.size(); i++)
//        {
//            cout << it->second[i];
//        }
//        cout << endl;
//
//    }
    
    
}
