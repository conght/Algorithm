package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func max(a ,b int) int {
    if (a > b) {
        return a
    } else {
        return b
    }
}

func solution(line string) string {
    // 在此处理单行数据
    AStr := strings.Split(line, ",")

    A := make([]int, len(AStr))

    for i:=0;i<len(AStr);i++ {
        A[i], _ = strconv.Atoi(AStr[i])
    }

    d := make([][]int, len(AStr))

    for i:=0;i<len(AStr);i++ {
        d[i] = make([]int, 2)
    }


    d[0][0] = 0
    d[0][1] = A[0]

    for i:=1;i < len(AStr);i++ {
        d[i][0] = max(d[i-1][1], d[i-1][0])
        d[i][1] = d[i-1][0]+A[i]
    }
    // 返回处理后的结果
    return strconv.Itoa(max(d[len(AStr)-1][0], d[len(AStr)-1][1]))
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}