# mod = 1000000007


# def binpow(a, b, mod):
#     a %= mod
#     res = 1
#     while (b > 0):
#         if (b & 1):
#             res = res * a % mod
#         a = a * a % mod
#         b >>= 1
#     return res


# f = [0] * mod


# def factmod(n, mod):
#     f[0] = 1
#     for i in range(1, mod):
#         f[i] = f[i-1] * i % mod
#     res = 1
#     while (n > 1):
#         if ((n/mod) % 2):
#             res = mod - res
#         res = res * f[n % mod] % mod
#         n //= mod
#     return res
#     # res = 1
#     # for i in range(1, n+1):
#     #     res = res * i % mod
#     # return res


# # n = int(input())
# # d = {i: 0 for i in list("ACGT")}
# # s = input()
# # for j in s:
# #     d[j] += 1
# # num = factmod(n, mod)
# # deno = 1
# # for i in d.values():
# #     t = factmod(i, mod)
# #     deno = deno * t % mod
# # num *= binpow(deno, mod-2, mod)
# # print(num % mod)

# factmod(10, mod)
# print(f)
print(83333334*12 % 1000000007)
