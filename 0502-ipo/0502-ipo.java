class Solution {
    class Project {
        int profit, capital;

        public Project(int profit, int capital) {
            this.profit = profit;
            this.capital = capital;
        }
    }

    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        if (profits.length == 1) {
            if (capital[0] <= w) {
                return profits[0];
            } else {
                return 0;
            }
        }
        int n = profits.length;

        //For data organisation we created class Projects
        //You can also use another PriorityQueue as per your convenience
        Project[] projects = new Project[n];
        for (int i = 0; i < n; i++) {
            projects[i] = new Project(profits[i], capital[i]);
        }
        
        //Sorting array according to its capital in ascending order;
        Arrays.sort(projects, (a,b) -> a.capital - b.capital);


        // We will use this priorotyqueue in order to get maximum profit i.e. we have declared in Descending order (reverse order)
        PriorityQueue<Integer> maxProfit = new PriorityQueue<Integer>(Collections.reverseOrder());

        int j=0;
        for (int i = 0; i < k; i++) {

            // After first check as "w" will increase we will check if we can again get some more projects done and gain more profit
            while(j < n && projects[j].capital <= w){
                maxProfit.add(projects[j++].profit);
            }
            if(maxProfit.isEmpty()){
                break;
            }

            // Will always give us maximum profit and add it to our capital
            w+=maxProfit.poll();
        }

        return w;
    }
}