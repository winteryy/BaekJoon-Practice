class Solution {
    fun solution(s: String): Int {
        var answer: Int = 0
        var ind = 0

        while(ind<s.length) {
            answer++
            var leftCh = s[ind]
            var left = 1
            var right = 0

            ind++
            while(ind<s.length) {
                if(s[ind] == leftCh) left++ else right++
                ind++
                if(left==right) break
            }
        }

        return answer
    }
}