# @param {Integer[]} nums
# @return {Boolean}
def contains_duplicate(nums)
    element_cnt = Hash.new(0);
    nums.each() do |num|
        element_cnt[num] += 1
        return true if element_cnt[num] > 1
    end
    return false
end