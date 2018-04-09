package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "strconv"
)

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}


func solution(line string) string {
    // 在此处理单行数据
    inputs := strings.Split(line, ";")
    M,_ := strconv.Atoi(inputs[0])

    WStr := strings.Split(inputs[1], ",")
    VStr := strings.Split(inputs[2], ",")

    W := []int{}
    V := []int{}

    for i:=0;i<len(WStr);i++ {
        item,_ := strconv.Atoi(WStr[i])
        W = append(W, item)
    }

    for i:=0;i<len(VStr);i++ {
        item,_ := strconv.Atoi(VStr[i])
        V = append(V, item)
    }

    d := make([][]int, len(W))
    for i:=0;i<len(W);i++ {
        d[i] = make([]int, M+1)
    }

    for i:=W[0];i<=M;i++ {
        d[0][i] = V[0]
    }

    for i:=1;i<len(W);i++ {
        for j:=1;j<=M;j++ {
            if (j >= W[i]) {
                d[i][j] = max(d[i-1][j], V[i] + d[i-1][j-W[i]])
            } else {
                d[i][j] = d[i-1][j]
            }
        }
    }


    //fmt.Println(W)
    //fmt.Println(V)
    // 返回处理后的结果
    //fmt.Println(d)
    return strconv.Itoa(d[len(W)-1][M])
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}