#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
#define WIDTHBYTES(bits) (((bits)+31)/32*4)
typedef unsigned char BYTE;//字符型
typedef unsigned short WORD;//短整型
typedef unsigned long DWORD;//长整形
typedef long LONG;
//位图文件头信息结构定义
//其中不包含文件类型信息（由于结构体的内存结构决定，要是加了的话将不能正确读取文件信息）
typedef struct tagBITMAPFILEHEADER {
    //WORD bfType;
    DWORD bfSize; //文件大小
    WORD bfReserved1; //保留字，不考虑
    WORD bfReserved2; //保留字，同上
    DWORD bfOffBits; //实际位图数据的偏移字节数，即前三个部分长度之和
} BITMAPFILEHEADER;
//信息头BITMAPINFOHEADER，也是一个结构，其定义如下：
typedef struct tagBITMAPINFOHEADER{
    //public:
    DWORD biSize; //指定此结构体的长度，为40
    LONG biWidth; //位图宽
    LONG biHeight; //位图高
    WORD biPlanes; //平面数，为1
    WORD biBitCount; //采用颜色位数，可以是1，2，4，8，16，24，新的可以是32
    DWORD biCompression; //压缩方式，可以是0，1，2，其中0表示不压缩
    DWORD biSizeImage; //实际位图数据占用的字节数
    LONG biXPelsPerMeter; //X方向分辨率
    LONG biYPelsPerMeter; //Y方向分辨率
    DWORD biClrUsed; //使用的颜色数，如果为0，则表示默认值(2^颜色位数)
    DWORD biClrImportant; //重要颜色数，如果为0，则表示所有颜色都是重要的
} BITMAPINFOHEADER;
//调色板Palette，当然，这里是对那些需要调色板的位图文件而言的。24位和32位是不需要调色板的。
//（似乎是调色板结构体个数等于使用的颜色数。）
typedef struct tagRGBQUAD {
    //public:
    BYTE rgbBlue; //该颜色的蓝色分量
    BYTE rgbGreen; //该颜色的绿色分量
    BYTE rgbRed; //该颜色的红色分量
    BYTE rgbReserved; //保留值
} RGBQUAD;
void Rgb2Hsv(float R, float G, float B, float& H, float& S, float&V);
void showRgbQuan(tagRGBQUAD* pRGB)
{
    printf("(%-3d,%-3d,%-3d) ",pRGB->rgbRed,pRGB->rgbGreen,pRGB->rgbBlue);
    printf("hello");
}
int main(){
    char ch,pd;
    int b,c,m,d,w,e,f;
    int x,y;
    unsigned char *q;
    int i,j;
    unsigned char a[2];
    char strFile[50];
    BITMAPFILEHEADER bitHead;
    BITMAPINFOHEADER bitInfoHead;
    tagRGBQUAD *pRgb ;
    FILE *fp;
    FILE *p;
    q=(unsigned char*)malloc(1);
    printf("mkx**用C语言编程来读取BMP文件某一像素点的数据**/n请输入一个bmp文件:/n");
    scanf("%s",strFile);
    fp=fopen(strFile,"rb");
    
    if(fp!=NULL)
    {
        printf("file open success!/n");
        WORD fileType;
        fread(&fileType,1,sizeof(WORD),fp);
        if(fileType != 0x4d42)
        {
            printf("file is not .bmp file!");
            system("pause");
            return 0;
        }
    }
    else
    {
        printf("file open fail!/n");
        system("pause");
        return 0;
    }
    //读文件头信息，并打印文件头信息各项的值
    fread(&bitHead,1,sizeof(tagBITMAPFILEHEADER),fp);
    printf("bmp文件头信息/n文件大小:%d/n保留字:%d/n保留字:%d/n实际位图数据的偏移字节数:%d/n/n",
           bitHead.bfSize,bitHead.bfReserved1,bitHead.bfReserved2,bitHead.bfOffBits);
    //读文件信息头，并打印文件信息头各项的值
    fread(&bitInfoHead,1,sizeof(tagBITMAPINFOHEADER),fp);
    printf("bmp文件信息头/n结构体的长度:%d/n位图宽:%d/n位图高:%d/nbiPlanes平面数:%d/nbiBitCount采用颜色位数:%d/n压缩方式:%d/nbiSizeImage实际位图数据占用的字节数:%d/nX方向分辨率:%d/nY方向分辨率:%d/n使用的颜色数:%d/n重要颜色数:%d/n",
           bitInfoHead.biSize,bitInfoHead.biWidth,bitInfoHead.biHeight,bitInfoHead.biPlanes,bitInfoHead.biBitCount,bitInfoHead.biCompression,bitInfoHead.biSizeImage,bitInfoHead.biXPelsPerMeter,bitInfoHead.biYPelsPerMeter,bitInfoHead.biClrUsed,bitInfoHead.biClrImportant);
    if(bitInfoHead.biBitCount < 24){
        printf("该文件有调色板，即该位图为非真彩色/n/n");
        m=1;
        if(bitInfoHead.biBitCount =8){
            long nPlantNum = long(pow(2,double(bitInfoHead.biBitCount))); // Mix color Plant Number;
            pRgb=(tagRGBQUAD *)malloc(nPlantNum*sizeof(tagRGBQUAD));
            memset(pRgb,0,nPlantNum*sizeof(tagRGBQUAD));
            int num = fread(pRgb,4,nPlantNum,fp);
            printf("Color Plate Number: %d/n",nPlantNum);
            printf("颜色板信息:/n");
            for (int i =0; i<nPlantNum;i++)
            {
                if (i%5==0)
                {
                    printf("/n");
                }
                showRgbQuan(&pRgb[i]);
            }
            printf("/n");
        }
    }
    else{
        printf("该位图为24位真彩色/n/n");
        m=3;
    }
    
    fclose(fp);
    
    while(ch!='N'){
        p=fopen(strFile,"rb");
        ch=NULL;
        f=bitInfoHead.biHeight;
        e=bitInfoHead.biWidth;
        b=bitHead.bfOffBits;
        printf("**输入指定像素点的数据**(行：1~%d  列1~%d)/n",f,e);
        printf("请输入第i行：");
        scanf("%d",&x);
        printf("请输入第j列：");
        scanf("%d",&y);
        c=b+(x-1)*e*m+m*(y-1);
        fseek(p,c,0);
        //printf("%d/n",m);
        if(m<2){
            fread(&a[0],1,1,p);
            printf("该点像素点的数据(十六进制)为：%x    ",a[0]);
            printf("用十进制表示：%d/n",a[0]);
            d=a[0];
            printf("它对应的rgb值为：");
            BYTE tmp1=pRgb->rgbRed;
            BYTE tmp2=pRgb->rgbGreen;
            BYTE tmp3=pRgb->rgbBlue;
            showRgbQuan(&pRgb[d]);
            float H,S,V;
            Rgb2Hsv(tmp1, tmp2, tmp3, H, S, V);
            printf("%f",H);
            printf("/n");
            printf("%f",S);
            printf("/n");
            printf("&f",V);
            printf("/n");
        }
        else {
            for(i=0;i<3;i++){
                fread(&a[i],1,1,p);
                // printf("%x/n",a[i]);
            }
            printf("十六进制表示:/n蓝:%x/n绿:%x/n红:%x/n",a[0],a[1],a[2]);
            printf("十进制表示:/n蓝:%d/n绿:%d/n红:%d/n",a[0],a[1],a[2]);
        }
        
        rewind(p);
        //w=ftell(p);
        //printf("%d",w);
        fclose(p);
        printf("**继续请输入任意字符，如需退出请输入N/n");
        getchar();
        scanf("%c",&ch);
    }
    printf("感谢您使用~/n");
    system("pause");
    return 0;
}

void Rgb2Hsv(float R, float G, float B, float& H, float& S, float&V)
{
    // r,g,b values are from 0 to 1
    // h = [0,360], s = [0,1], v = [0,1]
    // if s == 0, then h = -1 (undefined)
    float min, max, delta,tmp;
    tmp = R>G?G:R;
    min = tmp>B?B:tmp;
    tmp = R>G?R:G;
    max = tmp>B?tmp:B;
    V = max; // v
    delta = max - min;
    if( max != 0 )
        S = delta / max; // s
    else
    {
        // r = g = b = 0 // s = 0, v is undefined
        S = 0;
        H = 0;
        return;
    }
    if (delta == 0){
        H = 0;
        return;
    }
    else if(R == max){
        if (G >= B)
            H = (G - B) / delta; // between yellow & magenta
        else
            H = (G - B) / delta + 6.0;
    }
    else if( G == max )
        H = 2.0 + ( B - R ) / delta; // between cyan & yellow
    else if (B == max)
        H = 4.0 + ( R - G ) / delta; // between magenta & cyan
    H *= 60.0; // degrees
}
