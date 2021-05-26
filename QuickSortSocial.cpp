// 2018556502 Muhammed Ali ARICI
// 2019556461 Mahmut Can CINGI
// 2020556061 Emre ULUSOY


#include <iostream>
using namespace std;

template <class SWAP>void swapargs( SWAP &x, SWAP &y ) {
  SWAP temp;
  temp = x;
  x = y;
  y = temp;
}
template <class temp1, class temp2> void display( temp1 *array, temp2 size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}
template <class temp1, class temp2, class temp3> int partition( temp1 *array, temp2 primier, temp3 last_element) {

  int pivot = array[last_element];
  int m = primier - 1;
  for (int n = primier; n <= (last_element - 1); n++) {
    if ( array[n] <= pivot) 
    {
      m++;
      swapargs(array[m], array[n]);
    }
  }
swapargs(array[m+1], array[last_element]);
return (m+1);
}

template <class temp1, class temp2, class temp3> void quicksort(temp1 *array, temp2 primier, temp3 last_element) {
  
  if (primier < last_element) {
    int piv = partition(array, primier, last_element);
    quicksort(array, primier,piv -1);
    quicksort(array, piv+1, last_element);
  }
} 


int main(void) {
  
  int x[11] = {53, 5, 1, 12, 19, 46, 24, 34, 51, 9, 15};
  int size = sizeof(x) / sizeof(x[0]);
  quicksort(x,0,size -1);
  display(x,size);

  char y[10] = {'y', 'i', 'f', 'c', 'o', 's', 't', 'k', 'a', 'h'};
  size = sizeof(y) / sizeof(y[0]);
  quicksort(y,0,size -1);
  display(y,size);


}