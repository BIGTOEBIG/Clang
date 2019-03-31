#include <stdio.h>
#define PRINT printf("宏打印输出\n")
#define IN 1
#define OUT 0
/**/
int disp_num(char c , unsigned int num);
int get_line(char *s,int lim);
void copy(char *to, char *from);
int main() { /* main function */
    //char *s="1000022\n";/*字符串中也可以包括转义字符*/
    char *s="1000022\n1202233\n\0";/*字符串中也可以包括转义字符*/
    char a[30],am[30];
    char cc;
    int nc,nl,nw,ndig,status;
    int nd[10];
    int ind = 0;
    // main part
    puts("Hello, world!");// no need to add \n
    puts("================================");
    puts("打印一些类型的size:");
    printf("\tsize of float\t= %lu\n",sizeof(float));
    printf("\tsize of double\t= %lu\n",sizeof(double));
    printf("\tsize of short\t= %lx\n",sizeof(short));
    printf("\tsize of int\t= %lu\n",sizeof(int));
    printf("\tsize of long\t= %lo\n",sizeof(long));
    
    puts("================================");
    puts("格式化输出测试:");
    printf("6700009/3\t= %6.3f\t\n",6700009.0/3.0);
    printf("1/7\t\t= %6.3f\t\n",1.0/7.0);
    printf("1/1\t\t= %6.1f\t\n",1.0/1.0);

    puts("================================");
    puts("字符串测试:");
    printf("Please input contents of string a:(no more than 29 chars)\n\ta = ");
    //gets(a);//it is not supported by gcc
    //gets_s(a);// it is not supported by gcc
    fgets(a,25,stdin);/*结尾的回车换行也被输入进去了*/
    printf("\tarray string a = %10s\t\tsizeof a = %lu\n",a,sizeof(a));//数组的大小为数组的长度
    printf("\tconst string s = %10s\t\tsizeof s = %lu\n",s,sizeof(s));//指针的size为指针的大小（8）
    s=a;
    puts("after assign a to s:");
    printf("\tconst string s = %15s\t\tsizeof s = %lu\n",s,sizeof(s));
    printf("EOF\t=%d\n",EOF);

    puts("================================");
    nc=nw=nl=ndig=0;
    while((ind++)<10)
        nd[ind-1]=0;
    status=OUT;
    puts("字符检测，请输入一些字符:(Ctrl+D结束)");
    while( (cc=getchar()) != EOF ){
        ++nc;
        if(cc>='0' && cc<='9'){
            ndig++;
            nd[cc-'0']++;
        }
        if (cc == '\n')
            ++nl;
        if(( cc == ' ') || (cc == '\n') || (cc == '\t'))
            status = OUT;
        else if (status == OUT){
            status = IN;
            ++nw;
        }
    }
    printf("Nline = %d\tNword = %d\tNchar=%d\n",nl,nw,nc);
    ind=0;
    while(ind++<10){
        printf("num of dig %d:",ind-1);
        disp_num('*',(unsigned int)(nd[ind-1]*50/ndig));
    }
    puts("================================");
    puts("宏测试:");
    PRINT;
    
    puts("================================");
    puts("please input some lines:");
    nl=0;
    //for (ind=0; ind<4; ++ind){
    while((nc=get_line(a,30)) > 0 ){
        printf("number of char :%d \n", nc);
        if(nc>nl){
            nl = nc;
  //          copy(am,a);
        }
    }
    puts("The longest line is :");
    puts(am);
    return 0;
}

int disp_num(char c,unsigned int num){
    unsigned int i;
    for (i=0;i<num;i=i+1){
        printf("%c",c);
    }
    printf("\n");
    return 0;
}

int get_line(char * s,int lim){
    char c;
    int i;
    for (i=0; i<lim-1 && ((c=getchar()!='\0') && c!='\n') ; ++i)
        s[i]=c;
    if(c=='\n'){
        s[i]=c;
        ++i;
    }
    s[i]='\0';
    return i;
}
void copy(char *to, char *from){
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0');
        ++i;
}
