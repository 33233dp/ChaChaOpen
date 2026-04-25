# pr_hello

`pr_hello` 是一个 ROS 2 C++ 示例节点，用来演示订阅、回调和再次发布消息的流程。

## 功能

- 订阅 `hello_topic`
- 收到消息后打印日志
- 再向 `hello_topic` 发布一条 `std_msgs/msg/String` 消息，内容为 `hello world`

因为订阅和发布使用的是同一个 topic，当前代码会在收到第一条消息后不断触发自己，形成消息回环。

## 节点行为

1. 节点启动时打印 `created node: hello_node`
2. 当 `hello_topic` 收到一条消息时，`callback()` 被触发
3. `callback()` 打印收到的内容
4. `callback()` 发布一条新的 `hello_topic` 消息
5. 这条新消息再次进入回调，继续循环

## `spin()` 的工作原理

`rclcpp::spin(node)` 的作用不是“自动循环执行你的代码”，而是让节点一直运行，并持续等待和处理事件。

在 ROS 2 里，常见的事件包括：

- 收到订阅消息
- 定时器到点
- 服务请求到来
- Action 状态变化

`spin()` 本身不会主动发消息，也不会自己调用 `callback()`。  
它更像一个“事件分发器”：

1. 节点先通过 `create_subscription()`、`create_publisher()` 或 `create_wall_timer()` 注册好回调
2. `spin()` 一直挂起等待
3. 一旦有事件到来，executor 就把对应的回调调起来执行

所以在你这份代码里：

- `spin()` 负责让节点保持运行
- `callback()` 负责处理收到的消息
- `pub_->publish(...)` 负责把消息发出去

如果没有任何外部消息进入 `hello_topic`，`callback()` 就不会被触发。  
如果 `hello_topic` 收到了第一条消息，而你又在回调里继续发布到同一个 `hello_topic`，那就会形成消息回环，看起来像“不断循环打印”。

## 构造函数和事件的关系

事件到来时，**不会重新触发类的构造函数**。构造函数只在你创建对象的时候执行一次。

在这份代码里，构造函数负责做初始化工作：

- 创建节点
- 打印 `created node: hello_node`
- 创建订阅者 `sub_`
- 创建发布者 `pub_`

真正等到消息到来后，被触发的是你注册的回调函数 `callback()`，不是构造函数。

所以可以把它理解成：

1. 构造函数 = 准备工作，只执行一次
2. `spin()` = 持续等待事件
3. `callback()` = 事件发生时真正执行的处理逻辑

换句话说，在这种“订阅消息并响应”的节点里，`callback()` 基本就是整个节点的核心。
构造函数负责把节点、订阅者、发布者初始化好，`spin()` 负责让节点一直活着，而真正决定节点做什么、怎么处理消息、要不要再发布消息的，就是回调函数。

## 一个节点可以有多个回调函数吗

可以。一个 ROS 2 节点不只可以有一个回调函数，它可以同时注册很多回调，比如：

- 不同订阅者各自的订阅回调
- 定时器回调
- 服务回调
- Action 回调

也就是说，一个节点里可以有多个“事件入口”，每个入口到来时都会触发对应的回调函数。
另外，同一个回调函数也可以被多个订阅者复用，只要你在创建时把它绑定进去就可以。

在你的这个节点里，目前主要就是一个订阅回调 `callback()`，所以它看起来像是整个节点的核心。
如果以后你再加一个定时器回调，那这个节点就会同时拥有“收到消息触发”和“到时间自动触发”两种行为。

## 创建节点时可以写多个订阅者吗

可以。创建节点的时候，不只是可以写一个订阅者，你完全可以同时创建多个订阅者，并且给它们分别绑定不同的回调函数。

例如一个节点里可以同时有：

- 一个订阅 `topic_a`，对应 `callback_a()`
- 另一个订阅 `topic_b`，对应 `callback_b()`

这样当不同 topic 收到消息时，就会进入各自对应的回调函数。
这也是 ROS 2 里很常见的写法，一个节点可以同时处理多个话题，各自负责不同的任务。

## 构建

在工作区根目录执行：

```bash
colcon build --packages-select pr_hello
```

构建完成后记得加载环境：

```bash
source install/setup.bash
```

## 运行

启动节点：

```bash
ros2 run pr_hello pr_hello_node
```

手动发送第一条消息：

```bash
ros2 topic pub /hello_topic std_msgs/msg/String "{data: 'test'}"
```

## 相关文件

- `src/pr_hello/src/pr_hello.cpp`
- `src/pr_hello/CMakeLists.txt`
- `src/pr_hello/package.xml`

## 注意

当前代码中，`sub_` 和 `pub_` 都使用 `hello_topic`，所以节点会自循环打印。
如果你想让它只“收到一次，发布到另一个 topic”，需要把发布 topic 改成不同的名字。
