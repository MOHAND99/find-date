#include <stdio.h>
#include <stdlib.h>
#define TYPE unsigned int /// i like working using short
#define L_FEB 29
#define NOT_L_FEB 28

char isLeap(TYPE y){return ((!(y%4)&&(y%100))||(!(y%100)&&!(y%400)));}
enum months {jan=1,feb=2,mar=3,apr=4,may=5,june=6,july=7,aug=8,sep=9,oct=10,nov=11,dec=12};
char getFebL(TYPE year){
    if(isLeap(year)) return L_FEB;
    return NOT_L_FEB;
}


TYPE* find_date(int day_year, int year){
    TYPE *date=malloc(2*sizeof(TYPE));
    *date = (TYPE)day_year;
    /// months last days
    const char janLDay=31;
    TYPE febLDay,marLDay,aprLDay,mayLDay,juneLDay,julyLDay,augLDay,sepLDay,octLDay,novLDay,decLDay;
    febLDay=getFebL(year)+janLDay;marLDay=febLDay+31;aprLDay=marLDay+30;
    mayLDay=aprLDay+31;juneLDay=mayLDay+30;julyLDay=juneLDay+31;
    augLDay=julyLDay+31;sepLDay=augLDay+30;octLDay=sepLDay+31;
    novLDay=octLDay+30;decLDay=novLDay+31;

    if(*date<=janLDay)       *(date+1)=jan;
    else if(*date<=febLDay)  {*date-=janLDay;*(date+1)=feb;}
    else if(*date<=marLDay)  {*date-=febLDay;*(date+1)=mar;}
    else if(*date<=aprLDay)  {*date-=marLDay;*(date+1)=apr;}
    else if(*date<=mayLDay)  {*date-=aprLDay;*(date+1)=may;}
    else if(*date<=juneLDay) {*date-=mayLDay;*(date+1)=june;}
    else if(*date<=julyLDay) {*date-=juneLDay;*(date+1)=july;}
    else if(*date<=augLDay)  {*date-=julyLDay;*(date+1)=aug;}
    else if(*date<=sepLDay)  {*date-=augLDay;*(date+1)=sep;}
    else if(*date<=octLDay)  {*date-=sepLDay;*(date+1)=oct;}
    else if(*date<=novLDay)  {*date-=octLDay;*(date+1)=nov;}
    else if(*date<=decLDay)  {*date-=novLDay;*(date+1)=dec;}
    return date;
}

int main()
{
    TYPE * date;int day_year, year;
    printf("Enter day number and year :\n");
    scanf("%d%d", &day_year, &year);
    date = find_date(day_year, year);
    printf("Date : %d/%d/%d\n", *date, *(date+1), year);
    free(date);
    return 0;
}
