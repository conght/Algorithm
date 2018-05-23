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
    numbers := strings.Split(line, ",")
    //A := Array[int]{}
    max := 0
    min := int(^uint(0) >> 1)
    sum := 0
    count := 0
    for i:=0; i<len(numbers); i++ {
        number, _ := strconv.Atoi(numbers[i])
        if (number > 0) {
            sum += number
            count ++
            if (max < number) {
                max = number
            }
            if (min > number) {
                min = number
            }
        }
    }

    if (count == 0) {
        return "1"
    }

    n_sum := (max-min+1) * (max+min) / 2

    if (n_sum == sum) {
        if (min > 1) {
            return strconv.Itoa(min - 1)
        } else {
            return strconv.Itoa(max + 1)
        }
    } else {
        return strconv.Itoa(n_sum - sum)
    }

}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}