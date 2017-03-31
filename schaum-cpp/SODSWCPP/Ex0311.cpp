//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.11 on page 57
//  Implementation of Random class

Random::Random(unsigned long seed) : _seed(seed)
{ if (seed == 0) _seed = time(NULL);
  randomize();
}
void Random::reset_seed(unsigned long seed)
{ _seed = seed;
  if (seed == 0) _seed = time(NULL);
  randomize();
}
int Random::integer(unsigned long hi,unsigned long lo)
{ // returns a random integer in the range lo to hi
  randomize();
  return (_seed/10)%(hi-lo+1) + lo;
}
double Random::real()
{ // returns a random real number in the range 0.0 to 1.0
  randomize();
  return double(_seed)/ULONG_MAX;
}
void Random::randomize()
{ _seed = (1103515245*_seed+123456789)%ULONG_MAX;
}
