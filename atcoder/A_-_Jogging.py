# 
# ?Problem:  https://atcoder.jp/contests/abc249/tasks/abc249_a
# *Solution: just replace b with a and e with d, question mistake

b,a,c,e,d,f,x = [int(i) for i in input().split()]
tk = x//(b+c)
Takahashi = a*b*tk + min(b,x%(b+c))*a
ak = x//(e+f)
Aoki = d*e*ak + min(e,x%(e+f))*d
if Takahashi > Aoki:
    print('Takahashi')
elif Takahashi < Aoki:
    print('Aoki')
else:
    print('Draw')