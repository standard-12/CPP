#include <iostream>
#include <vector>
using namespace std;

/*
 Feature                 Lomuto                      Hoare
 Pivot                   Last element                First element (commonly)
 Final pivot location    Exact (returned index)      Not guaranteed (returns j)
 Efficiency              More swaps                  Fewer swaps (usually)
 Simplicity              Easier                      Trickier
 Handles duplicates      Worse                       Better
*/

/* ---------- Lomuto partition ----------
   - pivot = nums[high]
   - returns final pivot index
   - typical recursive calls: quickSort(low, p-1); quickSort(p+1, high);
*/
int partitionLomuto(vector<int>& nums, int low, int high) {
    int pivot = nums[high];
    int i = low; // place for the next element <= pivot
    for (int j = low; j < high; ++j) {
        if (nums[j] <= pivot) {
            swap(nums[i], nums[j]);
            ++i;
        }
    }
    swap(nums[i], nums[high]);
    return i;
}

/* ---------- Hoare partition ----------
   - pivot = nums[low]
   - returns index j such that all elements <= j are <= pivot and all > j are >= pivot,
     but pivot may not end up at position j in the same deterministic way as Lomuto.
   - typical recursive calls: quickSort(low, p); quickSort(p + 1, high);
   - Implementation uses i = low-1, j = high+1 (safe boundary).
*/
int partitionHoare(vector<int>& nums, int low, int high) {
    int pivot = nums[low];
    int i = low - 1;
    int j = high + 1;
    while (true) {
        // move i right until nums[i] >= pivot
        do { ++i; } while (nums[i] < pivot);
        // move j left until nums[j] <= pivot
        do { --j; } while (nums[j] > pivot);

        if (i >= j)
            return j;
        swap(nums[i], nums[j]);
    }
}

/* QuickSort wrappers that choose partition scheme */
/* Using Lomuto */
void quickSortLomuto(vector<int>& nums, int low, int high) {
    if (low < high) {
        int p = partitionLomuto(nums, low, high);
        quickSortLomuto(nums, low, p - 1);
        quickSortLomuto(nums, p + 1, high);
    }
}

/* Using Hoare */
void quickSortHoare(vector<int>& nums, int low, int high) {
    if (low < high) {
        int p = partitionHoare(nums, low, high);
        quickSortHoare(nums, low, p);
        quickSortHoare(nums, p + 1, high);
    }
}

/* Small helper to print vector */
void printVec(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> a = { 9, 3, 7, 1, 4, 8, 2, 5, 3, 7 };

    cout << "Original: ";
    printVec(a);

    // Choose one:
    vector<int> b = a; // for Lomuto
    quickSortLomuto(b, 0, (int)b.size() - 1);
    cout << "Sorted with Lomuto: ";
    printVec(b);

    vector<int> c = a; // for Hoare
    quickSortHoare(c, 0, (int)c.size() - 1);
    cout << "Sorted with Hoare : ";
    printVec(c);

    return 0;
}
