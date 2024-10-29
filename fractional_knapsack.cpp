#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of items"<<endl;
    cin>>n;
    int W;
    cout<<"Enter the weight of knapsack"<<endl;
    cin>>W;

     vector<vector<int>> items(n, vector<int>(2)); //profit,weight,p/w

    for(int i=0 ;i<n;i++)
    {
        int profit , weight;
        cout<<"Enter profit of"<<i+1<<":"<<endl;
        cin>>profit;
        cout<<"Enter weight of"<<i+1<<":"<<endl;    
        cin>>weight;

        items[i][0]=profit;
        items[i][1]=weight;

     }

     //sorting on p/w


     for(int i=0;i<n;i++)
     {
        for(int j=0;j<n-i-1;j++)
        {
            double itemprev= (double)items[j][0] / (double)items[j][1];
            double itemnext = (double)items[j+1][0] / (double)items[j+1][1];
            if( itemprev < itemnext)
            {
                swap(items[j], items[j + 1]);    // swap weight
            }
        }
     }

         int max_profit=0;
        cout<<"Weights used :"<<endl;
       
     for(int i=0;i<n;i++)
     {
        if(items[i][1]<=W)
        {
            W-=items[i][1];
            max_profit+=items[i][0];

            cout<<items[i][1]<<" ";
        }

        else
        { max_profit += items[i][0] * ((double)W / items[i][1]);
            cout << W << " (partial) ";
            W = 0;  // Knapsack is full
            break;
        }

        
     }

     cout<<"Total profit:"<<endl;
     cout<<max_profit<<endl;

}