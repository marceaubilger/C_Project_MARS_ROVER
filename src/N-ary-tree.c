#include "N-ary-tree.h"
#include "node.h"
#include <stdio.h>


/**
 * @brief Function to recursivly create the Nary tree and set the variables of the nodes
 * @param node : the root on which the tree will be created
 * @param NumOfSons : the number of sons too add to the root
 * @param count_node : pointer that indicates the number of nodes in the tree for debugging should be 18730
 * @param father_node : the address of the father of the sons created
 * @return : the root node
 */
p_node createNaryTree(p_node node,int NumOfSons,int *count_node,p_node father_node){

    int pos=0;
    if (node == NULL) {
        node = createNode(father_node,pos);
    }
    if(NumOfSons==5){
        father_node=node;
        node->sons = malloc(NumOfSons * sizeof(p_node));
        for(int j=0;j<5;j++){
            pos=j;
            node->sons[j]=createNode(node,pos);
            (*count_node)++;
        }
    }
    else{
        father_node=node;
        node->sons = malloc(NumOfSons * sizeof(p_node));
        for(int i=0;i<NumOfSons;i++){
            (*count_node)++;
            node->sons[i]=createNaryTree(NULL,NumOfSons-1,count_node,father_node);
            node->sons[i]->pos_in_children = i;
        }
    }
    return node;
}