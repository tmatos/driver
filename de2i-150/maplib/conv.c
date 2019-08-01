
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include "pcie_memmap.h"

//#define N 13   // qtd de coeficientes

#define VERBOSO


int main()
{
    unsigned int qtde_nums = 128;

    FILE * fp_entrada = fopen("entrada.dat", "r");

    if(!fp_entrada) {
        printf("Fornecer o arquivo \"entrada.dat\".\n");
        exit(1);
    }

    int i;

    int numeros[qtde_nums];
    u32 resultados[qtde_nums];

    for(i=0 ; i<qtde_nums ; i++) {
        fscanf(fp_entrada, "%i", (numeros+i) );
    }

    for(i=0 ; i<qtde_nums ; i++) {
        resultados[i] = (u32)0;
    }

    struct timeval inicio;
    struct timeval fim;

    // FPGA
    u32* ptr = get_device();

    gettimeofday(&inicio, NULL);  /// T_zero

    move(ptr, (u32*) numeros, qtde_nums);
    executar(ptr);
    get(ptr, resultados, qtde_nums);

    gettimeofday(&fim, NULL);  /// T_final

    close_device(ptr);
    // END FPGA

    long tempo = ((fim.tv_sec * 1000000 + fim.tv_usec) - (inicio.tv_sec * 1000000 + inicio.tv_usec));

    #ifdef VERBOSO

    printf("\nTeste da operacao em FPGA:\n\n");

    printf("Entrada = ");

    for(i=0 ; i<qtde_nums ; ++i) {
        printf("%i ; ", numeros[i]);
    }

    printf("\n\nSaida = ");

    for(i=0 ; i<qtde_nums ; ++i) {
        printf("%i ; ", ((int*)resultados)[i] );
    }

    printf("\n\nTEMPO GASTO (FPGA): %ld (us)\n", tempo );
    printf("\n\n");

    #endif

    #ifndef VERBOSO

    printf("%ld\n", tempo );

    #endif

    fclose(fp_entrada);
    
    return 0;
}
