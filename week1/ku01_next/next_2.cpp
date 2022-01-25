#include <iostream>
#include <vector>
using namespace std;

int main(void){
	int n;
	cin>>n;
	vector<vector<int>> v;
	for(int i = 0;i<n;++i){
		int temp = 0;
		cin>>temp;
		vector<int> tempv;
		tempv.push_back(temp-1);
		tempv.push_back(i);
		tempv.push_back(0);
		v.push_back(tempv);
	}
	bool check = 0;
	do{
		check = 1;
		for(int i = 0;i<n;++i){
			if(v.at(i).at(2) == 1){
				continue;
			}
			
