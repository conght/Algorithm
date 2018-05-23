// # 描述
// # 市政府想在毛纺路建一些基站，保证每个公司的员工都能享受到 Wifi。
// # 为了简化问题，我们将毛纺路理解成一条直线，一个 Wifi 基站为直线上的一个点。
// # 基站的费用为 A + k*B，其中A为建立基站的固定费用，B 为覆盖每单位距离需要的费用，k 为覆盖半径。
// # 如果在 a 点建立基站，覆盖半径为 k，那么位于 [a-k, a+k] 的公司都能享受到这个基站的服务。

// # 现在给出每个公司的坐标，以及 A 和 B，求覆盖到所有公司需要的最小建设费用。

// # 输入
// # 前两个整数是 A 和 B，然后是一个分号，然后是每个公司的坐标。（1 <= A, B <= 1000，0 <= 公司坐标 <= 1,000,000，坐标都为整数，公司数量 <= 2000）

// # 输出
// # 一个浮点，表示最小建设费用，四舍五入到小数点后一位

// # 输入样例
// # 20 5;100 0 7

// # 输出样例
// # 57.5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>


#define NMAX 10000

int cmp(const void *a, const void *b) {
    int lhs = *(const int*)a;
    int rhs = *(const int*)b;
    return (lhs > rhs) - (lhs < rhs);
}

/**
 * @param  char*  单行测试数据
 */
void solution(char *line)
{
    // 在此处理单行测试数据
    int C[NMAX];
    double A,B;
    int offset = 0;
	sscanf(line, "%lf %lf;%n", &A, &B, &offset);
	line += offset;

	int n = 0;
	while( sscanf(line, "%d%n", &C[n++], &offset) == 1) {
		line += offset;
	}

	n--;

	qsort(C, n, sizeof(n), cmp);

	double f[NMAX] = {0};
	int i=0;
	for (;i<n;i++) {
		f[i] = (C[i]-C[0])*B/2+A;
		int j=0;
		for (;j<i;j++) {
			if (f[i]> f[j]+(C[i]-C[j+1])*B/2+A) {
				f[i] = f[j]+(C[i]-C[j+1])*B/2+A;
			}
		}
	}
    // 打印处理结果
    printf("%.1lf\n", f[n-1]);
}

int main() {
	solution("20 5;100 0 7");
}