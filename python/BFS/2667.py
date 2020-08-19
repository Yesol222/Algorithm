from collections import deque

def bfs(x,y,size):
    queue = deque()
    queue.append((x,y))
    q,p = (0,0)
    while queue:
        x,y = queue.popleft()
        if (x,y) not in visited:
            visited.append((x,y))
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]

                if nx <0 or nx >= N or ny <0 or ny >= N:
                    continue
                if graph[nx][ny] == 0:
                    continue
                if graph[nx][ny] == 1:
                    queue.append((nx,ny))
                    graph[nx][ny] = 0
                    house[size] += 1
                    q,p = nx,ny
        else:
            continue

    size += 1
    for i in range(4):
        nx = q + dx[i]
        ny = p + dy[i]
        if nx <0 or nx >= N or ny <0 or ny >= N:
            continue
        elif (nx,ny) not in visited:
            return nx,ny
        else :
            return (0,0)

N = int(input())
size = 0
house = list()
visited = list()
graph = []

for i in range(N):
    graph.append(list(map(int,input())))

dx = [-1,1,0,0]
dy = [0,0,-1,1]

while len(visited)<(N*N):
    if bfs(0,0,size) == (0,0):
        break
    else:
        x,y = bfs(0,0,size)
    

house.sort()

for i in range(len(house)):
    print(house[i])