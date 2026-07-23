int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    set<pair<int,int>>os;
    for(auto& i:obstacles){
        os.insert({i[0],i[1]});
    }
    vector<pair<int,int>>dir = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    int box = 0;
    for(auto& j:dir){
        
        int r = r_q + j.first;
        int c = c_q + j.second;
         while(r>=1 && r<=n && c>=1 && c<=n && !os.count({r,c})){
            box++;
            r +=  j.first;
            c += j.second;
         }
    }
    return box;
}