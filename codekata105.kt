class Solution {
    fun solution(arr: Array<IntArray>): IntArray {
        originArr = arr
        val result = compress(0, 0, arr.size)
        return intArrayOf(result.first, result.second)
    }

    private fun compress(x: Int, y: Int, size: Int): Pair<Int, Int> {
        if(size==1) {
            if(originArr[y][x]==0) {
                return 1 to 0
            }else {
                return 0 to 1
            }
        }else {
            val half = size/2
            val compList = listOf(
                compress(x, y, half),
                compress(x+half, y, half),
                compress(x, y+half, half),
                compress(x+half, y+half, half)
            )

            var zeroNum = 0
            var oneNum = 0
            compList.forEach {
                zeroNum += it.first
                oneNum += it.second
            }
            if(zeroNum == 0) {
                return 0 to 1
            }else if(oneNum == 0) {
                return 1 to 0
            }else {
                return zeroNum to oneNum
            }
        }
    }

    companion object {
        var originArr = arrayOf(intArrayOf())
    }
}