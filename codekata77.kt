class Solution {
    fun solution(s: String): IntArray {
        var answer: IntArray = intArrayOf(0, 0)

        var cnt = 0
        var size = s.length
        for(num in s) {
            if(num=='1') cnt++
        }
        while(size>1) {
            answer[0]++
            answer[1] += size-cnt
            var newSize = 0
            var newCnt = 0

            while(cnt>0) {
                newSize++
                if(cnt%2 == 1) {
                    newCnt++
                }
                cnt/=2
            }

            size = newSize
            cnt = newCnt
        }

        return answer
    }
}
