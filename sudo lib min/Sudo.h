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

#include <string>

int bit_count(const int &b);
bool certain_bit(const int &b);
std::string bit2str(const int &b);
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
	//-------------------------
inline void set(int i , int j , int v);
inline  bool solve_loop();	
inline bool force_solve_loop();
inline bool try_set(int i,int j,int v);
inline bool undo_before();//反悔了
inline bool save_value();
inline bool restore_value();
inline int get_an_try(int &p,int &q);
inline bool determine_if_Answere_certain();
inline	bool solve_line();
inline	bool solve_row();
inline	bool solve_square();
inline	void update_square_line(int i , int r);
inline	void update_square_row(int i , int r);
inline	void update_line_square(int i , int r);
inline	void update_row_square(int i , int r);
//--------------------
public:
	Sudo();//初始化
void user_set(int i , int j , int v);
bool solve();
bool force_solve();//强行求解
int ref(int a,int b);
};
 
// extern "C" void * Sudo_interface(void);
#endif