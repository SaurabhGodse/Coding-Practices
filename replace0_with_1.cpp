#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num, rem, n = 0, t = 1;
    cout << "Enter a number : ";
    cin >> num;
    while(num != 0)
    {
        cout << "number is : " << num << endl;
        rem = num % 10;
        cout << "rem is : " << rem << endl;
        if(rem == 0)
        {
            rem = 1;
        }
        n = n + rem * t;
        cout << "n is : " << n << endl;
        num = num / 10;
        t = t * 10;
    }
    cout << "Resulting number is : " << n << endl;
    return 0;
}
