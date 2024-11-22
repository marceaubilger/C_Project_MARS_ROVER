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
   t_position popo;
   t_localisation loco;

    thenode->l=loco;
   popo=getRandomStartingPoint(map.y_max,map.x_max);
   thenode->cost=map.costs[popo.y][popo.x];
   printf("original y: %d   original x:%d   value at coo: %d  ",popo.y, popo.x, thenode->cost);

    random_orientation=rand()%4;
    t_orientation orientation = (t_orientation)random_orientation;
    thenode->l=loc_init(popo.x,popo.y,orientation);
    printf("orientation %d\n",thenode->l.ori);
    printf("\n");

   
   t_move *random_moves=getRandomMoves(9);
    for(int i=0;i<9;i++){
        thenode->mouv_for_sons[i]=random_moves[i];
    }

    thenode=createNaryTree(thenode,9,&countnode,NULL,map);
    traversePreOrder(thenode,&count_,map);

    

    p_node min_val = createNode(NULL,0);
    min_val->cost=99999;
    min_val = gettingSmallestValue(thenode,min_val);
    printf("cost: %d  height: %d\n",min_val->cost,min_val->height);

    p_node newtmp= min_val;
    int nmb_of_moves=newtmp->height;
    for(int i=0;i<nmb_of_moves;i++){
        printf("move: %s  cost: %d  height: %d  y: %d  x: %d  ori: %d\n",_moves[newtmp->move_to_get_here],newtmp->cost,newtmp->height,newtmp->l.pos.y,newtmp->l.pos.x,newtmp->l.ori);
        if(newtmp->father!=NULL){
            newtmp=newtmp->father;
        }else{newtmp=NULL;}
    }

    return 0;
}
