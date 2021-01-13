#include <iostream>
#include <vector>
using namespace std;


void getReviews(vector<int>lengths, int min, int max, int minRev);
//void findSubsets(vector<int>&arr, int size, vector<int>vect);

int main()
{
    vector<int>input = {6, 13, 5, 10, 12, 4, 2, 15};
    int min = 4;
    int max = 10;
    int rev = 3;
    
    getReviews(input, min, max, rev);
    
    
    
    return 0;
}

void getReviews(vector<int>lengths, int min, int max, int minRev)
{
    vector<int>temp;
    
    for(int i = 0; i < lengths.size(); i++)
    {
        if(lengths[i] >= min && lengths[i] <= max)
        {
            temp.push_back(lengths[i]);
        }
    }
    sort(temp.begin(), temp.end());

    
    
    
}


