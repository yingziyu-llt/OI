s = input().split()
res  = int(s[0]) + int(s[1])
if -9223372036854775808 <= res and res <= 9223372036854775807 :
    print(res)
else:
    print('''"hello, %lld\\n"''')
