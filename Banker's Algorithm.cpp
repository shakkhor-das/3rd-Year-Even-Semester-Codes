#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double lf;

ll n, r;
ll allocation[100][100];
ll mex[100][100];
ll available[100], work[100], req[100];
ll need[100][100];
bool finish[100];

vector <ll> ans;
vector <ll> st[100];

void make_need(){
    for (ll i=0;i<n;i++){
        for (ll j=0;j<r;j++){
            need[i][j] = mex[i][j]-allocation[i][j];
        }
    }
}

void is_safe(){
    memset(finish,1,sizeof finish);
    bool f=0;
    while(1){
        f=0;
        for (ll i=0;i<n;i++){
            if (finish[i]){
                bool ok=1;
                for (ll j=0;j<r;j++){
                    if (need[i][j]>work[j]){
                        ok=0;
                        break;
                    }
                }
                if (ok){
                    ans.push_back(i);
                    finish[i]=0;
                    for (ll j=0;j<r;j++){
                        work[j] += allocation[i][j];
                        st[i].push_back(work[j]);
                    }
                    f=1;
                }
            }
        }
        if (!f)
            break;
    }
}

int main(){

    printf("Enter the no. of processes: ");
    scanf("%lld",&n);

    printf("\nEnter the no. of resources: ");
    scanf("%lld",&r);

    for (ll i=0;i<n;i++){
        printf("\nEnter details for process P%lld: ",i+1);
        printf("\nEnter allocation: ");
        for (ll j=0;j<r;j++){
            scanf("%lld",&allocation[i][j]);
        }
        printf("\nEnter max: ");
        for (ll j=0;j<r;j++){
            scanf("%lld",&mex[i][j]);
        }
        printf("\n\n");
    }

    printf("Enter available resources: ");
    for (ll i=0;i<n;i++){
        scanf("%lld",&available[i]);
        work[i]=available[i];
    }

    make_need();
    is_safe();

    for (ll i=0;i<ans.size();i++){
        int ind=ans[i];
        printf("P%lld is visited-->",ans[i]-1);
        for (ll j=0;j<st[ind].size();j++){
            cout << st[ind][j] << " ";
        }
        printf("\n\n\n");
    }

    if (ans.size()==n){
        printf("The system is in safe state");
        printf("\nThe safe sequence is: ");
        for (ll i=0;i<ans.size();i++){
            cout << "P" << ans[i]-1 << " ";
        }
    }

    else
        printf("\nThe system is not in safe state!!\n\n");

    ans.clear();

    for (ll i=0;i<100;i++){
        st[i].clear();
    }

    printf("Enter new request details --- ");
    printf("\nEnter pid --- ");

    ll pid;
    scanf("%lld",&pid);

    pid++;
    printf("\nEnter request for resources --- ");
    for (ll i=0;i<r;i++){
        scanf("%lld",&req[i]);
    }

    bool check=true;

    for (ll i=0;i<r;i++){
        if (req[i]>need[pid][i]){
            check=false;
            break;
        }
    }

    if (!check)
        printf("\n\nMAXIMUM!!!\n\n");

    else{
        for (ll i=0;i<r;i++){
            available[i]-=req[i];
            work[i]=available[i];
        }
        for (ll i=0;i<r;i++){
            allocation[pid][i]+=req[i];
        }
        for (ll i=0;i<r;i++){
            need[pid][i]-=req[i];
        }
    }

    make_need();
    is_safe();

    printf("\n\n\n");

    printf("Process\t\tAllocation\tMax\t\tNeed\n");
    for (ll i=0;i<n;i++){
        printf("P%lld\t\t",i+1);
        for (ll j=0;j<r;j++){
            cout << allocation[i][j];
            if (j<r)
                cout << " ";
        }
        printf("\t\t");
        for (ll j=0;j<r;j++){
            cout << mex[i][j];
            if (j<r)
                cout << " ";
        }
        printf("\t\t");
        for (ll j=0;j<r;j++){
            cout << need[i][j];
            if (j<r)
                cout << " ";
        }
        printf("\n");
    }

    printf("\n\n");

    return 0;

}
