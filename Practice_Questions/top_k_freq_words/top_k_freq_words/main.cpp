#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<string> topK(vector<string>games, vector<string>reviews, int topKGames);
vector<string>removeDuplis(vector<string>inputs);

int main()
{
    vector<string>games = {"newshop", "shopnow", "afashion", "fashionbeats", "mymarket", "tcellular"};
    vector<string>reviews = {"newshop is providing good services in the city; everyone should use newshop",
        "best services by newshop",
        "fashionbeats has great services in the city",
        "I am proud to have fashionbeats",
        "mymarket has awesome services",
        "Thanks Newshop for the quick delivery"};
    int n = 2;
    vector<string>res = topK(games, reviews, n);
    
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    
    return 0;
}


vector<string>removeDuplis(vector<string>inputs)
{
    vector<string>res;
    unordered_set<string>map;
    
    for(int i = 0; i < inputs.size(); i++)
    {
        if(map.find(inputs[i]) == map.end())
        {
            map.insert(inputs[i]);
            res.push_back(inputs[i]);
        }
    }
    
    return res;
    
}

vector<string> topK(vector<string>games, vector<string>reviews, int topKGames)
{
    unordered_map<string, int>map;
    priority_queue<pair<int, string>>pq;
    vector<string>res;
    
    //count only once of occurs within the same array
    
    // to small cases letter
    for(int i = 0; i < reviews.size(); i++)
    {
        for(int j = 0; j < reviews[i].size(); j++)
        {
            reviews[i][j] = tolower(reviews[i][j]);
        }
    }
    
    // insert into the map of games set freq to initial 0
    for(int i = 0; i < games.size(); i++)
    {
        map[games[i]] = 0;
    }

    for(int i = 0; i < reviews.size(); i++)
    {
        string stringBuilder = "";
        vector<string>temp;
        for(int j = 0; j < reviews[i].size(); j++)
        {
            stringBuilder = "";
            while(reviews[i][j] != ' ' && j < reviews[i].size())
            {
                stringBuilder += reviews[i][j];
                j++;
            }
            temp.push_back(stringBuilder);
        }
        
        vector<string>newTemp = removeDuplis(temp);

        for(int k = 0; k < newTemp.size(); k++)
        {
            if(map.find(newTemp[k]) != map.end())
            {
                map[newTemp[k]]++;
            }
        }

    }

    for(auto it = map.begin(); it != map.end(); it++)
    {
        pq.push({it->second, it->first});
    }
    
    
    for(int i = 0; i < topKGames; i++)
    {
        string temp = pq.top().second;
        res.push_back(temp);
        pq.pop();
    }
    
    return res;
    
}
