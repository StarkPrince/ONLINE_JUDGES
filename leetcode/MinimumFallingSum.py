def helper(matrix,i,j,):
    if i == len(matrix)-1:
        return matrix[i][j]
    mn = 100000
    if j-1 >= 0:
        mn = min(mn,helper(matrix,i+1,j-1))
    if j+1 < len(matrix[0]):
        mn = min(mn,helper(matrix,i+1,j+1))
    mn = min(mn,helper(matrix,i+1,j))

    return matrix[i][j]+mn



def minFallingPathSum(matrix):
    mn = 100000
    for k in range(len(matrix[0])):
        mn = min(mn,helper(matrix,0,k))
    return mn

print(minFallingPathSum([[2,1,3],[6,5,4],[7,8,9]]))
