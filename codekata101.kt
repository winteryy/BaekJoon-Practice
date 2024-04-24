class Solution {
    fun solution(numbers: LongArray): LongArray {
        val answer: LongArray = LongArray(numbers.size)

        for((ind, num) in numbers.withIndex()) {
            var targetNum = num
            var powNum = 1L

            while(targetNum>=powNum) {
                powNum *= 2
            }
            if(targetNum==powNum-1) {
                answer[ind] = numbers[ind]+powNum-(powNum/2L)
            }else {
                var minZeroBitNum = 0L
                while(targetNum!=0L) {
                    powNum /= 2L
                    if(targetNum-powNum >= 0) {
                        targetNum -= powNum
                    }else {
                        minZeroBitNum = powNum
                    }
                }

                answer[ind] = if(powNum == 1L) numbers[ind]+minZeroBitNum-minZeroBitNum/2L else numbers[ind]+1L
            }
        }

        return answer
    }
}