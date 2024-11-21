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