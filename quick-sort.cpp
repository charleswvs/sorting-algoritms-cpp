#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

// (n+1) + 3
int partition(int array[], int low, int high)
{

  // +1
  int pivot = array[high];

  // +1
  int i = (low - 1);

  // n + 1
  for (int j = low; j < high; j++)
  {
    // 1
    if (array[j] <= pivot)
    {

      i++;

      // 1
      swap(&array[i], &array[j]);
    }
  }

  // 1
  swap(&array[i + 1], &array[high]);

  return (i + 1);
}

void quickSort(int array[], int low, int high)
{
  if (low < high) // +1
  {
    // (n)
    int pivot = partition(array, low, high);

    // 2 * ((n/2) - 1)
    quickSort(array, low, pivot - 1);
    quickSort(array, pivot + 1, high);
  }
}

void printArray(int array[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int main()
{
  int executions[1] = {300000};

  for (int j = 0; j < 1; j++)
  {

    int n = executions[j];
    int data[n];

    for (int i = 0; i < n; i++)
      data[i] = i;

    auto start = high_resolution_clock::now();

    quickSort(data, 0, n - 1);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function with "
         << n
         << " elements: "
         << duration.count() / (double)1000 << " ms" << endl;
  }
}
