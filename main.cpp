#include <stdio.h> // use fread, fclose, fopen
#include <stdint.h> // use nint32_t
#include <netinet/in.h> // use ntohl NBO -> HBO

int main(int argc, char const *argv[]){
        if(argc != 3){
            printf("wrong!");
            return 0;
        }
        FILE *file1, *file2; //use file pointer
        uint32_t num1;
        uint32_t num2;
        uint32_t sum;

        file1 = fopen(argv[1], "rb");
        file2 = fopen(argv[2], "rb");

        fread(&num1, sizeof(num1), 1, file1); // read 4 count for 1 byte
        fread(&num2, sizeof(num2), 1, file2);

        fclose(file1);
        fclose(file2);

        num1 = ntohl(num1);
        num2 = ntohl(num2);
        sum = num1 + num2;

        printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, sum, sum);


        return 0;

}
