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
    var numbers = strings.Split(line, ",")
    hashTable := make(map[int]int)

    maxCount := 0

    for i:=0; i < len(numbers); i++ {
        value, _ := strconv.Atoi(numbers[i])
        preCount := 0
        nexCount := 0
        if itemCount, ok := hashTable[value-1]; ok {
            preCount = itemCount
        }

        if itemCount, ok := hashTable[value+1]; ok {
            nexCount = itemCount
        }

        hashTable[value] = (preCount + 1 + nexCount)
        if ((preCount + 1 + nexCount) > maxCount) {
            maxCount = (preCount + 1 + nexCount)
        }
    }
    // 返回处理后的结果
    return strconv.Itoa(maxCount)
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}