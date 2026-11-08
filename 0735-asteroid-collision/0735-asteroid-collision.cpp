class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for (int ast : asteroids) {
            while (!s.empty() && s.back() > 0 && ast < 0 && s.back() < -1 * ast) s.pop_back();
            if (ast > 0 || s.empty() || s.back() < 0) s.push_back(ast);
            else if (ast < 0 && s.back() == ast * -1) s.pop_back(); // both explode
        }
        return s;
    }
};