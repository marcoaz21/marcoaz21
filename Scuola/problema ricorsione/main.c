#include <stdio.h>


void e2R(int *a, size_t *p_aLen, int min, int max, size_t index, size_t *new_len) {
  
    if (index == *p_aLen) {
        *p_aLen = *new_len; 
        return;
    }

   
    if (a[index] >= min && a[index] <= max) {
        a[*new_len] = a[index]; 
        (*new_len)++;           
    }

    
    e2R(a, p_aLen, min, max, index + 1, new_len);
}

void e2(size_t *p_aLen, int *a, int min, int max) {
    size_t new_len = 0; 
    e2R(a, p_aLen, min, max, 0, &new_len); 
}

void int_array_print(size_t len, int *a) 
{
    for (size_t i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


int main() {
    size_t aLen = 4;
    int a[] = {1, 2, 3, 4};

    e2(&aLen, a, 2, 3); 

    printf("Nuova lunghezza: %zu\n", aLen);
    int_array_print(aLen, a);

    return 0;
}
