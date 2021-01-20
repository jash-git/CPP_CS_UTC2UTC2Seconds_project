#include <iostream>
#include <cstdio>
#include <time.h>

#define BST (+1)//�۴�
#define CCT (+8)//�x�W

using namespace std;

void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
    time_t rawtime;
    /*
    #ifndef _TIME_T_DEFINED
    typedef long time_t; //�ɶ���
    #define _TIME_T_DEFINED
    #endif
    */

    struct tm *tm_time;
    /*
	int tm_sec;  //��A���`�d��0-59�A �����\��61
	int tm_min;  //�����A0-59
	int tm_hour; //�p�ɡA 0-23
	int tm_mday; //��A�Y�@�Ӥ뤤���ĴX�ѡA1-31
	int tm_mon;  //��A �q�@���_�A0-11 1+p->tm_mon;
	int tm_year; //�~�A �q1900�ܤ��w�g�h�֦~ 1900�� p->tm_year;
	int tm_wday; //�P���A�@�g�����ĴX�ѡA �q�P�����_�A0-6
	int tm_yday; //�q���~1��1���ثe���ѼơA�d��0-365
	int tm_isdst;//����`���ɶ����X��
    */

    int64_t lngNowTimeSeconds,lngNowTimeMilliseconds;
    char chrDateTimeBuf[80];
    rawtime = time(NULL);
    tm_time = gmtime(&rawtime);
    lngNowTimeSeconds= mktime(tm_time);//Seconds
    lngNowTimeMilliseconds = (lngNowTimeSeconds * 1000) + (clock()%1000);//Milliseconds
    sprintf(chrDateTimeBuf,"%d/%02d/%02d %02d:%02d:%02d",1900+tm_time->tm_year,tm_time->tm_mon+1,tm_time->tm_mday,(tm_time->tm_hour+CCT), tm_time->tm_min,tm_time->tm_sec);

    printf("%s --> Unix Seconds_00: %lld\n", chrDateTimeBuf, rawtime);//Equal to C#
    printf("%s --> Unix Milliseconds_00: %lld\n", chrDateTimeBuf, (rawtime*1000)+((clock()%1000)));//Equal to C#
    printf("\n");
    printf("%s --> Unix Seconds_01: %lld\n", chrDateTimeBuf, lngNowTimeSeconds);//Equal to C#+200
    printf("%s --> Unix Milliseconds_01: %lld\n", chrDateTimeBuf, lngNowTimeMilliseconds);
    Pause();
    return 0;
}
