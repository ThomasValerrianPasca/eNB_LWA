#!/bin/bash
modprobe tcp_probe port=80
cat /proc/net/tcpprobe >/tmp/data.out &
pid=$!
#iperf -c otherhost
kill $pid
