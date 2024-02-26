#include "benchmark.h"

#include "Xoshiro.h"
#include <random>
#include <ext/random>


#include<string>
#include<cstring>

#include <iostream>
#include <cassert>



inline
void fillBits(int64_t * v, uint64_t x) {
  for (int i = 0; i < 64; ++i) {
    v[i] += x & 1;
    x >>= 1;
  }
}


#include <typeinfo>
template<typename Engine>
void doTestV(Engine & engine)
{
  
  std::cout << "Testing vector engine "  << typeid(engine).name() << ' ' << Engine::vector_size << std::endl;
  int N = 32 * 1000 * 1000;

  auto gen = [&](uint64_t const*, uint64_t * r, int N) {
    for (int i=0; i<N; i+=Engine::vector_size) {
      auto x =  engine.next();
      std::memcpy(r+i,&x,Engine::vector_size*sizeof(uint64_t));
    }
  };


      benchmark::TimeIt bench;
      // fill in batch of 256
      uint64_t rv[256];
      uint64_t dummy[1];
      for (int i = 0; i < N; ++i) {
           bench(gen, dummy, rv, 256);
      }

      std::cout << "duration " << bench.lap() << std::endl;


}

int main()
{
#ifdef __AVX512__
 std::cout << "avx512 supported" << std::endl;
#endif

#ifdef __AVX2__
 std::cout << "avx2 supported" << std::endl;
#endif


   XoshiroPP xoshiroppV;

   doTestV(xoshiroppV);
   return 0;
}

