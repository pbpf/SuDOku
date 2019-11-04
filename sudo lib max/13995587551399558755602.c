
#include "Sudo.cpp"
//#include <stdio.h>
//#include "Sudo.cpp"
//#include

int main(int argc, char **argv)
{    Sudo a;
	 a.user_set(1,3,4);
	 a.user_set(1,7,9);
	 a.user_set(1,8,2);
	 a.user_set(1,9,1);
	 a.user_set(2,3,1);
	 a.user_set(2,4,9);
	 a.user_set(2,6,4);
	 a.user_set(2,8,6);
	 a.user_set(3,1,6);
	 a.user_set(3,5,1);
	 a.user_set(4,3,7);
	 a.user_set(4,4,1);
	 a.user_set(4,5,9);
	 a.user_set(5,1,1);
	 a.user_set(5,4,3);
	 a.user_set(5,6,7);
	 a.user_set(5,9,5);
	 a.user_set(6,5,5);
	 a.user_set(6,6,8);
	 a.user_set(6,7,7);
	 a.user_set(7,5,4);
	 a.user_set(7,9,3);
	 a.user_set(8,2,3);
	 a.user_set(8,4,2);
	 a.user_set(8,6,5);
	 a.user_set(8,7,1);
	 a.user_set(9,1,7);
	 a.user_set(9,2,1);
	 a.user_set(9,3,8);
	 a.user_set(9,7,4);
     //a.user_set(1,1,3);
     a.force_solve();
	 a.display_all();
	// auto func = [] () { cout << "Hello world"; };  
	return 0;
}
