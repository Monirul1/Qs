#include <iostream>
#include <vector>
using namespace std;


int optimal(vector<int>buildingOpen, vector<int>offLoadTime, int numBuildings);

int main()
{
    vector<int>buildingOpen = {7, 9};
    vector<int>offLoadTime = {7, 6, 3, 4, 1, 1, 2, 0};
    int n = 2;
    
    int res = optimal(buildingOpen, offLoadTime, n);
    
    cout << res << endl;
    
    
    return 0;
}

int optimal(vector<int>buildingOpen, vector<int>offLoadTime, int numBuildings)
{
    sort(offLoadTime.begin(), offLoadTime.end(), greater<int>());
    sort(buildingOpen.begin(), buildingOpen.end());
    
    int res = INT_MIN;
    
    int i = 0, j = 0;
    
    for(int a: buildingOpen)
    {
        int count = 0;
        while(j < offLoadTime.size() && count < 4)
        {
            res = max(res, a+offLoadTime[j]);
            j++;
            count++;
        }
    }
    
    return res;
    
    
}
