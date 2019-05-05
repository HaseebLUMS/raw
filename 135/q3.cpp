class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int ans = help(A, 0, A.size()-1);
        return ans;
    }
int min(int a, int b){
    return (a < b) ? a : b;
}



int cost(vector<int> A, int i, int j, int k)
{
    return A[i]*A[j]*A[k];
}

int help(vector<int> A, int i, int j)
{
   if (A.size() < 3) 
      return 0; 
    
   double t[A.size()][A.size()]; 

   for (int gap = 0; gap < A.size(); gap++) 
   { 
      for (int i = 0, j = gap; j < A.size(); i++, j++) 
      { 
          if (j < i+2) {t[i][j] = 0;} 
          else
          { 
              t[i][j] = INT_MAX; 
              for (int k = i+1; k < j; k++) 
              {
                double val = t[i][k] + t[k][j] + cost(A,i,j,k); 
                if (t[i][j] > val) 
                     t[i][j] = val; 
              } 
          } 
      } 
   } 
   return  t[0][A.size()-1]; 
}
};