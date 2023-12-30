import networkx as nx
import random
import math

def create_graph_with_hidden_clique(V, W):
    G = nx.Graph()
    # 分组
    group_size = V // W
    groups = [list(range(i * group_size, (i + 1) * group_size)) for i in range(W)]

    hidden_clique = [random.choice(group) for group in groups]
    
    #添加最大团
    for i in range(W):
        for j in range(i + 1, W):
            G.add_edge(hidden_clique[i], hidden_clique[j])
            
    
    edges_list = list(G.edges())
    # print(clique)
    # RB模型参数
    n = W
    k = 2
    d = V // W
    a = math.log(d, n)
    p = (k - 1)/k  
    r = (-a)/(math.log(1-p))
    m = r * n * math.log(n)
    edges_num  = (1-p) * (d**k)
    m = int(m)
    print("n:", n)
    print("k:", k)
    print("d:", d)
    print("a:", a)
    print("p:", p)
    print("r:", r)
    print("m:", m)
    print("edges:", edges_num)

    edges_num = int(edges_num)
    
    # 添加相容赋值
    for _ in range(m):
        group1, group2 = random.sample(range(W), k)
        
        for _ in range(edges_num):
            node1 = random.choice(groups[group1])
            node2 = random.choice(groups[group2])
            G.add_edge(node1, node2)
        
    # print("edges_num:", len(G.edges()))
    return G, edges_list
if __name__ == '__main__':
    V = 100
    W = 10
    G, clique = create_graph_with_hidden_clique(V, W)
    print("Nodes:", G.nodes())
    print("Edges:", G.edges())
    print(clique)
    import matplotlib.pyplot as plt
    nx.draw(G, with_labels=True)
    plt.show()
# # 设定顶点数V和最大团大小W
# V = 4000
# W = 100

# # 创建图
# graph = create_graph_with_hidden_clique(V, W)

# # 可以打印图的信息来确认生成的图是否符合要求
# print("Nodes:", graph.nodes())
# print("Edges:", graph.edges())
