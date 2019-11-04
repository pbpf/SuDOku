#ifndef _Bit_Matrix_H
  
  #define _Bit_Matrix_H
  
#ifdef BaseLength
 #define Length (BaseLength*BaseLength)
#endif

#ifndef Length
 #ifndef BaseLength
  #define BaseLength 3
 #endif
 #define Length (BaseLength*BaseLength)
#endif 

#define Index_Max 1<<Length
#define Bitwise_All ((1<<(Length+1))-1)
#define All_Set Bitwise_All>>1

bool clear_bit_matrix(int *a[], int &q);
bool clear_bit_matrix_base(int *a[],const int &r,const int &m);

#endif