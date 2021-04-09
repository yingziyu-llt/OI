#include"MD5.h"
using namespace std;
unsigned char encrypt[1024];//原文 
unsigned char decrypt[16];//md5值 
int main()
{
    MD5_CTX md5;
    gets((char *)encrypt);
    MD5Init(&md5);
    MD5Update(&md5,encrypt,(int)strlen((char *)encrypt));
    MD5Final(&md5,decrypt);
    bool bk=true;
    for(int j=0;j<16;j++){
        printf("%02x",decrypt[j]);
    }
    printf("\n");//输出 
    return 0;
}
