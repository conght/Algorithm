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
            x-=1
            break
        }
        x++
    }


    n -= (1+x)*x/2

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
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}