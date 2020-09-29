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
//bool newline = true;
int cur_line = 0;

void show_hist(){
	getmaxyx(stdscr,y,x);
	clear();
	move(0,0);
	cur_line = 0;
	if(hist.size()-hist_clear_ptr<y){
		for(int i=hist_clear_ptr;i<hist.size();i++){
			printw(">");
			for(int j=0;j<hist.at(i).length();j++){
				printw("%c",hist.at(i)[j]);
			}
			cur_line++;
			move(cur_line,0);
			//printw("\n");
		}
	}
	else{
		for(int i=hist.size()-y+1;i<hist.size();i++){
			printw(">");
			for(int j=0;j<hist.at(i).length();j++){
				printw("%c",hist.at(i)[j]);
			}
			cur_line++;
			move(cur_line,0);
			//printw("\n");
		}
	}

	//move(cur_line,0);
	printw(">");
	/*for(int i=1;i<x;i++){
		printw(" ");
	}
	move(cur_line,1);*/
	for(int i=0;i<bfr.length();i++){
		printw("%c",bfr[i]);
	}
	refresh();
}

int main(){
	initscr();
	keypad(stdscr,TRUE);
	raw();
	do
	{
		bfr = "";
		bfr_pos=0;
		show_hist();	
		do{
			sign = getch();

			if(sign>=' ' && sign<='~'){
				bfr.insert(bfr_pos,1,sign);
				bfr_pos++;
			}

			else if(sign==410){//resize window
				cur_line = (hist.size()-hist_clear_ptr) * (hist.size()-hist_clear_ptr<y) + (y-1) * (hist.size()-hist_clear_ptr>=y);
				show_hist();
			}
			else if(sign==12){
				cur_line = 0;
				hist_clear_ptr = hist.size();
				show_hist();
			}

		}while(sign!=10 && sign!=4);//ENTER and ^D
		if(sign==10){
			hist.push_back(bfr);
			/*if(cur_line>=y-1) newline = false;
			else newline = true;
			if(newline) cur_line++;*/
		}

	}while(bfr!="exit" && bfr!="quit" && sign!=4);//exit, quit and ^D
	endwin();
	return 0;
}
