// Author : ysh
// 2024/06/02 Sun 20:19:22
fun main() {
    var (a,b) = readLine()!!.split(' ').map {x -> x.toInt()};
    println("$a $b");
}
/*
fun main() {
    var (n,a,b) = readLine()!!.split(' ').map {it.toInt()}
    var f = (0 .. n - 1).toMutableList()

    fun ff(x: Int): Int = if(f[x] == x) x else {f[x] = ff(f[x]); f[x]}
    fun mg(a: Int, b: Int) {f[ff(a)] = ff(b); return}

    repeat(a) {
        var (a,b) = readLine()!!.split(' ').map {x -> x.toInt()}
        mg(a - 1,b - 1)
    }

    repeat(b) {
        var (a,b) = readln().split(' ').map {it.toInt()}
        println(if(ff(a - 1) == ff(b - 1)) "True" else "False")
    }
    return
}
*/
