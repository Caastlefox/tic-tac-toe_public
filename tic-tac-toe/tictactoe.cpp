#include "tictactoe.h"

void Board::cross(int pos) {
	switch (pos) {
	case 1: {
		pos1 = 1;
		break;
	}
	case 2: {
		pos2 = 1;
		break;
	}
	case 3: {
		pos3 = 1;
		break;
	}
	case 4: {
		pos4 = 1;
		break;
	}
	case 5: {
		pos5 = 1;
		break;
	}
	case 6: {
		pos6 = 1;
		break;
	}
	case 7: {
		pos7 = 1;
		break;
	}
	case 8: {
		pos8 = 1;
		break;
	}
	case 9: {
		pos9 = 1;
		break;
	}
	}
}

void Board::circle(int pos) 
	{
		switch (pos) {
		case 1: {
			pos1 = 2;
			break;
		}
		case 2: {
			pos2 = 2;
			break;
		}
		case 3: {
			pos3 = 2;
			break;
		}
		case 4: {
			pos4 = 2;
			break;
		}
		case 5: {
			pos5 = 2;
			break;
		}
		case 6: {
			pos6 = 2;
			break;
		}
		case 7: {
			pos7 = 2;
			break;
		}
		case 8: {
			pos8 = 2;
			break;
		}
		case 9: {
			pos9 = 2;
			break;
		}
		}
	}

	void Board::clear() {
		pos1 = 0;
		pos2 = 0;
		pos3 = 0;
		pos4 = 0;
		pos5 = 0;
		pos6 = 0;
		pos7 = 0;
		pos8 = 0;
		pos9 = 0;

	}