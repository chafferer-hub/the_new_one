#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>//Ϊmysql����
#include <mysql.h> //mysql���ݿ�ͷ�ļ�

#pragma warning(disabled : 4996)//���һЩ��ȫ��������

//�������鱾��������غ���
void book_show_information();//��ʾ���д���ͼ�����Ϣ
void add_book();//�����ݿ������ͼ��
void revise_book();//�޸�ͼ�����Ϣ
void delete_book();//�����ݿ���ɾ��ͼ�����Ϣ
void search_book();//��ѯ�鱾��Ϣ

//��ʾ��غ���
void menu_cover(void);//���������ʾ
void show_menu(void);//�˵����Ƿ���Ҫ�ٴ���ʾ

//���ݿ���ر���
MYSQL mysql; //mysql����
MYSQL_RES *result; //���������
MYSQL_ROW row;//�б���

char ch[2];

//��������ʾ�˵�������ָ��
int main()
{
    menu_cover();//��ʾ���˵�

    int commend;//���ڴ���û������ָ��

    scanf("%d", &commend);
    getchar();

    while (commend)
    {
        mysql_init(&mysql);//��ʼ��mysql�ṹ

          switch (commend)
        {
            case 1: book_show_information();break;//��ʾȫ��
            case 2: add_book();break;//�����
            case 3: revise_book();break;//�޸���
            case 4: delete_book();break;//ɾ����
            case 5: search_book();break;//������
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
    printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
    printf("\t�U       Welcome To Lemon Books System         �U\n");
    printf("\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
    printf("\t�U          1 - show all of the books          �U\n");
    printf("\t�U          2 - add books                      �U\n");
    printf("\t�U          3 - revise the books               �U\n");
    printf("\t�U          4 - delete the books               �U\n");
    printf("\t�U          5 - search for books               �U\n");
    printf("\t�U          6 - exit                           �U\n");
    printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
    printf("\n              ENTER YOUR CHOICE(1-6):");
}

void show_menu(void)//�Ƿ���Ҫ��ӡ���˵�
{
    printf("\t��ʾ���˵�����Y/N����");
    char cha = 'Y';

    scanf("%c",&cha);
    getchar();

    if (cha == 'Y' || cha == 'y')
        menu_cover();
    else
        printf("\t���������ָ�");
}

void book_show_information(void)//��ʾ��������
{
    //�������ݿ�
    if (!mysql_real_connect(&mysql, "localhost", "root", "123456", "db_books", 0, NULL, 0))
    {
        //�������óɹ�����true
        // mysql_real_connect�����˸������ֱ�Ϊmysql_init����ָ�룬host���˻��������룬���ݿ⣬port�˿ڣ�unix���ӷ�ʽ��client����flag
        printf("�������ݿ�ʧ��\n");//����ʧ��
    }
    else
    {
        //���ӳɹ��������
        if (mysql_query(&mysql, "select * from db_books"))
            //��ѯ���ݱ�tb_books�е������ֶ� ��ѯ�ɹ�������false
        {
            printf("\n��ѯ���ݿ�ʧ��\n");
        }

        else{
            result = mysql_store_result(&mysql);//��ȡ�����
            if (mysql_num_rows(result) != 0)//�����������������Ϊ0������½���
            {
                printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
                printf("\t                 �� ʾ �� �� ͼ �� �� Ϣ                  \n");
                printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
                printf("\t  ͼ����       ͼ����         ����        ������      \n");
                printf("\t ---------------------------------------------- \n");
                while ((row = mysql_fetch_row(result)) != 0) //ȡ��������е���һ������
                {
                    //ȡ��������м�¼
                    fprintf(stdout, "\t  %s       %s         %s        %s   \n", \
                        row[0], row[1], row[2], row[3]);  //������м�¼ [�൱�ڴ��ļ���ȡ�����ݣ�����ʹ����fprintf
                }
                printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
            }
            else
                {
                    printf("\n û�м�¼����! \n");
                }
            mysql_free_result(result); //�ͷŽ����
        }
        mysql_close(&mysql); //�ͷ�����
    }
}

void add_book()    //���ͼ����Ϣ
{
   // int rowcount;   //������е�����

    char book_ID[10];       //���
    char *book_name; //ͼ������
    char *book_author; //ͼ������
    char *book_publisher;//������

    char *sql; //���ݿ��ַ���
    char dest[500] = { "  " };

    //�������ݿ�
    if (!mysql_real_connect(&mysql, "localhost", "root", "123456", "db_books", 0, NULL, 0))
    {
        printf("\n\t �����������ݿ�!\n");
    }
    else
    {
        //���ݿ����ӳɹ�����������
        printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
        printf("\t                 �� �� ͼ �� �� Ϣ                 \n");
        printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
        if (mysql_query(&mysql, "select * from db_books"))
        {   //�����ѯʧ��
            printf("\n\t ��ѯ db_books ���ݱ�ʧ��!\n");
        }
        else
        {
            result = mysql_store_result(&mysql); //��ý����
            //rowcount = mysql_num_rows(result);  //�������
            row = mysql_fetch_row(result);       //��ȡ���������

            printf("\t ͼ����:");
            scanf("%s", book_ID);   //����ͼ����

            if (mysql_num_rows(result) != 0)
            {
                //�ж�����ı���Ƿ����
                do
                {   //������ͬ���
                    if (!strcmp(book_ID, row[0])) //row[0]Ϊÿ�еĵ�һ��Ԫ�أ���ID����row[1]��Ϊbookname
                    {
                        //  printf("%s",row[0]);
                        printf("\n\t ��¼���ڣ������������!\n");
                        getch();
                        mysql_free_result(result);   //�ͷŽ����
                        mysql_close(&mysql);         //�ͷ�����
                        return;
                    }
                } while ((row = mysql_fetch_row(result)) != 0);
            }

            //���ַ�ָ������ڴ�
            book_name = (char*)malloc(50);
            book_author = (char*)malloc(50);
            book_publisher = (char*)malloc(50);

            //��������ͬ�ı��
            printf("\t ������ͼ����:");
            scanf("%s", book_name);   //����ͼ����

            //��Ҫд�����ݿ���ַ�����ӵ�dest��
            sql = "insert into db_books (book_ID,book_name,book_author,book_publisher) values (";
            strcat(dest, sql);
            strcat(dest, "'");
            strcat(dest, book_ID);
            strcat(dest, "', '");
            strcat(dest, book_name);    //��ͼ����׷�ӵ�sql������

            printf("\t ����������:");
            scanf("%s", book_author);    //��������
            strcat(dest, "', '");
            strcat(dest, book_author);

            printf("\t �����������:");
            scanf("%s", book_publisher);    //���������
            strcat(dest, "', '");
            strcat(dest, book_publisher);
            strcat(dest, "')");
            printf("%s",dest);

            if (mysql_query(&mysql, dest) != 0) //��dest���뵽���ݿ���(db_books)
            {
                fprintf(stderr, "\t ���ܲ����¼!", mysql_error(&mysql));
            }
            else
            {
                printf("\t ����ɹ�!\n");
            }
            mysql_free_result(result);    //�ͷŽ����
        }
        mysql_close(&mysql);          //�ͷ�����
    }
}


void search_book()   //��ѯͼ����Ϣ
{
    char id[10];
    char *sql;
    char dest[100] = { "  " };

    if (!mysql_real_connect(&mysql, "localhost", "root", "123456", "db_books", 0, NULL, 0))
    {
        printf("\t �����������ݿ�!\n");
    }
    else
    {
        printf("\t ����������Ҫ��ѯ��ͼ����:");
        scanf("%s", id);   //����ͼ����
        sql = "select * from db_books where id="; //��ѯ����
        strcat(dest, sql);
        strcat(dest, id);    //��ͼ����׷�ӵ�sql������

        if (mysql_query(&mysql, dest))
        {   //�����ѯʧ��
            printf("\n ��ѯ tb_book ���ݱ�ʧ��!\n");
        }
        else
        {
            result = mysql_store_result(&mysql); //��ý����
            if (mysql_num_rows(result) != 0)
            {  //�м�¼�����,ֻ���м�¼ȡ���ݲ�������
                printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
                printf("\t                   ��ʾͼ����Ϣ                      \n");
                printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
                printf("\tͼ����       ͼ����         ����        ������      \n");
                printf("\t ---------------------------------------------- \n");
                while ((row = mysql_fetch_row(result)))
                {   //ȡ��������м�¼
                    fprintf(stdout, "\t  %s       %s         %s        %s   \n", row[0], row[1], row[2], row[3]);  //������м�¼
                }
                printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
            }
            else
            {
                printf("\t û�з���Ҫ��ѯ����Ϣ!\n");
            }
            mysql_free_result(result);    //�ͷŽ����
        }
        mysql_close(&mysql);          //�ͷ�����
    }
}

void revise_book()
{
    char id[10];   //������е�����
    char *sql;
    char dest[500] = { "  " };
    char dest1[500] = { "  " };

    char *book_name;
    char *author;
    char *book_publisher;

    if (!mysql_real_connect(&mysql, "localhost", "root", "123456", "db_books", 0, NULL, 0))
    {
        printf("\t �����������ݿ�!\n");
    }
    else
    {
        //���ݿ����ӳɹ�
        // printf("���ӳɹ�");
        printf("\t ����������Ҫ�޸ĵ�ͼ����.");

        scanf("%s", id);   //����ͼ����
        sql = "select * from db_books where id=";
        strcat(dest, sql);
        strcat(dest, id);    //��ͼ����׷�ӵ�sql������]

        //printf("%s\n",dest);

        //��ѯ��ͼ����Ϣ�Ƿ����
        if (mysql_query(&mysql, dest))
        {   //�����ѯʧ��
            printf("\n  ��ѯ db_books ���ݱ�ʧ��! \n");
        }
        else
        {
            result = mysql_store_result(&mysql); //��ý����
            if (mysql_num_rows(result) != 0)
            {
                //�м�¼�����,ֻ���м�¼ȡ���ݲ�������
                printf("\t ���ּ�¼��Ϣ,�Ƿ���ʾ?(y/n) ");
                scanf("%s", ch);
                if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)//�ж��Ƿ�Ҫ��ʾ���ҵ�����Ϣ
                {
                    printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
                    printf("\t               ***** ��ʾͼ����Ϣ *****                   \n");
                    printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
                    printf("\tͼ����       ͼ����         ����        ������      \n");
                    printf("\t ---------------------------------------------- \n");
                    while ((row = mysql_fetch_row(result)))
                    {   //ȡ��������м�¼
                        fprintf(stdout, "\t  %s       %s         %s        %s   \n", row[0], row[1], row[2], row[3]);  //������м�¼
                    }
                    printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
                }


                printf("\t �Ƿ���Ҫ�޸�?(y/n)");
                scanf("%s", ch);
                if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)    //�ж��Ƿ���Ҫ¼��
                {


                    sql = "update db_books set book_name= '";
                    strcat(dest1, sql);
                    //   printf("%s",sql);
                    book_name = (char*)malloc(20);
                    author = (char*)malloc(20);
                    book_publisher = (char*)malloc(20);

                    printf("\t ͼ����:");
                    scanf("%s", book_name);   //����ͼ����

                    strcat(dest1, book_name);
                    //  printf("%s",&book_name);

                    printf("\t ����:");
                    scanf("%s", author);    //��������
                    strcat(dest1, "', author= '");
                    strcat(dest1, author);    //׷��sql���]

                    printf("\t ������:");
                    scanf("%s", book_publisher);    //���������
                    strcat(dest1, "', book_publisher = '");
                    strcat(dest1, book_publisher);    //׷��sql���

                    strcat(dest1, "' where id= ");
                    strcat(dest1, id);

                    //printf("%s",dest1);

                    if (mysql_query(&mysql, dest1) != 0)
                    {
                        fprintf(stderr, "\t �����޸ļ�¼!\n", mysql_error(&mysql));
                    }
                    else
                    {
                        printf("\t �޸ĳɹ�!\n");
                    }
                }

            }
            else
            {
                printf("\t û�з���Ҫ�޸ĵ���Ϣ!\n");
            }
        }
        mysql_free_result(result);          //�ͷŽ����
    }
    mysql_close(&mysql);     //�ͷ�����
}

void delete_book()   //ɾ��ͼ����Ϣ
{
    char id[10];   //������е�����
    char *sql;
    char dest[100] = { "  " };
    char dest1[100] = { "  " };
    if (!mysql_real_connect(&mysql, "localhost", "root", "123456", "db_books", 0, NULL, 0))
    {
        printf("\t �����������ݿ�!\n");
    }
    else
    {
        printf("\t ����������Ҫɾ����ͼ����. ");
        scanf("%s", id);   //����ͼ����
        sql = "select * from tb_book where id=";
        strcat(dest, sql);
        strcat(dest, id);    //��ͼ����׷�ӵ�sql������
        //printf("%s\n",dest);

        //��ѯ��ͼ����Ϣ�Ƿ����
        if (mysql_query(&mysql, dest))
        {   //�����ѯʧ��
            printf("\n ��ѯ tb_book ���ݱ�ʧ��! \n");
        }
        else
        {
            result = mysql_store_result(&mysql); //��ý����
            if (mysql_num_rows(result) != 0)
            {  //�м�¼�����,ֻ���м�¼ȡ���ݲ�������
                printf("\t ���ּ�¼��Ϣ,�Ƿ���ʾ?(y/n) ");
                scanf("%s", ch);
                if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)//�ж��Ƿ�Ҫ��ʾ���ҵ�����Ϣ
                {
                    printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
                    printf("\t               ***** ��ʾͼ����Ϣ *****                   \n");
                    printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
                    printf("\tͼ����       ͼ����         ����        ������      \n");
                    printf("\t ---------------------------------------------- \n");
                    while ((row = mysql_fetch_row(result)))
                    {   //ȡ��������м�¼
                        fprintf(stdout, "\t  %s       %s         %s        %s   \n", row[0], row[1], row[2], row[3]);  //������м�¼
                    }
                    printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
                }

                printf("\t �Ƿ�ɾ��?(y/n) ");
                scanf("%s", ch);
                if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)    //�ж��Ƿ���Ҫɾ��
                {
                    sql = "delete from tb_book where ID= ";
                    printf("%s", dest1);
                    strcat(dest1, sql);
                    strcat(dest1, id);
                    // printf("%s",dest1);

                    if (mysql_query(&mysql, dest1) != 0)
                    {
                        fprintf(stderr, "\t ����ɾ����¼! \n", mysql_error(&mysql));
                    }
                    else
                    {
                        printf("\t ɾ���ɹ�!\n");
                    }
                }
            }
            else
            {
                printf("\t û�з���Ҫɾ������Ϣ!\n");
            }
        }
        mysql_free_result(result);    //�ͷŽ����
    }
    mysql_close(&mysql);
}