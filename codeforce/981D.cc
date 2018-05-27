#include <iostream>
#include <vector>


using namespace std;

long long mysum(std::vector<long long>& a, int start, int end)
{
    long long ans = 0;
    for (int i=start;i<=end;i++)
        ans += a[i];
    return ans;
}


/*long long count_max_k_product(std::vector<long long>& a, int N, int K, std::vector<int>& index)
{
   //int i,j;
    //int k_max[N][K] ; //k_max[i][j]表示1 ~ i十进制位分成j段所得的最大乘积
    long long sum =0;
    //分成一段
    if (1 == K)
    {
        //cout << N << endl;
        sum = mysum(a,1,N);
        return sum;
    }

    //假设先从最后一个数划分开,然后再乘上前面的k-1个不同划分的积，
    //找最大值，然后从倒数第二个数划分开，然后再乘上前面k-2个不同划分的积，
    //找到最大值，与前一个最大值比较得到最大值，然后从倒数第三个划分开，一
    //次类推，直到倒数第I-(K-1)个数为止,

    for (int i = N; i >= K; i--)
    {
          //表示在第i-1个的数后面划分
        index[K-1] = i-1;
        long long temp = 0;
        temp = count_max_k_product(a,i-1,K-1, index) & mysum(a,i,N);
        cout << temp << endl;
        if (sum < temp)
        {
            index[K-1] = i-1;
            sum = temp;
        }
    }

    return sum;

}

void solution()
{
    int n,k;
    cin >> n;
    cin >>k;

    std::vector<long long> a(n+1);

    std::vector<int> index(n+1);
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }

    long long ans = count_max_k_product(a, n, k, index);
    cout << ans <<endl;

    for (int i=1;i<=n;i++) {
        cout << index[i]<<" ";
    }
    cout << endl;

}*/

int main()
{
    solution();
}


/*#define N 51
long long m[N][N];
long long num[N];

int atoi(char arr[],int i,int j)
{
    int sum=0;
    while(i<=j)
    {
        sum = sum*10+arr[i]-'0';  //此处本来用了函数pow，然后wa了，一直找不到错在何处，
        i++;        //后来问师兄，才发现原来pow(double,int)
    }           //的参数double会使结果又偏差，改掉后就ac了
    return sum;
}

long long mysum(std::vector<long long>& a, int start, int end)
{
     long long ans = 0;
     for (int i=start;i<=end;i++)
         ans += a[i];
     return ans;
}

int main()
{
    int n,k,i,j,l;
    long long max,flag;
    while(cin>>n>>k)
    {
        for(i=1;i<=n;i++)
            cin>>num[i];
        m[1][1]=num[1];
        for(i=2;i<=n;i++)
            m[i][1]=m[i-1][1]*10+(num[i]-'0'); //初始化第一列
        for(j=2;j<=k;j++)//按列进行初始化
        {
            max=-1;
            for(i=1;i<=n;i++)
            {
                if(j>i)
                    m[i][j]=0;
                else
                {
                    for(l=j-1;l<=i-1;l++)
                    {
                        flag=m[l][j-1]*atoi(num,l+1,i);
                        if(flag>max)
                        max=flag;
                    }
                    m[i][j]=max;
                }
            }
        }
        cout<<m[n][k]<<endl;
    }
    return 0;
}*/