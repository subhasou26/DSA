#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void optimizedBubbleSort(int arr[], int n) {
    int swapped;
    for (int i = 0; i < n-1; i++) {
        swapped = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

//run this code using ./a.out file_reading_sample.txt
int main (int argc , char* argv[])
{
    if (argc != 2)
    {
        printf("incorrect number of arguments\n");
        printf("given arguments are as follows:\n");
        for(int i =0; i <argc; i++)
            printf("%s\n", argv[i]);
        exit(0);
    }
    FILE* fp = fopen (argv[1], "r"); //first line int the line is the size
    int size, i=0, *arr;
    if (fp)
    {
        fscanf(fp, "%d", &size);
        arr = (int*)malloc(sizeof(int)*size);
        while (!feof(fp) && i < size)
            fscanf(fp, "%d", &arr[i++]);
        if(i!=size) 
        {
            printf("insufficient number of inputs, expected %d inputs\n",size); 
            exit(0);
        }
        fclose(fp);
    }
    else
    {
        perror("FILE open error");
        exit(0);
    }
    //bubbleSort(arr,size);
    optimizedBubbleSort(arr,size);
    for (i = 0; i <size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);

}