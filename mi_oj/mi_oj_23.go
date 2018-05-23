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
    sum := 0
    d:= 10
    deta:=1
    start := 1
    for {
        if (x/d > 0) {
            d*=10
            deta+=1
        }

        sum += deta
        
        if (sum >= n) {
            x-=1
            break
        }
        x++
    }

    
    n = n - sum + deta

    
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}