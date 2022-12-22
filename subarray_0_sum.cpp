
  T.C O(n)
  S.C O(n)
bool subArrayExists(int arr[], int N)
    {
                
        unordered_set<int> sumSet;

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
 
        // If prefix sum is 0 or
        // it is already present
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;
 
        sumSet.insert(sum);
    }
    return false;
        
               
    }


  T.C O(n2)
  S.C O(n)

  void subArraySum(int arr[], int n, int sum)
{
 
    // Pick a starting point
    for (int i = 0; i < n; i++) {
        int currentSum = arr[i];
 
        if (currentSum == sum) {
            cout << "Sum found at indexes " << i << endl;
            return;
        }
        else {
            // Try all subarrays starting with 'i'
            for (int j = i + 1; j < n; j++) {
                currentSum += arr[j];
 
                if (currentSum == sum) {
                    cout << "Sum found between indexes "
                         << i << " and " << j << endl;
                    return;
                }
            }
        }
    }
    cout << "No subarray found";
    return;
}