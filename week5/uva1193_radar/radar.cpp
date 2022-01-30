#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <math.h>

class Coordinate{
    public:
    int x;
    int y;
};
bool CoordinateCompare(Coordinate c1,Coordinate c2){
    return c1.x < c2.x;
}

void swap(Coordinate *c1,Coordinate *c2);
void sortCoordinate(std::vector<Coordinate> &coor_list);

void printCoordinate(std::vector<Coordinate> coor_list);

int main(void){
    int N{0};
    while(true){
        int d{},n{};
        std::cin>>n>>d;
        if(d == 0 && n == 0)
            break;
        std::vector<Coordinate> coor_vector{};
        for(int i = 0;i<n;++i){
            int x{},y{};
            std::cin>>x>>y;
            coor_vector.push_back({x,y});
        }

        // std::sort(coor_vector.begin(),coor_vector.end(),CoordinateCompare);
        // std::sort(coor_vector.begin(),coor_vector.end(),[](const Coordinate* rhs , const Coordinate* lhs){
        //     if(rhs->x == lhs->x){
        //         return rhs->y < lhs->y;
        //     }
        //     return rhs->x < lhs->x;
        // });
        sortCoordinate(coor_vector);
        //std::reverse(coor_vector.begin(),coor_vector.end());

        std::vector<Coordinate> radar_list{};
        //printCoordinate(coor_vector);
        for(int i = 0;i<coor_vector.size();++i){
            int include = false;
            //printf("Check (%d,%d)\n",coor_vector.at(i).x,coor_vector.at(i).y);
            for(Coordinate radar : radar_list){
                int distance_square = pow(radar.x - coor_vector.at(i).x,2) + pow(radar.y - coor_vector.at(i).y,2);
                //printf("Distance_Square = %d, d*d = %d -> ",distance_square,d*d);
                if(distance_square <= d*d){
                    //printf("True");
                    include = true;
            }
            }
            if(include == true)
                continue;
            for(int x = coor_vector.at(i).x + d;x >= coor_vector.at(i).x - d;--x){
                //printf("(%d,%d) mid_circle = %d \n",coor_vector.at(i).x,coor_vector.at(i).y,x);
                
                int distance_square = pow(x - coor_vector.at(i).x,2) + pow(coor_vector.at(i).y,2);
                //printf("  distance = %d \n",distance_square);
                if(distance_square <= d*d){
                    radar_list.push_back({x,0});
                    x = coor_vector.at(i).x  - d - 1;
                }
            }
           // printf("-------------------------------\n");
            

        }
        //printf("\n");
        //printCoordinate(radar_list);
        N++;
        std::cout<<"Case "<<N<<": "<<radar_list.size()<<std::endl;
        //printf("======================================================\n");
        }
        
    return 0;
}
       


void printCoordinate(std::vector<Coordinate> coor_list){
    for(Coordinate coor : coor_list){
        printf("(%d,%d)  ",coor.x,coor.y);
    }
    printf("\n");
}

// void sortCoordinate(std::vector<Coordinate> &coor_list){
//     //Bubble Sort

//     for(int i = 0;i < coor_list.size() - 1;++i){
//         for(int j = 0;j< coor_list.size()- 1;++j){
//             if(coor_list.at(j).x > coor_list.at(j + 1).x){
//                 swap(&coor_list.at(j),&coor_list.at(j+1));
//             }else if(coor_list.at(j).x == coor_list.at(j + 1).x){
//                 if(coor_list.at(j).y < coor_list.at(j+1).y){
//                     swap(&coor_list.at(j),&coor_list.at(j+1));
//                 }
//             }
//         }
//     } 

// }

void sortCoordinate(std::vector<Coordinate> &coor_list){
    //Bubble Sort

    for(int i = 0;i < coor_list.size() - 1;++i){
        for(int j = 0;j< coor_list.size()- 1;++j){
            if(pow(coor_list.at(j).x,2) + pow(coor_list.at(j).y,2) < pow(coor_list.at(j + 1).x,2) + pow(coor_list.at(j+1).y,2)){
                swap(&coor_list.at(j),&coor_list.at(j+1));
        }
    } 

}
}

void swap(Coordinate *c1,Coordinate *c2){
    Coordinate temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}