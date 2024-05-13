import kotlin.math.max

class Solution {
    fun solution(arrayA: IntArray, arrayB: IntArray): Int {
        var answer: Int = 0

        var aGcd = arrayA.first()
        for(aNum in arrayA) {
            aGcd = gcd(aGcd, aNum)
        }
        var bGcd = arrayB.first()
        for(bNum in arrayB) {
            bGcd = gcd(bGcd, bNum)
        }
        
        for(bNum in arrayB) {
            if(bNum%aGcd == 0) {
                aGcd = 0
                break
            }
        }

        for(aNum in arrayA) {
            if(aNum%bGcd == 0) {
                bGcd = 0
                break
            }
        }

        return max(aGcd, bGcd)
    }

    tailrec fun gcd(a: Int, b: Int): Int {
        var big = 0
        var small = 0
        if(a>b) {
            big = a
            small = b
        }else {
            big = b
            small = a
        }

        val remain = big%small
        return if(remain==0) {
            small
        }else {
            gcd(small, remain)
        }
    }
}