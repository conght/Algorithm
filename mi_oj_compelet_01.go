package main

import (
    "bufio"
    "fmt"
    "os"
//    "strings"
    "strconv"
)

func solution(line string) string {
    // 在此处理单行数据
    M,_ := strconv.Atoi(line)

    if M == 0 {
        return "Bad"
    }

    if M == 2 {
        return "Good"
    }
    if M%2 == 0 {
        return "Normal"
    }

    v1:=0
    v2:=0

    b1:=false
    b2:=false

    v1 = M - 1
    v2 = M + 1

    for ;v1 > 2; {
        if (v1 % 2 == 0) {
            v1 = v1 / 2
        } else {
            break;
        }
    }

    if (v1 == 2) {
        b1 = true
    } else {
        b1 = false
    }

    for ;v2 > 2; {
        if (v2 % 2 == 0) {
            v2 = v2 / 2
        } else {
            break;
        }
    }

    if (v2 == 2) {
        b2 = true
    } else {
        b2 = false
    }

    if b1 == true && b2 == true {
        return "Very Good"
    } else if b1 == true && b2 == false {
        return "Good"
    } else if b1 == false && b2 == true {
        return "Bad"
    } else {
        return "Normal"
    }
    // 返回处理后的结果
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}