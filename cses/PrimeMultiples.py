EPS = 0.001
maxK = 20

n, k = map(int, input().split())
a = [0] * maxK

for i in range(k):
    a[i] = int(input())

cnt = n
# double RHS = log(N) + EPS;
# for(int mask = 0; mask < (1<<K); mask++){
#     bool odd = (__builtin_popcount(mask)&1);

#     ll prod = 1;
#     double LHS = 0.0;
#     for(int i = 0; i < K; i++){
#         if(mask&(1<<i)){
#             LHS += log(a[i]);
#             prod *= a[i];
#         }
#     }

#     if(LHS < RHS)
#         cnt += (odd ? 1 : -1) * (N/prod);
# }

# printf("%lld\n", cnt);
# }
