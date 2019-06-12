#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){

    ll n, flag = 0;

    printf("Enter the no. of files: ");
    scanf("%lld",&n);

    string s[n+10];
    ll sb[n+10], nob[n+10];

    for (ll i=0;i<n;i++){
        printf("\nEnter the name of file %lld: ",i+1);
        cin>>s[i];
        printf("\nEnter the starting block of file %lld: ",i+1);
        scanf("%lld",&sb[i]);
        printf("\nEnter the no. of blocks occupied by file %lld: ",i+1);
        scanf("%lld",&nob[i]);
    }

    string ss;

    printf("\nEnter the file name to be searched: ");
    cin>>ss;

    for (ll i=0;i<n;i++){
        if (s[i]==ss){
            printf("\nFILE NAME\tSTARTING BLOCK\tNO. OF BLOCKS\tBLOCKS OCCUPIED\n");
            cout<<s[i];
            printf("\t\t%lld\t\t%lld\t\t",sb[i],nob[i]);
            for (ll j=0;j<nob[i];j++){
                cout<<sb[i]+j<<" ";
            }
            return 0;
        }
    }

    printf("\nFILE NOT FOUND!!!");

    return 0;

}
