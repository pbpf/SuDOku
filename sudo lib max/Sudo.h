#ifndef _Sudo_H
 
 #define _Sudo_H
 
#ifdef BaseLength
 #define Length (BaseLength*BaseLength)
#endif

#ifndef Length
 #ifndef BaseLength
  #define BaseLength 3
 #endif
 #define Length (BaseLength*BaseLength)
#endif 
 
#include "bit_matrix.h"

//inline void get_square(int &p , int &q);
 class Sudo//三重索引，三重标记
{
	const static int Store_size=Length*Length;
	bool determine_Answered;//确定了一个解or证明无解时为true.
	bool answered;//solve求解le;
	bool answere;//determine_if_Answered所指的解
	int value[Length][Length];//值
	int *line[Length][Length];//行索引
	int *row[Length][Length];//列索引
	int *square[Length][Length];//square索引
	int line_set;//标记
	int row_set;//
	int square_set;//
	int Store[Store_size][Length][Length];
	int Store_pos;
	int step;
public:
	Sudo();//初始化
inline void set(int i , int j , int v);
void user_set(int i , int j , int v);
bool solve();
inline  bool solve_loop();	
bool force_solve();//强行求解
inline bool force_solve_loop();
bool force_solve_show();
inline bool force_solve_loop_show();
inline bool try_set(int i,int j,int v);
inline bool try_set_show(int i,int j,int v);
inline bool undo_before_show();//反悔了
inline bool undo_before();//反悔了
inline bool save_value();
inline bool restore_value();
inline int get_an_try(int &p,int &q);
inline bool determine_if_Answere_certain();
bool solve_show();
bool solve_show_loop();
inline	bool solve_line();
inline	bool solve_row();
inline	bool solve_square();
inline	void update_square_line(int i , int r);
inline	void update_square_row(int i , int r);
inline	void update_line_square(int i , int r);
inline	void update_row_square(int i , int r);
void display_all();
void display();
};
 
// extern "C" void * Sudo_interface(void);
#endif