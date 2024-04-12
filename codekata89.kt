class Solution {
    fun solution(want: Array<String>, number: IntArray, discount: Array<String>): Int {
        var answer: Int = 0

        val countMap = hashMapOf<String, Int>()
        want.forEach {
            countMap[it] = 0
        }
        val countSum = number.sum()

        for(i in 0 until countSum) {
            if(countMap.containsKey(discount[i])) {
                countMap[discount[i]] = countMap[discount[i]]!! + 1
            }
        }

        for(i in 0 .. discount.size-countSum) {
            var flag = true
            for(j in 0..want.lastIndex) {
                if(countMap[want[j]]!=number[j]) {
                    flag = false
                    break
                }
            }
            if(flag) answer++
            if(i==discount.size-countSum) break
            if(countMap.containsKey(discount[i])) {
                countMap[discount[i]] = countMap[discount[i]]!! - 1
            }
            val right = i+countSum
            if(countMap.containsKey(discount[right])) {
                countMap[discount[right]] = countMap[discount[right]]!! + 1
            }
        }

        return answer
    }
}