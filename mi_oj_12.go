package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "strconv"
)

func myfunc(numbers *[]int, sum int) int {
    if (sum == 0) {
        return 1
    }

    if (sum < 0) {
        return 0
    }

    ret := 0

    for i:=0;i<len(*numbers);i++ {
        ret += myfunc(numbers, sum-(*numbers)[i])
    }

    return ret
}

func solution(line string) string {
    // 在此处理单行数据
    
    items := strings.Split(line, " ")
    numbers := strings.Split(items[0], ",")
    k, _ := strconv.Atoi(items[1])
    
    num := make([]int, len(numbers))
    for i:=0;i<len(numbers);i++ {
        n, _ := strconv.Atoi(numbers[i])
        num[i] = n
    }

    // 返回处理后的结果
    return strconv.Itoa(myfunc(&num, k))
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}