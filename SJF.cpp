#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){

    ll n;

    printf("Enter the no. of processes: ");
    scanf("%lld",&n);

    ll WT[n+5], TAT[n+5];
    pair <ll,ll> BTI[n+5];
    double avgWT, avgTAT;

    for (ll i=0;i<n;i++){
        printf("\nEnter the burst time for process %lld: ",i+1);
        scanf("%lld",&BTI[i].first);
        BTI[i].second=i+1;
    }

    WT[0]=0;
    TAT[0]=BTI[0].first;
    avgWT=0, avgTAT=BTI[0].first;

    sort(BTI,BTI+n);

    for (ll i=1;i<n;i++){
        WT[i]=WT[i-1]+BTI[i-1].first;
        TAT[i]=TAT[i-1]+BTI[i].first;
        avgWT += WT[i];
        avgTAT += TAT[i];
    }

    printf("\nPROCESS\t\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (ll i=0;i<n;i++){
        printf("P%lld\t\t%lld\t\t%lld\t\t%lld\n",BTI[i].second,BTI[i].first,WT[i],TAT[i]);
    }

    avgWT/=n;
    avgTAT/=n;

    printf("\nAverage Waiting Time: %0.4f\n",avgWT);
    printf("\nAverage TurnAround Time: %0.4f\n",avgTAT);

    return 0;

}
