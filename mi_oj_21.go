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
    arr := strings.Split(line, " ")
    arrA := strings.Split(arr[0], ",")
    arrB := strings.Split(arr[1], ",")
    N,_ := strconv.Atoi(arr[2])

    lenA := len(arrA)
    lenB := len(arrB)

    //numberCountA := make([]int, 10)
    //numberCountB := make([]int, 10)
    //if N == (lenA+lenB) 

    ret := make([]string, N)
    pA := 0
    pB := 0
    //pR := 0

    for {
        if (pA == lenA && pB == lenB) {
            break
        }
        curr := ""
        if (pA == lenA) {
            curr = arrB[pB]
            pB += 1
        } else if (pB == lenB) {
            curr = arrA[pA]
            pA += 1
        } else {
            if (arrA[pA] < arrB[pB]) {
                curr = arrB[pB]
                pB += 1
            } else {
                curr = arrA[pA]
                pA += 1
            }
        }

        left := (lenA-pA) + (lenB - pB) + 1
        index := N-left
        if (index < 0) {
            index = 0
        }
        for ;index<N;index++ {
            if (curr > ret[index]) {
                ret[index] = curr
                break
            }
        }
    }
    
    // 返回处理后的结果
    return strings.Join(ret, "")
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}