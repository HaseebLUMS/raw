#include <iostream>

using namespace std;

bool canBalane()
{
  int nums[] = {1, 1, 1, 1, 1, 1};
  int numslength = sizeof(nums)/sizeof(nums[0]);
  
  if(numslength < 1) {return false;}
  int sum = nums[0];
  for(int i = 1; i< numslength; i++)
  {
    nums[i] = nums[i] + sum;
    sum = nums[i];
  }
  
  if(nums[numslength-1]%2 != 0){return false;}
  
  for(int i = 0; i < numslength; i++)
  {
    if (nums[i] == (nums[numslength-1])/2)
    {
      return true;
    }
  }
  
  return false;
}

int main()
{
  canBalane();
  return 0;
}