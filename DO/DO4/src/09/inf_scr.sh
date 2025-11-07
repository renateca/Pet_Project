#!/bin/bash
cpu=`top -b | head -3 | tail +3 | awk '{print $2}'`
cpu=$(echo $cpu | sed 's/,/./g')

mem_free=`top -b | head -4 | tail +4 | awk '{print $6}'`
mem_free=$(echo $mem_free | sed 's/,/./g')

mem_used=`top -b | head -4 | tail +4 | awk '{print $8}'`
mem_used=$(echo $mem_used | sed 's/,/./g')

mem_cache=`top -b | head -4 | tail +4 | awk '{print $10}'`
mem_cache=$(echo $mem_cache | sed 's/,/./g')

disk_used=`df / | tail -n1 | awk '{print $3}'`
disk_used=$(echo $disk_used | sed 's/,/./g')

disk_available=`df / | tail -n1 | awk '{print $4}'`
disk_available=$(echo $disk_available | sed 's/,/./g')

echo \# TYPE my_cpu_usage gauge
echo my_cpu_usage $cpu 
echo \# TYPE my_mem_free gauge
echo my_mem_free $mem_free
echo \# TYPE my_mem_used gauge
echo my_mem_used $mem_used
echo \# TYPE my_mem_cache gauge
echo my_mem_cache $mem_cache
echo \# TYPE my_disk_used gauge
echo my_disk_used $disk_used
echo \# TYPE my_disk_available gauge
echo my_disk_available $disk_available
