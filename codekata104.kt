class Solution {
    fun solution(numbers: String): Int {
        numLen = numbers.length
        numStr = numbers

        for(i in 1..numLen) {
            dfs(0, i, "", 0)
        }

        return answerSet.size
    }
    private fun dfs(cur: Int, target: Int, str: String, flag: Int) {
        if(cur==target) {
            val num = str.toInt()
            if(isPrime(num)) {
                answerSet.add(num)
            }
        }else {
            for(i in 0 until numLen) {
                if((1 shl i) and(flag) == 0) {
                    dfs(cur+1, target, str+numStr[i], (1 shl i) or(flag))
                }
            }
        }
    }

    private fun isPrime(n: Int): Boolean {
        if(n==0 || n==1) return false
        if(n==2 || n==3) return true
        if(n%2==0 || n%3==0) return false

        var div = 5

        while(div*div<=n) {
            if(n%div==0 || n%(div+2)==0) return false
            div+=6
        }

        return true
    }

    companion object {
        val answerSet = mutableSetOf<Int>()
        var numLen = 0
        var numStr = ""
    }
}