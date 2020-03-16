#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node *next;
    long value;
    int size;
}node_t;

int isPrime(long num){
    for (long i=2;i<num;i++){
        if (num%i==0) return 0;
    }
    return 1;
}

node_t* add_node(long value, node_t *nd){
    node_t *new=(node_t*)malloc(sizeof(node_t));
    if(new==NULL) return NULL;
    new->value=value;
    if (nd->size==0){
        new->next=NULL;
        new->size=1;
        return new;
    }
    new->size=nd->size+1;
    new->next=nd;
    return new;
}

node_t* primedivs(long num){
    node_t *nd=(node_t*)malloc(sizeof(node_t));
    nd->size=0;
    nd=add_node(num,nd);
    if(nd==NULL){
        printf("Erreur add_node");
        return NULL;
    }
    for(int i=2;i<num;i++){
        if (num%i==0&&isPrime(i)){
            nd=add_node(i,nd);
            if(nd==NULL){
                printf("Erreur add_node");
                return NULL;
            }
        }
    }
    return nd;
}
void check(long num){
    printf("Diviseurs premiers de :%ld\n",num);
    node_t *list=primedivs(num);
    while(list->next!=NULL){
        printf("%ld\n",list->value);
        list=list->next;
    }
    printf("%ld\n",list->value);
}

int main() {
    check(1021406);
    return 0;
}
