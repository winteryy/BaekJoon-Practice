class Solution {
    fun solution(w: Int, h: Int): Long {
        val gcdNum = gcd(w, h)
        val newW = w/gcdNum
        val newH = h/gcdNum

        var total = 0L
        var div = 0L
        var height = 0
        while(true) {
            height++
            val prevPoint = div/newH
            val nextPoint = (div+newW)/newH
            val consume = nextPoint-prevPoint+1
            if((div+newW)%newH == 0L) {
                total += consume-1
                break
            }else {
                div += newW
                total += consume
            }
        }

        return w.toLong() * h - (total * h/height)
    }

    tailrec fun gcd(a: Int, b: Int): Int {
        var big = 0
        var small = 0
        if(a>b) {
            big = a
            small = b
        } else {
            big = b
            small = a
        }

        val remain = big%small
        return if(remain == 0) {
            small
        }else {
            gcd(small, remain)
        }
    }
}