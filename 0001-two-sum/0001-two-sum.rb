# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
    seen = {} # 
    nums.each_with_index do |x, i|
        return [seen[target - x], i] if seen.key?(target - x)
        seen[x] = i
    end
    nil
end