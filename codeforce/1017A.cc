#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _student
{
    int id;
    int sum;
} student;

bool compare(student a, student b) {
    if (a.sum > b.sum)
        return true;
    else if (a.sum == b.sum) {
        if (a.id < b.id)
            return true;
    }
    return false;
}

int main() {

    int n = 0;
    vector<student> students;
    cin >> n;

    int id = 1;
    int num = n;
    while (n--) {
        student item;
        item.id = id++;
        item.sum = 0;
        int score = 0;
        for (int i=0;i<4;i++) {
            cin >> score;
            item.sum += score;
        }
        students.push_back(item);
    }

    sort(students.begin(), students.end(), compare);

    int i=0;
    for (;i<num;i++) {
        if (students[i].id == 1)
            break;
    }

    cout << i+1;
}