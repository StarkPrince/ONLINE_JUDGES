// # Suppose you are given an array of integers called data. Suppose we would like to be able to know the number of times that each number in the array appears in the array. So, for example, suppose that the number 7 is repeated 11 times in the array. Then we would like to be able to always access the fact that 7 has a frequency of 11 in our array.

// # a) Which Java data structure would you use for such a task? Explain why it would be helpful?

// # b) Implement a function called computeFrequencies that receives the array as input and returns the data structure that you suggest in part a, with the appropriate values from the array (i.e. with the numbers from the array and their frequencies).

// We would use a HashMap to store the frequency of each number in the array. The key would be the number and the value would be the frequency of that number. This would be helpful because we can use the HashMap to find the frequency of a number in constant time.



// create a hashmap to store the frequency of each number in the array
public static HashMap<Integer, Integer> computeFrequencies(int[] data) {
    HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
    for (int i = 0; i < data.length; i++) {
        if (map.containsKey(data[i])) {
            map.put(data[i], map.get(data[i]) + 1);
        } else {
            map.put(data[i], 1);
        }
    }
    return map;
}

// use the hashmap to find the frequency of a number
public static int getFrequency(HashMap<Integer, Integer> map, int num) {
    if (map.containsKey(num)) {
        return map.get(num);
    } else {
        return 0;
    }
}


steps to solve the problem:
1. create a hashmap to store the frequency of each number in the array (computeFrequencies) to get the HashMap of frequencies of each number in the array
2. use the hashmap to find the frequency of a number (getFrequency) to get the frequency of a number in the array
3. print the frequency of a number in the array (printFrequency) to print the frequency of a number in the array
4. explain why the HashMap is helpful (explain) to explain why the HashMap is helpful for this problem