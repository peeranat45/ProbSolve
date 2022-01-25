#include <stdio.h>

#define MAXARR 1000010
int search_tree(int node,int num);
int arr[MAXARR];

int main(void){
	
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i = 2;i<=N;++i){
		int input;
		scanf("%d",&input);
		int j = 1000*input;
		while(arr[j] != 0)
			j++;
        //printf("arr[%d] = %d\n",j,i);
		arr[j] = i;
	}

	for(int i = 0;i<M;++i){
		int A,B;
		scanf("%d %d",&A,&B);
		int ans = -1;
		if(ans = search_tree(A,B)){
            ans = A;
            
        }else if(ans = search_tree(B,A)){
           // printf("--------------------\n");
            ans = B;
        }
        if(ans == 0)
            ans = -1;
        printf("%d\n",ans);
	}
	return 0;
}

int search_tree(int node,int num){
    static int k = 0;

   // printf("node = %d, num = %d, k = %d , round 1\n",node,num,k);
    k++;
    if(node == num)
        return 1;
    if(node == 0)
        return 0;
   // printf("arr[%d] = %d\n",node*1000,arr[node*1000]);
    if(arr[node*1000] == 0)
        return 0;
    //printf("node = %d, num = %d, k = %d round 2\n",node,num,k);
    for(int j = node*1000;arr[j] != 0;j++){
      //  printf("arr[%d] = %d\n",j,arr[j]);
        if(search_tree(arr[j],num)){
            return 1;
        }
    }
    return 0;
     
}