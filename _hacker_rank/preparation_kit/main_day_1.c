#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void plusMinus(int arr_count, int* arr) {
    int _negValue = 0;
    int _posValue = 0;
    int _zero = 0;
    for (int i = 0; i < arr_count; ++i) {
        if (arr[i] == 0) {
            _zero++;
        }
        else if (arr[i] < 0) {
            _negValue++;
        }
        else {
            _posValue++;
        }
    }
    
    printf("%.6f\n%.6f\n%.6f", 
        (double)_posValue/arr_count, 
        (double)_negValue/arr_count, 
        (double)_zero/arr_count
    );
}

void miniMaxSum(int arr_count, int* arr) {
    long long int sum = 0;
    for (long long int i = 0; i < arr_count; ++i) {
        sum += arr[i];
    }
    
    long long int min = sum;
    long long int max = 0;
    
    for (long long int i = 0; i < arr_count; ++i) {
        long long int temp = sum - arr[i];
        if (temp < min) {
            min = temp;
        }
        if (temp > max) {
            max = temp;
        }
    }
    
    printf("%lld %lld", min, max);
}

struct map_type {
  char* key;
  char* value;  
};

void updateMap(struct map_type* map, char* key, char* value) {
    (*map).key = malloc(100 * sizeof(char));
    (*map).value = malloc(100 * sizeof(char));
    strcpy((*map).key, key);
    strcpy((*map).value, value);
}

char* timeConversion(char* s) {
    struct map_type m_map[13];
    updateMap(&m_map[0],"00","12");
    updateMap(&m_map[1],"01","13");
    updateMap(&m_map[2],"02","14");
    updateMap(&m_map[3],"03","15");
    updateMap(&m_map[4],"04","16");
    updateMap(&m_map[5],"05","17");
    updateMap(&m_map[6],"06","18");
    updateMap(&m_map[7],"07","19");
    updateMap(&m_map[8],"08","20");
    updateMap(&m_map[9],"09","21");
    updateMap(&m_map[10],"10","22");
    updateMap(&m_map[11],"11","23");
    updateMap(&m_map[12],"12","00");
    
    char* result = malloc(100 * sizeof(char));
    auto size = strlen (s);
    printf("input: %s - size of s: %d\n", s, size);
    if (s[size-2] == 'A') {
        printf("Get to case: %c\n",s[size-2]);
        char* _temp = malloc(100 * sizeof(char));
        strncpy(_temp, s, 2);
        if (strcmp(_temp, "12") == 0) {
            strcpy(result, "00");
            strncpy(result + 2, (s + 2), 6);
        }
        else {
            strncpy(result, s, 8);
        }
    }
    else {
        printf("Get to case: %c\n",s[size-2]);
        bool flag = false;
        char* _temp = malloc(100 * sizeof(char));
        //"";
        strncpy(_temp, s, 2);
        for (int i = 0; i < 13; i++) {
            if (strcmp(_temp, "12") == 0) {
                break;
            }
            if (strcmp(_temp, m_map[i].key) == 0) {
                flag = true;
                printf("idex: %d - key/value: %s\n", i, _temp);
                strcpy(result, m_map[i].value);
                printf("idex: %d - key/value: %s\n", i, result);
                strncpy(result + 2, (s + 2), 6);
                break;
            }
        }
        if (!flag)
            strncpy(result, (s), 8);
    }
    return result;
}

// ********* MOCK_TEST *************
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}


int findMedian(int arr_count, int* arr) {
    mergeSort(arr, 0, arr_count - 1);
    return arr[arr_count - 1];
}


int main(void) {
    printf("result: %s\n", timeConversion("12:45:54PM"));
    return 0;
}