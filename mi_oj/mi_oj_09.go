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
    items := strings.Split(line, ",")
    numbers := items[0]
    k, _ := strconv.Atoi(items[1])
    strLen := len(numbers)

    ret := ""

    for i:=0;i<strLen - 1;i++ {
        if (k > 0 && numbers[i] >= numbers[i+1]) {
            k--
        } else {
            ret += string(numbers[i])
        }
    }
    ret += string(numbers[strLen-1])

    if (k > 0) {
        ret = ret[k:]
    }
    //fmt.Println(ret)
    // 返回处理后的结果
    flag := true
    ret2 := ""
    for i:= 0; i<len(ret); i++ {
        if !(flag && ret[i] == '0') {
            flag = false
            ret2 += string(ret[i])
        }
    }
    if (ret2 == "") {
        ret2 = "0"
    }
    return ret2
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}