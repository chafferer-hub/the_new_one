# 图书管理系统

## 简介
通过C语言书写各个函数的功能，并连接数据库，实现对数据库的增、删、查、改等操作。

## 需要注意的事项
- *<label style="font-size:20px;color:blue">确保连接mysql数据库</lable>*
   > 需要确保连接数据库成功，不然可能发生数据库调用失败的情况。
   在配置失败的情况下，调用mysql头文件中的库函数可能导致直接跳出主程序但是不会报错。
   ![调用失败但未报错的情况](http://m.qpic.cn/psc?/V50IPqXz3xtREk48vs670eJbLr3oF54h/ruAMsa53pVQWN7FLK88i5q.pPXwSnfIUtm0ysRXDseGTyvoautkfn8uSzjL.HF2zpVmTF*WO6oQRHpu3xqoQenJw4oeb8CGkl2*pCTlgCG0!/b&bo=wwFXAAAAAAADB7c!&rf=viewer_4 "调用失败") 
<br>

- *<label style="font-size:20px;color:#0000FF">头文件的顺序关系</lable>*
  > 需要保证window.h头文件在mysql.h头文件前
  ![头文件顺序](http://m.qpic.cn/psc?/V50IPqXz3xtREk48vs670eJbLr3oF54h/ruAMsa53pVQWN7FLK88i5tatZqVwQSkXVxNF85iyatWnyZIxrlk5vEyZBzfqhc1W4ZKCVCbSXgolH562oSx51XWwNab.M3CeOXPst7.5RoI!/mnull&bo=gwFBAAAAAAADB.E!&rf=photolist&t=5 "头文件顺序")
<br>

- *<label style="font-size:20px;color:blue">demo中连接的是本地数据库</lable>*
    > 调用本地数据库 `mysql_real_connect`
    ![函数调用](http://m.qpic.cn/psc?/V50IPqXz3xtREk48vs670eJbLr3oF54h/ruAMsa53pVQWN7FLK88i5rSLXyFOZSjNocpyeyejSuXgo1sBztnKSUudr7qJrdfk2R3G2csWOB9gVGX11uMCvyyEamPvovkd1RKMS938riI!/b&bo=qwWwAAAAAAADBzw!&rf=viewer_4 "函数调用")
<br>

## 函数示例
`menu_cover()`
``` c {.line-numbers}
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
```

## 函数功能
|函数名称|函数功能|
|-|-|
|`void menu_cover(void)`|显示主菜单|
|`void show_menu(void)`|询问是否需要再次显示主菜单|
|`void book_show_information(void)`|打印出所有存入的书本数据|
|`void add_book() `|添加书本到库中|
|`void search_book()`|查询指定书本信息|
|`void revise_book()`|修改图书的信息|
|`void delete_book() `|删除指定书本|
<br>

# 效果展示
#### 执行
<img src="http://m.qpic.cn/psc?/V50IPqXz3xtREk48vs670eJbLr3oF54h/ruAMsa53pVQWN7FLK88i5uK80WGYTCTR3SbfNlyd3z5*6cVT7BRiXurULaiFgMIEyjco67Dl09wFyOw0ucDoqXigf*gBUizsGio*auRl2iw!/b&bo=LQPKAgAAAAADB8Q!&rf=viewer_4.jpg"  height="330" width="495">

#### 结果
![结果](http://m.qpic.cn/psc?/V50IPqXz3xtREk48vs670eJbLr3oF54h/45NBuzDIW489QBoVep5mcTyJBzKOx7MIrRIiF9YK.JrEaNlq*.SU0aQXi0IJ71ltDupXHnAN9OWKFoaKvLrwKpSoTEGqPL4HSyQZXlhSKNs!/b&bo=KgTxAQAAAAADJ9w!&rf=viewer_4 "结果")
## 配置时的参考文献
[mysql的安装配置](https://blog.csdn.net/shenkeding9350/article/details/84889562)
[连接数据库操作](https://blog.csdn.net/u011633428/article/details/86022135)

* * *
<center style="color:green">2020.8.12</center>  
