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

    delta := 0
    dtime := strings.Split(line, ":")
    day,_ := strconv.Atoi(strings.Split(dtime[0],"d")[0])
    hour,_ := strconv.Atoi(strings.Split(dtime[0],"d")[1])
    min,_ := strconv.Atoi(dtime[1])
    sec,_ := strconv.Atoi(dtime[2])

    delta += day * 24

    //fmt.Println(day)
    //fmt.Println(hour)
    //fmt.Println(min)
    //fmt.Println(sec)
    if (hour > min) {
        delta+= hour
    } else if (hour == min) {
        if (sec == 59) {
            delta += (hour + 1)
        } else {
            delta += hour
        }
    } else {
        delta += (hour + 1)
    }

    //fmt.Println(delta)

    dday := delta / (24*3600)
    delta = delta % (24*3600)
    dhour := delta / 3600
    delta = delta % 3600
    dmin := delta / 60
    delta = delta % 60
    dsec := delta

    //fmt.Println(dday)
    //fmt.Println(dhour)
    //fmt.Println(dmin)
    //fmt.Println(dsec)

    sec = sec - dsec
    if (sec < 0) {
        sec += 60
        dmin += 1
    }
    min = min - dmin
    if (min < 0) {
        min += 60
        dhour += 1
    }
    hour = hour - dhour
    if (hour < 0) {
        hour += 24
        dday += 1
    }
    day = day - dday

    ret := ""

    ret += strconv.Itoa(day)
    ret += "d"
    if (hour < 10) {
        ret += "0"
    }

    ret += strconv.Itoa(hour)
    ret += ":"
    if (min < 10) {
        ret += "0"
    }
    ret += strconv.Itoa(min)
    ret += ":"
    if (sec < 10) {
        ret += "0"
    }
    ret += strconv.Itoa(sec)
    // 返回处理后的结果
    return ret
}

func main() {
    r := bufio.NewReader(os.Stdin)
    for line, _, err := r.ReadLine(); err == nil; line, _, err = r.ReadLine() {
        fmt.Println(solution(string(line)))
    }
}