package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "strconv"
    "container/heap"
    "sort"
)

type Node struct {
    Key        string
    Count      int
}

type IntHeap []Node 
type IntHeapPtr []*Node 
type StrArray []string

func (h StrArray) Len() int           { return len(h) }  
func (h StrArray) Less(i, j int) bool { return h[i] < h[j] }  
func (h StrArray) Swap(i, j int)      { 
    h[i], h[j] = h[j], h[i]
} 

func (h IntHeap) Len() int           { return len(h) }  
func (h IntHeap) Less(i, j int) bool { return h[i].Count < h[j].Count }  
func (h IntHeap) Swap(i, j int)      { 
    h[i].Key, h[j].Key = h[j].Key, h[i].Key
    h[i].Count, h[j].Count = h[j].Count, h[i].Count 
} 

func (h *IntHeap) Push(x interface{}) {  
    // Push and Pop use pointer receivers because they modify the slice's length,  
    // not just its contents.  
    *h = append(*h, x.(Node))  
}  
  
func (h *IntHeap) Pop() interface{} {  
    old := *h  
    n := len(old)  
    x := old[n-1]  
    *h = old[0 : n-1]  
    return x
}  

func solution(line string) string {
    // 在此处理单行数据
    items := strings.Split(line, " ")
    numbers := strings.Split(items[0], ",")
    k, _ := strconv.Atoi(items[1])

    hashMap := make(map[string]int)
    for i:=0;i<len(numbers);i++ {
        if itemCount, ok := hashMap[numbers[i]]; ok {
            hashMap[numbers[i]] = itemCount + 1
        } else {
            hashMap[numbers[i]] = 1
        }
    }
    
    var h IntHeap
    for key, count := range hashMap {
        var node Node
        node.Key = key
        node.Count = count
        h = append(h, node)
    }

    heap.Init(&h)

    for i:=0;i<len(h)-k;i++ {
        heap.Pop(&h)
    }

    var retArray StrArray

    for i:=0;i<len(h);i++ {
        retArray = append(retArray, h[i].Key)
    }
    sort.Sort(retArray)


    // 返回处理后的结果
    return strings.Join(retArray, ",")
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}