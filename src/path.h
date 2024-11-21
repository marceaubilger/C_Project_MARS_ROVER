//
// Created by judeg on 21/11/2024.
//
#ifndef C_PROJECT_MARS_ROVER_PATH_H
#define C_PROJECT_MARS_ROVER_PATH_H
#include "N-ary-tree.h"
#include "stack.h"

struct path{
    t_stack stack;
    int cost;
}typedef path, *p_path;


/**
* @brief Function to create a path
* @param size : the size of the path
* @return empty path
*/
path CreatePath(int );

/**
* @brief Function to find the shortest path
* @param tree : the tree
* @return the shortest path
*/
path findShortestPath(p_tree);

/**
 * @brief Function to find the shortest path recursively from a starting node
 * @param node : the starting node
 * @param p : the path for recursion
 * @return
 */
path find_shortest_path_rec(p_node, path);

/**
 * @brief Function to find the best path from a list of paths, either shortest or cheapest
 * @param paths : the list of paths
 * @param size : the size of the list
 * @return the shortest path
 */
path min_path(path *, int);

#endif //C_PROJECT_MARS_ROVER_PATH_H
