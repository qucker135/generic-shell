#include <ncurses.h>
#include <unistd.h>
#include <string>
#include <vector>

using namespace std;

int y=0,x=0;
int sign = 0;
string bfr = "";
int bfr_pos=0;
vector<string> hist;
int hist_clear_ptr=0;
bool newline = true;
int cur_line = 0;

int main(){
	initscr();
	keypad(stdscr,TRUE);
	raw();
	do
	{
		bfr = "";
		bfr_pos=0;
		getmaxyx(stdscr,y,x);
		move(cur_line,0);
		printw(">");
		refresh();
		do{
			sign = getch();

			if(sign>=' ' && sign<='~'){
				bfr.insert(bfr_pos,1,sign);
				bfr_pos++;
			}

		}while(sign!=10 && sign!=4);//ENTER and ^D
		if(sign==10){
			hist.push_back(bfr);
			if(cur_line>=y-1) newline = false;
			else newline = true;
			if(newline) cur_line++;
		}

	}while(bfr!="exit" && bfr!="quit" && sign!=4);//exit, quit and ^D
	endwin();
	return 0;
}
