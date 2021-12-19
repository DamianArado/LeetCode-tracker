class Solution {
public:  
    int maxPoints(vector<vector<int>>& points) {
        
        int ans = 0; //this will be our answer
        
        /*
            We use two nested loops. First loop is for picking a point points[i] and
            2nd loop is to pick all the points points[j] except points[i]
        */
        for(int i = 0;i < points.size(); ++i)
        {
            //unordered map to store the slopes of ith point with all other jth points and the frequencies of all the slopes
            unordered_map<double,int> slope;
            
            for(int j = 0; j < points.size(); ++j)
            {
                
                if(j == i)
                    continue;
                
                //this condition is for all slopes except infinity
                if(points[j][0] - points[i][0] != 0)
                {
					//i am typecasting numerator with double because slope can be in decimal
                    double m = ((double)points[j][1] - points[i][1]) / (points[j][0] - points[i][0]); 
                    slope[m]++;
                }
                
                //this condition is if our slope is infinity 
                else
                    slope[INT_MAX]++;
            }
            
            //we find the most frequent slope
            for(auto x:slope)
            {
                ans = max(ans,x.second);
            }
        }
        
        return ans + 1;
    }
};