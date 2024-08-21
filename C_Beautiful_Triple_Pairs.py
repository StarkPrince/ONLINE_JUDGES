for _ in range(int(input())):
    n = int(input())
    lt = input().split()
    triplets = {}
    dct1 = {}
    dct2 = {}
    dct3 = {}

    for i in range(n-2):
        nm1 = str(lt[i]) +" " + str(lt[i+1])
        nm2 = str(lt[i+1]) + " " +str(lt[i+2]) 
        nm3 = str(lt[i]) + " " + str(lt[i+2])
        if nm1 not in dct1:
            dct1[nm1] = set()
        if nm2 not in dct2:
            dct2[nm2] = set()
        if nm3 not in dct3:
            dct3[nm3] = set()
        dct1[nm1].add(i)
        dct2[nm2].add(i)
        dct3[nm3].add(i)
        pm = str(lt[i]) + " " +str(lt[i+1]*10) + " " + str(lt[i+2])
        if pm not in triplets:
            triplets[pm] = {i}
        triplets[pm].add(i)
    
    ans1 = ans2 = ans3 = ans4 = 0
    for i,j in dct1.items():
        ans1 += len(j)*(len(j)-1)//2
    for i,j in dct2.items():
        ans2 += len(j)*(len(j)-1)//2
    for i,j in dct3.items():
        ans3 += len(j)*(len(j)-1)//2
    for i,j in triplets.items():
        ans4 += len(j)*(len(j)-1)//2
    
    print(ans1+ans2+ans3-3*ans4)