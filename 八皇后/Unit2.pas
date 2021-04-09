unit Unit2;

interface

uses
  Windows, Messages, Classes, SysUtils, StdCtrls, Graphics;

type
  TQS = function(n: integer): boolean of object;
  TQueenThread = class(TThread)
  private
    FBackgroundBitmap: TBitmap;
    FQueenIcon, FSeekIcon, FClashIcon: TIcon;
    FCanvas: TCanvas;
    FCounter: integer;
    FQueen: integer;
    FDemo: boolean;
    FDelay: integer;
    FClashRestoreIcon, FSeekQueenIcon: TIcon;
    FRecursion: boolean;
    QS: TQS;
    procedure SeekFinish(Sender: TObject);
    function QSeek(n: integer): boolean;
    function QSeekNonrecursion(n: integer): boolean;
    function QClash(n: integer): boolean;
    procedure ShowDelete;
    procedure ShowDraw;
    procedure ShowClashRestore;
    procedure SetRecursion(Value: boolean);
  protected
    procedure Execute; override;
  public
    constructor Create(ABackgroundBitmap: TBitmap; AQueenIcon, ASeekIcon, AClashIcon: TIcon; ACanvas: TCanvas);
    procedure ShowResult;
    property Demo: boolean write FDemo;
    property Delay: integer write FDelay;
    property Recursion: boolean write SetRecursion;
  end;

implementation

uses Unit1;

constructor TQueenThread.Create(ABackgroundBitmap: TBitmap; AQueenIcon, ASeekIcon, AClashIcon: TIcon; ACanvas: TCanvas);
begin
  FBackgroundBitmap := ABackgroundBitmap;
  FQueenIcon := AQueenIcon;
  FSeekIcon := ASeekIcon;
  FClashIcon := AClashIcon;
  FCanvas := ACanvas;
  FCounter := 0;
  FDemo := true;
  FDelay := 400;
  SetRecursion(true);
  OnTerminate := SeekFinish;
  inherited Create(true);
end;

procedure TQueenThread.SetRecursion(Value: boolean);
begin
  FRecursion := Value;
  if FRecursion then
    QS := QSeek
  else
    QS := QSeekNonrecursion;
end;

procedure TQueenThread.SeekFinish(Sender: TObject);
begin
  PostMessage(Form1.Handle, WM_SEEKFINISH, 0, 0);
end;

procedure TQueenThread.ShowClashRestore;
var
  i: integer;
  t: TRect;
begin
  for i := 1 to FQueen - 1 do
  begin
    if (Q[FQueen] = Q[i]) or (Abs(Q[FQueen] - Q[i]) = (FQueen - i)) then
    begin
      t := Rect((Q[i] - 1) * CellWidth, (i - 1) * CellHeight, Q[i] * CellWidth, i * CellHeight);
      FCanvas.CopyRect(t, FBackgroundBitmap.Canvas, t);
      FCanvas.Draw((Q[i] - 1) * CellWidth, (i - 1) * CellHeight, FClashRestoreIcon);
    end;
  end;
end;

procedure TQueenThread.ShowDelete;
var
  t: TRect;
begin
  t := Rect((Q[FQueen] - 1) * CellWidth, (FQueen - 1) * CellHeight, Q[FQueen] * CellWidth, FQueen * CellHeight);
  FCanvas.CopyRect(t, FBackgroundBitmap.Canvas, t);
end;

procedure TQueenThread.ShowDraw;
begin
  FCanvas.Draw((Q[FQueen] - 1) * CellWidth, (FQueen - 1) * CellHeight, FSeekQueenIcon);
end;

procedure TQueenThread.ShowResult;
var
  i: integer;
begin
  FCanvas.Draw(0, 0, FBackgroundBitmap);
  FSeekQueenIcon := FQueenIcon;
  for i := 1 to 8 do
  begin
    FQueen := i;
    ShowDraw;
  end;
end;

function TQueenThread.QSeek(n: integer): boolean;
begin
  if n > 0 then
  begin
    //==========demo begin==========
    if FDemo then
    begin
      FQueen := n; //Setup variable for call synchronize
      Synchronize(ShowDelete);
    end;
    //==========demo end============
    inc(Q[n]);
    //==========demo begin==========
    if FDemo then
    begin
      FSeekQueenIcon := FSeekIcon;
      Synchronize(ShowDraw);
      sleep(FDelay);
    end;
    //==========demo end============
    if Q[n] <= 8 then
      if QClash(n) then
      begin
        //==========demo begin==========
        if FDemo then
        begin
          FClashRestoreIcon := FClashIcon;
          Synchronize(ShowClashRestore);
          sleep(FDelay);
          FClashRestoreIcon := FQueenIcon;
          Synchronize(ShowClashRestore);
        end;
        //==========demo end============
        result := QSeek(n);
      end
      else
      begin
        //==========demo begin==========
        if FDemo then
        begin
          Synchronize(ShowDelete);
          FSeekQueenIcon := FQueenIcon;
          Synchronize(ShowDraw);
          sleep(FDelay);
        end;
        //==========demo end============
        result := true
      end
    else
    begin
      Q[n] := 0;
      if QSeek(n - 1) then
        result := Qseek(n)
      else
        result := false;
    end;
  end
  else
    result := false;
end;

function TQueenThread.QSeekNonrecursion(n: integer): boolean;
var
  flag: boolean;
  m: integer;
begin
  m := n;
  flag := false;
  repeat
    //==========demo begin==========
    if FDemo then
    begin
      FQueen := n;
      Synchronize(ShowDelete);
    end;
    //==========demo end============
    inc(Q[n]);
    //==========demo begin==========
    if FDemo then
    begin
      FSeekQueenIcon := FSeekIcon;
      Synchronize(ShowDraw);
      sleep(FDelay);
    end;
    //==========demo end============
    if Q[n] > 8 then
    begin
      Q[n] := 0;
      dec(n);
    end
    else
      if not QClash(n) then
      begin
        //==========demo begin==========
        if FDemo then
        begin
          Synchronize(ShowDelete);
          FSeekQueenIcon := FQueenIcon;
          Synchronize(ShowDraw);
          sleep(FDelay);
        end;
        //==========demo end============
        if m = n then
          flag := true
        else
          inc(n);
      end
      else
        //==========demo begin==========
        if FDemo then
        begin
          FClashRestoreIcon := FClashIcon;
          Synchronize(ShowClashRestore);
          sleep(FDelay);
          FClashRestoreIcon := FQueenIcon;
          Synchronize(ShowClashRestore);
        end;
        //==========demo end============
  until flag or (n < 1);
  result := flag;
end;

function TQueenThread.QClash(n: integer): boolean;
var
  flag: boolean;
  i: integer;
begin
  flag := false;
  i := 1;
  while (i < n) and not flag do
  begin
    flag := (Q[n] = Q[i]) or (Abs(Q[n] - Q[i]) = (n - i));
    inc(i);
  end;
  result := flag;
end;

procedure TQueenThread.Execute;
var
  i: integer;
begin
  for i := 1 to 7 do
    QS(i);
  while QS(8) do
  begin
    if FDemo then
      Beep
    else
      Synchronize(ShowResult);
    inc(FCounter);
    PostMessage(Form1.Handle, WM_SEEKSUSPEND, 0, 0);
    Suspend;
  end;
end;

end.
