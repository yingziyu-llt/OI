unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, ImgList, ComCtrls;

const
  WM_SEEKFINISH = WM_USER + $1;
  WM_SEEKSUSPEND = WM_USER + $2;
  CellWidth = 50;
  CellHeight = 50;

type
  TForm1 = class(TForm)
    GroupBox1: TGroupBox;
    GroupBox2: TGroupBox;
    GroupBox3: TGroupBox;
    GroupBox4: TGroupBox;
    GroupBox5: TGroupBox;
    GroupBox6: TGroupBox;
    Panel1: TPanel;
    Image1: TImage;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    CheckBox1: TCheckBox;
    CheckBox2: TCheckBox;
    TrackBar1: TTrackBar;
    ComboBox1: TComboBox;
    ComboBox2: TComboBox;
    ListBox1: TListBox;
    Button1: TButton;
    ImageList1: TImageList;
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure CheckBox1Click(Sender: TObject);
    procedure CheckBox2Click(Sender: TObject);
    procedure TrackBar1Change(Sender: TObject);
    procedure ComboBox1Change(Sender: TObject);
    procedure ComboBox2Change(Sender: TObject);
    procedure ListBox1DblClick(Sender: TObject);
  private
    BG: TBitmap;
    QIcon, SIcon, CIcon: TIcon;
    QResult: array of array[1..8] of integer;
    RunFlag: boolean;
  public
    procedure MsgSeekSuspend(var Msg: TMessage); message WM_SEEKSUSPEND;
    procedure MsgSeekFinish(var Msg: TMessage); message WM_SEEKFINISH;
  end;

var
  Form1: TForm1;
  Q: array[1..8] of integer;

implementation

{$R *.dfm}

uses Unit2;

var
  QueenThread: TQueenThread;
  CurrentResultIndex: integer;

procedure TForm1.MsgSeekSuspend(var Msg: TMessage);
var
  i: integer;
begin
  CurrentResultIndex := high(QResult) + 1;
  setlength(QResult, CurrentResultIndex + 1);
  for i := 1 to 8 do
    QResult[CurrentResultIndex, i] := Q[i];
  with ListBox1 do
  begin
    Items.Add(format('%u, %u, %u, %u, %u, %u, %u, %u [%u]', [Q[1], Q[2], Q[3], Q[4], Q[5], Q[6], Q[7], Q[8], CurrentResultIndex + 1]));
    ItemIndex := Count - 1;
  end;
  RunFlag := false;
  Button1.Caption := '&Seek';
end;

procedure TForm1.MsgSeekFinish(var Msg: TMessage);
begin
  MessageBox(Handle, 'End of seek.'+ #13#10#13#10 + 'Restart seek from first queen.', PWChar(Caption), MB_ICONINFORMATION or MB_OK);
  ListBox1.Clear;
  Image1.Canvas.Draw(0, 0, BG);
  QueenThread := nil;
  CurrentResultIndex := -1;
  setlength(QResult, 0);
  Button1.Caption := '&Seek';
end;

procedure TForm1.Button1Click(Sender: TObject);
var
  i: integer;
begin
  if not Assigned(QueenThread) then
  begin
    QueenThread := TQueenThread.Create(BG, QIcon, SIcon, CIcon, Image1.Canvas);
    QueenThread.Demo := CheckBox1.Checked;
    QueenThread.Delay := TrackBar1.Position;
    QueenThread.Recursion := CheckBox2.Checked;
  end;
  if QueenThread.Suspended then
  begin
    with ListBox1 do
    begin
      if (CurrentResultIndex <> high(QResult)) and not RunFlag then
      begin
        for i := 1 to 8 do
          Q[i] := QResult[high(QResult), i];
        QueenThread.ShowResult;
      end;
      ItemIndex := Count - 1;
    end;
    QueenThread.Resume;
    Button1.Caption := '&Pause';
  end
  else
  begin
    QueenThread.Suspend;
    Button1.Caption := '&Resume';
  end;
  RunFlag := true;
end;

procedure TForm1.CheckBox1Click(Sender: TObject);
begin
  TrackBar1.Enabled := CheckBox1.Checked;
  if Assigned(QueenThread) then
    QueenThread.Demo := CheckBox1.Checked;
end;

procedure TForm1.CheckBox2Click(Sender: TObject);
begin
  if Assigned(QueenThread) then
    QueenThread.Recursion := CheckBox2.Checked;
end;

procedure TForm1.ComboBox1Change(Sender: TObject);
var
  n: integer;
begin
  n :=  + ComboBox1.ItemIndex * 3;
  ImageList1.GetIcon(0 + n, QIcon);
  ImageList1.GetIcon(1 + n, SIcon);
  ImageList1.GetIcon(2 + n, CIcon);
  if Assigned(QueenThread) then
    QueenThread.ShowResult;
end;

procedure TForm1.ComboBox2Change(Sender: TObject);
begin
  BG.LoadFromResourceName(hInstance, 'BG' + IntToStr(ComboBox2.ItemIndex + 1));
  if Assigned(QueenThread) then
    QueenThread.ShowResult
  else
    Image1.Canvas.Draw(0, 0, BG);
end;

procedure TForm1.TrackBar1Change(Sender: TObject);
begin
  if Assigned(QueenThread) then
    QueenThread.Delay := TrackBar1.Position;
end;

procedure TForm1.ListBox1DblClick(Sender: TObject);
var
  i: integer;
begin
  if Assigned(QueenThread) and not RunFlag then
  begin
    CurrentResultIndex := ListBox1.ItemIndex;
    for i := 1 to 8 do
      Q[i] := QResult[CurrentResultIndex, i];
    QueenThread.ShowResult;
  end;
end;

procedure TForm1.FormCreate(Sender: TObject);
var
  i: integer;
begin
  for i := 1 to 8 do
    Q[i] := 0;
  BG := TBitmap.Create;
  QIcon := TIcon.Create;
  SIcon := TIcon.Create;
  CIcon := TIcon.Create;
  ComboBox1Change(self);
  ComboBox2Change(self);
  CurrentResultIndex := -1;
end;

procedure TForm1.FormDestroy(Sender: TObject);
begin
  BG.Free;
  QIcon.Free;
  SIcon.Free;
  CIcon.Free;
end;

end.
