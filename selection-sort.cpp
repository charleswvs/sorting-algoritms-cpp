#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

// function to swap the the position of two elements
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// function to print an array
void printArray(int array[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

void selectionSort(int array[], int size)
{
  for (int step = 0; step < size - 1; step++)
  {
    int min_idx = step;
    for (int i = step + 1; i < size; i++)
    {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    swap(&array[min_idx], &array[step]);
  }
}

// driver code
int main()
{
  int n = 500000;
  int data[n];

  for (int i = 0; i < n; i++)
    data[i] = rand() % 100000;

  auto start = high_resolution_clock::now();

  selectionSort(data, n);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<milliseconds>(stop - start);

  cout << "Time taken by function: "
       << duration.count() << " ms" << endl;
}