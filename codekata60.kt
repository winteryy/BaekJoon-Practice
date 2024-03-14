class Solution {
    fun solution(number: Int, limit: Int, power: Int): Int {
        var answer: Int = 0

        for(i in 1 .. number) {
            var j = 1
            var divisor = 0
            while(j*j<=i) {
                if(i%j==0) {
                    if(j*j==i) {
                        divisor++
                    }else {
                        divisor+=2
                    }
                }
                if(divisor>limit) {
                    break
                }
                j++
            }

            answer += if(divisor>limit) power else divisor
        }

        return answer
    }
}