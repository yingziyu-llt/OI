program ex9_3;
var  n,i,L,k,j:integer;
     b:array[1..100,1..3]of integer;
begin
  assign(input,'lic.in');reset(input);
  assign(output,'lic.out');rewrite(output);
  n := 0;                //��ʼ������������
  while not eoln do
   begin               //eoln���н�����־
     inc(n);
      read(b[n,1]);
      b[n,2]:=1;b[n,3]:=0;
   end;

  for i:=n-1 downto 1 do    //������½�����
      begin
         L:=0;k:=0;
         for j:=i+1 to n do
         if(b[j,1]>b[i,1])and(b[j,2]>L) then begin
                                           L:=b[j,2];
                                           k:=j;
                                         end;
         if L>0 then begin
                        b[i,2]:=L+1;b[i,3]:=k;
                     end;
      end;
      k:=1;
      for j:=1 to n do        //������½����е���ʼλ��
         if b[j,2]>b[k,2] then k:=j;
      writeln('max=',b[k,2]);  //������
      while k<>0  do        //�������½�����
        begin
          write(b[k,1],' ');
          k:=b[k,3];
        end;
      writeln;
      close(input);close(output);
end.
