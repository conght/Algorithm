package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func mySolution(strA, strB, strC string) bool {

    if (len(strA) + len(strB) != len(strC)) {
        return false
    }

    if ((strA == strC && strB == "") || (strA == "" && strB == strC)) {
        return true
    }

    ret1 := false
    ret2 := false

    strA1 := strA
    strB1 := strB

    if (len(strA) > 0 && strA[0] == strC[0]) {
        if len(strA) > 1 {
            strA1 = strA[1:]
        } else {
            strA1 = ""
        }
        ret1 = mySolution(strA1, strB, strC[1:])
    }

    if (len(strB) > 0 && strB[0] == strC[0]) {
        if len(strB) > 1 {
            strB1 = strB[1:]
        } else {
            strB1 = ""
        }
        ret2 = mySolution(strA, strB1, strC[1:])
    }

    return ret1 || ret2
}

func solution(line string) string {
    // 在此处理单行数据
    numbers := strings.Split(line, ",")
    if (len(numbers) != 3) {
        return "false"
    }

    strA := numbers[0]
    strB := numbers[1]
    strC := numbers[2]

    ret := mySolution(strA, strB, strC)
    if (ret) {
        return "true"
    } else {
        return "false"
    }
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}