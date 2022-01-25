#include <iostream>
#include <vector>
#include <limits.h>

#define MAX_ARR 100001

using namespace std;

long check_status[MAX_ARR];

int main(void){
	int n = 0;
	cin>>n;
	vector<long> v;
	int max = INT_MIN;
	for(int i = 0;i<n;++i){
		int temp = 0;
		cin>>temp;
		v.push_back(temp);
	}
	for(int i  = 0 ;i<n;++i){
		if(check_status[v.at(i)] == -1){
			continue;
		}
		int count = 0;
		long index_check = i;
		do{
			count++;
			check_status[i] = -1;
			index_check = v.at(index_check) - 1;
			}while(index_check != i);
		max = (count > max)?count : max;
	}
	cout<<max<<endl;
	return 0;

}