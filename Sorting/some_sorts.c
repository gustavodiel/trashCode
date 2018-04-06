#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge-sort implementado em Linguagem C sobre um vetor.
void merge(int v[], int e,int d){
    int i, j, k, metade, *vetTemp;
    if(e == d) return;
    metade = (e+d)/2;
    merge(v,e, metade);
    merge(v,metade+1,d);
    // lidando com vet temp.
    i = e;
    j = metade+1;
    k = 0;
    vetTemp = (int*) malloc(sizeof(int) * (d - e +1));
    for (; i < metade+1 || j < d+1;){
        if (i==metade+1){
            vetTemp[k]=v[j];
            j++;
            k++;
        } else {
            if (j==d+1){
                vetTemp[k] = v[i];
                i++;
                k++;
            } else {
                if (v[i] < v[j]) {
                    vetTemp[k] = v[i];
                    i++;
                    k++;
                } else {
                    vetTemp[k] = v[j];
                    j++;
                    k++;
                }
            }
        }
    }
    for (i=e; i<=d; i++){
        v[i] = vetTemp[i-e];
    }
    free(vetTemp);	
}

// Método de Quicksort sobre um vetor em Linguagem C.
void quicksort(int v[], int e, int d){
    int p = e;
    int i,j,ch;
    for(i=e+1; i<=d; i++){
        j = i;
        if (v[j] < v[p]){
            ch = v[j];
            for(; j > p;){
                v[j] = v[j-1];
                j--;
            }
            v[j] = ch;
            p++;
        }
    }
    if(p+1 < d) quicksort(v, d, p+1);
    if(p-1 > e) quicksort(v, e, p-1);
}

void bubble(int lista[], int n){
    int i, k;
    for (i = 0; i < n; ++i){
        for (k = 0; k < n; k++){
            if (lista[i] < lista[k]){
                int aux = lista[i];
                lista[i] = lista[k];
                lista[k] = aux;
            }
        }
    }
}


void heapsort_meu (int lista[], int n){
    int i = n / 2,
    pai,
    filho,
    espirito_santo;
    for (;;){
        if (i > 0){
            --i;
            espirito_santo = lista[i];
        }else{
            --n;
            if (n == 0)
                return;
            espirito_santo = lista[n];
            lista[n] = lista [0];
        }
        pai = i;
        filho = i * 2 + 1; // Como visto em sala, assim chegamos a posicao do filho
        while (filho < n) {
            if ((filho + 1 < n) && (lista[filho + 1] > lista[filho]))
                ++filho;
            if (lista[filho] > espirito_santo){
                lista[pai] = lista[filho];
                pai = filho;
                filho = pai * 2 + 1;
            } else {
                break;
            }
        }
        lista[pai] = espirito_santo;
    }
}


int main(){

    FILE *ord = fopen("ord.txt", "r"),
        *deord = fopen("desord.txt", "r"),
        *rando = fopen("rand.txt", "r"),
        *igual = fopen("igual.txt", "r");
    if (!ord || !deord || !rando || !igual){
        puts("Falha ao abrir um dos arquivos de teste!");
        return 1;
    }
    
    int max = 100000, i;
    
    int vO[max], vD[max], vR[max], vI[max];
    
    for ( i = 0; i < max; ++i){
        fscanf(ord, "%d", &vO[i]);
        fscanf(deord, "%d", &vD[i]);
        fscanf(rando, "%d", &vR[i]);
        fscanf(igual, "%d", &vI[i]);
    }
    printf("\nQuickSort com %d elementos:\n", max);
    clock_t begin, end;
    double time_spent;
    // *************** ORDENADO
    begin = clock();
    
    quicksort(vO, 0, max);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    

    
    printf ( "Tempo Ordenado: %lf\n", time_spent);
    
    // *************** AO CONTRARIO
   
    begin = clock();
    quicksort(vD, 0, max);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    
    printf ( "Tempo ao Contrario: %lf\n", time_spent);
    // *************** ALEATORIO
    begin = clock();
    
    quicksort(vR, 0, max);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    

    
    printf ( "Tempo Aleatorio: %lf\n", time_spent);
    // *************** IGUAL
    begin = clock();
    
    quicksort(vI, 0, max);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    
    printf ( "Tempo Igual: %lf\n", time_spent);
    
    //
    // ************ MERGE SORT
    //
    
    for ( i = 0; i < max; ++i){
        fscanf(ord, "%d", &vO[i]);
        fscanf(deord, "%d", &vD[i]);
        fscanf(rando, "%d", &vR[i]);
        fscanf(igual, "%d", &vI[i]);
    }
    printf("\nMerge Sort com %d elementos:\n", max);

    // *************** ORDENADO
    begin = clock();
    
    merge(vO, 0, max);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    
    
    printf ( "Tempo Ordenado: %lf\n", time_spent);
    
    // *************** AO CONTRARIO
    
    begin = clock();
    merge(vD, 0, max);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    
    printf ( "Tempo ao Contrario: %lf\n", time_spent);
    // *************** ALEATORIO
    begin = clock();
    
    merge(vR, 0, max);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    
    
    printf ( "Tempo Aleatorio: %lf\n", time_spent);
    // *************** IGUAL
    begin = clock();
    
    merge(vI, 0, max);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf ( "Tempo Igual: %lf\n", time_spent);
    
    //
    // ************ HEAP SORT
    //
    
    for ( i = 0; i < max; ++i){
        fscanf(ord, "%d", &vO[i]);
        fscanf(deord, "%d", &vD[i]);
        fscanf(rando, "%d", &vR[i]);
        fscanf(igual, "%d", &vI[i]);
    }
    printf("\nHeap Sort com %d elementos:\n", max);

    // *************** ORDENADO
    begin = clock();
    
    heapsort_meu(vO, max);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    
    
    printf ( "Tempo Ordenado: %lf\n", time_spent);
    
    // *************** AO CONTRARIO
    
    begin = clock();
    heapsort_meu(vD, max);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    
    printf ( "Tempo ao Contrario: %lf\n", time_spent);
    // *************** ALEATORIO
    begin = clock();
    
    heapsort_meu(vR, max);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    
    
    printf ( "Tempo Aleatorio: %lf\n", time_spent);
    // *************** IGUAL
    begin = clock();
    
    heapsort_meu(vI, max);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    
    printf ( "Tempo Igual: %lf\n", time_spent);
    
    //
    // ************ BUBBLE SORT
    //
    
    for ( i = 0; i < max; ++i){
        fscanf(ord, "%d", &vO[i]);
        fscanf(deord, "%d", &vD[i]);
        fscanf(rando, "%d", &vR[i]);
        fscanf(igual, "%d", &vI[i]);
    }
    printf("\nMerge Sort com %d elementos:\n", max);
    
    // *************** ORDENADO
    begin = clock();
    
    bubble(vO, max);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    
    
    printf ( "Tempo Ordenado: %lf\n", time_spent);
    
    // *************** AO CONTRARIO
    
    begin = clock();
    bubble(vD, max);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    
    printf ( "Tempo ao Contrario: %lf\n", time_spent);
    // *************** ALEATORIO
    begin = clock();
    
    bubble(vR, max);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    
    
    printf ( "Tempo Aleatorio: %lf\n", time_spent);
    // *************** IGUAL
    begin = clock();
    
    bubble(vI, max);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf ( "Tempo Igual: %lf\n", time_spent);
    return 0;
}
