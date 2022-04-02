#include <iostream>
using namespace std;
long long counts = 0;
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(long long array[], long long const left, long long const mid, long long const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    int multiples = 0;
    // Create temp arrays
    auto *leftArray = new long long[subArrayOne],
         *rightArray = new long long[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    long long indexOfMergedArray = left; // Initial index of merged array
  
    // Merge the temp arrays back long longo array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            multiples++;

        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            counts += multiples;
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
  
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(long long array[], long long const begin, long long const end)
{
    if (begin >= end)
        return; // Returns recursively
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
  
// UTILITY FUNCTIONS
// Function to prlong long an array
void longArray(long long A[], long long size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}
  
// Driver code
int main()
{
    long long arr[1000000];
    long long N{};
    std::cin>>N;

    for(int i = 0;i<N;++i){
        int temp{};
        std::cin>>temp;
        arr[i] = temp;
    }
    auto arr_size = sizeof(arr) / sizeof(arr[0]);
  
    // cout << "Given array is \n";
    //  longArray(arr, arr_size);
  
    mergeSort(arr, 0, arr_size - 1);
  
    std::cout <<counts<<std::endl;
    // longArray(arr, arr_size);
    
    return 0;
}