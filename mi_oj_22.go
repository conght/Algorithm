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

    // curr:=1
    // plus:=true
    // for i:=2;i<=n;i++ {
    //     if (plus) {
    //         curr ++
    //     } else {
    //         curr --
    //     }
            
    //     if (curr == 10) {
    //         curr = 8
    //         plus = false
    //     } 
    //     if (curr == 0) {
    //         curr = 2
    //         plus = true
    //     }
        
    // }
    // return strconv.Itoa(line)
    x:= 1 
    for {
        sum := (1+x)*x/2
        if (sum >= n) {
            x-=1
            break
        }
        x++
    }

    //fmt.Println(x)

    n -= (1+x)*x/2
    //fmt.Println(n)


    // if (n <= 9) {
    //     return strconv.Itoa(n)
    // } 
    // if (n <= 16) {
    //     return strconv.Itoa(17-n)
    // }

    ret := ""
    if (n/16 > 0) {
        n = n%16
        
    }
    if (n == 0) {
        return "2"
    }
    if (n <= 9) {
        ret= strconv.Itoa(n)
    } else {
        ret= strconv.Itoa(18-n)
    }
    return ret
    /*if (n/9 > 0) {
        n = n%9
        return strconv.Itoa(9-n)
    } else {
        return strconv.Itoa(n)
    }*/
    // 返回处理后的结果
    //return
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}