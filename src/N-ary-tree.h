
#ifndef UNTITLED_N_ARY_TREE_H
#define UNTITLED_N_ARY_TREE_H
#include "node.h"

typedef struct s_tree
{
    p_node root;
} t_tree, *p_tree;

p_node createNaryTree(p_node node,int NumOfSons,int *count_node,p_node father_node);

#endif //UNTITLED_N-ARY-TREE_H