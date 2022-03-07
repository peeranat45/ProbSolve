// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>

using namespace std;

const int max_size = 1002; 

int opt[max_size];

int n;
vector<pair<pair<int,int>,int>> job; 
int p[max_size];
int b[max_size];
int count_case=0;
set<int> ans;

void init(){
    p[0]=0;
    for(int i=1;i<n+1;i++){
        int count=0;
        for(int j=1;j<n+1;j++){
            if (job[i].first.first >= job[j].first.second){
                count++;
            }
        }
        //cout<<i<<" "<<count<<endl;
        p[i]=count;
    }
}

bool sort_pair(pair<pair<int,int>,int> a , pair<pair<int,int>,int> b){
    return (a.first.second<b.first.second);
}

void solve(){
    opt[0]=0;
    int count_1 = 0;
    int count_2 = 0;
    for (int i=1;i<n+1;i++){

        if (( job[i].second + opt[p[i]] > opt[i-1] )){
            b[i]=1;
            opt[i]=job[i].second + opt[p[i]];
            count_1++;
        }else {
            b[i]=2;
            opt[i]=opt[i-1];
            count_2++;
        }

    
        // debug opt
        cout<<endl;
        cout<<"b[i] "<<b[i]<<endl;
        cout<<"opt[i] "<<opt[i]<<endl;
        cout<<"job[i].second "<<job[i].second<<endl;
        cout<<"opt[p[i]] "<<opt[p[i]]<<endl;
        cout<<"opt[i-1] "<<opt[i-1]<<endl;
        cout<<"p(i) "<<p[i]<<endl;
        cout<<endl;

        if (count_1>count_2){
            count_case = count_1;
        }else{
            count_case = count_2;
        }
    }
}

int main(){
    cin>>n;
    job.resize(max_size);
    for(int i=1;i<n+1;i++){
        int tmp1,tmp2,tmp3;
        cin>>tmp1>>tmp2>>tmp3;
        job[i].first.first = tmp1;
        job[i].first.second = tmp2;
        job[i].second = tmp3;
    }
    sort(job.begin(),job.begin()+n,sort_pair);
    init();
    solve();

    for(int i=1;i<n+1;i++){
        if(b[i]==1){
            ans.insert(i);
        }
    }
    
    // debug p[i]
    //for (int i=0;i<n;i++){
        //cout<<p[i]<<" "<<endl;
    //} 
    
    
    // debug opt[i]
    //for(int i=1;i<n+1;i++){
        //cout<<opt[i]<<" "<<endl;
    //}

    // debug job
    //for(int i=0;i<n;i++){
        //cout<<job[i].first.first<<" "<<job[i].first.second<<" "<<job[i].second<<endl;
    //}

    // debug b[i]
    //for(int i=1;i<n+1;i++){
        //cout<<b[i]<<endl;
    //}


    // ans is here 
    //count_case--;
    //cout<<opt[n]<<"\n";
    //cout<<count_case<<"\n";
    //int tmp=1;
    //for(auto it = ans.begin();tmp<n+1;it++){
        //cout<<*it<<" ";
        //tmp++;
    //}
    return 0;
}