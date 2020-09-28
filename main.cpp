#include <ncurses.h>
#include <unistd.h>
#include <string>
#include <vector>

using namespace std;

int y=0,x=0;
int sign = 0;
string bfr = "";
vector<string> hist;
int hist_ptr=0;
bool newline = true;
int cur_line = 0;

int main(){
	initscr();
	do
	{
		getmaxyx(stdscr,y,x);
		move(cur_line,0);
		printw(">");
		refresh();
		sign = getch();
		


		if(cur_line>=y-1) newline = false;
		if(newline) cur_line++;
	}while(sign!='q');
	endwin();
	return 0;
}
