/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** define
*/

#ifndef DEFINE_H_
#define DEFINE_H_

#define CASSE(x) ((x >= 65 && x <= 90) ? x + 32 : x)
#define ERR_MSG "Invalid argument\n"
#define NB_KEYS 6
#define FLAGS 19
#define FAILURE 84
#define SUCCESS 0
#define U1 "[options]\nOptions:\n\t--help\t\t\tDisplay this "
#define U2 "help\n\t-L --level={num}\tStart Tetris at level num (def: 1)\n"
#define U3 "\t-l --key-left={K}\tMove the tetrimino LEFT using the K key (def:"
#define U4 " left arrow)\n\t-r --key-right={K}\tMove the tetrimino RIGHT using"
#define U5 " the K key (def: right arrow)\n\t-t --key-turn={K}\t TURN the"
#define U6 "tetrimino clockwise 90d using the K key (def: top arrow)\n\t-d "
#define U7 " --key-drop={K}\tDROP the tetrmino using the K key (def: down "
#define U8 "arrow)\n\t-q --key-quit={K}\tQUIT the game using the K key (def: "
#define U9 "'q' key)\n\t-p --key-pause={K}\tPAUSE/RESTART the game using "
#define U10 "the K key (def: space bar)\n\t--map-size={row,col}\tSet the "
#define U11 "numbers of rows and columns of the map (def: 20,10)\n\t-w "
#define U12 "--without-next\tHide next tetrimino (def: false)\n\t-D --debug\t"
#define U13 "\tDebug mode (def: false)\n"

#endif /* !DEFINE_H_ */