#include <vector>
#include <map>
//top-down
class SolutionTopDown{
private:
    std::map<int,int> memo;
    int dp(int i){
        if(i<=2) return i; //Base case
        if(memo.find(i)!=memo.end()){
            memo[i] = dp(i-1) + dp(i-2);
        }
        return memo[i]; //Recurrence relation
    }
public:
    int climbStairs(int n){
        return dp(n);
    }

};

//bottom-up

class SolutionBottomUp{
public: 
    int climbStairs(int n){
        if(n==1) return 1;
        std::vector<int> dp;
        dp[1] = 1; // Base cases
        dp[2] = 2; // Base cases
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};
