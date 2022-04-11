#include <iostream>

#define MAX_ARR 100010

long long arr[MAX_ARR];
long long count = 0;

void merge(long long start,long long mid,long long end);
void mergeSort(long long start,long long end);

int main(void){
    long long size{};
    std::cin>>size;
    for(long long i = 0;i<size;++i){
        std::cin>>arr[i];
    }
    // prlong longf("17\n");
    mergeSort(0,size-1);
    // std::cout<<"Count = "<<count<<std::endl;
    // for(long long i = 0;i<size;++i){
    //     std::cout<<arr[i]<<" ";
    // }
    
    std::cout<<count<<std::endl;

    return 0;

}

void mergeSort(long long start, long long end){
    if(start == end){
        return;
    }
    // prlong longf("Plese\n");
    long long mid = (start + end)/2;
    // prlong longf("Start = %d, end = %d\n",start,end);
    mergeSort(start,mid);
    mergeSort(mid+1,end);
    merge(start,mid,end);
}

void merge(long long start,long long mid,long long end){
    // prlong longf("Start Merge : start = %d, mid = %d, end = %d\n",start,mid,end);
    long long temp_array[MAX_ARR];
    long long left_index = start;
    long long right_index = mid+1;
    long long multiplier = 0;
    long long index_temp = 0;
    // prlong longf("Left : ");
    // for(long long i = 0;i<=mid;++i){
    //     std::cout<<arr[i]<<" ";
    // }
    // std::cout<<std::endl;
    // // prlong longf("Right : ");
    // for(long long i = mid + 1;i<=end;++i){
    //     std::cout<<arr[i]<<" ";
    // }
    // std::cout<<std::endl;
    while(left_index <= mid && right_index <= end){
        // prlong longf("left_index = %d,right_index = %d\n",left_index,right_index);
        if(arr[left_index] > arr[right_index]){
            multiplier++;
            // prlong longf("Before Temp arr\n");
            temp_array[index_temp] = arr[right_index];
            // prlong longf("After temp arr\n");
            right_index++;
            index_temp++;
        }else if(arr[left_index] <= arr[right_index]){
            count += multiplier;
            // prlong longf("Before Temp arr\n");
            temp_array[index_temp] = arr[left_index];
            // prlong longf("After temp arr\n");
            left_index++;
            index_temp++;
        }

       
    }
    // prlong longf("index_temp = %d\n",index_temp);
    // prlong longf("after loop\n");
    while(left_index <= mid){
            temp_array[index_temp] = arr[left_index];
            count += multiplier;
            left_index++;
            index_temp++;
    }
    while(right_index <= end){
            temp_array[index_temp] = arr[right_index];
            right_index++;
            index_temp++;
    }
    
    long long temp_index = 0;
    // for(long long i = start;i<index_temp;++i){
    //     arr[i] = temp_array[temp_index];
    //     std::cout<<temp_array[temp_index]<<" ";
    //     temp_index++;        
    // }
    // std::cout<<std::endl;

}

