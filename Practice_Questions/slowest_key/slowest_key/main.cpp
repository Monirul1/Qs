#include <iostream>
#include <vector>
using namespace std;

char slowest(vector<vector<int>>keyTimes);

int main()
{
    vector<vector<int>>input = {{0,2}, {1,5}, {0,9}, {2,15}};
    
    char res = slowest(input);
    cout << res << endl;
    
    return 0;
}

char slowest(vector<vector<int>>keyTimes)
{
    int maxIndex = keyTimes[0][0];
    int max = keyTimes[0][1];
    
    int prev = keyTimes[0][1];
    
    for(int i = 1; i < keyTimes.size(); i++) {
        int curr = keyTimes[i][1] - prev;
        
        if(curr > max) {
            maxIndex = keyTimes[i][0];
            max = curr;
        }
        
        prev = keyTimes[i][1];
    }
    
    
    string table = "abcdefghijklmnopqrstuvwxyz";
    
    return table[maxIndex];
    
}
