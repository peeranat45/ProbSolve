#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX_ARR 100010

int parent[MAX_ARR];
int rank[MAX_ARR];

int find(int u);
void unions(int u, int v);

class Distance{
    public:
    int index_A;
    int index_B;
    double Dis;
};

bool myFunction(Distance A,Distance B){
    return A.Dis < B.Dis;
}

class Pair{
    public:
    int X;
    int Y;
    int index;
    int parent_index;
};

int main(void){
    int input_size {};
    std::cin>>input_size;
    std::vector<Pair> pairs{};
    // pairs.resize(input_size);
    for(int i = 0;i<input_size;++i){
        int x,y;
        std::cin>>x>>y;
        pairs.push_back({x,y,i});
    }

    
    // printf("pair.at(2).X = %d, pairs.at(2).Y = %d",pairs.at(2),pairs.at(2).Y);
    std::vector<Distance> vector_of_distance{};
    // vector_of_distance.resize()
    for(int i = 0;i<input_size;++i){
        for(int j = i + 1;j<input_size;++j){
                // printf("pair.at(i).x = %d,pair.at(j).x = %d,pair.at(i).y = %d,pair.at(j).y = %d\n",pairs.at(i).X,pairs.at(j).X,pairs.at(i).Y,pairs.at(j).Y);
                double temp_dis = sqrt(pow((pairs.at(i).X - pairs.at(j).X),2) + pow((pairs.at(i).Y - pairs.at(j).Y),2));
                // printf("temp_dis = %lf ",temp_dis);
                vector_of_distance.push_back({i,j,temp_dis});
        }
    }
    std::sort(vector_of_distance.begin(),vector_of_distance.end(),myFunction);
    std::vector<int> visited{};
    double count = 0;
    visited.resize(input_size);
    int visited_count = 0;
    double max_distance = 0;
    
    //set_parent_index
    for(int i = 0;i<input_size;++i){
        parent[i] = i;
    }


    // for(int i = 0; visited_count < input_size;++i){
    //     // printf("visited_count = %d, i = %d count = %lf  ",visited_count,i,count);
    //     // printf("vecotr_of_distance.at(i) = %lf\n",vector_of_distance.at(i).Dis);
    //     if(visited.at(vector_of_distance.at(i).index_A) == 0 && visited.at(vector_of_distance.at(i).index_B) == 0){
    //         visited.at(vector_of_distance.at(i).index_A) = 1;
    //         visited.at(vector_of_distance.at(i).index_B) = 1;
    //         printf("A = %d, B = %d, distance_add = %lf\n",vector_of_distance.at(i).index_A,vector_of_distance.at(i).index_B,vector_of_distance.at(i).Dis);
    //         visited_count += 2;
    //         if(max_distance < vector_of_distance.at(i).Dis){
    //             max_distance = max_distance < vector_of_distance.at(i).Dis;
    //         }
    //         count += vector_of_distance.at(i).Dis;
    //     }else if(visited.at(vector_of_distance.at(i).index_A) == 0 && visited.at(vector_of_distance.at(i).index_B) == 1){
    //         visited.at(vector_of_distance.at(i).index_A) = 1;
    //         visited_count += 1;
    //          printf("A = %d, B = %d, distance_add = %lf\n",vector_of_distance.at(i).index_A,vector_of_distance.at(i).index_B,vector_of_distance.at(i).Dis);
    //         if(max_distance < vector_of_distance.at(i).Dis){
    //             max_distance = max_distance < vector_of_distance.at(i).Dis;
    //         }
    //         count += vector_of_distance.at(i).Dis;
    //     }else if(visited.at(vector_of_distance.at(i).index_A) == 1 && visited.at(vector_of_distance.at(i).index_B) == 0){
    //         visited.at(vector_of_distance.at(i).index_B) = 1;
    //         visited_count += 1;
    //          printf("A = %d, B = %d, distance_add = %lf\n",vector_of_distance.at(i).index_A,vector_of_distance.at(i).index_B,vector_of_distance.at(i).Dis);
    //         if(max_distance < vector_of_distance.at(i).Dis){
    //             max_distance = max_distance < vector_of_distance.at(i).Dis;
    //         }
    //         count += vector_of_distance.at(i).Dis;
    //     }
    // }

    
    // printf("%.4f\n",ans);
    for(int i = 0;i<vector_of_distance.size();++i){
        if(find(vector_of_distance.at(i).index_A) != find(vector_of_distance.at(i).index_B)){
            unions(vector_of_distance.at(i).index_A,vector_of_distance.at(i).index_B);
            count += vector_of_distance.at(i).Dis;
            if(max_distance < vector_of_distance.at(i).Dis){
                max_distance = vector_of_distance.at(i).Dis;
            }
        }

    }
    // printf("max_distance = %lf\n",max_distance);
    double ans = count - max_distance;
    printf("%.4f\n",ans);

}

int find(int u){
    while(parent[u] != u){
        //printf("u = %d\n",u);
        u = parent[u];
    }
    return u;
}

void unions(int u, int v){
    int pu = find(u);
    int pv = find(v);

    if(rank[pu] < rank[pv]){
        parent[pu] = pv;
    }else if(rank[pv] < rank[pu]){
        parent[pv] = pu;
    }else{
        parent[pu] = pv;
        rank[pv]++;
    }
}