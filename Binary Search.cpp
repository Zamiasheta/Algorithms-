#include<iostream>
using namespace std;

int binary_Search(int arr[], int left, int right, int x) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == x) {
      return mid;
    } else if (arr[mid] < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

int main() {
  int arr[10];
  int num;
  int output;

  cout << " Enter 10 elements ASCENDING order" << endl;
  for (int i = 0; i < 10; i++) {
    cin >> arr[i];
  }
  cout << "Enter an element to search" << endl;
  cin >> num;

  output = binary_Search(arr, 0, 9, num);

  if (output == -1) {
    cout << "No Match Found" << endl;
  } else {
    cout << "Match found: " << output << endl;
  }
  return 0;
}
