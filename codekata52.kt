class Solution {
    fun solution(a: Int, b: Int, n: Int): Int {
        var answer: Int = 0
        var curBottle = n;
        while(curBottle>=a) {
            val receivedBottle = curBottle/a*b;
            curBottle %= a;
            curBottle += receivedBottle;
            answer += receivedBottle;
        }
        return answer
    }
}