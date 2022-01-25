#include <iostream>

int main(void){
	int x = 0;
	int y = 0;
	int c = 0;
	while((c = getchar()) != EOF){
		switch(c){
			case 'N': y += 1; break;
			case 'S': y -= 1; break;
			case 'W': x -= 1; break;
			case 'E': x += 1; break;
			case 'Z': x = 0; y = 0; break;
		}
		//std::cout<<"x = "<<x<<" y = "<<y<<std::endl;
	}
	std::cout<<x<<" "<<y;
	return 0;
}