var
  n,ks,js:longint;
  k:array[1..200] of longint;                //ÿ������ki
  pd:array[1..200] of boolean;               //�жϸ�¥�㵽����û��
  i,j:longint;
  t,w,l:longint;
  q:array[1..10000,1..2] of longint;         //�ѿ��ܵ���¥������

procedure print(t:longint);
var
  i,j:longint;
begin
  if q[t,2]<>0 then print(q[t,2]);
  inc(l);
end;

begin
  assign(input,'lift.in');  reset(input);
  assign(output,'lift.out');rewrite(output);
  readln(n,ks,js);
  for i:=1 to n do
    read(k[i]);
  fillchar(pd,sizeof(pd),true);
  pd[ks]:=false;
  q[1,1]:=ks;
  t:=1;                                     //��ͷָ��
  w:=1;                                     //��βָ��
  repeat
    if q[t,1]=js then
      begin
        print(t);
        writeln(l-1);
        close(input);
        close(output);
        halt;
      end;
    if k[q[t,1]]<>0 then                     //��ki=0������ݾͲ�����
      begin
        if q[t,1]+k[q[t,1]]<=n then          //�������ϲ��ܳ�����¥
          if pd[q[t,1]+k[q[t,1]]] then       //��¥��û����
          begin
            inc(w);                          //���
            q[w,1]:=q[t,1]+k[q[t,1]];
            q[w,2]:=t;                       //���¶�ͷָ��
            pd[q[w,1]]:=false;               //��Ǹ�¥�㵽��
          end;
        if q[t,1]-k[q[t,1]]>=1 then          //�������²��ܳ���һ¥
          if pd[q[t,1]-k[q[t,1]]] then       //��¥��û����
          begin
            inc(w);                          //���
            q[w,1]:=q[t,1]-k[q[t,1]];
            q[w,2]:=t;                       //���¶�ͷָ��
            pd[q[w,1]]:=false;               //��Ǹ�¥�㵽��
          end;
      end;
    inc(t);                                  //����
  until t>w;
  writeln('-1');
  close(input);
  close(output);
end.