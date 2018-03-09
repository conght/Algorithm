package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "strconv"
    "sort"
)

var result [][]int

func myfunc(numbers *[]int, left int, sum int, start int, cos *[]int) int {
    if (left == 0) {
        if (sum == 0) {
            sort.Ints(*cos)

            var k int
            //fmt.Println(*cos)
            old := []int{(*cos)[0],(*cos)[1],(*cos)[2]}
            for k=0;k<len(result);k++ {
                //fmt.Println(result[k])
                if (result[k][0] == (*cos)[0] && result[k][1] == (*cos)[1] && result[k][2] == (*cos)[2]) {
                    break
                }
            }

            //fmt.Println(k, len(result))
            //fmt.Println(*cos)
            //fmt.Println(result)
            if (k == len(result)) {
                result = append(result, old)
                //fmt.Println(result)
                return 1
            } else {
                return 0
            }
        } else {
            return 0
        }
    }

    ret := 0

    for i:=start;i<len(*numbers)-left+1;i++ {
        sum += (*numbers)[i]
        *cos = append(*cos, (*numbers)[i])
        ret += myfunc(numbers, left -1 , sum, i+1, cos)
        sum -= (*numbers)[i]
        old := *cos  
        n := len(old)   
        *cos = old[0 : n-1]
    }

    return ret
}

func solution(line string) string {
    // 在此处理单行数据
    
    items := strings.Split(line, ",")
    numbers := make([]int, len(items))
    
    for i:=0;i<len(items);i++ {
        numbers[i] , _ = strconv.Atoi(items[i])
    }

    // 返回处理后的结果
    cos := []int{}
    return strconv.Itoa(myfunc(&numbers, 3, 0, 0, &cos))
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}