dim a,b,x
a = inputbox("运算数a")
b = inputbox("运算数b")
x = inputbox("符号")
if x = "+" then
	msgbox 0 + a + b
elseif x = "-" then
	msgbox 0 + a - b
elseif x = "*" then
	msgbox 0 + a * b
elseif x = "/" then
	msgbox 0 + a / b
end if
