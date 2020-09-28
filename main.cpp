#include <ncurses.h>
#include <unistd.h>

using namespace std;

int main(){
	initscr();
	printw(">");
	refresh();
	sleep(1);
	endwin();
	return 0;
}
