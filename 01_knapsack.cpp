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

     int profit[n];
     int weight[n];

    for(int i=0 ;i<n;i++)
    {
        int p , w;
        cout<<"Enter profit of"<<i+1<<":"<<endl;
        cin>>p;
        cout<<"Enter weight of"<<i+1<<":"<<endl;    
        cin>>w;

        profit[i]=p;
        weight[i]=w;

    }

    int dp[n+1][W+1];

    for(int i=0;i< n+1;i++)  // setting 0th column to 0
    {
        dp[i][0] = 0;
    }

    for(int i=0;i< W+1;i++)   //setting 0th row to 0
    {
        dp[0][i] = 0;
    }


    for (int item = 1; item <= n; item++) {

    for (int capacity = 1; capacity <= W; capacity++) {
        int maxValWithoutCurr = dp[item - 1][capacity]; // This is guaranteed to exist
        int maxValWithCurr = 0; // We initialize this value to 0

        int weightOfCurr = weight[item - 1]; // We use item -1 to account for the extra row at the top
        if (capacity >= weightOfCurr) { // We check if the knapsack can fit the current item
            maxValWithCurr = profit[item - 1]; // If so, maxValWithCurr is at least the value of the current item

            int remainingCapacity = capacity - weightOfCurr; // remainingCapacity must be at least 0
            maxValWithCurr += dp[item - 1][remainingCapacity]; // Add the maximum value obtainable with the remaining capacity
        }

        dp[item][capacity] = max(maxValWithoutCurr, maxValWithCurr); // Pick the larger of the two
    }
}
   cout<<"Final answer = "<<dp[n][W];
//  following is the kanpsack function


    

}