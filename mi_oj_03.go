package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func solution(line string) string {
    // 在此处理单行数据
    
    var numbers = strings.Split(line, " - ")
    var strA = numbers[0]
    var strB = numbers[1]

    var lengthA = len(strA)
    var lengthB = len(strB)

    //fmt.Println("lengthA is ", lengthA)
    //fmt.Println("lengthB is ", lengthB)
 
    c:=0
    var result string
    iterB:=0

    for i:=lengthA; i>0; i-- {
        var a int
        var b int

        a = int(strA[i-1] - '0')

        b = 0
        //fmt.Println("iterB is", iterB)
        if (iterB < lengthB) {
            iterB = iterB + 1
            //fmt.Println("iterB is", iterB)
            b = int(strB[lengthB - iterB] - '0')
        }

        a = a + c

        if a < b {
            c = -1
            a = 10 + a
        } else {
            c = 0
        }
        //fmt.Println(i, a, b)
        if (!(i == 1 && a == b)) {
            result = strconv.Itoa(a-b) + result
        }
    }
    // 返回处理后的结果
    if (result[0] == '0') {
        result = result[1:]
    }
    return result
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}