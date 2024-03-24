// Author : ysh
// 2024/02/22 Thu 15:50:00
// https://codeforces.com/contest/1926/problem/D
fun main() = repeat(readLine()!!.toInt()) {
    var n: Int = readLine()!!.toInt()
    var f = readLine()!!.split(' ').map {x -> x.toInt()}.toMutableSet()
    println(f)
}