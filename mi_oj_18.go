package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "strconv"
    "sort"
)

type node struct {
    Height int
    K      int
}

type nodeArray []node

func (c nodeArray) Len() int {
    return len(c)
}
func (c nodeArray) Swap(i, j int) {
    c[i].Height, c[j].Height = c[j].Height, c[i].Height
    c[i].K, c[j].K = c[j].K, c[i].K
}
func (c nodeArray) Less(i, j int) bool {
    if (c[i].Height > c[j].Height) {
        return true
    }

    if (c[i].Height == c[j].Height && c[i].K < c[j].K) {
        return true
    }
    return false
}


func solution(line string) string {
    // 在此处理单行数据
    line = line[2:len(line)-2]

    arr := strings.Split(line, "],[")

    nArr := make(nodeArray, len(arr))
    for i:=0;i<len(arr);i++ {
        numbers := strings.Split(arr[i], ",")
        nArr[i].Height,_ = strconv.Atoi(numbers[0])
        nArr[i].K,_ = strconv.Atoi(numbers[1])
    }
    sort.Sort(nArr)
    //fmt.Println(nArr)

    for i:=0;i<len(nArr); {
        count:=0
        for j:=0;j<i;j++ {
            if (nArr[i].Height<=nArr[j].Height) {
                count++
            }
        }

        //fmt.Println(count)

        if (count!=nArr[i].K) {
            //nArr[i], nArr[nArr[i].K - count + i] = nArr[nArr[i].K - count + i], nArr[i]
            d:=i-count+nArr[i].K
            for j:=i;j>d;j-- {
                //fmt.Println(j,i,d,count)
                nArr[j], nArr[j-1] = nArr[j-1], nArr[j]
            }
        }  //else {
            i++
        //}
        //fmt.Println(nArr)
    }
    
    ret := []string{}
    // 返回处理后的结果
    for i:=0;i<len(nArr);i++ {
        ret = append(ret, "["+strconv.Itoa(nArr[i].Height)+","+strconv.Itoa(nArr[i].K)+"]")
    }
    return "["+strings.Join(ret, ",")+"]"
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}