import RPi.GPIO as GPIO  # GPIO库
import time  # 时间库


class Car():  # 电机类
    def __init__(self):  # 初始化引脚
        self.IN1 = 29
        self.IN2 = 31
        self.IN3 = 33
        self.IN4 = 35
        self.setup()

    def setup(self):  # 设置引脚的模式
        GPIO.setmode(GPIO.BOARD)  # 设置编码模式
        GPIO.setup(self.IN1, GPIO.OUT)
        GPIO.setup(self.IN2, GPIO.OUT)
        GPIO.setup(self.IN3, GPIO.OUT)
        GPIO.setup(self.IN4, GPIO.OUT)

    def ahead(self, timevalue=0):  # 前进，参数是前进时间，默认一直前进为0
        self.setup()
        GPIO.output(self.IN1, GPIO.HIGH)
        GPIO.output(self.IN2, GPIO.LOW)
        GPIO.output(self.IN3, GPIO.HIGH)
        GPIO.output(self.IN4, GPIO.LOW)
        if timevalue != 0:
            time.sleep(timevalue)  # 程序挂起时间
            self.stop()

    def left(self, timevalue=0):  # 左转弯
        self.setup()
        GPIO.output(self.IN1, False)
        GPIO.output(self.IN2, False)
        GPIO.output(self.IN3, GPIO.HIGH)
        GPIO.output(self.IN4, GPIO.LOW)
        if timevalue != 0:
            time.sleep(timevalue)
            self.stop()

    def right(self, timevalue=0):  # 右转弯
        self.setup()
        GPIO.output(self.IN1, GPIO.HIGH)
        GPIO.output(self.IN2, GPIO.LOW)
        GPIO.output(self.IN3, False)
        GPIO.output(self.IN4, False)
        if timevalue != 0:
            time.sleep(timevalue)
            self.stop()

    def rear(self, timevalue=0):  # 后退
        self.setup()
        GPIO.output(self.IN1, GPIO.LOW)
        GPIO.output(self.IN2, GPIO.HIGH)
        GPIO.output(self.IN3, GPIO.LOW)
        GPIO.output(self.IN4, GPIO.HIGH)
        if timevalue != 0:
            time.sleep(timevalue)
            self.stop()

    def stop(self):  # 停止
        GPIO.output(self.IN1, False)
        GPIO.output(self.IN2, False)
        GPIO.output(self.IN3, False)
        GPIO.output(self.IN4, False)


class Ultrasonic():  # 超声波类
    def __init__(self, trig, echo):  # 初始化引脚
        self.trig = trig
        self.echo = echo
        self.setup()

    def setup(self):  # 设置对应引脚的模式
        GPIO.setmode(GPIO.BOARD)  # 引脚的编码模式为BOARD
        GPIO.setup(self.trig, GPIO.OUT)  # 设置trig为输出引脚
        GPIO.setup(self.echo, GPIO.IN)  # 设置echo为输入引脚

    def getdistance(self):  # 测距函数
        GPIO.output(self.trig, True)  # 发送前设为高电平
        time.sleep(0.000015)  # 向超声波模块发送15us的脉冲信号
        GPIO.output(self.trig, False)  # 发射完置为低电平
        while GPIO.input(self.echo) == 0:
            pass
        starttime = time.time()  # 开始计时，记录当前时间
        while GPIO.input(self.echo) == 1:
            pass
        endtime = time.time()  # 结束计时
        distance = (endtime - starttime) * 34000 / 2  # 声速*时间除以二。cm做单位
        return distance


class redObestacle():  # 红外避障类
    def __init__(self, out):  # 初始化引脚
        self.out = out
        self.setup()

    def setup(self):
        GPIO.setmode(GPIO.BOARD)  # 设置编码模式
        GPIO.setup(self.out, GPIO.IN)  # 设置out为输入模式

    def obstacle(self):  # 判断障碍，低电平有效（即有障碍物）
        if GPIO.input(out) == 0:
            return False
        else:
            return True


car = Car()
xjreda = redObestacle(21)  # 左一寻迹
xjredb = redObestacle(22)  # 左二寻迹
xjredc = redObestacle(23)  # 左三寻迹
xjredd = redObestacle(24)  # 左四寻迹

#0是有反射不是黑线，1是黑线吸收红外有黑线

time_right = 1  # 遇障碍物右转时间
time_left = 1  # 遇障碍物左转时间

