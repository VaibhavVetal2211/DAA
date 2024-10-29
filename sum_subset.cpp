#include<bits/stdc++.h>
using namespace std;

int flag = 0 ;
void solve(int i ,int n,int target , vector<int>&subset , int set[])
{
    if(target==0)
    {
        flag = 1;   //atleast one subset found
        cout<<" [";
        for(int i=0;i<subset.size();i++)
        {
            cout<<subset[i]<<" ";
        }
        cout<<"]";

        return;
        
    }
    if(i==n)
     {
         return;
     }

        solve(i+1,n,target,subset,set);   //not included current element

     if(set[i]<= target)
     {
            subset.push_back(set[i]);
 
        solve(i+1 , n , target-set[i] , subset , set);   // included current element

        subset.pop_back();
     }
}


int main()
{

    int n;
    int target_sum;
    vector<int>subset;

    cout<<"Enter the size of set"<<endl;
    cin>>n;

    int set[n];
    cout<<"Enter elements of the set"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>set[i];
    }


    cout<<"Enter the Target sum of subset"<<endl;
    cin>>target_sum;

    solve(0,n,target_sum,subset,set);


    if(flag == 0)
    {
        cout << "There is no such subset";
    }

}