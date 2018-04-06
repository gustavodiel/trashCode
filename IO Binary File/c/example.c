#include <stdio.h>
#include <stdlib.h>

// A random struct to write to our file
typedef struct {
        int x, y;
} Point;

// Name of the file
const char *fileName = "file.bin";

int main(){
        // Open the file for writing
        FILE* file = fopen(fileName, "wb");

        // Our string which we will send to the file, up to 256 char
        // The sizeof is not needed (sizeof(char) == 1 always)
        size_t maxStringSize = 256;
        size_t actualStringSize;
        char *string = (char*)malloc(maxStringSize * sizeof(char));

        // Read the entire line!
        // This is kinda safe because we send the max size of the string
        // so we wont run out of memory! :3
        if (!(actualStringSize = getline(&string, &maxStringSize, stdin))) {
                printf("Failed to read line!\n");
                return 1;
        }

        // Just a point
        Point p = {
                10,
                20
        };

        int i;

        // Dividing the total size of the array by the size of the
        // first array gives the amount of elements!
        int amountOfChars = sizeof(string)/sizeof(string[0]);

        // We write the size of the string, so later we know what to read
        fwrite(&actualStringSize, sizeof(size_t), 1, file);
        // Write down the string itself
        fwrite(string, sizeof(char), actualStringSize, file);

        // Generate some random points and write 'em down
        for (size_t i = 0; i < 5; i++) {
                p.x += i;
                p.y += i * 3;
                fwrite(&p, sizeof(Point), 1, file);
        }
        // Another way of writing to the file, should be more optmized
        Point pontos[] = {
                {1, 2},
                {2, 3},
                {10, 1},
                {20, 20},
                {66, 99}
        };
        int amountOfPoints = sizeof(pontos)/sizeof(pontos[0]);
        fwrite(pontos, sizeof(Point), amountOfPoints, file);

        // Close the file
        fclose(file);

        // Open the file for reading
        file = fopen(fileName, "rb");

        // Read the size of the string
        size_t foundStringSize;
        fread (&foundStringSize, sizeof(size_t), 1, file);


        Point novoP[10];
        char novoC[foundStringSize];

        // Read the string
        fread (&novoC, sizeof(char), foundStringSize, file);

        // Read the points
        printf("%s\n", novoC);
        // Two ways of reading the file. The second is more optmized
        // for (size_t i = 0; i < 5; i++) {
        //         fread (&(novoP[i]), sizeof(Point), 1, file);
        // }
        fread(&novoP, sizeof(Point), 10, file);

        for (i = 0; i < 10; i++) {
                printf("(%d, %d)\n", novoP[i].x, novoP[i].y);
        }

        fclose(file);
        return 0;
}
