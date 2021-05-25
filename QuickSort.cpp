// 2018556502 Muhammed Ali ARICI
// 2019556461 Mahmut Can CINGI
// 2020556061 Emre ULUSOY

#include <iostream>
using namespace std;

void swap_char(char *x, char *y)
{
  char temp = *x;
  *x = *y;
  *y = temp;
}
void printArray_char(char array_sort[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%c ", array_sort[i]);
  }
}
char partition_char(char array_sort_char[], int primer, int last_element)
{

  int pivot = array_sort_char[last_element];
  int m = primer - 1;

  for (int n = primer; n <= (last_element - 1); n++)
  {

    if (array_sort_char[n] <= pivot)
    {
      m++;
      swap_char(&array_sort_char[m], &array_sort_char[n]);
    }
  }
  swap_char(&array_sort_char[m + 1], &array_sort_char[last_element]);
  return (m + 1);
}
void quickSort_char(char array_sort_char[], int primer, int last_element)
{

  if (primer < last_element)
  {

    int piv = partition_char(array_sort_char, primer, last_element);

    quickSort_char(array_sort_char, primer, piv - 1);
    quickSort_char(array_sort_char, piv + 1, last_element);
  }
}
void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int arr[], int low, int high)
{
  int pivot = arr[high]; // pivot
  int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

  for (int j = low; j <= high - 1; j++)
  {
    // If current element is smaller than the pivot
    if (arr[j] < pivot)
    {
      i++; // increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
void printArray(int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main()
{
  int x[11] = {53, 5, 1, 12, 19, 46, 24, 34, 51, 9, 15};
  int n = sizeof(x) / sizeof(x[0]);
  quickSort(x, 0, n - 1);
  cout << "Sorted arrays: \n";
  printArray(x, n);

  char y[10] = {'y', 'i', 'f', 'c', 'o', 's', 't', 'k', 'a', 'h'};
  n = sizeof(y) / sizeof(y[0]);
  quickSort_char(y, 0, n - 1);
  printArray_char(y, n);

  return 0;
}
