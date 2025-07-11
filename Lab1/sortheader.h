//Header file
    //Function for bubble sort
    void bubble_sort(int arr[],int n){
        for (int i =0;i<n-1;i++){
            for (int j=0;j<n-i-1; j++){
                if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                }
            }
        }
    }

    //function for selection sort
    void selection_sort(int arr[],int n){
        for (int i=0;i<n-1;i++){
            int min_index=i;
            for (int j=i+1;j<n;j++){
                if (arr[j]<arr[min_index]){
                    min_index=j;
                }
            }
            int temp=arr[min_index];
            arr[min_index]=arr[i];
            arr[i]=temp;
        }
    }

    //function for insertion sort
    void insertion_sort(int arr[],int n){
        for (int i=1;i<n;i++){
            int key=arr[i];
            int j=i-1;
            while (j>=0&&arr[j]>key)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
    }
