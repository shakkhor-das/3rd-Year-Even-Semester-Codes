#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct file{
    string s;
    ll nob;
    struct block *sb;
}LFA[50];

struct block{
    ll bno;
    struct block *nxt;
};

int main(){

    ll n;

    printf("Enter the no. of files: ");
    scanf("%lld",&n);

    struct block *temp;

    for (ll i=0;i<n;i++){
        printf("\nEnter the name for file %lld: ",i+1);
        cin>>LFA[i].s;

        printf("\nEnter the no. of blocks in file %lld: ",i+1);
        scanf("%lld",&LFA[i].nob);

        LFA[i].sb=(struct block*)malloc(sizeof(struct block));
        temp=LFA[i].sb;

        printf("\nEnter the blocks of the file: ");
        scanf("%lld",&temp->bno);

        temp->nxt=NULL;

        for (ll j=1;j<LFA[i].nob;j++){
            temp->nxt = (struct block*)malloc(sizeof(struct block));
            temp=temp->nxt;
            scanf("%lld",&temp->bno);
        }

        temp->nxt=NULL;
    }

    string ss;

    printf("\nEnter the file name to be searched for: ");
    cin>>ss;

    for (ll i=0;i<n;i++){
        if (LFA[i].s==ss){
            printf("\nFILE NAME\tNO. OF BLOCKS\tBLOCKS OCCUPIED\n");
            cout<<ss;
            printf("\t\t%lld\t\t",LFA[i].nob);
            temp=LFA[i].sb;
            for (ll j=0;j<LFA[i].nob-1;j++){
                printf("%lld -> ",temp->bno);
                temp=temp->nxt;
            }
            printf("%lld",temp->bno);
            return 0;
        }
    }

    printf("\nFILE NOT FOUND!!!");

    return 0;

}
