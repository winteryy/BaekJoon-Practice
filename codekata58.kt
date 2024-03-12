class Solution {
    fun solution(nums: IntArray): Int {
        var answer = 0
        val isPrime = MutableList<Boolean?>(3001) { null }

        for (i in 0 until nums.size-2) {
            for (j in i+1 until nums.size-1) {
                for (k in j+1 until nums.size) {
                    val sum = nums[i]+nums[j]+nums[k]
                    if (isPrime[sum] == null) {
                        isPrime[sum] = isPrime(sum)
                    }
                    if (isPrime[sum] == true) answer++
                }
            }
        }

        return answer
    }

    fun isPrime(num: Int): Boolean {
        if (num < 2) return false
        if (num == 2 || num == 3) return true
        if (num % 2 == 0 || num % 3 == 0) return false

        var i = 5
        while (i * i <= num) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false
            }
            i += 6
        }
        return true
    }
}