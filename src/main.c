#include <stdio.h>
#include "map.h"
#include "N-ary-tree.h"
#include "node.h"
#include "time.h"
#include "moves.h"
#include "loc.h"

int main() {
    srand(time(NULL));
    
    t_map map = createMapFromFile("maps/example1.map");
    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.costs[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    /*
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    displayMap(map);
    return 0;
    */
   p_node thenode = createNode(NULL,0);
   int countnode=1;
   int count_=0;
   int random_orientation;
   int base_found=0;
   int sequence_count=1;
   int actual_move=1;
   t_position popo;
   t_localisation loco;
   p_node newtmp;
   p_node storing_min_val=createNode(NULL,0);


    thenode->l=loco;
   popo=getRandomStartingPoint(map.y_max,map.x_max);
   thenode->cost=map.costs[popo.y][popo.x];
   printf("original y: %d   original x:%d   value at coo: %d  ",popo.y, popo.x, thenode->cost);


    random_orientation=rand()%4;
    t_orientation orientation = (t_orientation)random_orientation;
    thenode->l=loc_init(popo.x,popo.y,orientation);
    printf("orientation %d\n",thenode->l.ori);
    printf("\n");

    p_node min_val = createNode(NULL,0);

    if(thenode->cost==0){
        printf("Rover started on base! No need for path calculation\n");
        base_found=1;
    }
    if(thenode->cost>=10000){
        printf("Robot started on crevasse, game over\n");
        base_found=1;
    }


    while(!base_found){

    printf("Calculating sequence %d\n",sequence_count);

    t_move *random_moves=getRandomMoves(9);
    for(int i=0;i<9;i++){
        thenode->mouv_for_sons[i]=random_moves[i];
    }

    thenode=createNaryTree(thenode,9,&countnode,NULL,map);
    traversePreOrder(thenode,&count_,map);

    

    min_val->cost=99999;
    min_val = gettingSmallestValue(thenode,min_val);
    if(min_val->cost==0){
        printf("Base found!\nPrinting move sequence...\n");
        base_found=1;
    }
    if(min_val->cost>=10000){
        printf("No viable way to base, stopping path fiding sequence\n");
        base_found=1;
    }

    newtmp= min_val;
    int nmb_of_moves=newtmp->height;
    actual_move=nmb_of_moves+1;
    for(int i=0;i<nmb_of_moves;i++){
        actual_move--;
        printf("move n°%d of the sequence, move: %s  cost: %d  height: %d  y: %d  x: %d  ori: %d\n",actual_move,_moves[newtmp->move_to_get_here],newtmp->cost,newtmp->height,newtmp->l.pos.y,newtmp->l.pos.x,newtmp->l.ori);
        if(newtmp->father!=NULL){
            newtmp=newtmp->father;
        }else{newtmp=NULL;}
    }
    printf("\n");

    storing_min_val->l=min_val->l;;
    storing_min_val->cost=min_val->cost;
    free_tree(thenode);
    free(random_moves);

    if (!base_found) {
        thenode = createNode(NULL, 0);
        thenode=storing_min_val; 
        sequence_count++;
    }

    }
    return 0;
}
