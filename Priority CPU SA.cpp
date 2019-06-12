#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){

    ll n;

    printf("Enter the no. of processes: ");
    scanf("%lld",&n);

    pair <ll,pair<ll,ll> > BPI[n+5];
    ll WT[n+5], TAT[n+5];
    double avgWT, avgTAT;

    for (ll i=0;i<n;i++){
        printf("\nEnter the burst time and priority of process %lld: ",i+1);
        scanf("%lld%lld",&BPI[i].second.first,&BPI[i].first);
        BPI[i].second.second=i+1;
    }

    sort(BPI,BPI+n);

    avgWT=0, avgTAT=BPI[0].second.first;
    WT[0]=0, TAT[0]=BPI[0].second.first;

    for (ll i=1;i<n;i++){
        WT[i]=WT[i-1]+BPI[i-1].second.first;
        TAT[i]=TAT[i-1]+BPI[i].second.first;
        avgTAT+=TAT[i];
        avgWT+=WT[i];
    }

    printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (ll i=0;i<n;i++){
        printf("%lld\t\t%lld\t\t%lld\t\t%lld\t\t%lld\n",BPI[i].second.second,BPI[i].first,BPI[i].second.first,WT[i],TAT[i]);
    }

    avgWT/=n;
    avgTAT/=n;

    printf("\nAverage Waiting Time is: %0.4f\n",avgWT);
    printf("\nAverage TurnAround Time is: %0.4f\n",avgTAT);

    return 0;

}
