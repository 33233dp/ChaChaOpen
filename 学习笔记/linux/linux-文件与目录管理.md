# 目录与路径
## 显示目录
pwd 显示当前所在的目录(printf work directory)
## 创建与删除目录
ls -al test 查看test存在多少目录

mkdir [-mp] 目录名称
-m配置文件权限
-p递归建立

rmdir [-p] 目录名称  删除空目录
-p递归
```
mkdir test
mkdir -p test/test1/test2
mkdir -m 711 test2
rmdir -p test/test1/test2
```
echo 显示指令
echo $PATH 显示path,$代表后面接的变量

## 文件与目录的检视
* ls [-aAdFfhilnRrSt1] 文件目录或名称
* ls [--color={never,auto,always}] 文件目录或名称
* ls [--full -time] 文件目录或名称
## 复制移动与删除 cp mv rm
* cp [-adfilprsu] 源文件(source) 目标文件(destination)
* cp [options] source1 source2 source3  ... directory

* rm [-fir] fileORdirectory
    -f 强制
    -i 交互式（询问是否删除）
    -r 递归删除（最危险）
* 移动文件或者更名 mv [-fiu] source destination
* mv [options] source1 source2 source3 ... directory
    -f 强制，若目标文件存在就不询问直接覆盖
    -i 交互模式，询问是否覆盖已存在的文件
    -u 目标文件存在，但是source最新的时候会覆盖
## 文件内容查询
* cat
* tac
* nl输出内容和行号
* more一页一页显示内容
* head至看透几行
* tail 只看尾巴几行
* od以二进制文件读取 
## 查看文件类型
* file 
## 指令与文件搜寻
which 寻找执行档
* which [-a] command
-a 将所有PATH目录中可以找到的指令列出
whereis 寻找文件或目录
* whereis [-bmsu] 文件或者目录名

