//Câu 1: Sự khác nhau giữa #include <...> và #include "header file" là:
/*
#include <...>: Khi khai báo header file(.h) nó chỉ tìm kiếm header file(.h)
có trong thư viện chuẩn của C.
#include "...": Nó sẽ tìm kiếm header file(.h) của người dùng tạo ra trước
sau đó nếu không có thì nó sẽ sử dụng header file(.h) trong thư viện chuẩn của C.
*/

//Câu 2: Khai báo kiểu dữ liệu tương ứng cho một biến đã được gán giá trị:
#include <stdio.h>
int main()
{
    int myNum = 5; //Vì 5 là số nguyên nên khai báo theo kiểu dữ liệu "int".
    float myFloatNum = 3.14; //Vì 3.14 là số thực nên khai báo theo kiểu dữ liệu "float".
    char myLetter = 'S'; //Vì S là một kí tự nên khai báo theo kiểu dữ liệu "char".
    return 0;
}

//Câu 3: Thay đổi giá trị của một biến:
#include <stdio.h>
int main()
{
    char myLetter; //Khai báo biến "myLetter" theo kiểu "char".
    myLetter = 'A'; //Gán giá trị "A" cho biến "myLetter".
    myLetter = 'X'; //Thay đổi giá trị cho biến "myLetter".
    printf("%c",myLetter); /*Hàm "printf()" sẽ xuất giá trị của biến "myLetter"
    ra màn hình là "X" thay vì là "A".*/
    return 0;
}
//Câu 4: Tính kích thước các biến trong hình:
#include <stdio.h>
int main()
{
    struct
    {
        char c1;
        short sh2;
        long l2;
    }t1;
    #pragma pack(1)
    struct
    {
        char c1;
        short sh2;
        long l2;
    }t2;
    struct
    {
        short sh1;
        long l2;
        char c3;
    }u3;
    struct
    {
        int b1: 3;
        short b2: 2;
        long b3: 6;
    }bf4;
    printf("%lu\n",sizeof(t1));
    printf("%lu\n",sizeof(t2));
    printf("%lu\n",sizeof(u3));
    printf("%lu",sizeof(bf4));
    return 0;
}
//Câu 5: Kể tên các #Keyword có trong C:
/*
Trong ngôn ngữ lập trình C bao gồm 32 từ khoá:
auto; double; int; struct
break; else; long; switch
case; enum; register; typedef
char; extern; return; union
const; float; short; unsigned
continue; for; signed; void
default; goto; sizeof; volatile
do; if; static; while
*/
//Câu 6: Kể tên các bước khi 1 chương trình C được xây dựng. Mô tả từng bước.
//Dưới đây là mô tả cách xây dựng một chương trình C sử dụng IDE VSCode
/*
#include <header file> ==> #include dùng để thông báo cho bộ tiền biên dịch
thêm các thư viện chuẩn trong C, header file dùng để khai các hàm
cần dùng để viết chương trình.
return-type function-name(Type-1 parameter-1, Type-2 parameter-2,etc...) ==> return
trong hàm trả về giá trị.
{ ==> Chương trình C bắt đầu được thực thi.
    Code block; ==> Các khối mã sẽ được viết bên trong dấ
    return Value-return; ==> Đánh dấu kết thúc đoạn mã.
} ==> Bất kỳ đoạn mã nào bên trong cặp dấu ngoặc "{}" sẽ được thực thi.
*/
/*Câu 7: Khai báo kiểu dữ liệu tương ứng cho 2 biến, gán giá trị cho 2 biến
sử dụng toán tử tính chiều dài và chiều rộng sau đó xuất giá trị ra màn hình*/
#include <stdio.h>
int main()
{
    float Length, Width, Area, Perimeter;
    Length = 22.7;
    Width = 15.1;
    Perimeter = (Length+Width)*2;
    Area = Length * Width;
    printf("Chu vi hin  h chu nhat la: %.1f\n",Perimeter);
    printf("Dien tich hinh chu nhat la: %.2f",Area);
    return 0;
}