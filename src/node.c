#include "node.h"

p_node createNode(t_node *father,int pos)
{
    p_node nouv;

    nouv = (p_node)malloc(sizeof(t_node));
    nouv->father=father;
    nouv->pos_in_children=pos;
    return nouv;
}