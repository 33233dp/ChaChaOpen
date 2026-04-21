# linux基本指令

## 常用  
* **cat** cat file.txt 将文件内容读取出来  
* **cp** cp file.txt destination.txt将file拷贝成以destination为名的文件 
* **date**输出日期  
* **ncal**显示日历  
* **bc**计算器软件  
* 查阅bz开头的指令：bz[tab][tab]  
* 终端中#开头表示root用户，$开头表示一般用户（注意root和sudo的密码是不同的）  
  使用sudo passwd root 可以设置root密码
## su -

将身份切换为root
## 关机 

关机的时候应当注意：\
系统的使用状态：*who*看在线的用户;*ps -aux*查看主机的使用状态\
**关机指令**  
```  

关机与重新启动:  
shutdown  
reboot  
将数据同步写入硬盘中:sync  
定时关机：shutdown -h 21:25  
立即关机：shutdown -h now
立即重新启动：shutdown -r now
系统关机停电：systemctl poweroff
系统重新启动: systemctl reboot
```  

# 文件权限与目录配置  
## 使用者与群组  
* **列出所有文件及其属性** ls -al  
## 变更文件权限与属性  
* **chgrp** 改变所处群组  
```  
递归变更：  
chgrp -R group_name dirname  
普通变更(将群组改变成users)：  
chgrp users file.txt  
```  
* **chown** 改变拥有者  
-r 递归变更  
* **chmod**改变权限    
```  
[1]数字类型改变权限  
r-4  (二进制第三位)
w-2  
x-1  
rwx-7(111)
例如：chmod 777 .bashrc
[2]符号类型改变权限  
```  
## 目录与文件的权限  
文件能否被执行由[x]决定，与文件名和拓展名无关  
* **文件** 存储数据  
* **目录**  记录文件名列表  
    r-具有读取目录结构列表的权限  
    w-具有 建立新的文件，目录  删除已经存在的文件与目录  更名 移动  
    x-决定用户能否进入这个目录  
## 文件种类与文件拓展名 
* **文件种类**  
    * ** 正规文件** 
        纯文本文档，二进制文件，数据格式文件，
    * **目录**  
    * **连接档** 属性为l即lrwxrwxrwx,是快捷方式
    * **设备与装置文件** 
        区块设备档 存储数据  
        字符设备文件 接口设备  
    * **资料接口文件(sockets)**  属性为s
    * **数据传输文件(FIFO pipe)** 
        FIFO用于解决同时存储同一个文件造成的问题
* **文件拓展名**  
linux没有所谓的拓展名，文件能否被执行取决于属性x。但是有x不一定能执行成功。  
* *.sh：脚本或者批处理文件  
* *.zip等：压缩文件  
* *。html：网页相关文件  

## linux目录配置

### Linux FHS 文件系统层次结构标准  

| 属性分类 | 可分享的 (Shareable) | 不可分享的 (Unshareable) |
| :--- | :--- | :--- |
| **不变的 (Static)** | `/usr` (软件放置处)<br>`/opt` (第三方协作软件) | `/etc` (配置文件)<br>`/boot` (开机与核心档) |
| **可变动的 (Variable)** | `/var/mail` (使用者邮件信箱)<br>`/var/spool/news` (新闻组) | `/var/run` (程序相关)<br>`/var/lock` (程序锁相关) |



