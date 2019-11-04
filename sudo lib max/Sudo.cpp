#ifndef _Sudo
 #define _Sudo

#include <stdio.h>
#include "Sudo.h"
#include "bit_matrix.cpp"

inline void get_square(int &p , int &q)
{
	int a=p/BaseLength,b=q/BaseLength,c=p%BaseLength,d=q%BaseLength;
	p=a*BaseLength+b;
	q=c*BaseLength+d;
}
int get_bit_first_set(int s)
{
	int p=1;
		for(int i=0;i<Length;i++)
		{
			if(p&s)
			{
				return i+1;
			}
			p<<=1;
		}
		return 0;
}
void bit_printf(int s)
{
	bool flag=false;
	int p=1;
		for(int i=0;i<Length;i++)
		{
			if(p&s)
			{
				flag=true;
				printf("%d",i+1);
			}
			p<<=1;
		}
		if(!flag)
		{
			printf("!");
		}
		printf("\t");
}
bool bit_solved(int b,int &last)
{
	int count=0;
	int p=1;
		for(int i=0;i<Length;i++)
		{
			if(p&b)
			{
				count++;
				last=i;
			}
			p<<=1;
		}
		last++;
		return count==1;
}
inline bool certain_bit(const int &b)
{
	int count=0,p=1;
		for(int i=0;i<Length;i++)
		{
			if(p&b)
			{
				count++;
				if(count>=2)
				{
					return false;
				}
			}
			p<<=1;
		}
		return count==1;
}

inline int bit_count(const int &b)
{
	int count=0;
	int p=1;
		for(int i=0;i<Length;i++)
		{
			if(p&b)
			{
				count++;
			}
			p<<=1;
		}
		return count;
}
Sudo:: Sudo()//初始化
	{
		int p , q , *pp;
		for(int i=0;i<Length;i++)
			for(int j=0;j<Length;j++)
		    {
			    value[i][j]=Bitwise_All;
				pp=&value[i][j];//取地址
				p=i,q=j;
				get_square(p,q);
			  line[i][j]=row[j][i]=square[p][q]=pp;
              Store[i][j]=0;		  
		    }
		line_set=row_set=square_set=0;
		answered=determine_Answered=false;
		answere=true;//善意假定
		Store_pos=0;
		step=1;
	}
inline void Sudo:: set(int i , int j , int v)
{
	int r=1<<v,i1=1<<i,j1=1<<j;
	r|=Index_Max;
	value[i][j]=r;
	line_set|=i1;
	row_set|=j1;
	int p=i , q=j;
	get_square(p,q);
	square_set|=1<<p;
	answered=determine_Answered=false;
	clear_bit_matrix_base(line[i],r,j1);
	clear_bit_matrix_base(row[j],r,i1);
	clear_bit_matrix_base(square[p],r,1<<q);
}
void Sudo:: user_set(int i , int j , int v)
{
	set(i-1, j-1 , v-1);
}
bool Sudo:: solve()
{
	if(answered)
		return answere;
	else
	{
		answere=solve_loop();
		if(!answere)
		{
			determine_Answered=true;
		}
		answered=true;
		return answere;
	}
}
inline  bool Sudo:: solve_loop()
	{
		bool flag=false;
		if(line_set!=0)
		 {
			 flag=solve_line();
			 if(!flag)
			 {
				 return false;
			 }
		}
		if(row_set!=0)
		 {
			 flag=solve_row();
			 if(!flag)
			 {
				 return false;
			 }
		 }
		 if(square_set!=0)
		 {
			 flag=solve_square();
			 if(!flag)
			 {
				 return false;
			 }
		 }
		 if(flag)
			 return solve_loop();
		 else
		 {
			 return true;
		 }
    }
	
bool Sudo:: force_solve()//强行求解
	{
	//	bool flag;
		if(!answered)
		{
			solve();
		}
		if(determine_Answered)//如果已经解答就不解了
		{
			return answere;
		}
		else 
		{
			
				bool flag=determine_if_Answere_certain();//检查结果是否唯一
				if(flag)
				{
					answered=determine_Answered=true;
					return true;
				}
				else//需要尝试
				{
					answere=force_solve_loop();//强制求解
					answered=determine_Answered=true;
				}
			
		}
	}
