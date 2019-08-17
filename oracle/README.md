超管进入：
1. sqlplus / as sysdba;

创建账户：
1. sys as sysdba
2. create user xx identified by pwd;
3. grant connect, resouce, dba to xx;
4. 现在就可以使用用户xx进行登录了。

修改用户密码（二选一）：
1. password username
2. alter user username identified by pwd

查看当前用户：
1. show user

查看当前用户的表名：
1. select table_name,tablespace_name,num_rows from user_tables;

查看是否有该用户：
1. select username from dba_users where username='XX';

查看表的列：
1. select * from user_col_commnets;
2. select column_name, data_type from user_tab_columns;

查看表的所有者：
1. select owner from dba_tables where table_name='TB_XX';

查看表中列的属性，包括 数据类型，是否非空等：
1. desc TB_XX;

执行sql
1. @xx.sql
