#ifndef _Bit_Matrix

#define _Bit_Matrix

#include "bit_matrix.h"
//使用指针数组
//i指出要证明的元素所在的行
//j指出当前使用的全局掩码 也指出当前试选的元素说在的列
//index指出试选的元素 
//m指出还需要证明的
inline bool Backtracking_select_matrix(int *a[] , int *index, int *q , int *m,const int &i , int j,const int &beg , const int &end)
{
   static int  p;
   if(i==j)//正向运行时作用
   {
	   q[j+1]=q[j];
	   return Backtracking_select_matrix(a,index,q, m,i,j+1,beg,end);
   }
   else
   {
	   p=q[j]&*a[j];//p指出可选的元素 t起始位置
	  for(int t=index[j];t<Index_Max;t<<=1)
	  {
		if(t&p)
		{
			 if(j==end)//已经是结尾
			 {//运行更改 已证明的
			    index[j]=t;
				for(int k=0;k<Length;k++)
				 {
					 m[k]&=~index[k];//记录这次证明
				}
	           return true;//返回:证明的
			  }
			  else
			  {
				index[j]=t;
				q[j+1]=q[j]&(~t);//更新掩码避免重复
				return Backtracking_select_matrix(a,index,q,m,i,j+1,beg,end);//前进
			  }
		}
	  }
	if(j==beg)//已证否
	{//运行更改 已证否的 将此位置为0
	   *a[i]&=~index[i];
		 m[i]&=~index[i];//记录这次证明
		 return false;//返回:证否的
	}
	else 
	{//回溯 表明index[j1]失败
		index[j]=1;//重置自己的位置
	    j--;//要回溯到的位置
		if(j==i)//要回溯到的就是要证明的位置 就再往前跳
			  j--;
		index[j]<<=1;//要回溯到的位置的下一个位置
	return Backtracking_select_matrix(a,index,q,m,i,j,beg,end);
	}
  }
}
//m=1....7 not(0 8)
//return 0 or i<<8 
//i行 t=1<<列；
inline int clear_bit_matrix_it(int  *a[], int  *m, const int &i , const int &t,const int &beg ,const int &end)//证明或者证否
{
	bool r;
	static int index[Length],q[Length];//
	int e=Bitwise_All^t;
	 for(int k=0;k<Length;k++)
	 {
		 q[k]=e;//消去一位
		 index[k]=1;
	 }
	 index[i]=t;//在回溯中保持不变
	 r=Backtracking_select_matrix(a , index, q , m, i, 0,beg,end);//i始终不变
	return r? 0:1<<i;
}
inline int clear_bit_matrix_i(int *a[] , int *m ,const int &i)
{
	int r=0,beg,end;
	if(i==0)
	{
		beg=1;end=Length-1;
	}
    else if(i==Length-1)
	{
		beg=0;end=Length-2;
	}
	else
	{
		beg=0;end=Length-1;
	}
	 
	for(int t=1;t<Index_Max;t<<=1)
	{
		if(t&m[i])
			{
				r|=clear_bit_matrix_it(a ,m,i,t,beg,end);
			}
	}
	return r;
}
bool clear_bit_matrix(int *a[], int &q)
{
	static int m[Length],r;
	q=0;
	for(int j=0;j<Length;j++)
	{
		m[j]=*a[j];//what?
	}//拷贝用作掩码
	for(int i=0;i<Length;i++)
	{
		r=clear_bit_matrix_i(a,m,i);
		if(*a[i]==Index_Max)
		{
			return false;
		}
		else
		{
		 q|=r;
		}
		
	}
	return true;
}

bool clear_bit_matrix_base(int *a[],const int &r,const int & m)
{
	int t=~r,q=1,p=~m;//p 要消除的位置
	for(int i=0;i<Length;i++)
	{
		if(q&p)
		{
			*a[i]&=t;
		}
		q<<=1;
	}
	return true;
}

#endif