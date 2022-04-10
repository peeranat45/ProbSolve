#include <iostream>
#include <vector>


//Class Implement


//Global Variable
std::vector<int> robots{};

//Function Declare
std::vector<int> binarySearch(int start,int end,int value);

//Main Code
int main(void){
    int N{},M{};
    std::cin>>N>>M;
    for(int i = 0;i<N;++i){
        int input{};
        std::cin>>input;
        robots.push_back(input);
    }
    std::sort(robots.begin(),robots.end());
    std::vector<int> status{}; //เช็ตว่าหุ่นไหนเพึ่งถูกเรียนใช้ไป
    for(int i = 0;i<M;++i){
        int input{};
        std::cin>>input;
        
    }
    
}

//Function Implement

//binarysearch
//คืนช่วงที่ value อยู่ระหว่าง index สองตัวอยู่ติดกัน
std::vector<int> binarySearch(int start,int end,int value){ 
    if(end - start == 1){
        std::vector<int> ans{};
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }

    int mid = (start + end)/2;
    if(value <= robots.at(mid)){
        return binarySearch(start,mid,value);
    }else{
        return binarySearch(mid + 1,end,value);
    }
}