var
        a:array[1..1000000] of string;
        n,i,x,j:longint;
        tmp:string;

function swap(i,j:longint):longint;
var
        tmp:string;
begin
        tmp:=a[i];
        a[i]:=a[j];
        a[j]:=tmp;
end;

begin
        assign(input,'maxnum.in');reset(input);
        assign(output,'maxnum.out');rewrite(output);
        readln(n);
        for i:=1 to n do
        begin
          read(x);
          str(x,a[i]);
        end;
        for i:=1 to n-1 do
         for j:=i+1 to n do
           if (a[i]<a[j]) then
             swap(i,j);
        for i:=1 to n-1 do
         for j:=1 to n-1 do  //��ͬ�Ӵ���ĵ�1�����ֺ���һ�ִ���1���Ƚ�,����ǰ
          if (pos(a[j+1],a[j])<>0)and(a[j,length(a[j+1])+1]<a[j,1]) then
            swap(j,j+1);     //����:123��12���ֵΪ12312,321��32���ֵΪ32321
        for i:=1 to n do write(a[i]);
        writeln;
        close(input); close(output);
end.