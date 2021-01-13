#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

vector<string> get_fraud_id(vector<string> input, int threshold);

int main()
{

    vector<string> id = {{"88 99 45"},
        {"88 99 23"},
        {"99 32 15"},
        {"12 12 77"},
       };

    vector<string>res = get_fraud_id(id, 2);
    
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}

vector<string> get_fraud_id(vector<string> input, int threshold)
{
    unordered_map<string, int>map;
    priority_queue<pair<int, string>>pq;
    vector<string>res;
    
    for(int i = 0; i < input.size(); i++)
    {
        string stringBuilder = "";
        vector<string>temp;
        for(int j = 0; j < input[i].size(); j++)
        {
            stringBuilder = "";
            while(input[i][j] != ' ' && j < input[i].size())
            {
                stringBuilder += input[i][j];
                j++;
            }
            temp.push_back(stringBuilder);
        }
        vector<string>temp2;
        for(int i = 0; i < 1; i++)
        {
            if(temp[i] == temp[i+1])
            {
                temp2.push_back(temp[i]);
            } else {
                temp2.push_back(temp[i]);
                temp2.push_back(temp[i+1]);
            }
        }
       
        for(int k = 0; k < temp2.size(); k++)
        {
            map[temp2[k]]++;
        }
        
    }
    
    for(auto it = map.begin(); it != map.end(); it++)
    {
        pq.push({it->second, it->first});
    }
    
    for(int i = 0; i < threshold; i++)
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    
    return res;
}
