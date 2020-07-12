#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc, char **argv) {
    if(argc != 3){
        printf("syntax : add-nbo <file1> <file2>\nsample : add-nbo a.bin c.bin\n");
        printf("%d",argc);
        return -1;
    }

    FILE* f1 = fopen(argv[1],"rb");
    FILE* f2 = fopen(argv[2], "rb");
    uint32_t num1, num2, result;
    if(f1 == NULL || f2 == NULL){
        printf("[!] File Open Error!!\n");
        return -1;
    }
    fread(&num1, sizeof(uint32_t), 1, f1);
    fread(&num2, sizeof(uint32_t), 1, f2);

    num1 = ntohl(num1);
    num2 = ntohl(num2);
    result = num1 + num2;
//    printf("0x%x / %d\n",num1, num1);
//    printf("0x%x / %d\n",num2, num2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, result, result);

    fclose(f2);
    fclose(f1);


}
