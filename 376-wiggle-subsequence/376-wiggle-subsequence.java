class Solution {
    public int wiggleMaxLength(int[] nums) {
        if (nums == null) return 0;
        if (nums.length <= 1) return nums.length;
        int f = 1, b = 1; //the first number can be a smaller number or larger number depends on what the next number it is. 
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i-1]) f = b + 1;
            else if (nums[i] < nums[i-1]) b = f + 1;
        }
        return Math.max(f, b);
    }
}