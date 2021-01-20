#include <iostream>
#include <cstdio>
#include <time.h>

#define BST (+1)//倫敦
#define CCT (+8)//台灣

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
    typedef long time_t; //時間值
    #define _TIME_T_DEFINED
    #endif
    */

    struct tm *tm_time;
    /*
	int tm_sec;  //秒，正常範圍0-59， 但允許至61
	int tm_min;  //分鐘，0-59
	int tm_hour; //小時， 0-23
	int tm_mday; //日，即一個月中的第幾天，1-31
	int tm_mon;  //月， 從一月算起，0-11 1+p->tm_mon;
	int tm_year; //年， 從1900至今已經多少年 1900＋ p->tm_year;
	int tm_wday; //星期，一週中的第幾天， 從星期日算起，0-6
	int tm_yday; //從今年1月1日到目前的天數，範圍0-365
	int tm_isdst;//日光節約時間的旗標
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
