#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

// 12, 10, 7, 8, 50, 28
// 12, 10, INTMAX, 8, 50, 28
int main()
{
    int n;
    cin >> n;
    int array[n];
    for(int i = 0; i < n; i++)
        cin >> array[i];
    
    int firstmin = INT_MAX;
    int firstminind;

    for(int i = 0; i < n; i++)
    {
        if(array[i] < firstmin)
        {
            firstmin = array[i];
            firstminind = i;
        }
    }
    array[firstminind] = INT_MAX;
    int secondmin = INT_MAX;
    

    for(int i = 0; i < n; i++)
    {
        if(array[i] < secondmin)
        {
            secondmin = array[i];
        }
    }
    
    cout << "second minimum is : " << secondmin << endl;



    return 0;
}