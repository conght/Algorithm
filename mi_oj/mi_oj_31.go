package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func solution(line string) string {
    // 在此处理单行数据
    N,_ := strconv.Atoi(line)

    sum := 0

    for i:=1;;i++ {
        if (N/i + 1 - i) <= 0 {
            break;
        }
        if N%i != 0 {
            continue
        }
        if N%2==0 && (N/i + 1 - i)%2 != 0 {
            sum += 1
            continue
        }

        sum+=1
        
    }
    // 返回处理后的结果
    return strconv.Itoa(sum)
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}