class Solution {
    fun solution(n: Int): Int {
        var answer = 0
        fiboArr[0] = 0
        fiboArr[1] = 1

        return fibo(n)
    }

    fun fibo(num: Int): Int {
        if(fiboArr[num]==-1) {
            fiboArr[num] = (fibo(num-1) + fibo(num-2)) % 1234567
        }
        return fiboArr[num]
    }

    companion object {
        val fiboArr = IntArray(100001) { -1 }
    }
}