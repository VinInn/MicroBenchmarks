#include "benchmark.h"

#include "Xoshiro.h"
#include <random>
#include <ext/random>


#include<string>
#include<cstring>

#include <iostream>
#include <cassert>

constexpr int batch = 512;


inline
void fillBits(int64_t * v, uint64_t x) {
  for (int i = 0; i < 64; ++i) {
    v[i] += x & 1;
    x >>= 1;
  }
}


#include <typeinfo>
void doTestSoA()
{

      // each generation is 14 int ops (10 if rotations (rol/ror) are present)
      std::cout << "Testing engine with SoA "  << typeid(XoshiroType::TwoSums).name() << ' ' << std::endl;


      xoshiroRNG::SOA<VECTOR_SIZE> soa;
      xoshiroRNG::setSeed(soa,0);
      auto fgen = [&](uint32_t const * __restrict__ dummy, float *__restrict__ out, int N) {
        
         auto ni = N/soa.size; 
         for (int i = 0; i < ni; i++) {
          int j=0;
//           #pragma omp simd aligned(out:64)
          for (int k=0; k<soa.size; ++k)
            out[j++] = xoshiroRNG::nextPP(soa,k);
         }
         
        // auto f = [&](int i, uint64_t r) { out[i] = r;};
        // xoshiroRNG::loop<XoshiroType::TwoSums>(soa, f, N);
      };

      long long N = 32 * 1000 * 1000;
      benchmark::TimeIt bench;
      // fill in batch of batch
      float rv[batch];
      uint32_t dummy[1];
      for (int i = 0; i < N; ++i) {
        bench(fgen, dummy, rv, batch);
      }

      std::cout << N*batch*14 << " int ops" << std::endl;
      std::cout << "duration " << bench.lap() << std::endl;

}


template<typename Engine>
void doTestV(Engine & engine)
{
  
  std::cout << "Testing vector engine "  << typeid(engine).name() << ' ' << Engine::vector_size << std::endl;
  long long N = 32 * 1000 * 1000;

  auto gen = [&](uint64_t const*, uint64_t * r, int N) {
    for (int i=0; i<N; i+=Engine::vector_size) {
      auto x =  engine.next();
      std::memcpy(r+i,&x,Engine::vector_size*sizeof(uint64_t));
    }
  };


      benchmark::TimeIt bench;
      // fill in batch of batch
      uint64_t rv[batch];
      uint64_t dummy[1];
      for (int i = 0; i < N; ++i) {
           bench(gen, dummy, rv, batch);
      }
      
      std::cout << N*batch*14 << " int ops" << std::endl;
      std::cout << "duration " << bench.lap() << std::endl;


}

int main()
{
#ifdef __AVX512F__
 std::cout << "avx512 supported" << std::endl;
#endif

#ifdef __AVX2__
 std::cout << "avx2 supported" << std::endl;
#endif

#ifdef TESTSOA 
  doTestSoA();
#elif TESTSCALAR
   Xoshiro<XoshiroType::TwoSums,uint64_t> xoshiroppS;
   doTestV(xoshiroppS);
#else
   XoshiroPP xoshiroppV;
   doTestV(xoshiroppV);
#endif
   return 0;
}

