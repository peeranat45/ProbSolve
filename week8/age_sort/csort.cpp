#include <iostream>

#define MAX_ARR 100010

long long arr[MAX_ARR];


void merge(long long start,long long mid,long long end);
void mergeSort(long long start,long long end);

int main(void){
    long long size{};
    std::cin>>size;
    for(long long i = 0;i<size;++i){
        std::cin>>arr[i];
    }
    mergeSort(0,size-1);
    
    std::cout<<count<<std::endl;

    return 0;

}

void mergeSort(long long start, long long end){
    if(start == end){
        return;
    }
    long long mid = (start + end)/2;
    mergeSort(start,mid);
    mergeSort(mid+1,end);
    merge(start,mid,end);
}

void merge(long long start,long long mid,long long end){
    long long temp_array[MAX_ARR];
    long long left_index = start;
    long long right_index = mid+1;
    long long index_temp = 0;
    while(left_index <= mid && right_index <= end){
        if(arr[left_index] > arr[right_index]){
            temp_array[index_temp] = arr[right_index];
            right_index++;
            index_temp++;
        }else if(arr[left_index] <= arr[right_index]){
            temp_array[index_temp] = arr[left_index];
            left_index++;
            index_temp++;
        }

       
    }
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
    
}

