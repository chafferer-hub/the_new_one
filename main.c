#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>//为mysql服务
#include <mysql.h> //mysql数据库头文件

#pragma warning(disabled : 4996)//针对一些不全函数警告

//声明对书本操作的相关函数
void book_show_information();//显示所有存入图书的信息
void add_book();//向数据库中添加图书
void revise_book();//修改图书的信息
void delete_book();//在数据库中删除图书的信息
void search_book();//查询书本信息

//显示相关函数
void menu_cover(void);//进入程序显示
void show_menu(void);//菜单栏是否需要再次显示

//数据库相关变量
MYSQL mysql; //mysql对象
MYSQL_RES *result; //结果集变量
MYSQL_ROW row;//行变量

char ch[2];

//主程序，显示菜单，接收指令
int main()
{
    menu_cover();//显示主菜单

    int commend;//用于存放用户输入的指令

    scanf("%d", &commend);
    getchar();

    while (commend)
    {
        mysql_init(&mysql);//初始化mysql结构

          switch (commend)
        {
            case 1: book_show_information();break;//显示全部
            case 2: add_book();break;//添加书
            case 3: revise_book();break;//修改书
            case 4: delete_book();break;//删除书
            case 5: search_book();break;//查找书
            case 6: exit(0);
            default:break;
        }

            show_menu();

            scanf("%d", &commend);
            getchar();
    }
}

void menu_cover(void)
{
    printf("\n\n");
    printf("\t╔═════════════════════════════════════════════╗\n");
    printf("\t║       Welcome To Lemon Books System         ║\n");
    printf("\t╠═════════════════════════════════════════════╣\n");
    printf("\t║          1 - show all of the books          ║\n");
    printf("\t║          2 - add books                      ║\n");
    printf("\t║          3 - revise the books               ║\n");
    printf("\t║          4 - delete the books               ║\n");
    printf("\t║          5 - search for books               ║\n");
    printf("\t║          6 - exit                           ║\n");
    printf("\t╚═════════════════════════════════════════════╝\n");
    printf("\n              ENTER YOUR CHOICE(1-6):");
}

void show_menu(void)//是否需要打印主菜单
{
    printf("\t显示主菜单？（Y/N）：");
    char cha = 'Y';

    scanf("%c",&cha);
    getchar();

    if (cha == 'Y' || cha == 'y')
        menu_cover();
    else
        printf("\t请继续输入指令：");
}

void book_show_information(void)//显示所有数据
{
    //连接数据库
    if (!mysql_real_connect(&mysql, "localhost", "root", "123456", "db_books", 0, NULL, 0))
    {
        //函数调用成功返回true
        // mysql_real_connect函数八个参数分别为mysql_init返回指针，host，账户名，密码，数据库，port端口，unix连接方式，client——flag
        printf("连接数据库失败\n");//连接失败
    }
    else
    {
        //连接成功的情况下
        if (mysql_query(&mysql, "select * from db_books"))
            //查询数据表tb_books中的所有字段 查询成功，返回false
        {
            printf("\n查询数据库失败\n");
        }

        else{
            result = mysql_store_result(&mysql);//获取结果集
            if (mysql_num_rows(result) != 0)//获得行数，在行数不为0的情况下进行
            {
                printf("\t ══════════════════════════════════════════════ \n");
                printf("\t                 显 示 所 有 图 书 信 息                  \n");
                printf("\t ══════════════════════════════════════════════ \n");
                printf("\t  图书编号       图书名         作者        出版社      \n");
                printf("\t ---------------------------------------------- \n");
                while ((row = mysql_fetch_row(result)) != 0) //取出结果集中的下一行数据
                {
                    //取出结果集中记录
                    fprintf(stdout, "\t  %s       %s         %s        %s   \n", \
                        row[0], row[1], row[2], row[3]);  //输出这行记录 [相当于从文件中取出数据，所以使用了fprintf
                }
                printf("\t ══════════════════════════════════════════════ \n");
            }
            else
                {
                    printf("\n 没有记录数据! \n");
                }
            mysql_free_result(result); //释放结果集
        }
        mysql_close(&mysql); //释放连接
    }
}

