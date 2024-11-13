//
// Created by flasque on 19/10/2024.
//

#ifndef UNTITLED1_MOVES_H
#define UNTITLED1_MOVES_H

#include "loc.h"

/**
 * @brief Array of strings for the possible moves of the robot
 */
static char _moves[8][8] = {"F 10m", "F 20m", "F 30m", "B 10m", "T left", "T right", "U-turn"};
/**
 * @brief Array of integers associated to the available moves of the robot (with the same indices as _moves)
 */
static int nb_moves[8] = {22,15,7,7,21,21, 7};

/**
 * @brief Enum for the possible moves of the robot
 */

typedef enum e_move
{
    F_10, // Forward 10 m
    F_20, // Forward 20 m
    F_30, // Forward 30 m
    B_10, // Backward 10 m
    T_LEFT, // Turn left (+90°)
    T_RIGHT, // Turn right (-90°)
    U_TURN
} t_move;

/**
 * @brief function to get a t_move as a string
 * @param move : the move to convert
 * @return the string corresponding to the move
 */
char *getMoveAsString(t_move move);

/**
 * @brief function to update the localisation of the robot according to a move
 * @param loc : the localisation of the robot
 * @param move : the move to do
 * @return the new localisation of the robot
 */
t_localisation move(t_localisation, t_move);

/**
 * @brief wrapper function to update a single location
 * @param p_loc : the pointer to the localisation of the robot
 * @param move : the move to do
 * @return none
 */
void updateLocalisation(t_localisation *, t_move);

/**
 * @brief function to a random move and decrement it's availability
 * @return a random move
 */
char* draw_move(char *_moves);

/**
 * @brief function to set the moves of the robot
 * @return the set of moves
 */
char* move_set(char *_moves);

#endif //UNTITLED1_MOVES_H
