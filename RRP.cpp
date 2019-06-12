#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void findWaitingTime(ll n, ll bt[], ll rem_bt[], ll wt[], ll ts){
    ll rem_BT[n];
    for (ll i=0;i<n;i++){
        rem_bt[i] = bt[i];
    }
    ll total=0;
    while (1){
        bool done = true;
        for (ll i=0;i<n;i++){
            if (rem_bt[i]){
                done = false;
                if (rem_bt[i]>ts){
                    rem_bt[i]-=ts;
                    total+=ts;
                }
                else{
                    total+=rem_bt[i];
                    wt[i]=total-bt[i];
                    rem_bt[i]=0;
                }
            }
        }
        if (done)
            break;
    }
}

ll findTurnAroundTime(ll n, ll wt[], ll bt[], ll tat[]){
    for (ll i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
    }
}

void findavgTime(ll n, ll wt[], ll bt[], ll tat[], double avgtat, double avgwt){
    for (ll i=0;i<n;i++){
        avgtat+=tat[i];
        avgwt+=wt[i];
    }
    avgtat/=n;
    avgwt/=n;
    printf("\nAverage Waiting Time: %0.4f\n",avgwt);
    printf("\nAverage TurnAround Time : %0.4f\n",avgtat);
}


int main(){

    ll n;

    printf("Enter the no. of processes: ");
    scanf("%lld",&n);

    string s[n+5];
    ll BT[n+5], rem_BT[n+5], WT[n+5], TAT[n+5];
    double avgWT, avgTAT;

    for (ll i=0;i<n;i++){
        cin >> s[i] >> BT[i];

    }

    ll ts;
    cout<<"Enter Time Slice: ";
    cin>>ts;

    findWaitingTime(n,BT,rem_BT,WT,ts);
    findTurnAroundTime(n,WT,BT,TAT);
    findavgTime(n,WT,BT,TAT,avgTAT,avgWT);

    return 0;

}
