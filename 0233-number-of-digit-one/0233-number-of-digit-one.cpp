int dp[10][2][10];

class Solution {
public:
    int countDigitOne(int nums) {
        
        memset(dp,-1,sizeof(dp));

   int i=0,tight=1,countOnes=0;  

   // for i=0, tight=1 becouse we cannot put all digits to this position
        
        string str=to_string(nums);
        
   return find(i,tight,countOnes,str);

        
    }
    
int find(int i,int tight,int countOnes,string nums){
    
  if(i==nums.size())
  return countOnes;

  if(dp[i][tight][countOnes]!=-1)
  return dp[i][tight][countOnes];

  int ub;   // upperBound digit of position i

  if(tight==1)
  ub=nums[i]-'0';
  else
  ub=9;

  int ans=0;

  for(int d=0;d<=ub;d++){

   ans=ans+find(i+1,tight && (d==ub),countOnes + (d==1),nums);
      
  }

  return dp[i][tight][countOnes]=ans;
 }

};