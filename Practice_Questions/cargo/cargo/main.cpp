#include <functional>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

void totalItem(vector<int>container, vector<int>items, int cargoSize);

int main()
{
    priority_queue<int>pq;
    vector<int>container = {3, 1, 2};
    vector<int>items = {1, 2, 3};
    int n = 4;
    
    totalItem(container, items, n);
    
    
    return 0;
}

void totalItem(vector<int>container, vector<int>items, int cargoSize)
{
    vector<pair<int, int>>vect;
    
    vector<int>temp;
    
    for(int i = 0; i < container.size(); i++)
    {
        for(int j = 0; j < container[i]; j++)
        {
            temp.push_back(items[i]);
        }
    }

    sort(temp.begin(), temp.end(), greater<int>());
    int res = 0;
    for(int i = 0; i < cargoSize; i++)
    {
        res += temp[i];
    }
    
    cout << res << endl;
    
}
