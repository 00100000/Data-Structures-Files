enum Piece { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, EMPTY };

int main() {
	Piece board[8][8] = {
		{ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
		{PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
		{PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
		{ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK}
	};
	return 0;
}