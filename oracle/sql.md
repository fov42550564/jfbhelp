drop table location;

--创建表
create table location(
    id varchar2(4) primary key,
    ssi number(10),
    longitude varchar2(12),
    latitude varchar2(12)
    -- syncTime date,
    -- locTime date,
);

-- 注释
comment on column location.ssi is '终端号码';
comment on column location.longitude is '经度';
comment on column location.latitude is '纬度';
-- comment on column location.syncTime is '同步时间';
-- comment on column location.locTime is '定位时间';


--创建序列
-- drop sequence location_seq;
create sequence location_seq start with 1 increment by 1;

--创建触发器
-- select trigger_name from all_triggers where table_name='LOCATION_TRIGGER';
create or replace trigger location_trigger
before insert on location
for each row enable
begin
select location_seq.nextval into :new.id from dual;
end location_trigger;

--添加数据
insert into location (id, ssi, longitude,latitude) values (location_seq.nextval, 123, '113.072000', '23.233217');
insert into location (id, ssi, longitude,latitude) values (location_seq.nextval, 124, '114.072000', '22.233217');

commit;

-- select * from location;
