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
    
    return nouv;
}

void free_node(p_node node){
    if(node==NULL){
        return;
    }
    if (node->sons==NULL){
        free(node);
        return;
    }
    for (int i=0; i<node->height;i++){
        if(node->sons[i]!=NULL){
            free_node(node->sons[i]);
        }
    }
    free(node->sons);
    free(node);
}