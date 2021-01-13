#include <iostream>
#include <vector>
using namespace std;

vector<int>winningSequence(int num, int lower, int upper);

int main()
{
    int n = 5;
    int l = 3;
    int u = 10;
    
    vector<int>res = winningSequence(n, l, u);
    
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    
    
    
}

vector<int>winningSequence(int num, int lower, int upper)
{
    int delta = upper - lower;
    vector<int>res;

    if (num > 2 * delta + 1) return res; // we cannot form a sequence, there are not enough numbers between lower and upper

    // if we can form a sequence, assume that the element to the left of upper is the starting one
    int starting_number = upper - 1;

    // move to the left until we can form a sequence
    while ((((upper - starting_number) + 1) + delta) < num) {
      starting_number--;
    }

    // construct the array
//    int[] res = new int[num];
    int i = 0;

    // this will fill the elements in the strictly increasing order
    while (starting_number < upper) {
        res.push_back(starting_number++);
        i++;
    }

    // we need to place the upper number
    res.push_back(starting_number--);

    // this will fill the elements in the strictly decreasing order
    while (i < num) {
     res.push_back(starting_number--);
    }

    return res;
    
}
