import networkx as nx
import time
import genGraph as gg

def solve_max_clique():
    G, _ = gg.create_graph_with_hidden_clique(4000, 100)
    print("edge length: ",len(G.edges()))
    time_start = time.time()
    max_cliques = list(nx.find_cliques(G))
    time_end = time.time()

    largest_clique = max(max_cliques, key=len)
    largest_clique_size = len(largest_clique)

    # 输出最大团和其大小和时间
    print("最大团：", largest_clique)
    print("最大团大小：", largest_clique_size)
    print("运行时间：", time_end - time_start)
    
    
