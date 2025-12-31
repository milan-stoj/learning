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

int are_pieces_on_same_diagonal(position_t piece_1, position_t piece_2) {
    position_t traversing_ne = {piece_1.row, piece_1.column};
    position_t traversing_se = {piece_1.row, piece_1.column};
    position_t traversing_sw = {piece_1.row, piece_1.column};
    position_t traversing_nw = {piece_1.row, piece_1.column};

    // traverse piece_1 accross all 4 diagonals until they match piece_2
    // otherwise return false
    for (int i = 0; i < 8; i++) {
        if (are_pieces_on_same_position(traversing_ne, piece_2)
                || are_pieces_on_same_position(traversing_se, piece_2)
                || are_pieces_on_same_position(traversing_sw, piece_2)
                || are_pieces_on_same_position(traversing_nw, piece_2)
                ) {
            return 1;
        } 
        traversing_ne.column++;
        traversing_ne.row++;
        traversing_se.column++;
        traversing_se.row--;
        traversing_sw.column--;
        traversing_sw.row--;
        traversing_nw.column--;
        traversing_nw.row++;
    }
    return 0;
}
