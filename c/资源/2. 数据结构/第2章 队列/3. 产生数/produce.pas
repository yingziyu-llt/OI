var
  n,k:longint;
  pd:array[0..9,0..9] of boolean;                        //����������
  pp:array[0..10000] of boolean;                         //��Ų������Ķ���
  i,j:longint;
  dl:array[1..100000,1..4] of longint;                   //������4λ��ŵĶ���
  t,w,c:longint;
begin
  assign(input,'produce.in');  reset(input);
  assign(output,'produce.out');rewrite(output);
  readln(n,k);
  fillchar(pp,sizeof(pp),true);
  pp[n]:=false;
  for i:=1 to k do
    begin
      readln(t,w);
      pd[t,w]:=true;
    end;
  dl[1,1]:=n mod 10;
  dl[1,2]:=n div 10 mod 10;
  dl[1,3]:=n div 100 mod 10;
  dl[1,4]:=n div 1000;
  t:=1;
  w:=1;
  repeat
    for i:=1 to 4 do
      for j:=0 to 9 do
        if pd[dl[t,i],j] then
          begin
            c:=dl[t,1]+dl[t,2]*10+dl[t,3]*100+dl[t,4]*1000;  //ԭ������,��234
            c:=round(c-dl[t,i]*exp((i-1)*ln(10)));           //����ȥ����,��2
            c:=round(c+j*exp((i-1)*ln(10)));                 //�ӱ�ص���,��5
            if pp[c] then                                    //����û�в�����
              begin
                inc(w);                                      //����±����
                dl[w,1]:=c mod 10;
                dl[w,2]:=c div 10 mod 10;
                dl[w,3]:=c div 100 mod 10;
                dl[w,4]:=c div 1000;
                pp[c]:=false;                               //��Ǹ���������
              end;
          end;
    inc(t);                                                 //����
  until t>w;
  t:=0;
  for i:=1 to 10000 do                                      //ͳ�Ʊ�ǹ��������ĸ���
    if not pp[i] then inc(t);
  writeln(t);
  close(input);
  close(output);
end.
