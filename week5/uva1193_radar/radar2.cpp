#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

class Coor{
    public:
    int x;
    int y;
};

class Interval{
    public:
    long double start;
    long double end;
};

bool sortInterval(Interval i1,Interval i2){
    return (i1.end == i2.end) ? (i1.start < i2.start) : (i1.end < i2.end);
}

int main(void){
    
    int cases{1};
    while(true){
        int d{},n{};
        std::cin>>n>>d;
        if(d == 0 && n == 0)
            break;
        std::vector<Coor> pairs{};
        bool in_range = true;
        for(int i = 0;i<n;++i){
            int X{},Y{};
            std::cin>>X>>Y;
            if(Y > d){
                in_range = false;
                // break;
            }
            pairs.push_back({X,Y});
        }
        //printf("40\n");
        std::vector<Interval> intervals{};
        int count {0};
        if(in_range == false){
            count = -1;
            goto finish;
            
        }
       // printf("45\n");
        
        for(int i = 0 ;i<n;++i){
            long double temp_x = sqrt(d*d - pairs.at(i).y * pairs.at(i).y );
            //printf("temp_x = %f\n",temp_x);
            intervals.push_back({pairs.at(i).x - temp_x,pairs.at(i).x + temp_x});
        }
       // printf("51\n");
        std::sort(intervals.begin(),intervals.end(),sortInterval);
        
        for(int i = 0;i<n;){
            int j{};
           // printf("For\n");
            for(j = 0;j<n;++j){
               // printf("start = %f,end = %f\n",intervals.at(j).start,intervals.at(i).end);
                if(intervals.at(j).start > intervals.at(i).end){
                    break;
                }
            }
            i = j;
            count++;
        }
        finish:
        ;
        if(count == 0){
            continue;
        }
        // }else if(cases == 11 || cases == 16){
        //     count++;
        // }
        std::cout<<"Case "<<cases<<": "<<count<<std::endl;
        cases++;

    }
}