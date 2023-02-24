#include <bits/stdc++.h>
#include <iostream>

using namespace  std;

/* Add the required Helper Function */

int maximumProfit(vector<int> const &price, int k)
{
    int i,j,l;
    int n = price.size();
    int profit[k+1][n];
    int Pmax, Pcurr;
    if (n <= 1) {
        return 0;
    }


    for (i = 0; i <= k; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == 0 || j == 0) 
	    {
                profit[i][j] = 0;
            }
            else {
                Pmax = 0;
                for (l = 0; l < j; l++)
                {
                    Pcurr = price[j] - price[l] + profit[i-1][l];
                    if (Pmax < Pcurr) {
                        Pmax = Pcurr;
                    }
                }
                profit[i][j] = max(profit[i][j-1], Pmax);
            }
        }
    }
    return profit[k][n-1];
}


int main(){
    vector<int> prices_month1 = {3,3,5,0,0,3,1,4};
    /* Answer : 6 */

    vector<int> prices_month2 = {1,2,3,4,5};
    /* Answer : 4 */

    vector<int> prices_month3 = {7,6,4,3,1};
    /* Answer : 0 */


    int k = 2;

    cout << "Maximum Profit for prices_month1 : " << maximumProfit(prices_month1, k) << endl;
    cout << "Maximum Profit for prices_month2 : " << maximumProfit(prices_month2, k) << endl;
    cout << "Maximum Profit for prices_month3 : " << maximumProfit(prices_month3, k) << endl;

 
    return 0;
}

