  
  #Basic dfs code
def dfs(graph, start_node):
    visit = list()
    stack = list()
  
    stack.append(start_node)
  
    while stack:
        node = stack.pop()
        if node not in visit:
            visit.append(node)
            stack.extend(graph[node])
 
    return visit

     

def main():
    # N,M = map(int,input("N,M").split())
    N = 4
    M = 5
    graph = list()

    for _ in range(N):
        graph.append(list(map(int, input().split())))
        print(graph)

if __name__ == '__main__':
    main()