from collections import deque

#not one directional graph

def dfs(graph,V):
    stack = [V]
    visited = list()

    while stack:
        node = stack.pop()
        if node not in visited:
            visited.append(node)
            stack.extend(reversed(graph[node]))
    return visited
    
def bfs(graph,V):
    
    queue = deque()
    visited = list()
    queue.append(V)

    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.append(node)
            queue.extend(graph[node])
    return visited



def main():
    n = input().split(' ')
    N, M, V = [int(i) for i in n]
    graph = {}

    for i in range(N):
        edge_info = input().split(' ')
        n1, n2 = [int(j) for j in edge_info]
        if n1 not in graph:
            graph[n1] = [n2]
        elif n2 not in graph[n1]:
            graph[n1].append(n2)

        if n2 not in graph:
            graph[n2] = [n1]
        elif n1 not in graph[n2]:
            graph[n2].append(n1)
 
    print(dfs(graph,V))
    print(bfs(graph,V))


if __name__ == '__main__':
    main()