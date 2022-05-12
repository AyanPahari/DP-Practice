class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int arr[10] = {0};
        arr[0] = 1;
        arr[1] = 10;
        arr[2] = 91;
        
        for(int i=3;i<=n;i++){
            int val_1 = 8;
            int val_2 = 1;
            for(int j=0;j<i-1;j++){
                val_1 = val_1 * (10 - j - 1);
                val_2 = val_2 * (10 - j - 1);
            }
            arr[i] = arr[i-1] + val_1 + val_2;
        }
        return arr[n];
    }
};