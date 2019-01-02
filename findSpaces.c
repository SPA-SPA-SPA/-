#include <stdio.h>
#include <stdlib.h>
//统计文件中字符串的空格个数
int main(int argc, char *argv[])    //main需要加参数
{
    int totalsum = 0;
    int sum = 0;
    char ch;
    FILE *fp;   //声明文件指针

    if((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Error: Can't open file.\n");
        exit(EXIT_FAILURE);
    }
    ch = getc(fp);              //获取初始输入
    while(ch != EOF)            //如果文件不为空，则进入循环
    {
        //处理输入字符
        if(ch == ' ')   //如果是空格sum就加1
        {
            sum += 1;
        }
        else if(ch == '\n')     //遇到换行符，将其视作一个字符串的结束
        {
            printf("\t sum: %d", sum);
            totalsum += sum;
            sum = 0;
        }

        printf("%c", ch);   //打印字符
        ch = getc(fp);      //获取下一个输入
        if(ch == EOF && sum != 0)      //如果遇到文件结尾后，且sum没清零，则意味着sum未被统计
        {
            printf("\t sum: %d", sum);
            totalsum += sum;
            sum = 0;
        }
    }

    printf("\nTotalsum: %d", totalsum);     //打印字符空格总数totalsum

    if(fclose(fp) != 0)     //关闭文件
    {
        printf("Error in closing file %s\n", argv[1]);
    }

    printf("\n按任意键结束...");
    getchar();      //暂停，任意键退出
return 0;
}
