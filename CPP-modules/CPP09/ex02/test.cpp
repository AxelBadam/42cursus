#include <iostream>
#include <vector>

void mergeInsertionSort(std::vector<int> &arr, int left, int right);
void merge(std::vector<int> &arr, int left, int middle, int right);
void insertionSort(std::vector<int> &arr, int left, int right);

int main() 
{
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    std::cout << "Given array is \n";
    for (int i : arr) std::cout << i << " ";
    
    mergeInsertionSort(arr, 0, n - 1);

    std::cout << "\nSorted array is \n";
    for (int i : arr) std::cout << i << " ";
    return 0;
}

void mergeInsertionSort(std::vector<int> &arr, int left, int right) 
{
    if (left < right)
	{
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeInsertionSort(arr, left, middle);
        mergeInsertionSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

void merge(std::vector<int> &arr, int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++) L[i] = arr[left + i];
    for (j = 0; j < n2; j++) R[j] = arr[middle + 1 + j];

    i = 0; 
    j = 0; 
    k = left;
    while (i < n1 && j < n2)
	{
        if (L[i] <= R[j]) 
		{
            arr[k] = L[i];
            i++;
        } else 
		{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
	{
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
	{
        arr[k] = R[j];
        j++;
        k++;
    }

    // Insertion sort for the merged array
    insertionSort(arr, left, right);
}

void insertionSort(std::vector<int> &arr, int left, int right) 
{
    int i, key, j;
    for (i = left + 1; i <= right; i++) 
	{
        key = arr[i];
        j = i - 1;

        while (j >= left && arr[j] > key) 
		{
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
