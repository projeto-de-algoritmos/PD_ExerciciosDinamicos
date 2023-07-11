#include <bits/stdc++.h>
#include <iostream> 
#include <stdlib.h> 
using namespace std;
#define MAXSIZE 2500

int dp[MAXSIZE][MAXSIZE];


int knapSack(int W, int wt[], int val[], int n)
{
    memset(dp, 0, sizeof(dp));

    int menor = wt[0];
    int pos = 0;
 
    for (int i = 1; i <= n; i++) {
        for(int w = 1; w <= W; w++)
        {
            if (wt[i-1] > w){
                dp[i][w] = dp[i-1][w];
            }
            else{
                dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w-wt[i-1]]);
            }
        }
    }

    return dp[n][W];
    
}
 
int main()
{
    int n, t;
    while(1){

        cin >> n;

        if(n==0){
            break;
        }

        int *peso = (int*)malloc(n*sizeof(int));
        int *preco = (int*)malloc(n*sizeof(int));

        int c, v;

        for(int i = 0; i<n; i++){
            cin >> c >> v;
            peso[i] = v;
            preco[i] = c;
        }

        cin >> t;

        cout << knapSack(t, peso, preco, n) << "\n";
    }

    return 0;
}