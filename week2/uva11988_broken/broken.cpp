#include <iostream>
#include <stdio.h>
#include <list>
#include <fstream>
#include <cctype>
void print_list(std::list<char> lst);

int main(void){
	char chr {};
	std::list<char> lst{};
	std::list<char>::iterator it = lst.begin();
	while((chr = getchar()) != EOF){
		//std::cout<<"chr = "<<chr<<"-"<<std::endl;
		if(chr == ' ' || chr == '\n'){
			print_list(lst);
			lst.clear();
			//lst.resize(0);
			it = lst.begin();
			continue;
		}
		if(chr == '['){
			it = lst.begin();
			continue;
		}else if(chr == ']'){
			it = lst.end();
			continue;
		}else{
			lst.insert(it,chr);
			
		}
	}
	for(auto chr : lst){
		putchar(chr);
	}
	
}

void print_list(std::list<char> lst){
	for(auto chr : lst){
		putchar(chr);
		
	}
	std::puts("");
}