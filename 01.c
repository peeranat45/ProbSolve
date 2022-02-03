#include <stdio.h>

int main(void){
    for(int i = 0;i<10;++i){
        for(int j = 0;j<20;++j){
            if(j == 10){
                break;
            }
            printf("i = %d,j = %d\n",i,j);
        }
    }
}