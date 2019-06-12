#include<bits/stdc++.h>

using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[], int ts){
    int rem_bt[n];
    for (int i=0;i<n;i++)
        rem_bt[i]=bt[i];

    int t=0;

    while (1){
        bool done = true;
        for (int i=0;i<n;i++){
            if (rem_bt[i]>0){
                done = false;
                if (rem_bt[i]>ts){
                    t+=ts;
                    rem_bt[i]-=ts;
                }
                else{
                    t+=rem_bt[i];
                    wt[i]=t-bt[i];
                    rem_bt[i]=0;
                }
            }
        }
        if (done==true)
            break;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]){
    for (int i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
    }
}

void findavgTime(int processes[], int n, int bt[], int ts){
    int wt[n], tat[n], total_wt=0, total_tat=0;

    findWaitingTime(processes, n, bt, wt, ts);
    findTurnAroundTime(processes, n, bt, wt, tat);

    cout<<"Processes "<<" Burst time "<<" Waiting time "<<" Turn around time\n";

    for (int i=0;i<n;i++){
        total_wt += wt[i];
        total_tat += tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "<< wt[i] <<"\t\t " << tat[i] <<endl;
    }

    cout << "Average waiting time = "<< (double)total_wt/(double)n;
    cout << "\nAverage turn around time = "<< (double)total_tat/(double)n;
}

int main(){

    int processes[]={1,2,3};

    int n=sizeof(processes)/sizeof(processes[0]);

    int burst_time[]={10,5,8};

    int ts=3;
    findavgTime(processes, n, burst_time, ts);

    return 0;
}
