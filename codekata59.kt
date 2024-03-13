class Solution {
    fun solution(n: Int, m: Int, section: IntArray): Int {
        var answer = 1

        var curPart = section.first()
        for(part in section) {
            if(part >= curPart+m) {
                answer++
                curPart = part
            }
        }
        return answer
    }
}