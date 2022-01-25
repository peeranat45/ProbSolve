#include <iostream>
#include <math.h>

using namespace std;

int main(void){
	int n = 0;
	cin>>n;
	int scores = 0;
	for(int i = 0;i<n;++i){
		int x = 0;
		int y = 0;
		cin>>x;
		cin>>y;
		double r = sqrt(x*x + y*y);
		//cout<<"r = "<<r<<endl;
		// if(r > 10){
		// 	;
		// }
		// else if(r >= 8){
		// 	scores += 1;
		// }
		// else if(r >= 6){
		// 	scores += 2;
		// }
		// else if(r >= 4){
		// 	scores += 3;
		// }
		// else if(r >= 2){
		// 	scores += 4;
		// }
		// else{
		// 	scores += 5;
		// }

		if (r <= 2.0){
			scores += 5;
		}else if(r<=4.0){
			scores += 4;
		}else if(r<=6.0){
			scores += 3;
		}else if(r<=8.0){
			scores += 2;
		}else if(r<= 10.0){
			scores += 1;
		}else{
			;
		}
	}
	cout<<scores<<endl;
	return 0;
}
