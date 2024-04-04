class Solution {
    fun solution(arr: IntArray): Int {
        var answer = arr[0]

        for(i in 1..arr.lastIndex) {
            if(answer>arr[i]) {
                answer=lcm(answer, arr[i])
            }else {
                answer=lcm(arr[i], answer)
            }
        }

        return answer
    }

    private tailrec fun gcd(a: Int, b: Int): Int {
        return if(a%b==0) {
            b
        }else {
            gcd(b, a%b)
        }
    }

    private fun lcm(a: Int, b: Int): Int {
        return a*b/gcd(a, b)
    }
}