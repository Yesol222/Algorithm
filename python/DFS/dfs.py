

def dfs(graph,start_node):
    visited = list()
    stack = [start_node]

    while stack:
        n = stack.pop()
        if n not in visited:
            visited.append(n)
            # stack += graph[n] - set(visied)
            stack.extend(reversed(graph[n]))
            #to search from left to right, push linked nodes in reversed order
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

    print(dfs(graph,0))

if __name__ == '__main__':
    main()
