#include <iostream>

using namespace std;

const long arr_size = 100001;

int arr[arr_size];

int main(void){
	// ios::sync_with_stdio(false);
	// cin.tie(NULL);
	int size = 0;
	cin>>size;

	for(int i = 0;i<size;i++){
		int temp = 0;
		cin>>temp;
		arr[i] = temp;
	}
	int max = 1;
	for(int i = 0;i<size;i++){
		int count = 0;
		int index_check = i;
		do{
			++count;
			index_check = arr[index_check] - 1;
			}while(index_check != i);
		
		max = (count>max)?count : max;
	}
	cout<<max<<endl;
	return 0;
}