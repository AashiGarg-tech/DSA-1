class Solution {
    public int maxSumMinProduct(int[] nums) {
        int n = nums.length;
        long MOD = 1_000_000_007;
        
        // Step 1: Prefix Sum
        long[] prefix = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        long maxProduct = 0;
        Stack<Integer> stack = new Stack<>();
        
        // Step 2: Monotonic Stack
        for (int i = 0; i <= n; i++) {
            while (!stack.isEmpty() && 
                   (i == n || nums[stack.peek()] > nums[i])) {
                
                int mid = stack.pop();
                int left = stack.isEmpty() ? -1 : stack.peek();
                int right = i;
                
                long subarraySum = prefix[right] - prefix[left + 1];
                long product = subarraySum * nums[mid];
                
                maxProduct = Math.max(maxProduct, product);
            }
            stack.push(i);
        }
        
        return (int)(maxProduct % MOD);
    }
}
