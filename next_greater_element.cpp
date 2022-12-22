
  T.C O(n)
  S.C O(n)
vector<long long> nextLargerElement(vector<long long> arr, int n){
    
        vector<long long>v;
        
        stack<long long>st;
        
   
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                v.push_back(-1);
                st.push(arr[i]);
            }
            
            else if(st.top() > arr[i])
            {
                 v.push_back(st.top());
                 st.push(arr[i]);
            }
            else if(st.top() < arr[i])
            {
               while(!st.empty() && st.top() < arr[i])
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    v.push_back(st.top());
                    st.push(arr[i]);
                   
                }
                else
                {
                     v.push_back(-1);
                     st.push(arr[i]);
                }
            }
          
        }
        reverse(v.begin(),v.end());
        
        return v;
    }


  T.C O(nlogn)
  S.C O(n)

  vector<long long> nextLargerElement(vector<long long> arr, int n){
       
       priority_queue<long long,vector<long long>,greater<long long>>pq;
       vector<long long> ans;
       
       
       for(int i=n-1;i>=0;i--)
       {
           if(pq.empty())
           {
               ans.push_back(-1);
               pq.push(arr[i]);
           }
           else
           {
               if(pq.top() > arr[i])
               {
                   ans.push_back(pq.top());
                   pq.push(arr[i]);
               }
               else if(pq.top() < arr[i])
               {
                   while(!pq.empty() && pq.top() < arr[i])
                   {
                       pq.pop();
                   }
                   if(pq.empty())
                   {
                       ans.push_back(-1);
                       pq.push(arr[i]);
                   }
                   else
                   {
                       ans.push_back(pq.top());
                       pq.push(arr[i]);
                   }
               }
           }
       }
       reverse(ans.begin(),ans.end());
       return ans;
       
    }

  
  T.C O(n2)
  S.C O(n)

  void printNGE(int arr[], int n)
{
    int next, i, j;
    for (i = 0; i < n; i++) {
        next = -1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << " --> " << next << endl;
    }
}

  
