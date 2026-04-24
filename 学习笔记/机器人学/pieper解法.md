如果六自由度机械臂，又连续三个轴的轴线交于同一点，那么手臂有解析解。如下图中z4 z5 z6交于同一点，机械臂具有解析解。
![[Pasted image 20260418110410.png]]
**一般设计**：
前三轴：产生移动
后三轴：产生动作
![[Pasted image 20260418110548.png]]
**先解移动的部分**
目的是让“手腕”到达目标位置，因此利用手腕的目标位置反算出前三个手臂的角度。
利用DH法的公式：
![[Pasted image 20260418110813.png]]
其中右上角的矢量为{4}原点所在的位置。
因此，对以上的6自由度机械臂，由目标坐标（x,y,z）有：
![[Pasted image 20260418111039.png]]
利用等式关系有：
![[Pasted image 20260418111235.png]]
以此类推：
![[Pasted image 20260418111254.png]]
带入坐标(x,y,z)有：
![[Pasted image 20260418111449.png]]
![[Pasted image 20260418111701.png]]
  因此得到r和z
 ![[Pasted image 20260418111828.png]]
	 此时，若知道(x,y,z)则r和z都可以知道，由上式可以解出各个角度。
	 ![[Pasted image 20260418112120.png]]
	 ![[Pasted image 20260418112218.png]]
由上式解出theta3之后，利用下面的等式解出theta1和theta2
![[Pasted image 20260418112622.png]]
**得出移动部分的角度之后，解算动作部分的角度。**
* 利用反变换
* 利用欧拉角解算
![[Pasted image 20260418112933.png]]
* 按照dh定义进行转动（运动后的坐标系见“红色”）
	![[Pasted image 20260418140503.png]]
* 按照欧拉角进行转动（运动后的坐标系见绿色）
	![[Pasted image 20260418141208.png]]
	可见对于theta4为了满足ZYZ的次序，在欧拉角变换下，需要多转动180度。其余的同理。

### 举例
![[Pasted image 20260418141302.png]]
**由目标位置反解角度。**
	![[Pasted image 20260418141654.png]]
	1.确定dh表
	![[Pasted image 20260418142350.png]]
		其中表中的theta是未知的，需要根据目标位置进行反解。
	2.先找到物件cup与word的变换矩阵
		![[Pasted image 20260418143011.png]]
	3.再由手与物件cup的关系有
		![[Pasted image 20260418143738.png]]
	4.由pieper法解出theta角
		先求theta1-3
		![[Pasted image 20260418144007.png]]
		![[Pasted image 20260418144107.png]]
		再利用Z_Y_Z求theta4,5,6
		![[Pasted image 20260418144142.png]]
### [[pieper编程实现]]
