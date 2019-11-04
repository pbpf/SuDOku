#ifndef permute_def
#define permute_def

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
//int quartic_of_three = Pow<3, 4>::value;

#endif