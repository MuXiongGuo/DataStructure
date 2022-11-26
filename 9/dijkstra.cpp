/**
 *  Vertex 的结构的伪代码
 *  C++ 实际上应该是 Vertex* 类型
 */

strcut Vertex {
    List adj;  // 邻接表 list<Vertex*>
    bool known;  // 是否已经找到最短路径
    DistType dist;  // 距离 int
    Vertex path;  // 路径 通常为指针
};

// 打印最短路径
void Graph::printPath(Vertex v) {
    if (v.path != nullptr) {
        printPath(v.path);
        cout << " to ";
    }
    cout << v.name;
}

void Graph::dijkstra(Vertex start) {
    for (int i = 0; i < NUM_VERTICES; ++i) {
        vertices[i].known = false;
        vertices[i].dist = INFINITY;
    }

    start.dist = 0;

    while (there is an unknown vertex with minimun distance) {
        Vertex v = smallest unknown distance vertex;
        v.known = true;
        for each Vertex w adjacent to v
            if (!w.known && v.dist + weight(v, w) < w.dist) {
                w.dist = v.dist + weight(v, w);
                w.path = v;
            }
    }
}