var
  a,b,t,h,n,i:integer;
  q,d,k:array[1..1000]of integer;  //qΪ���У�kΪ¥�����֣�dΪ�˵��ݴ���
  s:set of 1..200;                 //����¥����뼯��
begin
  assign(input,'lift.in');reset(input);
  assign(output,'lift.out');rewrite(output);
  read(n,a,b);
  for i:=1 to n do
    read(k[i]);
  h:=0;                            //��ͷָ��
  t:=1;                            //��βָ��
  q[1]:=a;
  repeat
    inc(h);
    for i:=-1 to 1 do              //��¥����¥
      if (q[h]+k[q[h]]*i>0) and not (q[h]+k[q[h]]*i in s) then
        begin                      //����¥��Ҫ����û����
          inc(t);
          s:=s+[q[h]+k[q[h]]*i];   //���뼯��
          q[t]:=q[h]+k[q[h]]*i;    //���
          d[t]:=d[h]+1;            //��¼�˵��ݴ���
        end;
  until (h=t) or (q[t]=b);
  if a=b then
    writeln(0)
  else
    if q[t]=b then                //����ָ��¥��
      writeln(d[t])
    else
      writeln('-1');              //�޷�����
  close(input);close(output);
end.