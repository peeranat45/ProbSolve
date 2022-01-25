#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main(void){
	long n,k;
	cin>>n>>k;
	vector<long> v;
	long min = LONG_MAX;
	for(long i = 0;i<n;++i){
		long temp = 0;
		cin>>temp;
		if(temp < min)
			min = temp;
		v.push_back(temp);
	}
	long ans = n;
	for(long i = 0;i<n;i++){
		if(v.at(i) * (k-1) >= min * k)
			ans--;
	}
	cout<<ans<<endl;
}
