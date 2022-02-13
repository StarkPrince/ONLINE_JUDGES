import time

def generateParenthesis(n):
    return helper("",n,n)
        
def helper(paren,op,cl):
    ans = []
    if op==0 and cl==0:
        return [paren]
    if op==0:
        ans += helper(paren+")",op,cl-1)
    else:
        if op>0:
            ans += helper(paren+"(",op-1,cl)
        ans += helper(paren+")",op,cl-1)
    print(ans,op,cl,paren)
    return ans

print(generateParenthesis(3))