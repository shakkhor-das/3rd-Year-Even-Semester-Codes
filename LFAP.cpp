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

    scanf("%lld",&n);

    struct block *temp;

    for (ll i=0;i<n;i++){
        cin>>LFA[i].s>>LFA[i].nob;
        LFA[i].sb=(struct block*)malloc(sizeof(struct block));
        temp=LFA[i].sb;
        cin>>temp->bno;
        temp->nxt=NULL;
        for (ll j=1;j<LFA[i].nob;j++){
            temp->nxt=(struct block*)malloc(sizeof(struct block));
            temp=temp->nxt;
            cin>>temp->bno;
        }
        temp->nxt=NULL;
    }

    string ss;
    cin>>ss;

    for (ll i=0;i<n;i++){
        if (LFA[i].s==ss){
            printf("\nFILE NAME\tNO. OF BLOCKS\t\tBLOCKS OCCUPIED\n");
            cout<<LFA[i].s<<'\t'<<'\t'<<LFA[i].nob<<'\t'<<'\t';
            temp=LFA[i].sb;
            for (ll j=0;j<LFA[i].nob-1;j++){
                cout << temp->bno << " -> ";
                temp=temp->nxt;
            }
            cout << temp->bno;
            return 0;
        }
    }

    cout << endl << endl << "FILE NOT FOUND" << endl;

    return 0;

}
