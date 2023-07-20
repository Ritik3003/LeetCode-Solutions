class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ans;
        int i = asteroids.size()-1;
        while(i>=0){
            if(asteroids[i]<0){
                s.push(abs(asteroids[i]));
            }
            else{
                while(!s.empty() && s.top()<asteroids[i]){
                    s.pop();
                }
                if(!s.empty() && s.top()==asteroids[i]){
                    s.pop();
                    asteroids.erase(asteroids.begin()+i);
                }
                else if(!s.empty()){
                    asteroids.erase(asteroids.begin()+i);
                }
            }
            i--;
        }
        while(!s.empty()){
            ans.push_back(-s.top());
            s.pop();
        }
        for(int k=0;k<asteroids.size();k++){
            if(asteroids[k]>0) ans.push_back(asteroids[k]);
        }
        return ans;
    }
};