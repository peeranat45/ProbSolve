#include <iostream>
#include <list>
#include <algorithm>


//Global Variable
std::list<int> lst{};
std::list<int>::iterator pointer{};

//Declare Function
void reset();
void next();
void insertBefore(int num);
void insertAfters(int num);
void printList();

//Code main
int main(void){
    int N{},M{};
    std::cin>>N>>M;
    for(int i = 0;i<N;++i){
        int temp;
        std::cin>>temp;
        lst.push_back(temp);
    }
    pointer = lst.begin();
    
    for(int i = 0;i<M;++i){
        // printList();
        int input{};
        std::cin>>input;
        switch(input){
            case 1 : {
                reset();
                break;
            }
            case 2 : {
                next();
                break;
            }
            case 3: {
                int x{};
                std::cin>>x;
                insertBefore(x);
                break;
            }
            case 4: {
                int x{};
                std::cin>>x;
                insertAfters(x);
                break;
            }
            
        }
    }
    printList();
    // std::cout<<"0";
}

//Function Implementation

void reset(){
    pointer = lst.begin();
}

void next(){
    if(pointer == --lst.end()){
        pointer = lst.begin();
    }else{
        pointer++;
    }
}

void insertBefore(int num){
    lst.insert(pointer,num);
}

void insertAfters(int num){
    pointer++;
    lst.insert(pointer,num);
    pointer--;
}
void printList(){
    for(auto num : lst){
        std::cout<<num<<"\n";
    }
    // std::cout<<std::endl;
}