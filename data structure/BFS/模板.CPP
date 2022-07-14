void bfs()
{
    queue<int> q;
    q.push(起点);
    标记起始状态入队;
    while (!q.empty())
    {
        top=q.front();
        q.pop();
        for (枚举所有的下一步可能)
        {
            if (check())
            {
                q.push(下一个)
                标记入队
            }
            
        }
        
    }
    
}