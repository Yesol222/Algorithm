int Solution(){

    for(int i=1;i<=n;i++){
        for(int j=1; j<=n;j++) dist[j] = 2147000000;
        Dijkstra(i);
        res[i] = dist[x];
    }

    for(int j=1;j<=n;j++) dist[j]=2147000000;

    Dijkstra(x);

    for(int i=1;i<=n;i++) {
        if(i==x) continue;
        res[i] = res[i]+dist[i];
        if(res[i]>answer) answer=res[i];
    }
    cout << answer;
}
int Solution(){

    for(int i=1;i<=n;i++){
        for(int j=1; j<=n;j++) dist[j] = 2147000000;
        Dijkstra(i);
        res[i] = dist[x];
    }

    for(int j=1;j<=n;j++) dist[j]=2147000000;

    Dijkstra(x);

    for(int i=1;i<=n;i++) {
        if(i==x) continue;
        res[i] = res[i]+dist[i];
        if(res[i]>answer) answer=res[i];
    }
    cout << answer;
}
