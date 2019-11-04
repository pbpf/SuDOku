//#define BaseLength 3
#include "Sudo.h"
#include <iostream>
#include<string>
using namespace std;
//#include <stdio.h>
//#include "Sudo.cpp"
//#include

string sudo2string(Sudo &a){
	string r="";
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			int x=a.ref(i,j);
			if(certain_bit(x)){
				r=r+bit2str(x);
			}
			else{
				r=r+"?";
			}
		}
	}
	return r;
}
string sudo2strings(Sudo &a){
	string r="";
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			int x=a.ref(i,j);
			r=r+","+bit2str(x);
		}
	}
	return r;
}
string sudo_solver(Sudo &a,string str,bool force,bool &r){
	//cout<<1<<endl;
	char x='1',y='9';
	for(unsigned int i=0;(i<81)&&(i<str.size());i++){
		int p=i/9,q=i%9;
		//cout<<'x'<<endl;
		if((x<=str[i])&&(str[i]<=y)){
			//cout<<"z: "<<p<<","<<q<<"="<<str[i]-x+1<<endl;
			a.user_set(p+1,q+1,str[i]-x+1);
			//cout<<"x2"<<endl;
		}
	}
	//cout<<2<<endl;
	if(force){
		r=a.force_solve();
	}
	else{
		r=a.solve();
		//r=1;
	}
	if(r){
		return sudo2strings(a);
	}
	else{
		return "no answer!";
	}	
}
int main(int argc, char **argv)
{   //cout<<-1;
   if(argc>1){
	   Sudo x;
	//cout<<argv[1]<<endl;
	string a=argv[1];
	//cout<<0;
	bool r=false,t;
	if(argc>2){
		t=false;
	}
	else{
		t=true;
	}
    string b=sudo_solver(x,a,t,r);
    cout<<"\nanswer:\n"<<b<<endl;
}
    return 0;
}

