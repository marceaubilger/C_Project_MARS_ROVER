//
// Created by judeg on 21/11/2024.
//
#include "path.h"

path createPath(int size){
    path p;
    p.stack = createStack(size);
    p.cost = 0;
    return p;
}

path find_shortest_path(p_tree tree){
    path p = createPath(9);
    p_node node = tree->root;
    p= find_shortest_path_rec(node,p);
    return p;
};

path find_shortest_path_rec(p_node node, path p){
    if(node==NULL){
        return p;
    }
    int nb_moves_left = 9 - node->height;
    path *paths = malloc(nb_moves_left*sizeof(path));
    for(int i=0;i<nb_moves_left;i++){
        paths[i] = createPath(nb_moves_left);
        paths[i] = find_shortest_path_rec(node->sons[i],paths[i]);
    }
    p=min_path(paths,nb_moves_left);
    push(&p.stack,node->move_to_get_here);
    p.cost+=node->value;
    free(paths);
    return p;
}

path min_path(path *paths, int size){
    path min = paths[0];
    for(int i=1;i<size;i++){
        if(paths[i].stack.size<min.stack.size && paths[i].cost<=min.cost){
            min = paths[i];
        }
    }
    return min;
}