class Solution {
    fun solution(n: Int, k: Int): Int {
        var answer = 0

        val newNumStr = toConvertSystem(n, k)

        val nums = newNumStr.split("0").filter { it.isNotEmpty() }

        for(num in nums) {
            if(isPrime(num.toLong())) {
                answer++
            }
        }

        return answer
    }

    private fun toConvertSystem(n: Int, k: Int): String {
        val sb = StringBuilder()

        var num = n
        while(num>=k) {
            sb.append((num%k).digitToChar())
            num/=k
        }
        sb.append((num%k).digitToChar())

        return sb.toString().reversed()
    }

    private fun isPrime(n: Long): Boolean {
        if(n==1L) return false
        if(n==2L || n==3L) return true
        if(n%2L==0L || n%3==0L) return false

        var i = 5L
        while(i*i<=n) {
            if(n%i==0L || n%(i+2L)==0L) {
                return false
            }
            i += 6L
        }
        return true
    }
}