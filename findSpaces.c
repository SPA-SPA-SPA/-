#include <stdio.h>
#include <stdlib.h>
//ͳ���ļ����ַ����Ŀո����
int main(int argc, char *argv[])    //main��Ҫ�Ӳ���
{
    int totalsum = 0;
    int sum = 0;
    char ch;
    FILE *fp;   //�����ļ�ָ��

    if((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Error: Can't open file.\n");
        exit(EXIT_FAILURE);
    }
    ch = getc(fp);              //��ȡ��ʼ����
    while(ch != EOF)            //����ļ���Ϊ�գ������ѭ��
    {
        //���������ַ�
        if(ch == ' ')   //����ǿո�sum�ͼ�1
        {
            sum += 1;
        }
        else if(ch == '\n')     //�������з�����������һ���ַ����Ľ���
        {
            printf("\t sum: %d", sum);
            totalsum += sum;
            sum = 0;
        }

        printf("%c", ch);   //��ӡ�ַ�
        ch = getc(fp);      //��ȡ��һ������
        if(ch == EOF && sum != 0)      //��������ļ���β����sumû���㣬����ζ��sumδ��ͳ��
        {
            printf("\t sum: %d", sum);
            totalsum += sum;
            sum = 0;
        }
    }

    printf("\nTotalsum: %d", totalsum);     //��ӡ�ַ��ո�����totalsum

    if(fclose(fp) != 0)     //�ر��ļ�
    {
        printf("Error in closing file %s\n", argv[1]);
    }

    printf("\n�����������...");
    getchar();      //��ͣ��������˳�
return 0;
}
