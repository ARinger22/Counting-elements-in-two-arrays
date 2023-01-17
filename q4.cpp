
class Solution{
  public:

    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
    {
        sort(arr2,arr2+n);
        vector<int> v(m);
        
        vector<int> v1(m);
        for(int i =0; i< m;i++) v1[i] = arr1[i];
        vector<int> v2(n);
        for(int i =0; i< n;i++) v2[i] = arr2[i];
        
        vector<int> ct(1000000,0);
        for(int i =0; i< n; i++)
        {
            ct[v2[i]]++;//here we are counting the same element and storing it in vector index by increament every time if we got same element.
        }
        
        for(int i =0; i<m; i++)
        {
            int x = lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();//here we are searching that how many elemnets are less then but not grater than and equal to.
            v[i] = x+ct[v1[i]];//since we also have to count the element which are equal to then we add number of element which are same as v[i];
        }
        
        return v;
        
    }
};