void add_book()    //添加图书信息
{
   // int rowcount;   //结果集中的行数

    char book_ID[10];       //编号
    char *book_name; //图书名称
    char *book_author; //图书作者
    char *book_publisher;//出版社

    char *sql; //数据库字符串
    char dest[500] = { "  " };

    //连接数据库
    if (!mysql_real_connect(&mysql, "localhost", "root", "123456", "db_books", 0, NULL, 0))
    {
        printf("\n\t 不能连接数据库!\n");
    }
    else
    {
        //数据库连接成功，插入数据
        printf("\t ══════════════════════════════════════════════ \n");
        printf("\t                 添 加 图 书 信 息                 \n");
        printf("\t ══════════════════════════════════════════════ \n");
        if (mysql_query(&mysql, "select * from db_books"))
        {   //如果查询失败
            printf("\n\t 查询 db_books 数据表失败!\n");
        }
        else
        {
            result = mysql_store_result(&mysql); //获得结果集
            //rowcount = mysql_num_rows(result);  //获得行数
            row = mysql_fetch_row(result);       //获取结果集的行

            printf("\t 图书编号:");
            scanf("%s", book_ID);   //输入图书编号

            if (mysql_num_rows(result) != 0)
            {
                //判断输入的编号是否存在
                do
                {   //存在相同编号
                    if (!strcmp(book_ID, row[0])) //row[0]为每行的第一个元素，即ID，则row[1]则为bookname
                    {
                        //  printf("%s",row[0]);
                        printf("\n\t 记录存在，按任意键继续!\n");
                        getch();
                        mysql_free_result(result);   //释放结果集
                        mysql_close(&mysql);         //释放连接
                        return;
                    }
                } while ((row = mysql_fetch_row(result)) != 0);
            }

            //给字符指针分配内存
            book_name = (char*)malloc(50);
            book_author = (char*)malloc(50);
            book_publisher = (char*)malloc(50);

            //不存在相同的编号
            printf("\t 请输入图书名:");
            scanf("%s", book_name);   //输入图书名

            //将要写入数据库的字符串添加到dest后
            sql = "insert into db_books (book_ID,book_name,book_author,book_publisher) values (";
            strcat(dest, sql);
            strcat(dest, "'");
            strcat(dest, book_ID);
            strcat(dest, "', '");
            strcat(dest, book_name);    //将图书编号追加到sql语句后面

            printf("\t 请输入作者:");
            scanf("%s", book_author);    //输入作者
            strcat(dest, "', '");
            strcat(dest, book_author);

            printf("\t 请输入出版社:");
            scanf("%s", book_publisher);    //输入出版社
            strcat(dest, "', '");
            strcat(dest, book_publisher);
            strcat(dest, "')");
            printf("%s",dest);

            if (mysql_query(&mysql, dest) != 0) //将dest插入到数据库中(db_books)
            {
                fprintf(stderr, "\t 不能插入记录!", mysql_error(&mysql));
            }
            else
            {
                printf("\t 插入成功!\n");
            }
            mysql_free_result(result);    //释放结果集
        }
        mysql_close(&mysql);          //释放连接
    }
}


void search_book()   //查询图书信息
{
    char id[10];
    char *sql;
    char dest[100] = { "  " };

    if (!mysql_real_connect(&mysql, "localhost", "root", "123456", "db_books", 0, NULL, 0))
    {
        printf("\t 不能连接数据库!\n");
    }
    else
    {
        printf("\t 请输入您想要查询的图书编号:");
        scanf("%s", id);   //输入图书编号
        sql = "select * from db_books where id="; //查询条件
        strcat(dest, sql);
        strcat(dest, id);    //将图书编号追加到sql语句后面

        if (mysql_query(&mysql, dest))
        {   //如果查询失败
            printf("\n 查询 tb_book 数据表失败!\n");
        }
        else
        {
            result = mysql_store_result(&mysql); //获得结果集
            if (mysql_num_rows(result) != 0)
            {  //有记录的情况,只有有记录取数据才有意义
                printf("\t ══════════════════════════════════════════════ \n");
                printf("\t                   显示图书信息                      \n");
                printf("\t ══════════════════════════════════════════════ \n");
                printf("\t图书编号       图书名         作者        出版社      \n");
                printf("\t ---------------------------------------------- \n");
                while ((row = mysql_fetch_row(result)))
                {   //取出结果集中记录
                    fprintf(stdout, "\t  %s       %s         %s        %s   \n", row[0], row[1], row[2], row[3]);  //输出这行记录
                }
                printf("\t ══════════════════════════════════════════════ \n");
            }
            else
            {
                printf("\t 没有发现要查询的信息!\n");
            }
            mysql_free_result(result);    //释放结果集
        }
        mysql_close(&mysql);          //释放连接
    }
}

