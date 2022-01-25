i#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long size = 0;
	cin>>size;
	vector<long> v;
	for(long i = 0;i<size;i++){
		long temp = 0;
		cin>>temp;
		v.push_back(temp);
	}
	long max = 1;
	for(long i = 0;i<size;i++){
		long count = 0;
		long index_check = i;
		do{
			++count;
			index_check = v.at(index_check) - 1;
			}while(index_check != i);
		
		max = (count>max)?count : max;
	}			
	cout<<max<<endl;
	return 0;
}
