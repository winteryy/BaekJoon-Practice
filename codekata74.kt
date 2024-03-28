class Solution {
    fun solution(id_list: Array<String>, report: Array<String>, k: Int): IntArray {
        val answer = IntArray(id_list.size) { 0 }

        val nameMap: HashMap<String, Int> = HashMap()
        val personalReportedSet: HashMap<String, HashSet<String>> = HashMap()

        id_list.forEachIndexed { ind, name ->
            nameMap[name] = ind
            personalReportedSet[name] = HashSet()
        }

        for(str in report) {
            val (reporter, reportee) = str.split(" ")
            if(!personalReportedSet[reportee]!!.contains(reporter)) {
                personalReportedSet[reportee]!!.add(reporter)
            }
        }

        personalReportedSet.forEach { (name, reporterSet) ->
            if(reporterSet.size>=k) {
                for(reporter in reporterSet) {
                    answer[nameMap[reporter]!!]++
                }
            }
        }

        return answer
    }
}