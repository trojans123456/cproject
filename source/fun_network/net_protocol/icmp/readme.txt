
/*
icmp(internet control message protocol)互联网控制消息协议
*/

1.分类
差错报文。即通知出错原因的错误信息 (traceroute)

查询报文。即用于诊断的查询消息(ping)

 20-bytes
----------------------
| ip头 |   icmp报文   |
-----------------------


2.报文

0|<-- 8bit     8bit        16bit     -->|31
 ----------------------------------------
 | type   |    code   |    chksum       | ---|
 ----------------------------------------    |
 |                                      |    |---> 8 byte
 |       首部其他部分                   | ---|
 ----------------------------------------
 |                                      |
 |          数据                        |
 ----------------------------------------

 8bit的类型字段和 8bit的代码字段决定是哪种icmp报文

 type        code                      describe                             查询       差错

  0           0                     回显应答(ping)                           √

  3           0                     网络不可达                                           √
              1                     主机不可达                                           √
              2                     协议不可达                                           √
              3                     端口不可达                                           √
              4                     需要进行分片但设置了不分片比特                       √
              5                     源站选路失败                                         √
              6                     目的网络不认识                                       √
              7                     目的主机不认识                                       √
              8                     源主机被隔离                                         √
              9                     目的网络被强制禁止                                   √
              10                    目的主机被强制禁止                                   √
              11                    由于服务类型TOS。网络不可达                          √
              12                    由于服务类型TOS。主机不可达                          √
              13                    由于过滤。通信被强制禁止                             √
              14                    主机越权                                             √
              15                    优先权中止生效                                       √

 4             0                    源端被关闭                                           √

 5             0                    对网络重定向                                         √
               1                    对主机重定向                                         √
               2                    对服务类型和网络重定向                               √
               3                    对服务类型和主机重定向                               √

 8             0                    请求回显                                        √

 9             0                    路由器通告                                      √

 10            0                    路由器请求                                      √

 11            0                    传输期间生存时间为0(traceroute)                      √
               1                    在数据报组装期间生存时间为0                          √

 12            0                    坏的ip首部                                      √
               1                    缺少必须的选项                                  √

 13            0                    时间戳请求                                      √

 14            0                    时间戳应答                                      √

 15

 16

 17            0                    地址掩码请求                                    √


 18            0                    地址掩码应答                                    √