void revise_book()
{
    char id[10];   //结果集中的行数
    char *sql;
    char dest[500] = { "  " };
    char dest1[500] = { "  " };

    char *book_name;
    char *author;
    char *book_publisher;

    if (!mysql_real_connect(&mysql, "localhost", "root", "123456", "db_books", 0, NULL, 0))
    {
        printf("\t 不能连接数据库!\n");
    }
    else
    {
        //数据库连接成功
        // printf("连接成功");
        printf("\t 请输入您想要修改的图书编号.");

        scanf("%s", id);   //输入图书编号
        sql = "select * from db_books where id=";
        strcat(dest, sql);
        strcat(dest, id);    //将图书编号追加到sql语句后面]

        //printf("%s\n",dest);

        //查询该图书信息是否存在
        if (mysql_query(&mysql, dest))
        {   //如果查询失败
            printf("\n  查询 db_books 数据表失败! \n");
        }
        else
        {
            result = mysql_store_result(&mysql); //获得结果集
            if (mysql_num_rows(result) != 0)
            {
                //有记录的情况,只有有记录取数据才有意义
                printf("\t 发现记录信息,是否显示?(y/n) ");
                scanf("%s", ch);
                if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)//判断是否要显示查找到的信息
                {
                    printf("\t ══════════════════════════════════════════════ \n");
                    printf("\t               ***** 显示图书信息 *****                   \n");
                    printf("\t ══════════════════════════════════════════════ \n");
                    printf("\t图书编号       图书名         作者        出版社      \n");
                    printf("\t ---------------------------------------------- \n");
                    while ((row = mysql_fetch_row(result)))
                    {   //取出结果集中记录
                        fprintf(stdout, "\t  %s       %s         %s        %s   \n", row[0], row[1], row[2], row[3]);  //输出这行记录
                    }
                    printf("\t ══════════════════════════════════════════════ \n");
                }


                printf("\t 是否需要修改?(y/n)");
                scanf("%s", ch);
                if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)    //判断是否需要录入
                {


                    sql = "update db_books set book_name= '";
                    strcat(dest1, sql);
                    //   printf("%s",sql);
                    book_name = (char*)malloc(20);
                    author = (char*)malloc(20);
                    book_publisher = (char*)malloc(20);

                    printf("\t 图书名:");
                    scanf("%s", book_name);   //输入图书名

                    strcat(dest1, book_name);
                    //  printf("%s",&book_name);

                    printf("\t 作者:");
                    scanf("%s", author);    //输入作者
                    strcat(dest1, "', author= '");
                    strcat(dest1, author);    //追加sql语句]

                    printf("\t 出版社:");
                    scanf("%s", book_publisher);    //输入出版社
                    strcat(dest1, "', book_publisher = '");
                    strcat(dest1, book_publisher);    //追加sql语句

                    strcat(dest1, "' where id= ");
                    strcat(dest1, id);

                    //printf("%s",dest1);

                    if (mysql_query(&mysql, dest1) != 0)
                    {
                        fprintf(stderr, "\t 不能修改记录!\n", mysql_error(&mysql));
                    }
                    else
                    {
                        printf("\t 修改成功!\n");
                    }
                }

            }
            else
            {
                printf("\t 没有发现要修改的信息!\n");
            }
        }
        mysql_free_result(result);          //释放结果集
    }
    mysql_close(&mysql);     //释放连接
}

void delete_book()   //删除图书信息
{
    char id[10];   //结果集中的行数
    char *sql;
    char dest[100] = { "  " };
    char dest1[100] = { "  " };
    if (!mysql_real_connect(&mysql, "localhost", "root", "123456", "db_books", 0, NULL, 0))
    {
        printf("\t 不能连接数据库!\n");
    }
    else
    {
        printf("\t 请输入您想要删除的图书编号. ");
        scanf("%s", id);   //输入图书编号
        sql = "select * from tb_book where id=";
        strcat(dest, sql);
        strcat(dest, id);    //将图书编号追加到sql语句后面
        //printf("%s\n",dest);

        //查询该图书信息是否存在
        if (mysql_query(&mysql, dest))
        {   //如果查询失败
            printf("\n 查询 tb_book 数据表失败! \n");
        }
        else
        {
            result = mysql_store_result(&mysql); //获得结果集
            if (mysql_num_rows(result) != 0)
            {  //有记录的情况,只有有记录取数据才有意义
                printf("\t 发现记录信息,是否显示?(y/n) ");
                scanf("%s", ch);
                if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)//判断是否要显示查找到的信息
                {
                    printf("\t ══════════════════════════════════════════════ \n");
                    printf("\t               ***** 显示图书信息 *****                   \n");
                    printf("\t ══════════════════════════════════════════════ \n");
                    printf("\t图书编号       图书名         作者        出版社      \n");
                    printf("\t ---------------------------------------------- \n");
                    while ((row = mysql_fetch_row(result)))
                    {   //取出结果集中记录
                        fprintf(stdout, "\t  %s       %s         %s        %s   \n", row[0], row[1], row[2], row[3]);  //输出这行记录
                    }
                    printf("\t ══════════════════════════════════════════════ \n");
                }

                printf("\t 是否删除?(y/n) ");
                scanf("%s", ch);
                if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)    //判断是否需要删除
                {
                    sql = "delete from tb_book where ID= ";
                    printf("%s", dest1);
                    strcat(dest1, sql);
                    strcat(dest1, id);
                    // printf("%s",dest1);

                    if (mysql_query(&mysql, dest1) != 0)
                    {
                        fprintf(stderr, "\t 不能删除记录! \n", mysql_error(&mysql));
                    }
                    else
                    {
                        printf("\t 删除成功!\n");
                    }
                }
            }
            else
            {
                printf("\t 没有发现要删除的信息!\n");
            }
        }
        mysql_free_result(result);    //释放结果集
    }
    mysql_close(&mysql);
}