#include <iostream>
#include <vector>

class pair{
    public:
    int s;
    int t;
    int w;
    int pi;
    int opti;
    int index;
};

int main(void){
    int N{};
    std::cin>>N;
    std::vector<pair> pairs{};
    pairs.push_back({-1,-1,-1,-1,0,0});
    for(int i = 0;i<N;++i){
        int s{},t{},w{};
        std::cin>>s>>t>>w;
        pairs.push_back({s,t,w,-1,0,i+1});
    }
    for(int i = 1;i<=N;++i){
        int maxJ = 0;
        for(int j = 1;i<=N;++j){
            if(pairs.at(j).t <= pairs.at(i).s){
                maxJ = j;
            }else{
                break;
            }
        }
        pairs.at(i).pi = maxJ;
    }
    std::vector<int> ans{};
    // std::vector
    for(int i = 1;i<=N;++i){
        int choose_i = pairs.at(i).w + pairs.at(pairs.at(i).pi).opti;
        int not_choose_i = pairs.at(i-1).opti;
        // pairs.at(i).opti = (choose_i > not_choose_i) ? choose_i : not_choose_i;
        
        if(choose_i > not_choose_i){
            ans.push_back(i);
            pairs.at(i).opti = choose_i;
        }else{
            pairs.at(i).opti = not_choose_i;
        }
    }
    for(auto one_pair : pairs){
        // printf("si = %d, ti = %d, wi = %d, pi = %d opti = %d\n",one_pair.s,one_pair.t,one_pair.w,one_pair.pi,one_pair.opti);
    }
    // for(auto one_pair : ans){
       
      std::cout<<pairs.at(N).opti<<std::endl;
    int pi = ans.at(ans.size()-1);
    int count = 0;
    while(pi != 0){
        count++;
        //  printf("pi = %d\n",pi);
        //  printf("si = %d, ti = %d,i = %d\n",pairs.at(pi).s,pairs.at(pi).t,pairs.at(pi).index);
        //  std::cout<<pairs.at(pi).index<<std::endl;
         pi = pairs.at(pi).pi;
    }
    pi = ans.at(ans.size()-1);

    std::cout<<count<<std::endl;
    while(pi != 0){
        // count++;
        //  printf("pi = %d\n",pi);
        //  printf("si = %d, ti = %d,i = %d\n",pairs.at(pi).s,pairs.at(pi).t,pairs.at(pi).index);
        std::cout<<pairs.at(pi).index<<" ";
        pi = pairs.at(pi).pi;
    }
    std::cout<<std::endl;
    // for(int i = 0;i<ans.size();++i){
    //     if(i + 1 < ans.size() && pairs.at(ans.at(i)).pi == pairs.at(ans.at(i+1)).pi){
    //         ans.erase(ans.begin() + i);
    //         i--;
    //     }
    // }
   
    //  for(int i = 0;i<ans.size();++i){
    //      std::cout<<ans.at(i)<<std::endl;
    //  }


}