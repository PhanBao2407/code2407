/*Câu 1:*/
#include <stdio.h>
int main() {
    int month, year, last_day;
    printf("Nhap thang: ");
    scanf("%d", &month);
    printf("Nhap nam: ");
    scanf("%d", &year);
    switch(month) {
        case 1:
        case 3:
        case 5:
        case 8:
        case 10:
        case 12:
            last_day = 31;
            break;
        case 4:
        case 6: 
        case 9:
        case 11:
            last_day = 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                last_day = 29;
            else
                last_day = 28;
            break;
        default:
            printf("Thang khong hop le\n");
            return 1;
    }
    printf("Thang %d nam %d co %d ngay.\n", month, year, last_day);
    return 0;
}
/*Câu 2:*/
//Loop:
#include <stdio.h>
int main()
{
    int giaithua=7;
    for(int i=6;i>0;i--)
    {
        giaithua*=i;
    }
    printf("%d",giaithua);
    return 0;
}
//Goto Label:
#include <stdio.h>
int main()
{
    int i=1,giaithua=1;
    meomeo:
    giaithua*=i;
    i++;
    if(i<=7)
    {
        goto meomeo;
    }
    printf("%d",giaithua);
    return 0;
}
/*Câu 3:*/
#include <stdio.h>
int main()
{
    int a,b;
    printf("Nhap gia tri cua a:\n");
    scanf("%d",&a);
    printf("Nhap gia tri cua b:\n");
    scanf("%d",&b);
    if(a>b)
    {
        printf("a lon hon b");
    }
    else
    {
        printf("b lon hon a");
    }
    return 0;
}
/*Câu 4:*/
#include <stdio.h>
int main()
{
    int a,b,c;
    printf("Nhap lan luot cac gia tri cua bien a,b,c:\n");
    scanf("%d%d%d",&a,&b,&c);
    if(a>=b&&a>=c)
    {
        printf("a la so lon nhat");
    }
    else if(b>=a&&b>=c)
    {
        printf("b la so lon nhat");
    }
    else
    {
        printf("c la so lon nhat");
    }
    return 0;
}
/*Câu 5:*/
#include <stdio.h>
int main()
{
    int A;
    printf("Nhap gia tri cua A:\n");
    scanf("%d",&A);
    (A%2==0) ? printf("A la so chan.") : printf("A la so le.");
}
/*Câu 6:*/
#include <stdio.h>
int main()
{
    int year;
    printf("Nhap nam can kiem tra:\n");
    scanf("%d",&year);
    if(year%4==0)
    {
        if(year%100!=0)
        {
            printf("Nam nhuan");
        }
        else if(year%400==0)
        {
            printf("Nam nhuan");
        }
        else
        {
            printf("Nam khong nhuan");
        }
    }
    else
    {
        printf("Nam khong nhuan");
    }
    return 0;
}
/*Câu 7:*/
#include <stdio.h>
int main()
{
    int a,b,c;
    printf("Nhap gia tri cua a:\n");
    scanf("%d",&a);
    printf("Nhap gia tri cua b:\n");
    scanf("%d",&b);
    c=a+b;
    b=b+c;
    a=b-c;
    b=c-a;
    printf("Gia tri cua a sau khi trao doi la: %d\n",a);
    printf("Gia tri cua b sau khi trao doi la: %d",b);
    return 0;
}
/*Câu 8:*/
#include <stdio.h>
int main()
{
    int a,b;
    printf("Nhap gia tri cua a:\n");
    scanf("%d",&a);
    printf("Nhap gia tri cua b:\n");
    scanf("%d",&b);
    b=a+b;
    a=b-a;
    b=b-a;
    printf("Gia tri cua a sau khi trao doi la: %d\n",a);
    printf("Gia tri cua b sau khi trao doi la: %d",b);
    return 0;
}
/*Câu 9:*/
#include <stdio.h>
int main() {
    int consumption_kwh;
    long long consumption_fee;
    printf("Nhap kwh tieu thu trong thang: ");
    scanf("%d", &consumption_kwh);
    if (consumption_kwh <= 100)
    {
        consumption_fee = consumption_kwh * 600;
    }
    else if (consumption_kwh <= 150)
    {
        consumption_fee = 100 * 600 + (consumption_kwh - 100) * 900;
    }
    else if (consumption_kwh <= 250)
    {
        consumption_fee = 100 * 600 + 50 * 900 + (consumption_kwh - 150) * 1200;
    }
    else
    {
        consumption_fee = 100 * 600 + 50 * 900 + 100 * 1200 + (consumption_kwh - 250) * 1500;
    }
    printf("Phi tieu thu dien %d kWh: %lld VND\n", consumption_kwh, consumption_fee);
    return 0;
}
/*Câu 10:*/
#include <stdio.h>
struct Date
{
    int day;
    int month;
    int year;
};
int calculate_difference(struct Date date1, struct Date date2)
{
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (date2.year % 4 == 0 && (date2.year % 100 != 0 || date2.year % 400 == 0))
    {
        days_in_month[1] = 29;
    }
    int total_days1 = date1.day;
    for (int i = 0; i < date1.month - 1; i++)
    {
        total_days1 += days_in_month[i];
    }
    total_days1 += date1.year * 365;
    int total_days2 = date2.day;
    for (int i = 0; i < date2.month - 1; i++)
    {
        total_days2 += days_in_month[i];
    }
    total_days2 += date2.year * 365;
    return total_days2 - total_days1;
}
int main()
{
    struct Date date1, date2;
    printf("Enter date 1 (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &date1.day, &date1.month, &date1.year);
    printf("Enter date 2 (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &date2.day, &date2.month, &date2.year);
    int difference = calculate_difference(date1, date2);
    printf("Difference in days: %d\n", difference);
    return 0;
}