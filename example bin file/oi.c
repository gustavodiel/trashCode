#include <stdio.h>

typedef struct{
    int x, y;
} ponto;

int main(){
    FILE* f = fopen("oi.bin", "wb");
    const char gustavo[20] = "Gustavo Woooooo :3";
    ponto p;
    p.x = 10;
    p.y = 20;
    int i;
    int qnt = sizeof(gustavo)/sizeof(gustavo[0]);
    for (i = 0; i < qnt; i++){
      fwrite(&(gustavo[i]), sizeof(char), 1, f);
    }
    for (size_t i = 0; i < 100; i++) {
      p.x += i;
      p.y += i * 3;
      fwrite(&p, sizeof(ponto), 1, f);
    }
    fclose(f);

    f = fopen("oi.bin", "rb");
    ponto novoP[100];
    char novoC[20];
    fread (&novoC,sizeof(char),20,f);

    printf("%s\n", novoC);
    for (size_t i = 0; i < 100; i++) {
      fread (&(novoP[i]),sizeof(ponto),1,f);
      printf("%d %d\n", novoP[i].x,novoP[i].y);
    }
    fclose(f);
    return 0;
}
