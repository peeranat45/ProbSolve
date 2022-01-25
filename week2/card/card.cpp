#include <iostream>
#include <list>
#include <algorithm>

void print_deck(std::list<int>);

int main(void){
	int input{};
	std::list<int> deck{};
	while(true){
		std::cin>>input;
		//printf("input = %d\n",input);
		if(input == 0)
			break;
		deck.resize(input);
		std::list<int>::iterator it = deck.begin();
		for(int i = 1;it != deck.end();++i){
			*it = i;
			it++;
		}
		std::cout<<"Discarded cards:";
		while((int)deck.size() >= 2){
			int temp {};
			temp = deck.front();
			std::cout<<" "<<temp;
			deck.pop_front();
			temp = deck.front();
			deck.push_back(temp);
			deck.pop_front();
			if(deck.size() >= 2)
				std::cout<<",";
		}
		std::cout<<std::endl<<"Remaining card: "<<deck.front()<<std::endl;

	}
}