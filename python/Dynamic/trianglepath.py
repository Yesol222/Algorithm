
# (y,x) = current point, sum. return max path sum
#path1(y,x,sum) = max path(y+1,x,sum+triangle[y][x]) or path(y+1,x+1,sum+triangle[y][x])

n = 0
triangle[100][100]
answer = 0

def path(y,x):
    if (y == n-1):
        return triangle[y][x]
    answer = triangle[y][x] + max(path(y+1,x),path(y+1,x+1)

print(answer)