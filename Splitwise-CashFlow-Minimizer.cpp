#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define n 3
// n represents number of persons.
// MCF represents Minimum Cash Flow

// Input:-
// 0 1000 2000
// 0 0 5000
// 0 0 0

// Output:-
// Person 1 pays 4000 to 2.
// Person 0 pays 3000 to 2.

int get_Maximum(vector<int>& amount)
{
    int max_Index = 0;
    for(int i = 1; i < n; i++)
    {
        if(amount[i] > amount[max_Index])
            max_Index = i;    
    }

    //returns the index of maximum value
    return max_Index;
}
int get_Minimum(vector<int>& amount)
{
    int min_Index = 0;
    for(int i = 1; i < n; i++)
    {
        if(amount[i] < amount[min_Index])
            min_Index = i;
    }

    //returns the index of the minimum value
    return min_Index;
}

void MCF_recursive(vector<int>& amount)
{
    // Getting the maxCredit and maxDebit.
    int maxCredit = get_Maximum(amount);
    int maxDebit = get_Minimum(amount);

    //If both amounts are 0, then all amounts are settled.
    if((amount[maxCredit] == 0) && (amount[maxDebit] == 0))
        return;

    //Finding the minimum of the two amounts
    int minimum = min(-amount[maxDebit], amount[maxCredit]);
    amount[maxCredit] -= minimum;
    amount[maxDebit] += minimum;

    //If minimum is the maximum amount to be, then
    cout<<"Person "<< maxDebit <<" pays "<< minimum <<" to "<< maxCredit <<"."<< endl;

    // It is guaranteed that the recursion would terminate as either amount[maxCredit] or amount[maxDebit] becomes 0.
    MCF_recursive(amount);
}

void MCF(vector<vector<int>>& graph)
{
    //Creating an array amount and initializing all value in it as 0.
    vector<int> amount(n, 0);

    //Now calculating the net amount to be paid to person 'p' and stores it in amount[p],
    //The value of amount[p] can be calculated by subtracting debts of 'p' from credits of 'p'.
    for(int p=0; p<n; p++)
    {
        for(int i=0; i<n; i++)
        {
            amount[p] += (graph[i][p] - graph[p][i]);
        }
    }

    MCF_recursive(amount);
}

void solve()
{
    vector<vector<int>> graph(n, vector<int>(n));

    // Taking the input
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> graph[i][j];
        }
    }

    // Printing the result.
    MCF(graph);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ll TEST_CASES=1;
    ll t = 1;
    // cin>>TEST_CASES; //comment for single test case
    while(TEST_CASES--)
    {
        solve();
    }
    return 0;
}
