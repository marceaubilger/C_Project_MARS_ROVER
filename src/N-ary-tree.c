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
        performeMove(node,map);
    }

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


void performeMove(p_node node,t_map map){
    t_move moveee;
    if(node->move_to_get_here==1){
        moveee=(t_move)(0);
        node->l=move(node->father->l,moveee);
        if(node->cost>=10000){return;}
        node->l=move(node->l,moveee);
    }

    if(node->move_to_get_here==2){
        moveee=(t_move)(0);
        node->l=move(node->father->l,moveee);
        if(node->cost>=10000){return;}
        node->l=move(node->l,moveee);
        if(node->cost>=10000){return;}
        node->l=move(node->father->l,moveee);
        if(node->cost>=10000){return;}
        node->l=move(node->l,moveee);
    }

    moveee = (t_move)(node->move_to_get_here);
    node->l=move(node->father->l,moveee);
    valueOnMapAtCoo(map,node);

}

void free_tree(p_node root) {
    if (root != NULL) {
        free_node(root); 
    }
}