bool Sudo:: force_solve_show()//强行求解
	{
		//bool flag;
		if(!answered)
		{
			solve_show();
		}
		if(determine_Answered)//如果已经解答就不解了
		{
			return answere;
		}
		else 
		{
			
			bool	flag=determine_if_Answere_certain();//检查结果是否唯一
				if(flag)
				{
					answered=determine_Answered=true;
					printf("\nSolver figure out the solution!\n");
					return true;
				}
				else//需要尝试
				{
					answere=force_solve_loop_show();//强制求解
					answered=determine_Answered=true;
					if(answere)
					{
						printf("\nSolver figure out one solution!\n");
					}
					else
					{
						printf("\nThe solver can determine there is no solution.\n");
					}
				}
			
		}
	}
inline bool Sudo:: force_solve_loop()
	{
		bool flag;
		int i , j ,v,p=1;
         v=get_an_try(i,j);//取一个尝试
		for(int t=0;t<Length;t++)
		{
			int r=p&v;
			if(r)
			{
				flag=save_value();//储存
				if(!flag)
				{
					return true;//------------
				}
				set(i,j,t);
				flag=solve_loop();
				if(flag)
				{
					flag=determine_if_Answere_certain();
					if(flag)
					{
						return true;
					}
					else
					{
						flag=force_solve_loop();
						if(flag)
						{
							return true;
						}
						else
						{
							flag=restore_value();//还原
							if(!flag)
								{
									return true;//----------------
								}
						}
					}
				}
				else
				{
					restore_value();//还原
				}
			}
			p<<=1;
		}
		return false;
	}

inline bool Sudo:: force_solve_loop_show()
	{
		bool flag;
		int i , j ,v,p=1;
         v=get_an_try(i,j);//取一个尝试
		for(int t=0;t<Length;t++)
		{
			int r=p&v;
			if(r)
			{
				flag=try_set_show(i,j,t);//储存
				if(!flag)
				{
					return true;//------------
				}
				flag=solve_show_loop();
				if(flag)
				{
					flag=determine_if_Answere_certain();
					if(flag)
					{
						return true;
					}
					else
					{
						flag=force_solve_loop_show();
						if(flag)
						{
							return true;
						}
						else
						{
							flag=undo_before_show();//还原
							if(!flag)
								{
									return true;//----------------
								}
						}
					}
				}
				else
				{
					undo_before_show();//还原
				}
			}
			p<<=1;
		}
		return false;
	}
inline bool Sudo:: try_set(int i,int j,int v)
{
	bool r=save_value();
	set(i,j,v);
	return r;
}

inline bool Sudo:: try_set_show(int i,int j,int v)
{
	printf("\nstep %d : try set ",step++);
	printf("%d ", i+1);
	printf("%d ", j+1);
	printf("%d\n", v+1);
	bool r=try_set(i,j,v);
	display_all();
	return r;
}
inline bool Sudo:: undo_before_show()//反悔了
{
	printf("\nstep %d : get error undo before.\n",step++);
	return restore_value();
}

inline bool Sudo:: undo_before()//反悔了
{
	return restore_value();
}
inline bool Sudo:: save_value()
{
	if(Store_pos>=Store_size)
		return false;
	for(int i=0;i<=Length;i++)
	{
		for(int j=0;j<Length;j++)
		{
			Store[Store_pos][i][j]=value[i][j];
		}
	}
	Store_pos++;
	return true;
}


inline bool Sudo:: restore_value()
{
	if(Store_pos<=0)
		return false;
		Store_pos--;
	for(int i=0;i<Length;i++)
	{
		for(int j=0;j<Length;j++)
		{
			value[i][j]=Store[Store_pos][i][j];
		}
	}
	return true;
}
inline int Sudo:: get_an_try(int &p,int &q)
{
	int min=8,t,count=0,v;
	for(int i=0;i<Length;i++)
	{
		for(int j=0;j<Length;j++)
		{
			v=value[i][j];
			t=bit_count(v);
			if(t>1)
			{
				if(t<min)
				{
					p=i;q=j;
					min=t;
					count++;
					if(count>=((Length/2)+1)||min==2)
					{
					   return v;
				    }
			   }
			}
		}
	}
	return v;
}
inline bool Sudo:: determine_if_Answere_certain()
{
	bool flag;
	for(int i=0;i<Length;i++)
	{
		for(int j=0;j<Length;j++)
		{
			flag=certain_bit(value[i][j]);
			if(!flag)
			{
				return false;
			}
		}
	}
	return true;
}
bool Sudo:: solve_show()
	{
		bool flag;
		printf("before solve:\n");
		display_all();
		flag=solve_show_loop();
		if(!flag)
		{
			printf("\n The solver can determine there is no solution.");
		}
		return flag;
	}
