// 无权最短路径问题
// 广度优先搜索

// 高效版
// 利用队列 dist的传递体现在里面
// 线性时间完成, 对于到达不了的点 距离就是无穷了
// 利用队列性质, 每次都是先处理同层的
void Graph::unweighted(Vertex start) {
    Queue<Vertex> q;
    Vertex v, w;

    for (int i = 0; i < NUM_VERTICES; ++i)
        vertices[i].dist = INFINITY;

    start.dist = 0;
    q.makeEmpty();
    q.enqueue(start);

    while (!q.isEmpty()) {
        v = q.dequeue();
        for (w = v.firstEdge; w != nullptr; w = w.nextEdge)
            if (w.dist == INFINITY) {
                w.dist = v.dist + 1;
                w.path = v;  // 保存路径
                q.enqueue(w);
            }
    }
}