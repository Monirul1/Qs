#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

vector<vector<int>> kNearest(vector<int>myPositions, vector<vector<int>>postOffices, int k);

int main()
{
    vector<int>me = {0, 0};
    vector<vector<int>>post = {{-16,5}, {-1,2}, {4,3}, {10,-2}, {0,3}, {-5,-9}};
    int k = 3;
    
   vector<vector<int>> res = kNearest(me, post, k);
    
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << ", " << res[i][1];
        cout << endl;
    }
    
    return 0;
}

vector<vector<int>>  kNearest(vector<int>myPositions, vector<vector<int>>postOffices, int k)
{
    
    vector<vector<int>>res;
    priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>> > pq;

    
    int m = myPositions[0];
    int n = myPositions[1];
    
    for(int i = 0; i < postOffices.size(); i++)
    {
        vector<int>temp;
        
        int p = postOffices[i][0];
        int q = postOffices[i][1];
        
        double location = sqrt( (m-p)*(m-p) + (n-q)*(n-q) );
        
        temp.push_back(p);
        temp.push_back(q);
        
        pq.push({location, temp});
    }
    
    for(int i = 0; i < k; i++)
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    
    
    return res;
    
    
}
