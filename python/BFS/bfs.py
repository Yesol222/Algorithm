from collections import deque

def bfs(graph, start_node):
    visited = list()
    queue = deque()

    queue.append(start_node)

    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.append(node)
            queue.extend(graph[node])
    return visited

def main():
    graph = dict()
    graph[0] = [1, 2]
    graph[1] = [0, 3, 4]
    graph[2] = [0, 5, 6]
    graph[3] = [1]
    graph[4] = [1]
    graph[5] = [2]
    graph[6] = [2]

    print(bfs(graph,0))

if __name__ == '__main__':
    main()
