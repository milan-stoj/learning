#include <stdio.h>
#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    
    // boolean to store if both pieces are on the board, and not on the same square
    int are_positions_valid = (is_piece_on_board(queen_1) && is_piece_on_board(queen_2))
        && !(are_pieces_on_same_position(queen_1, queen_2));

    if (!are_positions_valid) {
        return INVALID_POSITION;
    } else if (queen_1.column == queen_2.column) {
        return CAN_ATTACK;
    } else if (queen_1.row == queen_2.row) {
        return CAN_ATTACK;
    } else if (are_pieces_on_same_diagonal(queen_1, queen_2)) {
        return CAN_ATTACK;
    } else {
        return CAN_NOT_ATTACK;
    }
}

int is_piece_on_board(position_t piece) {
    return piece.column <= 7 && piece.row <= 7;
}

int are_pieces_on_same_position(position_t piece_1, position_t piece_2) {
    int on_same_column = piece_1.column == piece_2.column;
    int on_same_row = piece_1.row == piece_2.row;
    return on_same_row && on_same_column;
}

// refactor: using slope = 1 to determine same angle
// y2 - y1 / x2 - x1 = slope
int are_pieces_on_same_diagonal(position_t piece_1, position_t piece_2) {
    int slope = (piece_2.column - piece_1.column) / (piece_2.row - piece_1.row);
    return slope == 1 || slope == -1;
}
