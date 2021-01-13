#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> partitionLabels(string S);

int main()
{
    string s = "awaglk";
    int k = 4;
    
    vector<int>res = partitionLabels(s);
    
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    
    cout << endl;
    
    
    
    return 0;
}

vector<int> partitionLabels(string S) {
       unordered_map<char, int> lastOccurence;
       for(int i = 0; i<S.size(); i++){
           char c = S[i];
           lastOccurence[c] = i;
       }
       
       int lastPartitionIdx = 0;
       int beginPartition = 0;
       vector<int> partitionIdx;
       for(int i = 0; i<S.size(); i++){
           char c = S[i];
           if (i > lastPartitionIdx){
               partitionIdx.push_back(i-beginPartition);
               beginPartition = i;
           }
           lastPartitionIdx = max(lastOccurence[c], lastPartitionIdx);
           
       }
       partitionIdx.push_back(S.size()-beginPartition);
       return partitionIdx;
   }
