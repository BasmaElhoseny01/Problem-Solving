// https://codeforces.com/contest/365/problem/A
// Easier when using string find :D

// #include <bits/stdc++.h>
#include <set>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

#define el "\n"

string digits = "0123456789";
bool isGood(string n, int k)
{

    for (int i = 0; i <= k; i++)
    {
        size_t found = n.find(digits[i]);
        if (found == string::npos)
            return false;
    }
    return true;
}

// Another idea but the above is more simple :D
//  bool isGood(int n,int k){
//      set<int> UniqueDigits;
//      //2.Unique digits
//      while (n != 0) {
//          int digit = n % 10;//get last digit
//          n = n / 10;//Remove this digit :)
//          if(digit<=k)
//              UniqueDigits.insert(digit);

//         if(UniqueDigits.size()==k+1)
//             return true;
//     }
//     return false;
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //    cout<<"Hello World :D" el;

    unsigned __int16 n, k;
    cin >> n >> k;
    string x;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        count += isGood(x, k);
    }
    cout << count << endl;

    return 0;
}