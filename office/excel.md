1.获取文件名的部分
MID(CELL("filename"); SEARCH("["; CELL("filename"))+1; SEARCH("-"; CELL("filename"))-SEARCH("["; CELL("filename"))-1)

2.连表查询

INDIRECT("综合统计!B"&MATCH(TEXT(MID(CELL("filename";$A$1);FIND("]";CELL("filename";$A$1))+1;LEN(CELL("filename";$A$1))-FIND("]";CELL("filename";$A$1)));"00\3\0"); 综合统计!A3:综合统计!A13; 0)+2)

3.连表运用
INDIRECT(INDIRECT("A"&ROW())&"!F37")&" x 40% + "&INDIRECT(INDIRECT("A"&ROW())&"!F36")&" x 60% = "&INDIRECT(INDIRECT("A"&ROW())&"!F37")*0.4&" + "&INDIRECT(INDIRECT("A"&ROW())&"!F36")*0.6&" = "&INDIRECT(INDIRECT("A"&ROW())&"!F37")*0.4+INDIRECT(INDIRECT("A"&ROW())&"!F36")*0.6&"分"

