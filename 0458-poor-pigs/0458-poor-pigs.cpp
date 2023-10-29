class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // min_pig_count determined by equation: buckets =max_sub_job_load ** min_pig_count
		// max_sub_job_load  = minutesToTest / minutesToDie + 1
        // min_pig_count = ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
        // (T+1)^p >= N
        return ceil(log2(buckets) / log2(minutesToTest / minutesToDie + 1));
    }
};