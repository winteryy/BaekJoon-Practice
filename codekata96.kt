class Solution {
    fun solution(fees: IntArray, records: Array<String>): IntArray {
        val parkingMap = hashMapOf<String, Int>()
        val totalTimeMap = hashMapOf<String, Int>()
        for(record in records) {
            val recordArr = record.split(" ")
            val timeInt = recordArr[0].split(":").let {
                it[0].toInt()*60 + it[1].toInt()
            }
            if(recordArr[2]=="IN") {
                parkingMap[recordArr[1]] = timeInt
            }else {
                totalTimeMap[recordArr[1]] = (totalTimeMap[recordArr[1]]?:0) + timeInt-parkingMap[recordArr[1]]!!
                parkingMap.remove(recordArr[1])
            }
        }
        if(parkingMap.isNotEmpty()) {
            parkingMap.forEach { (num, time) ->
                totalTimeMap[num] = (totalTimeMap[num]?:0) + 1439-time
            }
        }

        val costList = totalTimeMap.toSortedMap().map { (_, time) ->
            if(time<=fees[0]) fees[1] else {
                val overTime = time-fees[0]
                var totalCost = fees[1] + overTime/fees[2]*fees[3]
                if(overTime%fees[2]!=0) {
                    totalCost += fees[3]
                }
                totalCost
            }
        }

        return costList.toIntArray()
    }
}