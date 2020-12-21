class Solution {
    public int jump(int[] nums) {
        if (nums.length == 1) return 0;
        int n = nums.length;
        int[] dp = new int[n];

        for(int i = 0 ; i < n ; i++) dp[i] = (int)1e7;
        dp[n-1] = 0 ;

        for(int i = n-2; i > 0 ; i-- ) {
            for(int j = i+1 ; j < Math.min(n-1,i + nums[i]);j++){
                System.out.println(i + " " + j);
                dp[i] = Math.min(dp[i],1 + dp[j]);
            }
        }

        return dp[0];
    }
}