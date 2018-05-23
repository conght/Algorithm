package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "strconv"
)

func solution(line string) string {
    // 在此处理单行数据
    M, _ := strconv.Atoi(strings.Split(line, ",")[0])
    N, _ := strconv.Atoi(strings.Split(line, ",")[1])

    d := make([][]int, M+1)
    for i:=0;i<=M;i++ {
        d[i] = make([]int, N+1)
    }

    d[0][0] = 0
    d[1][1] = 1

    for j:=1;j<=N;j++ {
        d[1][j] = 1
    }
    
    for i:=2;i<=M;i++ {
        for j:=1;j<=N;j++ {
            fmt.Println(i,j)
            d[i][j] = d[i-1][j-1] + j*d[i-1][j]
        }
    }
    fmt.Println(d)
    // 返回处理后的结果
    return strconv.Itoa(d[M-1][N-1])
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}