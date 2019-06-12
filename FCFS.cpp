#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){

    ll n;

    printf("Enter the no. of processes: ");
    scanf("%lld",&n);

    ll BT[n+5], WT[n+5], TAT[n+5];

    for (ll i=0;i<n;i++){
        printf("\nEnter burst time for process %lld: ",i+1);
    	scanf("%lld",&BT[i]);
    }

    double avgWT=0, avgTAT=BT[0];
    WT[0]=0;
    TAT[0]=BT[0];

    for (ll i=1;i<n;i++){
    	WT[i] = WT[i-1]+BT[i-1];
    	TAT[i] = TAT[i-1]+BT[i];
    	avgTAT += TAT[i];
    	avgWT += WT[i];
    }

    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\t\tTurnaround Time\n");
    for (ll i=0;i<n;i++){
    	printf("%lld\t\t%lld\t\t\t%lld\t\t\t\t%lld\n",i+1,BT[i],WT[i],TAT[i]);
    }

    avgWT/=n;
    avgTAT/=n;

    printf("\nAverage Waiting Time is: %0.4f\n",avgWT);
    printf("\nAverage TurnAround Time is: %0.4f\n",avgTAT);

	return 0;

}
