# BASH
## 命令别名功能
alias
```
alias lsa='ls -al'
```
## 查询指令是否为Bash shell的内部指令
type [-tpa] name
* 输入-t的时候，显示name的来源
```
file:外部指令
alias:通过alias设置别名得到的指令
builtin:内部指令
```
* 输入-p后面的name为外部指令的时候才会完整显示文件名
* -a:会由PATH变量定义的路径中，将所有的name指令列出来，包含alias
[补充]
使用echo $PATH可以查看当前的PATH
```
PATH:当用户输入一个指令的时候，系统会按照PATH变量中的路径从左至右依次查找，知道出现同名文件，并运行这个文件。

❯ echo $PATH
/home/chacha/.local/bin:/opt/ros/jazzy/bin:/home/chacha/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin:/home/chacha/.local/bin:/home/chacha/.local/bin:/home/chacha/.local/bin:/home/chacha/.local/bin

其中':'为各个路径之间的分隔符。
/home/chacha/.local/bin是个人工具包
/opt/ros/jazzy/bin  是ROS相关的工具
/usr/local/bin 手动安装的软件
/usr/bin 大部分指令（python,git）
/snap/bin 通过snap安装的软件qq,wechats
```
## 跳脱功能
如果指令太长，则可以输入\[ENTER]跳脱enter即禁止enter运行程序，输入\enter之后就可以输入接下来的内容。
## 指令编辑快捷键
* [ctrl] + u / [ctrl] + k分别对应从光标开始向前和向后删除指令
* [ctrl] + a / [ctrl] + e分别移动到指令最前面和最后面

## shell的变量功能
shell的变量可以存储数字，字符串，路径等各种信息。
```
name=chacha
#注意等号两侧不能有空格，否则name会被识别成命令。
#如果=后面的内容有空格，则需要使用双引号引起来
echo ${name} 
#引用并输出name的内容
echo "${name}Bot"
#输出chachaBot
```
一般的变量的生存周期仅在当前当前终端。关闭之后，变量就从内存中消失。

如果想永久保留对当前用户的变量可以将变量写进~/.bashrc。
    注意变量前面不加export就只能在当前终端中使用。
    加了export变量就会变成环境变量，可以在任何地方使用。也就是终端里面运行的任何程序(py,c）等都可以用到这个变量。
    保存退出后，记得执行：source ~/.bashrc（让配置立刻生效）。
    注意：tmux中无法执行./bashrc中的内容，需要回到shell才行。
    tmux对应的是~/.zshrc
    ```
    #创建一个命令的"快捷方式"
    alias lsa='ls -al'
    #创建一个变量
    export name=chacha
    ```
设置变量之后想要引用变量只需要在${}的括号中接一个待引用的变量名就行。
变量名称只能是英文和数字，且数字不能作为开头。可以使用跳脱字符'\'。
使用unset取消变量,但是不会从bashrc或者zshrc中消失。重新source就可以恢复使用。
如果要给软件使用alias需要给文件赋予执行权限即chmod +x
```
unset myname
```

## 环境变量的功能
env 观察环境变量与常见环境变量说明
set 观察所有变量，含环境变量与自定义变量

