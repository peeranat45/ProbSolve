#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 100010

typedef struct node{
    int index;
    struct node* next;
    struct node* previous;
}node_t;

void printLinkList(node_t* node_list);

int main(void){
    int L,N;
    scanf("%d %d",&L,&N);
    node_t* dna_list[MAX_ARR];
    int current_dna = 1;
    for(int i = 0;i<L;++i){
        int M;
        scanf("%d",&M);
        node_t* node_list = (node_t*)malloc(sizeof(node_t));
        node_list->index = current_dna;
        node_list->previous = NULL;
        node_t* temp = node_list;
        for(int j = current_dna + 1;j<current_dna + M;++j){
            node_t* node_temp = (node_t*)malloc(sizeof(node_t));
            node_temp->index = j;
            node_temp->previous = temp;
            temp->next = node_temp;
            temp = node_temp;
        }
        current_dna += M;
        temp->next = NULL;
        dna_list[i] = node_list;
    }

    // printLinkList(dna_list[0]);
    // printLinkList(dna_list[1]);
    // printLinkList(dna_list[2]);
    // printLinkList(dna_list[3]);
    return 0;
}

void printLinkList(node_t* node_list){
    if(node_list == NULL){
        return;
    }

    node_t* temp = node_list;
    while(temp != NULL){
        printf("%d->",temp->index);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void dna_function(node_t *dna_list[],node_t *bot_pos,char command,int func,int L){
    if(command == 'B'){
        if(bot_pos->previous == NULL){
            return;
        }else{
            bot_pos--;
            return;
        }
    }else if(command == 'F'){
        if(bot_pos->next == NULL){
            return;
        }else{
            bot_pos++;
        }
    }else if(command == 'C'){
        node_t* cut = bot_pos->next;
        for(int i = 0;i<L;++i){
            node_t* temp = dna_list[i];
            while(temp != NULL){
                if(temp->index == L){
                    break;
                }
            }
            if(temp->next == NULL){
                
            } //ปลายหัว

        }
    }

}