inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}//如果输入
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();//输入数字并统计
   return s*w;//输出结果
}