function numRescueBoats(people: number[], limit: number): number {
    let i: number = 0;
    let j: number = people.length - 1;
    let boats: number = 0;
    people.sort((a, b) => a - b);
    while(i <= j) {
        if(people[i] + people[j] <= limit) {
            ++i;
            --j;
        } else {
            --j;
        }
        ++boats;
    }
    return boats;
};