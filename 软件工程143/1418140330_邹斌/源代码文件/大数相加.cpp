#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1024

char num1[N];
char num2[N];
int sum[N+500];

void reversed(char num[])
{
    int len,len1;
    len1 = strlen(num);
    len = int(len1/2);
    char tag;
    for(int i = 0; i < len; i++)
    {
        tag = num[i];
        num[i] = num[len1-i-1];
        num[len1-i-1] = tag;
    }
}

void reversed2(char num[],int len)
{
    int a = int(len/2);
    char tag;
    for(int i = 0; i < a;i++)
    {
        tag = num[i];
        num[i] = num[len-i-1];
        num[len-i-1] = tag;
    }
}


void reversed_Int(int num[],int cnt)
{
    int len,len1;
    len1 = cnt;
    len = int(len1/2);
    int tag;
    for(int i = 0; i < len; i++)
    {
        tag = num[i];
        num[i] = num[len1-i-1];
        num[len1-i-1] = tag;
    }
}

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for(int k = 1; k <= n;k++)
        {
            memset(num1,'0',sizeof(num1));
            memset(num2,'0',sizeof(num2));
            memset(sum,0,sizeof(sum));
            int tag,len1,len2;
            int cnt = 0;
            scanf("%s",num1);
            len1 = strlen(num1);
            reversed(num1);
            scanf("%s",num2);
            len2 = strlen(num2);
            reversed(num2);
            if(len1 < len2) tag = len2;
            else tag = len1;
            num1[len1] = '0';
            num2[len2] = '0';
            for(int i = 0; i < tag; i++)
            {
                if(sum[i]+int(num1[i]-'0')+int(num2[i]-'0') >= 10)
                {
                    if(sum[i]==0) cnt++;
                    sum[i]=sum[i]+int(num1[i]-'0')+int(num2[i]-'0')-10;
                    //cnt++;
                    sum[i+1]++;
                    cnt++;
                }
                else
                {
                    if(sum[i]==0) cnt++;
                    sum[i]=sum[i]+int(num1[i]-'0')+int(num2[i]-'0');
                    //cnt++;
                }
            }
            reversed_Int(sum,cnt);
            reversed2(num1,len1);
            reversed2(num2,len2);
            printf("Case %d:\n",k);
            for(int i = 0; i < len1-1; i++)
            {
                printf("%c",num1[i]);
            }
            printf("%c",num1[len1-1]);
            printf(" ");
            printf("+");
            printf(" ");
            for(int i = 0; i < len2-1; i++)
            {
                printf("%c",num2[i]);
            }
            printf("%c",num2[len2-1]);
            printf(" = ");
            for(int i = 0; i < cnt-1; i++)
            {
                printf("%d",sum[i]);
            }
            printf("%d\n",sum[cnt-1]);
            getchar();
        }
    }
    return 0;
}
