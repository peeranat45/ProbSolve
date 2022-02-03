#include <iostream>
#include <utility>
#include <vector>
#include <list>

using namespace std;

class interval{
    public:
    int l;
    int r;
};

void printPair(vector<interval> coverage){
    for(auto pair : coverage){
        std::cout<<"("<<pair.l<<","<<pair.r<<") ";
    }
    std::cout<<std::endl;
}
void bubblesort(vector<interval> &coverage){
    for (int i = 0;i < coverage.size();++i){
        bool is_sorted = true;
        for (int j = 0;j < coverage.size()-1;++j){
            if (coverage.at(j).r == coverage.at(j+1).r){
                if (coverage.at(j).l > coverage.at(j+1).l){
                    interval tmp = coverage.at(j+1);
                    coverage.at(j+1) = coverage.at(j);
                    coverage.at(j) = tmp;
                }
                is_sorted = false;
                continue;
            }
            else if (coverage.at(j).r < coverage.at(j+1).r){
                interval tmp = coverage.at(j+1);
                coverage.at(j+1) = coverage.at(j);
                coverage.at(j) = tmp;
                is_sorted = false;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    //cout << endl;
    for (int i = 0;i < n;++i){
        vector<interval> coverage;
        int m;
        cin >> m;
        int l, r;
        cin >> l >> r;
        while (l != 0 || r != 0){
            coverage.push_back({l,r});
            cin >> l >> r;
        }
        //cout << endl;
        bubblesort(coverage);
        
        //printPair(coverage);
        // greedy
        int latest = 0, count = 0;
        vector<interval> ans;
        while (latest < m && coverage.size() > 0){
            //printf("latest = %d\n", latest);
            bool check = true;
            for (int i = 0;i < coverage.size();++i){
                if (coverage.at(i).l <= latest){
                    latest = coverage.at(i).r;
                    count += 1;
                    ans.push_back(coverage.at(i));
                    coverage.erase(coverage.begin()+i);
                    check = false;
                    break;
                }
            }
            if (check){
                break;
            }
        }
        if (latest < m){
            cout << 0 << endl;
        }
        else{
            cout << count << endl;
            for (auto pair : ans){
                cout << pair.l << " " << pair.r << endl;
            }
        }
        cout << endl;
    }
}