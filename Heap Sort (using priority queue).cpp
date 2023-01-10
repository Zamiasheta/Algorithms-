#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void show(priority_queue<int, vector<int>, greater<int>> q)
{
    priority_queue<int, vector<int>, greater<int>> mh = q;

    while (!mh.empty())
    {
        cout << "\t" << mh.top();
        mh.pop();
    }

    cout << endl;
}

int main()
{
    int i;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    cout << " Inserting elements into the Priority Queue\n\n";
    for (i = 1; i < 6; i++)
    {
        minHeap.push(i * 20);
    }

    cout << "The number of elements in the Min Heap are : " << minHeap.size();
    ;

    cout << "\n\nThe first element or the element with the highest priority is: " << minHeap.top();
    ;

    cout << "\n\nThe elements of the Min Heap are: ";
    show(minHeap);

    cout << "\n\nAfter Deleting the first or the smallest element from the Min Heap, it becomes: ";
    minHeap.pop();
    show(minHeap);

    cout << "\n\nThe number of elements in the Min Heap after deleting the smallest element are : " << minHeap.size();
    ;

    cout << "\n\n\n";

    return 0;
}
