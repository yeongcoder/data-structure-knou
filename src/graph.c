/*DFS 재귀호출로 구현*/
void DFS(int v){
    int w;
    extern int VISITED[];
    VISITED[v] = 1;
    while(/*v에 인접한 모든 노드 w*/){
        if(!VISITED[w])
            DFS(w)
    }
}

/*DFS 스택으로 구현*/
void DFSwithStack(int v){
    int n, w;
    extern struct stack *s;
    extern int VISITED[];
    InitStack(s);
    push(s,v);
    VISITED[v] = 1;
    while((n=pop(s)) >= 0){
        VISITED[n] = 1;
        while (/* n에 인접한 모든 노드 w */)
        {
            if(!VISITED[w]){
                push(s,w)
            }
        }
        
    }
}

/*BFS 큐로 구현*/
void BFS(int v){
    int w;
    extern struct queue *q;
    VISITED[v] = 1;
    initQueue(q)
    addQueue(q,v)
    while(!q_empty()){
        v = DeleteQueue(q);
        while(/*v에 인접한 모든 노드 w*/){
            if(!VISITED[w]){
                AddQueue(q,w);
                VISITED[w] = 1
            }
        }
    }
}