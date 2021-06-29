#include <ncurses.h>

int is_win(int moves[3][3])
{
	if (   (moves[0][0] * moves[0][1] * moves[0][2] == 1)
		|| (moves[1][0] * moves[1][1] * moves[1][2] == 1)
		|| (moves[2][0] * moves[2][1] * moves[2][2] == 1)
		|| (moves[0][0] * moves[1][0] * moves[2][0] == 1)
		|| (moves[0][1] * moves[1][1] * moves[2][1] == 1)
		|| (moves[0][2] * moves[1][2] * moves[2][2] == 1)
		|| (moves[0][0] * moves[1][1] * moves[2][2] == 1)
		|| (moves[0][2] * moves[1][1] * moves[2][0] == 1))
	{
		move(9,0);
		clrtoeol();
		mvprintw(9, 0, "The first player won!");
		return 1;
	}
	else if ((moves[0][0] * moves[0][1] * moves[0][2] == 8)
		||   (moves[1][0] * moves[1][1] * moves[1][2] == 8)
		||   (moves[2][0] * moves[2][1] * moves[2][2] == 8)
		||   (moves[0][0] * moves[1][0] * moves[2][0] == 8)
		||   (moves[0][1] * moves[1][1] * moves[2][1] == 8)
		||   (moves[0][2] * moves[1][2] * moves[2][2] == 8)
		||   (moves[0][0] * moves[1][1] * moves[2][2] == 8)
		||   (moves[0][2] * moves[1][1] * moves[2][0] == 8))
	{
		move(9,0);
		clrtoeol();
		mvprintw(9, 0, "The second player won!");
		return 1;
	}
	return 0;
}