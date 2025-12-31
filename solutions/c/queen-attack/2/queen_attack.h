#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H

#include <stdint.h>

typedef enum { CAN_NOT_ATTACK, CAN_ATTACK, INVALID_POSITION } attack_status_t;

typedef struct {
   uint8_t row;
   uint8_t column;
} position_t;

attack_status_t can_attack(position_t queen_1, position_t queen_2);

int is_piece_on_board(position_t piece);

int are_pieces_on_same_position(position_t piece_1, position_t piece_2);

int are_pieces_on_same_diagonal(position_t piece_1, position_t piece_2);

#endif
