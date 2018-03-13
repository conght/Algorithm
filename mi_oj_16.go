package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "container/list"
    "strconv"
)

type Stack struct {
     list *list.List
 }
 
 func NewStack() *Stack {
     list := list.New()
     return &Stack{list}
 }
 
 func (stack *Stack) Push(value interface{}) {
     stack.list.PushBack(value)
 }
 
 func (stack *Stack) Pop() interface{} {
     e := stack.list.Back()
     if e != nil {
         stack.list.Remove(e)
         return e.Value
     }
     return nil
 }
 
 func (stack *Stack) Peak() interface{} {
     e := stack.list.Back()
     if e != nil {
         return e.Value
     }
 
     return nil
 }
 
 func (stack *Stack) Len() int {
     return stack.list.Len()
 }
 
 func (stack *Stack) Empty() bool {
     return stack.list.Len() == 0
 }

func isOperator(oper string) bool {
    if (oper == "+" || oper == "-" || oper == "*" || oper == "/") {
        return true
    }
    return false
}

func isMutliOrDivision(oper string) bool {
    if (oper == "*" || oper == "/") {
        return true
    }
    return false
}

func solution(line string) string {
    // 在此处理单行数据
    
    items := strings.Split(line, " ")

    backOrder := []string{}

    stack1 := NewStack()
    for i:=0;i<len(items);i++ {
        if !isOperator(items[i]) {
            backOrder = append(backOrder, items[i])
        } else {
            if (stack1.Len() == 0) {
                stack1.Push(items[i])
            } else {
                if (isMutliOrDivision(items[i])) {
                    for ;stack1.Len() != 0; {
                        value := stack1.Peak().(string)
                        if (!isMutliOrDivision(value)) {
                            break;
                        } else {
                            backOrder = append(backOrder, value)
                            _ = stack1.Pop().(string)
                        }
                    }
                    stack1.Push(items[i])
                    
                } else {
                    for ;stack1.Len() != 0; {
                        value := stack1.Pop().(string)
                        backOrder = append(backOrder, value) 
                    }
                    stack1.Push(items[i])
                }
            }
        }
    }
    for ;stack1.Len() != 0; {
        value := stack1.Pop().(string)
        backOrder = append(backOrder, value)    
    }
    // 返回处理后的结果
    fmt.Println(backOrder)
    stack2 := NewStack()
    for i:=0;i<len(backOrder);i++ {
        if !isOperator(backOrder[i]) {
            stack2.Push(backOrder[i])
        } else {
            a,_ := strconv.Atoi(stack2.Pop().(string))
            b,_ := strconv.Atoi(stack2.Pop().(string))
            c := 0
            if (backOrder[i] == "+") {
                c = b + a
            }
            if (backOrder[i] == "-") {
                c = b - a
            }
            if (backOrder[i] == "*") {
                c = b * a
            }
            if (backOrder[i] == "/") {
                if (a == 0) {
                    return "err"
                }
                c = b / a
            }
            stack2.Push(strconv.Itoa(c))
        }
    }
    return stack2.Pop().(string)
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}