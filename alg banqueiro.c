#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    /*Declara��o de Vari�veis*/
    int n, m, i, j, k;
    n = 5; // n = n�mero de processos no sistema
    m = 3; // m = n�mero de recursos

    int alloc[5][3] = { { 0, 3, 0 }, // P0    // define o n�mero de recursos de cada tipo atualmente alocados para cada processo
                        { 2, 0, 0 }, // P1
                        { 3, 0, 2 }, // P2
                        { 2, 1, 1 }, // P3
                        { 3, 3, 2 } }; // P4

    int max[5][3] = { { 7, 5, 3 }, // P0    // define a demanda m�xima de cada processo em um sistema
                      { 3, 2, 2 }, // P1
                      { 9, 0, 2 }, // P2
                      { 2, 2, 2 }, // P3
                      { 4, 3, 3 } }; // P4

    int avail[3] = { 3, 1, 2 }; //  indica o n�mero de recursos dispon�veis de cada tipo

    int f[n], ans[n], ind = 0; // ans indica o �ndice do processo
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m]; // indica a necessidade de recursos restantes de cada processo.
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){//se o valor que est� na instancia do processo for maior que o disponivel, o processo n�o deve terminar
                        printf("need: %d avail: %d\n", need[i][j], avail[j]);
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y]; //se a solicita��o terminar, o vetor de trabalho � implementado com os valores do vetor aloca��o
                    f[i] = 1;
                    break; //add
                    //i=0;//add
                }
            }
        }
    }

      int flag = 1;

    for(int i=0;i<n;i++)
    {
      if(f[i]==0)
      {
        flag=0;
         printf("A sequencia segura �:");
        break;
      }
    }

    if(flag==1)
    {
      printf("A sequencia segura �:\n");
      for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
      printf(" P%d", ans[n - 1]);
    }

    return (0);
}
