#include <bits/stdc++.h>
using namespace std;


#define el "\n"


//Check if number is a cool number
bool isCool(int n) {
    int original = n;
    int reversed = 0;

    set<int> UniqueDigits;
    //2.Unique digits
    int count = 0;
    while (n != 0) {
        count++;
        int digit = n % 10;//get last digit
        n = n / 10;//Remove this digit :)
        UniqueDigits.insert(digit);

        reversed = reversed * 10 + digit;
    }
    if (UniqueDigits.size() != count && reversed != original) {
        //Note here the corner case of last digit is 0 ==> any number with last digit=0 isn't pandelinme
        return false;
    }

    return true;
}

void Recursive(const vector<int>&arr,int index,vector<bool>isTaken,vector<int>combination,int x,vector<int>sch,vector<int>&max_sch,vector<int>&max_comb){
    if(index==arr.size())
    {
        //One combination is Ready
        //Count no of Cool Numbers
        int count=0;
        for(int j=0;j<sch.size();j++)
        {
            if(isCool(sch[j])) {
                count++;
                if (count > max_sch.size())
                    break;
            }
        }
        if(count>max_sch.size()) {
            max_sch = sch;
            max_comb=combination;
        }

//        for(int j=0;j<combination.size();j++)
//        {
//            cout<<combination[j]<<" ";
//        }
//        cout<<endl;
        return;
    }

    for(int i=0;i<arr.size();i++){
        //Check if not taken
        if(isTaken[i]==true)
            continue;

//        Add to x
        int newx=x+arr[i];
            //is this number cool
            //Take arr[index]
            isTaken[i] = true;
            combination.push_back(arr[i]);
            sch.push_back(newx);
            Recursive(arr, index + 1, isTaken, combination, newx, sch, max_sch,max_comb);
            //Undo
            isTaken[i] = false;
            combination.pop_back();
            sch.pop_back();
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout<<"Hello World :D" el;


    vector<int>arr;
    vector<bool>isTaken(4,false);

    vector<int>combination;
    vector<int>sch;
    vector<int>max_sch;
    vector<int>max_comb;

    arr.push_back(193);
    arr.push_back(270);
    arr.push_back(2011);
    arr.push_back(2424);

    Recursive(arr, 0, isTaken, combination, 767, sch, max_sch,max_comb);

    for(int j=0;j<max_comb.size();j++)
    {
        cout<<max_comb[j]<<" ";
    }

    cout<<endl;

    for(int j=0;j<max_sch.size();j++)
    {
            cout<<max_sch[j]<<" ";
    }

    return 0;
}

