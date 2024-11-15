
#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H
#include <stdlib.h>

typedef struct s_node
{
    int value;
    struct s_node **sons;
    struct s_node *father;
    int last_mouv;
    int pos_in_children;

}t_node, *p_node;

p_node createNode(t_node *father,int pos);
#endif //UNTITLED_NODE_H