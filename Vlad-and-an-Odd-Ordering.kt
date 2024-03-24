// Author : ysh
// 2024/02/22 Thu 18:01:57
// https://codeforces.com/contest/1926/problem/E
fun check(n: Int,x: Int): Int {
    var pre = (n + 1) / 2
    if(x - pre <= 0) return (x * 2) - 1
    return (check(x / 2,x - pre) * 2)
}
fun main() = repeat(readLine()!!.toInt()) {
    var (a,b) = readLine()!!.split(' ').map {x -> x.toInt()}
    println("${check(a,b)}")
}