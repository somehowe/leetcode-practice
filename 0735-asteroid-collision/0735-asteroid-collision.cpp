class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s; // this will be our stack as well
        for (int asteroid : asteroids) {
            if (s.empty() || s.back() < 0 || asteroid > 0) s.push_back(asteroid);
            else if (s.back() < -1 * asteroid) {
                s.pop_back();
                while (!s.empty() && s.back() > 0 && s.back() < -1 * asteroid) s.pop_back();
                if (!s.empty() && s.back() == -1 * asteroid) s.pop_back();
                // only push_back if it is empty or negative
                else if (s.empty() || s.back() < 0) s.push_back(asteroid);
            }
            else if (s.back() == -1 * asteroid) s.pop_back();
            // else it is greater so that one would get destroyed like current asteroid
        }
        return s;
    }
};