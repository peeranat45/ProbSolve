// #include<bits/stdc++.h>
#include <iostream>
using namespace std;

const int max_size = 2000002 ;

int a[max_size];

void merge(int l,int m,int h){
    int i=l;
    int j=m+1;
    int k=l;
    int b[h+1];
    while (i<=m && j<=h){
        if (a[i]<a[j]){
            b[k++]=a[i++];
        }else{
            b[k++]=a[j++];
        }
    }
    while (i<=m){
        b[k++]=a[i++];
    }
    while (j<=h){
        b[k++]=a[j++];
    }
    for(int i=l;i<=h;i++){
        a[i]=b[i];
    }

}

void mergesort(int l, int h){
    int m = (l+h)/2; 
    if (l<h){
        mergesort(l,m);
        mergesort(m+1,h);
        merge(l,m,h);
    }
}

int main(){
    bool check = true;
    while (check){
        int n ;cin>>n;
        if (n==0){
            check = false;
            break;
        }
        for(int i=0;i<n;i++){
            int tmp; cin>>tmp;
            a[i]=tmp;
        }
        mergesort(0,n-1);
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    //a[0]=3;
    //a[1]=4;
    //a[2]=2;
    //a[3]=1;
    //a[4]=5;
    //mergesort(0,4);
    //for(int i=0;i<5;i++){
        //cout<<a[i]<<endl;
    //}
    return 0;
}