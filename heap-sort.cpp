#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

using namespace std;

void buildHeap(int arr[], int n, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    buildHeap(arr, n, largest);
  }
}

void heapSort(int arr[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    buildHeap(arr, n, i);

  for (int i = n - 1; i > 0; i--)
  {
    swap(arr[0], arr[i]);
    buildHeap(arr, i, 0);
  }
}

int main()
{
  int numberOfExecutions = 5;
  int executions[5] = {10, 10000, 100000, 500000, 1000000};

  for (int j = 0; j < 5; j++)
  {

    int n = executions[j];
    int data[n];

    for (int i = 0; i < n; i++)
      data[i] = i;

    auto start = high_resolution_clock::now();

    heapSort(data, n);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function with "
         << n
         << " elements: "
         << duration.count() / (double)1000 << " ms" << endl;
  }
}