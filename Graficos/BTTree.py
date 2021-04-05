
import pydot
graph = pydot.Dot(graph_type='graph')



graph.add_node(pydot.Node('{}_0', label='{}'))
graph.add_node(pydot.Node('{}_1', label='{}'))
graph.add_node(pydot.Node('{P1}_1', label='{P1}',color = 'yellow', style = 'filled'))
graph.add_node(pydot.Node('{}_2', label='{}'))
graph.add_node(pydot.Node('{P2}_2', label='{P2}',color = 'yellow', style = 'filled'))
#graph.add_node(pydot.Node('{P1}_2', label='{P1}'))
graph.add_node(pydot.Node('{P2,P3}_3', label='{P2,P3}', color='green', style='filled'))
graph.add_node(pydot.Node('{P1,P2}_2', label='{P1,P2}', color = 'orange', style = 'filled'))
graph.add_node(pydot.Node('{}_3', label='{}'))
graph.add_node(pydot.Node('{P3}_3', label='{P3}'))
#graph.add_node(pydot.Node('{P2}_3', label='{P2}'))
#graph.add_node(pydot.Node('{P1}_3', label='{P1}'))
#graph.add_node(pydot.Node('{P1,P3}_3', label='{P1,P3}'))
#graph.add_node(pydot.Node('{P1,P2}_3', label='{P1,P2}'))
#graph.add_node(pydot.Node('{P1,P2,P3}_3', label='{P1,P2,P3}'))



edge = pydot.Edge("{}_0", "{}_1")
graph.add_edge(edge)
edge = pydot.Edge("{}_0", "{P1}_1")
graph.add_edge(edge)

edge = pydot.Edge("{}_1", "{}_2")
graph.add_edge(edge)
edge = pydot.Edge("{}_1", "{P2}_2")
graph.add_edge(edge)
#edge = pydot.Edge("{P1}_1", "{P1}_2")
#graph.add_edge(edge)

edge = pydot.Edge("{}_2", "{}_3")
graph.add_edge(edge)
edge = pydot.Edge("{}_2", "{P3}_3")
graph.add_edge(edge)
#edge = pydot.Edge("{P2}_2", "{P2}_3")
#graph.add_edge(edge)
edge = pydot.Edge("{P2}_2", "{P3}_3")
graph.add_edge(edge)
edge = pydot.Edge("{P2}_2", "{P2,P3}_3")
graph.add_edge(edge)
#edge = pydot.Edge("{P1}_2", "{P1}_3")
#graph.add_edge(edge)
#edge = pydot.Edge("{P1}_2", "{P1,P3}_3")
#graph.add_edge(edge)

edge = pydot.Edge("{P1}_1", "{P2,P3}_3")
graph.add_edge(edge)

edge = pydot.Edge("{P1}_1", "{P1,P2}_2")
graph.add_edge(edge)
#edge = pydot.Edge("{P1,P2}_2", "{P1,P2}_3")
#graph.add_edge(edge)
#edge = pydot.Edge("{P1,P2}_2", "{P1,P2,P3}_3")
#graph.add_edge(edge)





graph.write_png('BTTree.png')