bool Sudo:: solve_show_loop()
	{
		bool flag=false;
		if(line_set!=0)
		 {
			 printf("\nstep %d : solve in line ",step++);
			 bit_printf(line_set);
			 printf("\n");
			 
			 flag=solve_line();
			 display_all();
			  if(!flag)
			 {
				 return false;
			 }
		}
		if(row_set!=0)
		 {
			  printf("\nstep %d : solve in row ",step++);
			 bit_printf(row_set);
			 printf("\n");
			 
			 flag=solve_row();
			 display_all();
			  if(!flag)
			 {
				 return false;
			 }
			  
		 }
		 if(square_set!=0)
		 {
			 printf("\nstep %d : solve in square ",step++);
			 bit_printf(square_set);
			 printf("\n");
			 
			 flag=solve_square();
			 display_all();
			  if(!flag)
			 {
				 return false;
			 }
			 
		 }
		 if(flag)
			 return solve_show_loop();
		else
			 return true;
    }
inline	bool Sudo:: solve_line()
	{
		int p=1,r;
		bool flag;
		for(int i=0;i<Length;i++)
		{
			int t=p&line_set;
			if(t)
				{ 
					flag=clear_bit_matrix(line[i],r);//r表示列标记
					if(flag)
					{
					   row_set|=r;
					   update_square_line(i,r);//更新square
					}
					else 
					{
						return false;
					}
					
					//sync_row_from_line(i,r);//值同步 使用指针避免这个问题
					//sync_square_from_line(i,r);//值同步
				}
			p<<=1;
		}
		line_set=0;
		return true;
	}
inline	bool Sudo:: solve_row()
	{
		int p=1,r;
		bool flag;
		for(int i=0;i<Length;i++)
		{
			int t=p&row_set;
			if(t)
			{
				flag=clear_bit_matrix(row[i],r);
				if(flag)
				{
					line_set|=r;
				update_square_row(i,r);//更新square
				}
				else
				{
					return false;
				}
				
			}
			p<<=1;
		}
		row_set=0;
		return true;
	}
inline	bool Sudo:: solve_square()
	{
		int p=1,r;
		bool flag;
		for(int i=0;i<Length;i++)
		{
			int t=p&square_set;
			if(t)
			{
				flag=clear_bit_matrix(square[i],r);
				if(flag)
				{
					update_line_square(i,r);
					update_row_square(i,r);
					
				}
				else
				{
					return false;
				}
							
		   }
			p<<=1;
		}
		square_set=0;
		return true;
	}
inline	void Sudo:: update_square_line(int i , int r)
   {
	   int a=1,p=i,q;
	   for(int j=0;j<Length;j++)
	   {
		   int t=a&r;
		   if(t)
		   {
			   q=j;
			   get_square(p,q);
			   square_set|=1<<p;
		   }
		   a<<=1;
	   }
   }
   
inline	void Sudo:: update_square_row(int i , int r)
   {
	  int a=1,p,q=i;
	   for(int j=0;j<Length;j++)
	   {
		   int t=a&r;
		   if(t)
		   {
			   p=j;
			   get_square(p,q);
			   square_set|=1<<p;
		   }
		   a<<=1;
	   }
   }
inline	void Sudo:: update_line_square(int i , int r)
   {
	   int a=1,p=i,q;
	   for(int j=0;j<Length;j++)
	   {
		  int t=a&r;
		   if(t)
		   {    q=j;
			   get_square(p,q);
			   line_set|=1<<p;
		   }
		   a<<=1;
	   }
   }

inline	void Sudo:: update_row_square(int i , int r)
   {
	    int a=1,p=i,q;
	   for(int j=0;j<Length;j++)
	   {
		  int t=a&r;
		   if(t)
		   {    q=j;
			   get_square(p,q);
			   row_set|=1<<q;
		   }
		   a<<=1;
	   }
   }

void Sudo:: display_all()
{
	int t;
	for(int i=0;i<Length;i++)
	{
		for(int j=0;j<Length;j++)
		{
			t=value[i][j];
			bit_printf(t);
		}
		printf("\n");
	}
}
void Sudo:: display()
{
	bool flag;
	int t,p;
	for(int i=0;i<Length;i++)
	{
		for(int j=0;j<Length;j++)
		{
			t=value[i][j];
			flag=bit_solved(t,p);
			if(flag)
				printf("%d\t",p);
			else
				printf("?\t");
		}
		printf("\n");
	}
}

#endif