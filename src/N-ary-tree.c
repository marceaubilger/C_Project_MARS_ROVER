#include "N-ary-tree.h"
#include "node.h"
#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "map.h"


p_node createNaryTree(p_node node, int NumOfSons, int *count_node, p_node father_node,t_map map) {
    if (node == NULL) {
        node = createNode(father_node, 0); // Create the node
        (*count_node)++;

    }

    if (NumOfSons > 4) {
        node->sons = malloc(NumOfSons * sizeof(p_node));

        for (int i = 0; i < NumOfSons; i++) {
            node->sons[i] = createNaryTree(NULL, NumOfSons - 1, count_node, node,map); // Recursively create children
            node->sons[i]->pos_in_children = i; // Assign position
        }
    } else {
        node->sons = NULL; // No children at this level
    }

    return node;
}


void traversePreOrder(p_node node,int *count_,t_map map) {
    if (node == NULL) {return;}
    (*count_)++;
    getListOfMovesFromFather(node);

    if(node->father!=NULL){
        t_move moveee = (t_move)(node->move_to_get_here);
        node->l=move(node->father->l,moveee);
    }
    valueOnMapAtCoo(map,node);
    for (int i = 0; i < 9-(node->height); i++) { 
        if (node->sons != NULL && node->sons[i] != NULL) {
            traversePreOrder(node->sons[i],count_,map);
        }
    }
}

void getListOfMovesFromFather(p_node node){
    if(node==NULL)return;
    if(node->father !=NULL){//} && node->father->father==NULL){

        int size = 10 - (node->height);
        int j=0;
        for(int i=0 ;i<size;i++){
            if(i!=node->pos_in_children){
                node->mouv_for_sons[j]=node->father->mouv_for_sons[i];
                j++;
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


p_node gettingSmallestValue(p_node node, p_node min_val) {
    if (min_val == NULL ||node->cost < min_val->cost) {
        min_val = node;
    }
    for (int i = 0; i < 9-(node->height); i++) { 
        if (node->sons != NULL && node->sons[i] != NULL) {
            min_val=gettingSmallestValue(node->sons[i],min_val);
        }
    }
    return min_val;
}