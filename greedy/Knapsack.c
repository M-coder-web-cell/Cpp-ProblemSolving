#include <stdio.h>

float maxProfit(int *profit, int *weight, int maxweight, int size){
    float arr[size];

    // compute ratios
    for(int i = 0; i<size; i++){
        arr[i] = (float)profit[i]/weight[i];
    }

    // sort ALL THREE arrays together (based on ratio)
    for(int i = 0; i<size - 1; i++){
        for(int j = 0; j<size - i - 1; j++){
            if(arr[j] > arr[j+1]){

                // swap ratio
                float temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                // swap profit
                int t1 = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = t1;

                // swap weight
                int t2 = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = t2;
            }
        }
    }

    float mprofit = 0;
    int j = size - 1;

    // take full items
    while(j >= 0 && maxweight - weight[j] >= 0){
        mprofit += profit[j];   // ✅ use profit, not ratio
        maxweight -= weight[j];
        j--;
    }

    // take fraction
    if(j >= 0){
        mprofit += ((float)maxweight / weight[j]) * profit[j]; // ✅ fix division
    }

    return mprofit;
}

int main(){
    int profit[] = {10, 5, 15, 7, 6, 18, 3};
    int weight[] = {2, 3, 5, 7, 1, 4, 1};

    float mprofit = maxProfit(profit, weight, 15, 7);
    printf("%f", mprofit);

    return 0;
}