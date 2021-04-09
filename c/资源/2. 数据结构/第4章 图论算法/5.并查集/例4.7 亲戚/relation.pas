Program relation1;
const	
	maxn=20000;
type
	eletype=record
		   rank,father	:integer;
	end;

procedure work;
var  
   opt :array[1..maxn] of eletype;
   m,i,q :longint;
   n,x,y :integer;

 procedure mdf(r1,r2:integer);
  var
   path  :array[1..maxn]of integer;
    k,i	 :integer;
  begin
	k:=0;
	repeat
	  inc(k);
          path[k]:=r1;
	  r1:=opt[r1].father;
	until r1=opt[r1].father;                      {��r1�������ϵĴ���}
	for i:=1 to k-2 do  opt[path[i]].father:=r1;  {·��ѹ���Ż��������·���ϵĵ�ȫ��ָ������}
	k:=0;
	repeat
	   inc(k);
           path[k]:=r2;
	   r2:=opt[r2].father;
	until r2=opt[r2].father;
	for i:=1 to k-2 do  opt[path[i]].father:=r2;  {ͬ��}
	if r1=r2 then exit;            {r1��r2������ͬһ���ϣ����˳�������������ĺϲ�}
	if opt[r1].rank<opt[r2].rank   {���ð��Ⱥϲ�}
		  then begin
			  opt[r1].father:=r2;
			  inc(opt[r2].rank,opt[r1].rank);
		       end
		else begin
			opt[r2].father:=r1;
			inc(opt[r1].rank,opt[r2].rank);
		     end;
  end;

 begin{work}
    readln(n,m);
    for i:=1 to n do begin           {��ʼ��}
		       opt[i].father:=i;
		       opt[i].rank:=1;
	             end;
    for i:=1 to m do begin
		       readln(x,y);
		       mdf(x,y);     {��������}
	             end;

    readln(q);
    for i:=1 to q do 
      begin
	readln(x,y);
        repeat
           x:=opt[x].father;
        until x=opt[x].father;    {��x�������ϵĴ���}
        repeat
           y:=opt[y].father;
        until y=opt[y].father;    {��y�������ϵĴ���}
		if opt[x].father=opt[y].father
			then writeln('Yes')
			else writeln('No');
    end;
 end;

Begin{main}
	assign(input, 'relation.in'); reset(input);
	assign(output, 'relation.out');rewrite(output);
	work;
close(input);close(output);
End.
