






#include <iostream>
using namespace std;

#define MAX_STR_LEN 100
#define MAX_NUM_STR 100

int compareStrings (char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i])
            return -1;
        else if (str1[i] > str2[i])
            return 1;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        return 0;
    else if (str1[i] == '\0')
        return -1;
    else
        return 1;
}

void copyString(char* dest, char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void MinHeapify(char arr[][MAX_STR_LEN], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && compareStrings(arr[l], arr[smallest]) < 0)
        smallest = l;

    if (r < n && compareStrings(arr[r], arr[smallest]) < 0)
        smallest = r;

    if (smallest != i) {
        char temp[MAX_STR_LEN];
        copyString(temp, arr[i]);
        copyString(arr[i], arr[smallest]);
        copyString(arr[smallest], temp);
        MinHeapify(arr, n, smallest);
    }
}

void MinHeapSort(char arr[][MAX_STR_LEN], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        MinHeapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        cout << arr[0] << " "; 
        char temp[MAX_STR_LEN];
        copyString(temp, arr[0]);
        copyString(arr[0], arr[i]);
        copyString(arr[i], temp);
        MinHeapify(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;

    char arr[MAX_NUM_STR][MAX_STR_LEN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    MinHeapSort(arr, n);

    return 0;
}
