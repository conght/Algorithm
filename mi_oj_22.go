package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func solution(line string) string {
    // 在此处理单行数据
    n,_ := strconv.Atoi(line)

    x:= 1 
    for {
        sum := (1+x)*x/2
        if (sum >= n) {
            x--
            break
        }
        x++
    }

    //fmt.Println(x)

    n -= (1+x)*x/2
    //fmt.Println(n)


    if (n <= 9) {
        return strconv.Itoa(n)
    } 
    if (n <= 16) {
        return strconv.Itoa(17-n)
    }

    if (n/16 > 0) {
        n = n%16 
    }

    if (n/9 > 0) {
        n = n%9
        return strconv.Itoa(9-n)
    } else {
        return strconv.Itoa(n)
    }
    // 返回处理后的结果
    //return
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}