#include "node.h"
#include "moves.h"
#include <string.h>

p_node createNode(t_node *father,int pos)
{
    p_node nouv;

    nouv = (p_node)malloc(sizeof(t_node));
    nouv->father=father;
    nouv->pos_in_children=pos;

    if(nouv->father==NULL)nouv->height=0;
    else nouv->height = nouv->father->height+1;
    nouv->mouv_for_sons=(int*)malloc((9-(nouv->height))*sizeof(int));
    
    return nouv;
}


void free_node(p_node node) {
    if (node == NULL) {
        return; // Base case: nothing to free
    }

    // Recursively free all the children
    if (node->sons != NULL) {
        for (int i = 0; i < 9 - (node->height); i++) {
            if (node->sons[i] != NULL) {
                free_node(node->sons[i]);
            }
        }
        free(node->sons); // Free the array of child pointers
    }

    // Free the array for moves
    if (node->mouv_for_sons != NULL) {
        free(node->mouv_for_sons);
    }

    // Free the node itself
    free(node);
    
}