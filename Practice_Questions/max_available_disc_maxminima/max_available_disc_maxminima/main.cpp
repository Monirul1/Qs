#include <iostream>
#include <vector>
using namespace std;

void minima(vector<int>temp, int kDays);

int main()
{
    vector<int>input = {62, 64, 77, 75, 71, 60, 79, 75};
    int k = 4;
    
    minima(input, k);
    
    
    return 0;
}

void minima(vector<int>temp, int kDays)
{
    vector<vector<int>>vect;
   
    int i = 0;
    
    while(i <= temp.size()-kDays)
    {
        vector<int>v;
        int j = i;
        int k = 0;
        while(k < kDays)
        {
            v.push_back(temp[j]);
            j++;
            k++;
        }
        vect.push_back(v);
        i++;
    }
    
    vector<int>collectMini;
    
    for(int i = 0; i < vect.size(); i++)
    {
        int mini = INT_MAX;
        for(int j = 0; j < vect[i].size(); j++)
        {
            if(vect[i][j] < mini)
            {
                mini = vect[i][j];
            }
        }
        collectMini.push_back(mini);
        
    }
    
    sort(collectMini.begin(), collectMini.end(), greater<int>());
    cout << collectMini[0];
    
}
