docker-oracle-xe-11g
Oracle Express Edition 11g Release 2 on Ubuntu 14.04.1 LTS - including a database for ownCloud CI.

Installation
docker pull deepdiver/docker-oracle-xe-11g
Run with 22 and 1521 ports opened:

docker run -d -p 49160:22 -p 49161:1521 deepdiver/docker-oracle-xe-11g
Connect database with following setting:

hostname: localhost
port: 49161
sid: xe
username: system
password: oracle
Password for SYS & SYSTEM

oracle
Login by SSH

ssh root@localhost -p 49160
password: admin
Connect to ownCloud CI database

username: autotest
password: owncloud

传输文件：
scp -P 49160 init.sql root@localhost:/root/
