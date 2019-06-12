#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){

    ll n;

    printf("Enter the no. of files: ");
    scanf("%lld",&n);

    string s[n+10];
    ll nob[n+10], blocks[n+10][n+10];

    for (ll i=0;i<n;i++){
        printf("\nEnter the name for file %lld: ",i+1);
        cin>>s[i];
        printf("\nEnter the no. of blocks occupied by file %lld: ",i+1);
        scanf("%lld",&nob[i]);
        printf("\nEnter the blocks of the current file: ");
        for (ll j=0;j<nob[i];j++){
            scanf("%lld",&blocks[i][j]);
        }
    }

    string ss;

    printf("\nEnter the file name to be searched: ");
    cin>>ss;

    for (ll i=0;i<n;i++){
        if (s[i]==ss){
            printf("\nFILE NAME\tNO. OF BLOCKS\tBLOCKS OCCUPIED\n");
            cout<<s[i];
            printf("\t\t%lld\t\t",nob[i]);
            for (ll j=0;j<nob[i];j++){
                printf("%lld ",blocks[i][j]);
            }
            return 0;
        }
    }

    printf("\nFILE NOT FOUND!!!");

    return 0;

}
