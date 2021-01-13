#include <iostream>
#include <cmath>
using namespace std;

int finalInstances(int instances, int arr[]);
const int SIZE = 14;

int main()
{
    int instances = 2;
    int arr[SIZE] = {25, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 76, 80};
    
    int res = finalInstances(instances, arr);
    cout << res << endl;
    
    return 0;
}

int finalInstances(int instances, int arr[])
{
    for(int i = 0; i < SIZE; i++)
    {
        if(arr[i] < 25)
        {
            if(instances != 1)
            {
                instances = ceil(float(instances)/float(2));
                
                i = i+10;
            }
            
        } else if(arr[i] > 60)
        {
            if(!(arr[i]*2 > 2*(pow(10, 8))))
            {
                instances = instances*2;
                i = i+10;
            }
        }
        
    }
    
    return instances;
    
    
}
