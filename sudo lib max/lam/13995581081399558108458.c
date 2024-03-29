
#include <iostream>  

using namespace std;  
  
template<int B, int N>
struct Pow {
    // recursive call and recombination.
    enum{ value = B*Pow<B, N-1>::value };
};
 
template< int B > 
struct Pow<B, 0> { 
    // ''N == 0'' condition of termination.
    enum{ value = 1 };
};
int main()  
{  
    auto func = [] () { cout << "Hello world"; };  
    func(); // now call the function 
   int b=Pow<3,7>::value;
   cout<<b<<endl;
}  

