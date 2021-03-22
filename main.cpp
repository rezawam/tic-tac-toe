#include <ncurses.h>

int main()
{
	int j;
	int x = 1, y = 0;
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

		move(y, x);
		refresh();

		while ((j = getch()) != 'q')
		{
			switch (j)
			{
				case KEY_LEFT:
					if (x != 1) x-=5;
					break;
				case KEY_RIGHT:
					if (x != 11) x+=5;
					break;
				case KEY_UP:
					if (y != 0) y-=2;
					break;
				case KEY_DOWN:
					if (y != 4) y+=2;
					break;
				case '\n':
					addch('x');
					break;
			}
			move(y, x);
			refresh();
		}
		break;
	}
	endwin();
	return 0;
}

