package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "strconv"
)

type Item struct {
    Value string
    Index int
    Flag  int
}

func solution(line string) string {
    // 在此处理单行数据
    arr := strings.Split(line, " ")
    arrA := strings.Split(arr[0], ",")
    arrB := strings.Split(arr[1], ",")
    N,_ := strconv.Atoi(arr[2])

    lenA := len(arrA)
    lenB := len(arrB)

    ret := make([]Item, N)
    pA := 0
    pB := 0
    pR := -1

    for {
        if (pA == lenA && pB == lenB) {
            break
        }
        var curr = Item{"",0,0}
        if (pA == lenA) {
            curr.Value = arrB[pB]
            curr.Flag = 1
            curr.Index = pB
            pB += 1
        } else if (pB == lenB) {
            curr.Value = arrA[pA]
            curr.Flag = 0
            curr.Index = pA
            pA += 1
        } else {
            if (arrA[pA] < arrB[pB]) {
                curr.Value = arrB[pB]
                curr.Flag = 1
                curr.Index = pB
                pB += 1
            } else {
                curr.Value = arrA[pA]
                curr.Flag = 0
                curr.Index = pA
                pA += 1
            }
        }

        left := 0//(lenA-pA) + (lenB - pB) + 1
        index := 0
        for ;index<pR+1;index++ {
            if (curr.Value > ret[index].Value) {
                if ret[index].Flag == 0 {
                    if ret[index].Flag == curr.Flag {
                        left = (lenA-pA-1) + (lenB - pB)
                    } else {
                        left = (lenA-ret[index].Index) + (lenB - pB)
                    }
                     
                } else {
                    if ret[index].Flag == curr.Flag {
                        left = (lenA-pA) + (lenB - pB-1)
                    } else {
                        left = (lenB-ret[index].Index) + (lenA - pA)
                    }
                }
                fmt.Println(ret, curr, ret[index], left, N-index-1, index, pR)
                if ret[index].Flag != curr.Flag && pR > index {
                    if (ret[index].Flag == 0) {
                        pA = ret[index].Index
                    } else {
                        pB = ret[index].Index
                    }
                    
                }
                if (left >= (N-index-1)) {
                    ret[index] = curr
                    //fmt.Println(ret)
                    //fmt.Println(curr, ret[index], left, N-index-1, index, pR)
                    pR = index
                    break
                }       
            }
        }
        fmt.Println(ret, curr, ret[index], left, N-index-1, index, pR)
        if (index == pR + 1 && index < N) {
            ret[index] = curr
            //fmt.Println(ret)
            //fmt.Println(curr, ret[index], left, N-index-1, index, pR)
            pR = index
        }
        //
    }
    
    retStr := make([]string, N)
    for i:=0;i<N;i++ {
        retStr[i] = ret[i].Value
    }
    // 返回处理后的结果
    return strings.Join(retStr, "")
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}