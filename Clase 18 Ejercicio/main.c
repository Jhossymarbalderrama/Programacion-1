#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct S_Data
{
    char* key;
    char* value;
};


int loadDataFile(char* fileName,struct S_Data* array, int arrayLen){


    FILE *fp;
    char lineStr[128];//variable donde almacenamos la linea leida

    fp = fopen(fileName,"r");
    if(fp == NULL){
        printf("Error Al abrir el Archivo.\n");
        return -1;
    }

    //Leemos el Archivo
    int index = 0;
    while(fgets(lineStr,128,fp)!= NULL){
        int indexDivider = strcspn(lineStr,"=");

        int keyLen = indexDivider+1;
        int valueLen = strlen(lineStr) - indexDivider -1;

        char* key = (char* )malloc(keyLen);
        char* value = (char* )malloc(valueLen);

        strncpy(key,lineStr,keyLen-1);
        key[keyLen-1]= 0x00;

        strncpy(value,&lineStr[keyLen],valueLen-1);
        value[valueLen-1]=0x00;

        array[index].key = key;
        array[index].value = value;

        index++;
        if(index >= arrayLen){
            break;
        }
    }
    fclose(fp);
    return index;

}

int main()
{
   struct S_Data array[16];
   int len = loadDataFile("dict.txt",array,16);

   for(int i = 0; i<len;i++){


        printf("%s = %s \r\n",array[i].key,array[i].value);
   }

    return 0;
}
