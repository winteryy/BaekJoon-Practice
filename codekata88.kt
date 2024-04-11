class Solution {
    fun solution(arr1: Array<IntArray>, arr2: Array<IntArray>): Array<IntArray> {
        val answer = Array(arr1.size) { IntArray(arr2[0].size) { 0 } }

        for(i in 0..answer.lastIndex) {
            for(j in 0..answer[0].lastIndex) {
                for(k in 0..arr1[0].lastIndex) {
                    answer[i][j] += arr1[i][k]*arr2[k][j]
                }
            }
        }
        return answer
    }
}