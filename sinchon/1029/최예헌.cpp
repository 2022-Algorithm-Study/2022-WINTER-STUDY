//ll solve(ll visited,ll pre,ll now){
//    if (visited == (1<<n)-1){       // 다 방문한 경우
//        return 0;
//    }
//    
//    if (dp[visited][pre][now]!=-1){
//        return dp[visited][pre][now];
//    }
//    
//    dp[visited][pre][now]=0;
//    for (int i=0;i<n;i++){
//        if ((1<<i)&visited || w[pre][now] > w[now][i])
//            continue;
//        
//        dp[visited][pre][now]=max(dp[visited][pre][now],solve(visited|(1<<i),now,i)+1);
////        cout<<now<<" "<<i<<": "<<bitset<5>(visited)<<" "<<dp[visited][now]<<"\n";
//    }
//    return dp[visited][pre][now];
//}
