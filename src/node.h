
#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H
#include <stdlib.h>
#include "moves.h"

typedef struct s_node
{
    int value;
    struct s_node **sons;
    struct s_node *father;
    int mouv_for_sons[9];
    int pos_in_children;
    int height;
    int move_to_get_here;

}t_node, *p_node;

p_node createNode(t_node *father,int pos);

void free_node(p_node node);

#endif //UNTITLED_NODE_H