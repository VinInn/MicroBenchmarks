#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <random>
#include <iostream>

constexpr double LU_num_flops(int N)
{
        /* rougly 2/3*N^3 */

    double Nd = (double) N;

    return (2.0 * Nd *Nd *Nd/ 3.0);
}


int LU_factor(int M, int N, double **A, int *pivot);


    double kernel_measureLU(int cycles, int N)
    {

        std::mt19937_64 gen;
        std::uniform_real_distribution<double> dis(0.1,1.);

        double result = 0.0;
        int i=0;
        std::vector<double> A(N*N);
        std::vector<double> luS(N*N);
        std::vector<double*> lu(N);
        std::vector<int> pivot(N);

        for (int i=0; i<N; ++i) 
          lu[i] = &luS[i*N];

        for (auto & a : A)  a = dis(gen);
        
        int res = 0;
        for (i=0; i<cycles; i++)
            {
                std::copy(A.begin(),A.end(),luS.begin());
                res |= LU_factor(N, N, lu.data(), pivot.data());
            }
        /* approx Mflops */
        result = LU_num_flops(N) * cycles;

        if (res) std::cout << "problem with LU" << std::endl;
        return result;

    }

int main() {

  int cycles = 64;
  auto res = kernel_measureLU(cycles,1024);
  std::cout << "LU flops " << res << std::endl;

}

void LU_copy_matrix(int M, int N, double **lu, double **A)
{
    int i;
    int j;

    for (i=0; i<M; i++)
        for (j=0; j<N; j++)
            lu[i][j] = A[i][j];
}


int LU_factor(int M, int N, double **A,  int *pivot)
{
    int minMN =  M < N ? M : N;
    int j=0;

    for (j=0; j<minMN; j++)
    {
        /* find pivot in column j and  test for singularity. */

        int jp=j;
        int i;
        
        double t = fabs(A[j][j]);
        for (i=j+1; i<M; i++) {
          double ab = fabs(A[i][j]);
          if ( ab > t)  {
             jp = i;
             t = ab;
          }
        }
        pivot[j] = jp;

        /* jp now has the index of maximum element  */
        /* of column j, below the diagonal          */

        if ( A[jp][j] == 0 )                 
            return 1;       /* factorization failed because of zero pivot */


        if (jp != j)
        {
            /* swap rows j and jp */
            double *tA = A[j];
            A[j] = A[jp];
            A[jp] = tA;
        }

        if (j<M-1)                /* compute elements j+1:M of jth column  */
        {
            /* note A(j,j), was A(jp,p) previously which was */
            /* guarranteed not to be zero (Label #1)         */

            double recp =  1.0 / A[j][j];
            int k;
            for (k=j+1; k<M; k++)
                A[k][j] *= recp;
        }


        if (j < minMN-1)
        {
            /* rank-1 update to trailing submatrix:   E = E - x*y; */
            /* E is the region A(j+1:M, j+1:N) */
            /* x is the column vector A(j+1:M,j) */
            /* y is row vector A(j,j+1:N)        */

            int ii;
            for (ii=j+1; ii<M; ii++)
            {
                double *Aii = A[ii];
                double *Aj = A[j];
                double AiiJ = Aii[j];
                int jj;
                for (jj=j+1; jj<N; jj++)
                  Aii[jj] -= AiiJ * Aj[jj];

            }
        }
    }

    return 0;
}

