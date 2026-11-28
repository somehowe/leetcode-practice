# @param {String} s
# @param {String} t
# @return {Boolean}
def is_anagram(s, t)
    s_cnt = Array.new(26, 0);
    t_cnt = Array.new(26, 0);
    s.each_char do |c|
        s_cnt[c.ord - 'a'.ord] += 1
    end
    t.each_char do |c|
        t_cnt[c.ord - 'a'.ord] += 1
    end
    s_cnt == t_cnt 
end