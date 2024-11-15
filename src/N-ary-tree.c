#include "N-ary-tree.h"
#include "node.h"
#include <stdio.h>

p_node createNaryTree(p_node node,int NumOfSons,int *count_node,p_node father_node){

    int pos=0;
    if (node == NULL) {
        node = createNode(father_node,pos);
    }
    if(NumOfSons==5){
        father_node=node;
        node->sons = malloc(NumOfSons * sizeof(p_node));
        for(int j=0;j<5;j++){
            pos=j;
            node->sons[j]=createNode(node,pos);
            (*count_node)++;
        }
    }
    else{
        father_node=node;
        node->sons = malloc(NumOfSons * sizeof(p_node));
        for(int i=0;i<NumOfSons;i++){
            (*count_node)++;
            node->sons[i]=createNaryTree(NULL,NumOfSons-1,count_node,father_node);
            node->sons[i]->pos_in_children = i;
        }
    }
    return node;
}