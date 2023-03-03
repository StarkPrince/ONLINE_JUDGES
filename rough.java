// Write a java method that has takes an argument array and return an integer of the length of the longest increasing sequence in the argument array.

// ex: If there is an array that has the fallowing: [0, 1, 2, 1, 7] so 0,1,2,4 is an increasing sequence of length 3. Also in the same array 1,7 an increasing sequence of length 2.

class rough {
    public static void main(String[] args) {
        int[] arr = {0, 1, 2, 1, 7};
        System.out.println(longestIncreasingSequence(arr));
    }

    public int lengthofLongestIncreasingSubsequence(int[] nums) {
        int[] tails = new int[nums.length];
        int size = 0;
        for (int x : nums) {
            int i = 0, j = size;
            while (i != j) {
                int m = (i + j) / 2;
                if (tails[m] < x)
                    i = m + 1;
                else
                    j = m;
            }
            tails[i] = x;
            if (i == size) ++size;
        }
        return size;
    }
}