print("请选择避障模式：1.三路寻迹   2.四路寻迹")
a = int(input("输入对应数字："))
if a == 1:
    print("******您选择的是三路寻迹******")#使用的是左数一二三红外寻迹
    car.setup()
    print("小车开始运动")
    try:
        while True:
            if xjreda.obstacle() == 0 and xjredb.obstacle() == 1 and xjredc.obstacle() == 0:  # 左二骑着黑线
                car.ahead()  # 继续前进
            elif xjreda.obstacle() == 1 and xjredb.obstacle() == 0 and xjredc.obstacle() == 0:  # 左一接触到黑线
                car.left(time_left)  # 左转
                car.ahead()  # 继续前进
            elif xjreda.obstacle() == 0 and xjredb.obstacle() == 0 and xjredc.obstacle() == 1:  # 左三接触到黑线
                car.right(time_right)  # 右转
                car.ahead()  # 继续前进
            else:  # 三个都接触不到黑线
                car.left(time_left)  # 左转
                car.ahead(1)  # 前进1S
                if xjreda.obstacle() == 0 #左转还接触不到黑线
                    car.right(time_right)  # 右转
                    car.ahead(1)  # 前进1S
                car.ahead()  # 前进
    except KeyboardInterrupt:  # 使用ctrl+c键终止程序
        car.stop()
        print("停止")
        GPIO.cleanup()  # 清空通道资源

elif a == 2:
    print("******您选择的是四路寻迹******")
    car.setup()
    print("小车开始运动")
    fdistance = 1000  # 初始化，1000无意义
    ldistance = 1000  # 初始化，1000无意义
    rdistance = 1000  # 初始化，1000无意义
    try:
        while True:
            if xjreda.obstacle() == 0 and xjredb.obstacle() == 0 and xjredc.obstacle() == 0 and xjredd.obstacle() == 0:  # 假设黑线在左二左三之间
                car.left(time_left)  # 左转试一下
                car.ahead(1)  # 前进1S
                if xjreda.obstacle() == 0 and xjredb.obstacle() == 0 and xjredc.obstacle() == 1 and xjredd.obstacle() == 0:
                    car.right(time_right)  # 右转
                    car.ahead()  # 继续前进
                elif xjreda.obstacle() == 0 and xjredb.obstacle() == 0 and xjredc.obstacle() == 0 and xjredd.obstacle() == 1:
                    car.right(time_right)  # 右转
                    car.ahead(1)  # 前进1S
                    #car.right(time_right)  # 右转
                    car.ahead(1)  # 前进1S
                    #car.left(time_left)  # 左转试一下
                    car.ahead()  # 继续前进
                elif xjreda.obstacle() == 0 and xjredb.obstacle() == 1 and xjredc.obstacle() == 0 and xjredd.obstacle() == 0:
                    car.ahead(1)  # 前进1S
                    car.left(time_left)  # 左转
                    car.ahead()  # 继续前进
                elif xjreda.obstacle() == 1 and xjredb.obstacle() == 0 and xjredc.obstacle() == 0 and xjredd.obstacle() == 0:
                    car.ahead(1)  # 前进1S
                    car.ahead(1)  # 前进1S
                    car.left(time_left)  # 左转
                    car.ahead()  # 继续前进
            elif xjreda.obstacle() == 0 and xjredb.obstacle() == 0 and xjredc.obstacle() == 1 and xjredd.obstacle() == 0:
                car.right(time_right)  # 右转
                car.ahead()  # 继续前进
            elif xjreda.obstacle() == 0 and xjredb.obstacle() == 0 and xjredc.obstacle() == 0 and xjredd.obstacle() == 1:
                car.right(time_right)  # 右转
                car.ahead()  # 继续前进
            elif xjreda.obstacle() == 0 and xjredb.obstacle() == 1 and xjredc.obstacle() == 0 and xjredd.obstacle() == 0:
                car.left(time_left)  # 左转
                car.ahead()  # 继续前进
            elif xjreda.obstacle() == 1 and xjredb.obstacle() == 0 and xjredc.obstacle() == 0 and xjredd.obstacle() == 0:
                car.left(time_left)  # 左转
                car.ahead()  # 继续前进
    except KeyboardInterrupt:  # 使用ctrl+c键终止程序
        car.stop()
        print("停止")
        GPIO.cleanup()  # 清空通道资源
else:
print("您的输入有误！！！小车无法启动")
GPIO.cleanup()  # 清空通道资源