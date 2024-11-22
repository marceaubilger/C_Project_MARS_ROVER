
#ifndef UNTITLED_N_ARY_TREE_H
#define UNTITLED_N_ARY_TREE_H
#include "node.h"
#include "map.h"

typedef struct s_tree
{
    p_node root;
} t_tree, *p_tree;

/**
 * @brief Function to recursivly create the Nary tree and set the variables of the nodes
 * @param node : the root on which the tree will be created
 * @param NumOfSons : the number of sons too add to the root
 * @param count_node : indicates the number of nodes in the tree for debugging should be 18730
 * @param father_node : the address of the father of the sons created
 * @return : the root node
 */
p_node createNaryTree(p_node node,int NumOfSons,int *count_node,p_node father_node,t_map map);


/**
 *@brief : function to recursivly go throught the tree in a prefix way
 *@param node :  the origine node
 *@param count : count to verify that the entire tree is visited, should be 18730
 *@return : void 
*/
void traversePreOrder(p_node node,int *count_,t_map map);


/**
 * @brief: fuunction to get the array of move available and the move used to get to the node
 * @param node: the node on which the move is used
 * @return : void
 */
void getListOfMovesFromFather(p_node node);

p_node gettingSmallestValue(p_node node,p_node min_val);


#endif //UNTITLED_N-ARY-TREE_H