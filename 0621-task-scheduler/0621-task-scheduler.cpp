class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) {
            ++freq[c - 'A'];
        }
        // the one that constrains you is your most occuring element,
        // the others you can squeeze between that one
        int max_count = 0;
        for (int i = 0; i < 26; ++i) {
            max_count = max(max_count, freq[i]);
        }
        int num_max = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == max_count) ++num_max;
        }
        int other_count = tasks.size() - (max_count * num_max);
        // we should be able to fit these in the gaps basically, and extra will be added onto the end
        // n might no be good enough
        // we have size of interval with how many intervals there are
        int count = max(n + 1, num_max) * (max_count - 1) + num_max;
        int free_slots = (max(n+1, num_max) - num_max) * (max_count - 1); // we need n between them
        if (free_slots < 0) free_slots = 0;
        other_count -= free_slots; // these are the ones we have to have anyway
        if (other_count > 0) {
            count += other_count; // these have to all work becuase they are of lower frequency 
            // we would never need to create new interval for them we could just add them into the
            // interval somewhere
        }
        return count;
    }
};