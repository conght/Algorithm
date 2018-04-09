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
    M,_ := strconv.Atoi(strings.Split(line, ",")[0])
    N,_ := strconv.Atoi(strings.Split(line, ",")[1])

    C := M/N
    if (N*C < M) {
        C += 1
    }
    //fmt.Println(C)
    D := (C*2-1)*4/18
    if (D*18 == (C*2-1)*4) {
        D -= 1
    }
    return strconv.Itoa((C*2-1)*4 + D*5)
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}