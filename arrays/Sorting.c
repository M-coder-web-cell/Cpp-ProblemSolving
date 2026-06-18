void selectionSort(int arr[]){
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n-1; i++){
        int min_idx = i;

        for(int j = i+1; j<n; j++){
            if(arr[j]< arr[min_idx]) min_idx = j;
        }

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}


//QuickSort
//take an element and partition around it and recursively do it
int LomutoPartition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            int temp =arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}
void quicksort(int arr[], int low, int high){
    if(low < high){

        int pi = LomutoPartition(arr, low, high);

        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}


//InsertionSort
void insertionSort(int arr[]){
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 1; i< n; i++){
        int j = i;
        while(j>0 && arr[j]< arr[j-1]){
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}
