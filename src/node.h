
#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H
#include <stdlib.h>
#include "moves.h"

typedef struct s_node
{
    t_localisation l;
    int isOutisde; //=0 is a valid position, =1 is on a crevass, =2 is outside of the map
    struct s_node **sons;
    struct s_node *father;
    int *mouv_for_sons;
    int pos_in_children;
    int height;
    int move_to_get_here;
    int cost;

}t_node, *p_node;

/**
 * @brief function to create the nodes
 * @param father the addresse of the father of the node that will be created
 * @param pos the position of the node in the array of children of its father
 * @return node the created node
 */
p_node createNode(t_node *father,int pos);


/**
 * @brief free the memory allocated to a node
 * @param node the node to free
 * @return void
 */
void free_node(p_node node);
#endif //UNTITLED_NODE_H