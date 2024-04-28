#include <iostream>
#include <vector>
#include <random>

//Here's below the bubble Sort implementation:
template<typename T>
void bubbleSort(std::vector<T>& v) {   
    //Below there is iteration through the vector, starting from the beginning:
    for(int i = 0; i < v.size()-1; ++i) {
        //Below there is iteration through the remaining unsorted elements
        for(int j = 0; j < v.size() - 1 - i; ++j) {
            //The lines want to mean if the current element is greater than the next element, swap them
            if(v.at(j) > v.at(j+1)) {
                int temp = v.at(j);
                v.at(j) = v.at(j+1);
                v.at(j+1) = temp;
            }
        }
    }
}

//Below there is insertion Sort implementation:
template <typename T>
void insertionSort(std::vector<T>& v) {
    //below there is iteration through the vector, starting from the second element
    for(int i = 1; i < v.size(); i++) {
        T key = v.at(i); //To store the current element as the key
        int j = i - 1; //To initialize the index for the sorted part of the vector
        
        // Shift the elements in the sorted part of the vector to make room for the key
        while(j >= 0 && v.at(j) > key) {
            v.at(j + 1) = v.at(j);
            --j;
        }
        v.at(j + 1) = key; // To insert the key in its correct position
    }
}

//Here is selection Sort implementation below:
template <typename T>
void selectionSort(std::vector<T>& v) {
    // the iterate through the vector, starting from the beginning:
    for(int i = 0; i < v.size()-1; i++) {
        int min_indx = i; // Initialize the index of the minimum element
        
        // Find the index of the minimum element in the unsorted part of the vector
        for(int j = i + 1; j < v.size(); j++) {
            if(v.at(j) < v.at(min_indx))
            min_indx = j;
        }
        
        //To swap the minimum element with the element at the current index
        if (min_indx != i) {
            T temp = v.at(i);
            v.at(i) = v.at(min_indx);
            v.at(min_indx) = temp;
        }
    }
}

//This is Partition function for QuickSort:
template <typename T>
int partition(std::vector<T>& v, int low, int high) {
    T pivot = v[high]; //On this line we choose the rightmost element as the pivot
    int i = (low - 1); // Index of the smaller element

    // Iterate through the vector, moving elements smaller than the pivot to the left
    for (int j = low; j <= high - 1; j++) {
        if (v[j] < pivot) {
            i++;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[high]); // Swap the pivot with the element at the correct position
    return (i + 1); // Return the index of the pivot
}

// QuickSort implementation
template <typename T>
void quickSort(std::vector<T>& v, int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high); // This line shows partition the vector around the pivot
        quickSort(v, low, pi - 1); // The Recursively sort the left part
        quickSort(v, pi + 1, high); // The Recursively sort the right part
    }
}

template <typename T>
void quickSort(std::vector<T>& v) {
    quickSort(v, 0, v.size() - 1); //This line shows Call of the recursive QuickSort function
}

//The Merge function which shows MergeSort
template <typename T>
void merge(std::vector<T>& v, int l, int m, int r) {
    int n1 = m - l + 1; // Size of the left subarray
    int n2 = r - m; // Size of the right subarray

    std::vector<T> L(n1), R(n2); // Create temporary subarrays

    //To Copy the elements to the temporary subarrays:
    for (int i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];

    int i = 0, j = 0, k = l; // To Initialize indices for merging

    //To Merge the temporary subarrays back into the original vector:
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    //To Copy the remaining elements from the left subarray
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    //To Copy the remaining elements from the right subarray
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

//The MergeSort implementation below:
template <typename T>
void mergeSort(std::vector<T>& v, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; //To find the middle index
        mergeSort(v, l, m); // Recursively sort the left half
        mergeSort(v, m + 1, r); // Recursively sort the right half
        merge(v, l, m, r); // Merge the sorted halves
    }
}

template <typename T>
void mergeSort(std::vector<T>& v) {
    mergeSort(v, 0, v.size() - 1); // To call the recursive MergeSort function
}

template<typename T>
bool isSorted(const std::vector<T>& v) {
    for(size_t i=0; i<v.size()-1;++i)
        if(v.at(i)>v.at(i+1)) return false;
    return true;
}

int main() {

    std::vector<int> v1{23,45,12,7,6,9,3};
    std::vector<int> v3{4,3,2,1,7,8,9,6};
    std::vector<int> v4{3,6,1,7,9,8,2,4,5};
    std::vector<int> v5{22,44,33,11,66,55,88,77};
    std::vector<int> v2{9,2,3,1,7,8,6,4,5};

    bubbleSort(v1);
    insertionSort(v2);
    selectionSort(v3);
    quickSort(v4);
    mergeSort(v5);


    std::vector<std::vector<int>> vectors;
    vectors.push_back(v1);
    vectors.push_back(v2);
    vectors.push_back(v3);
    vectors.push_back(v4);
    vectors.push_back(v5);

    int sorted = 0;
    for (auto v: vectors)
        if( isSorted(v)) ++sorted;
    std::cout<<"sorted :"<<sorted<<"\n";

    return 0;
}