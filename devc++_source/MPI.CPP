#include "mpi.h"
#include <stdio.h>
#include <math.h>
#define l 4 /*第一个矩阵的行*/
#define m 3 /*第一个矩阵的列，第二个矩阵的行*/
#define n 2 /*第二个矩阵的列*/
main(int argc, char *argv[])
{
    int a[l][m] = {{2, 3, 5}, {4, 5, 7}, {6, 3, 6}, {1, 6, 7}};
    int b[m][n] = {{2, 4}, {3, 6}, {8, 5}};
    int c[l][n] = {0}; /*保存最终结果*/
    int d[l][n] = {0}; /*各个分进程保存中间结果*/
    int numproces, id, i, j, k, p, q, s, t, x, y;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numproces);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    printf("Process %d :\n", id);
    if (id > 0)
    { /*numproces个进程，l行，每个进程l/numproces行， 从(id-1)*l/numproces行到id*l/numproces行*/
        for (x = 0, i = (id - 1) * l / numproces; i < id * l / numproces, x < l /
                                                                                  numproces;
             i++, x++)
        {
            for (y = 0, j = 0; j < n, y < n; j++, y++)
            {
                for (k = 0; k < m; k++)
                {
                    d[x][y] = d[x][y] + a[i][k] * b[k][j]; /*d[][]
        保存该进程计算结果*/
                }
                printf("d[%d][%d]=%d\t", x, y, d[x][y]);
                fflush(stdout);
            }
        }
        MPI_Send(&d, (l / numproces) * n, MPI_INTEGER, 0,
                 id, MPI_COMM_WORLD); /*将得到的矩阵传递给0号进程*/
    }
    if (id == 0)
    { /*最后一个进程分得从(numproces-1)*l/numproces到 l行的部分*/
        for (i = (numproces - 1) * l / numproces; i < l; i++)
            for (j = 0; j < n; j++)
            {
                for (k = 0; k < m; k++)
                {
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }
                printf("c[%d][%d]=%d\t", i, j, b[k][j]);
            }
        for (k = 1; k <= numproces - 1; k++)
        { /*将其他进程
计算得到的矩阵合并*/
            MPI_Recv(&d, (l / numproces) * n, MPI_IN⁃ TEGER, MPI_ANY_SOURCE, MPI_ANY_TAG,
                     MPI_COMM_WORLD, &status);
            for (p = (k - 1) * l / numproces, s = 0; p < k * l / num⁃ proces - 1, s < l / numproces; p++, s++)
                for (q = 0, t = 0; q < n, t < n; q++, t++)
                {
                    c[p][q] = d[s][t];
                }
        }
        printf("the result is :\n"); /*打印最终结果*/
        for (i = 0; i < l; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%d\t", c[i][j]);

                printf("\n");
            }
        }
        MPI_Finalize();
    }