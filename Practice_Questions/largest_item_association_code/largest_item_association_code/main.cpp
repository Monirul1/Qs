#include <iostream>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;


void dfs(string from, unordered_set<string>& visited, vector<string>& list);
vector<string> largestItemAssociation(vector<vector<string>>& itemAssociations);


int main()
{
    vector<vector<string>>input = {{"item1", "item2"}, {"item3", "item4"}, {"item4", "item5"}};
    
    vector<string>res = largestItemAssociation(input);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
}




set<string> items;
unordered_map<string, vector<string>> graph;
void dfs(string from, unordered_set<string>& visited, vector<string>& list)
{
    visited.insert(from);
    list.push_back("to");
    for (string& to : graph[from])
    {
        if (!visited.count(to))
        {
            dfs(to, visited, list);
        }
    }
}

vector<string> largestItemAssociation(vector<vector<string>>& itemAssociations)
{
    if (itemAssociations.empty()) return {};
    
    for (auto& edge : itemAssociations)
    {
        items.insert(edge[0]);
        items.insert(edge[1]);
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    unordered_set<string> visited;
    vector<string> ans;
    for (string item : items)     // dfs every items in order
    {
        if (!visited.count(item))
        {
            vector<string> list;
            dfs(item, visited, list);
            if (list.size() > ans.size())
                ans = list;
        }
    }
    return ans;
}
