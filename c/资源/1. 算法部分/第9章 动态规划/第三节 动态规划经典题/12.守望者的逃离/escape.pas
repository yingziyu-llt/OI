


var 
m,s,t,ti:longint; 
ms:array[1..2,0..300000] of longint; 
ts:array[0..300000] of longint; 
begin 
assign(input,'escape.in'); reset(input);
assign(output,'escape.out'); rewrite(output);
readln(m,s,t); 
ms[2,0]:=m; 
ts[0]:=0; 
for ti:=1 to t do {��̬�滮} 
begin 
if ms[2,ti-1]>=10 then {�����ʹ����˸��������} 
begin 
ms[1,ti]:=ms[1,ti-1]+60; 
ms[2,ti]:=ms[2,ti-1]-10; 
end 
else 
begin 
ms[1,ti]:=ms[1,ti-1]; {�ָ�ħ��ֵ} 
ms[2,ti]:=ms[2,ti-1]+4; 
end; 
if ts[ti-1]+17>ms[1,ti] then ts[ti]:=ts[ti-1]+17 else ts[ti]:=ms[1,ti]; {�ҳ����ֵ} 
if ts[ti]>=s then {���˳���ӳ���������} 
begin 
writeln('Yes'); 
writeln(ti); 
close(output);
halt; 
end; 
end; 
writeln('No'); {�޷��ӳ���������} 
writeln(ts[t]); 
close(output);
end. 