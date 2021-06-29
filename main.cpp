#include <ncurses.h>
#include "functions.h"

int main()
{
	int j;
	int x = 1, y = 0;
	int z = 0, w = 0;
	int counter = 0; // count of moves
	bool who_moves = 0; // 0 for the x, 1 for the o
	int moves[3][3] = {}; // 1 for x, 2 for o

	initscr();
	keypad(stdscr, TRUE);
	raw();
	cbreak();
	noecho();
	while (1)
	{
		mvprintw(0, 0, "    |    |   \n");
		printw("--------------\n");
		mvprintw(2, 0, "    |    |   \n");
		printw("--------------\n");
		mvprintw(4, 0, "    |    |   \n");
		mvprintw(6, 0, "Press ENTER to choose cell: ");
		mvprintw(7, 0, "Press q to exit: ");
		mvprintw(9, 0, "The first player's move now");

		move(y, x);
		refresh();

		while ((j = getch()) != 'q')
		{
			switch (j)
			{
				case KEY_LEFT:
					if (x != 1)
					{
						x-=5;
						z-=1;
					}
					break;
				case KEY_RIGHT:
					if (x != 11)
					{
						x+=5;
						z+=1;
					}
					break;
				case KEY_UP:
					if (y != 0)
					{
						y-=2;
						w-=1;
					}
					break;
				case KEY_DOWN:
					if (y != 4)
					{
						y+=2;
						w+=1;
					}
					break;
				case '\n':
					if (moves[z][w] == 0)
					{
						if (!who_moves) addch('x');
						else addch('o');
						who_moves = !who_moves;
						++counter;
						moves[z][w] = who_moves ? 1 : 2;
					}
					break;
			}
			if (who_moves) mvprintw(9, 0, "The second player's move now");
			else mvprintw(9, 0, "The first player's move now ");
			is_win(moves);
			move(y, x);
			refresh();
			if (is_win(moves)) break;
		}
		move(6, 0);
		clrtoeol();
		move(y, x);
		refresh();
		while ((j = getch()) != 'q')
		{

		}
		break;
	}
	endwin();
	return 0;
}