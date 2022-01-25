#include <iostream>
#include <list>
#include <vector>
#include <queue>
#define MAX_SIZE 1000010

int visited_node[MAX_SIZE];

int main(void){
	int n{},m{};
	std::cin>>n>>m;
	std::vector<std::list<int>> v{};
	v.resize(n+1);
	for(int i = 0;i<m;++i){
		int A{},B{};
		std::cin>>A>>B;
		v.at(A).push_back(B);
		v.at(B).push_back(A);
	}
	//std::cout<<"Step 1\n";
	int visited{0};
	int count{0};
	while(visited<=n){
		int s{};
		std::queue<int> q{};
		for(int i = 0;i<MAX_SIZE;++i){
			if(visited_node[i] == 0){
				s = i;
				goto finish;
			}
		}
		finish:
		q.push(s);
		while(!q.empty()){
			int top = q.front();
			if(visited_node[top] == 0){
				visited_node[top] = 1;
				q.pop();
				visited++;
				for(int node : v.at(top)){
					if(visited_node[node] == 0)
						q.push(node);
				}
				continue;
			}
			q.pop();
		}
		++count;
	}
	std::cout<<count-1;
	
	return 0;
}