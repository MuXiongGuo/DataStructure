// 拓扑排序
// 可以优化的一点是 加入一个盒子 每次取盒子里的一个
// 这个点 导致其他的点 入度为0了 那就把其他点也放进来
// 盒子里都是入度为0的点
void Graph::topsort() {
    for (int i = 0; i < NUM_VERTICES; ++i) {
        Vertex v = findNewVertexOfIndegreeZero();
        if (v == NOT_A_VERTEX) {
            cout << "Error: Graph has a cycle" << endl;
            return;
        }
        v.topNum = counter;
        for each Vertex w adjacent to v
            w.indegreee--;
    }
}

void Graph::topsort() {
    Queue<Vertex> q;
    int counter = 0;

    q.makeEmpty();
    for (int i = 0; i < NUM_VERTICES; ++i) {
        if (vertices[i].indegree == 0)
            q.enqueue(vertices[i]);
    }

    while (!q.isEmpty()) {
        Vertex v = q.dequeue();
        v.topNum = counter++;
        for each Vertex w adjacent to v
            if (--w.indegree == 0)
                q.enqueue(w);
    }

    if (counter != NUM_VERTICES)
        cout << "Error: Graph has a cycle" << endl;
}

// 计算入度 也是线性的
void Graph::findIndegree() {
    for (int i = 0; i < NUM_VERTICES; ++i)
        vertices[i].indegree = 0;
    for (int i = 0; i < NUM_VERTICES; ++i)
        for each Vertex w adjacent to vertices[i]
            w.indegree++;
}
