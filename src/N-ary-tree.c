#include "N-ary-tree.h"
#include "node.h"
#include <stdio.h>
#include <string.h>
#include "queue.h"


p_node createNaryTree(p_node node, int NumOfSons, int *count_node, p_node father_node) {
    if (node == NULL) {
        node = createNode(father_node, 0); // Create the node
        (*count_node)++;

    }

    if (NumOfSons > 4) {
        node->sons = malloc(NumOfSons * sizeof(p_node));

        for (int i = 0; i < NumOfSons; i++) {
            node->sons[i] = createNaryTree(NULL, NumOfSons - 1, count_node, node); // Recursively create children
            node->sons[i]->pos_in_children = i; // Assign position
        }
    } else {
        node->sons = NULL; // No children at this level
    }

    return node;
}


void traversePreOrder(p_node node,int *count_) {
    if (node == NULL) {return;}
    (*count_)++;

    getListOfMovesFromFather(node);

    for (int i = 0; i < 9-(node->height); i++) { 
        if (node->sons != NULL && node->sons[i] != NULL) {
            traversePreOrder(node->sons[i],count_);
        }
    }
}

void getListOfMovesFromFather(p_node node){
    if(node==NULL)return;
    if(node->father !=NULL && node->father->father==NULL){

        int size = 10 - (node->height);

        for(int i=0 ;i<size;i++){
            if(i!=node->pos_in_children){
                node->mouv_for_sons[i]=node->father->mouv_for_sons[i];
            }
            else{
                node->move_to_get_here= node->father->mouv_for_sons[i];
            }
        }
    }
    else{
        getListOfMovesFromFather(node->father);
    }

}

