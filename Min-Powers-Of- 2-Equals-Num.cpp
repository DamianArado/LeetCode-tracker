/*
 *  Given a number n, represent this number as the summation of the minimum number of powers of 2.
 *
 *  I/P: 13   O/P: [1, 4, 8]  Explanation: 1 + 4 + 8 = 13
 *  I/P: 3   O/P: [1, 2]
 */

// Approach 1 : tc - O(log2n), sc - 2 * O(log2n)
vector<int> minPowersOf2EqualsNum(int number) {
    vector<int> remainders, minPowersOf2;
    while(number > 0) {
        int remainder = number % 2;
        remainders.push_back(remainder);
        number = number / 2;
    }
    for(int i = 0; i < remainders.size(); ++i) {
        if(remainders[i] == 1) 
            minPowersOf2.push_back(pow(2, i));
    }
    sort(minPowersOf2.begin(), minPowersOf2.end());
    return minPowersOf2;
}

// Approach 2: tc & sc - O(log2n)
vector<int> minPowersOf2EqualsNum(int number) {
    vector<int> minPowersOf2;
    int power = 0;
    while(number > 0) {
        if(number % 2 == 1)
            minPowersOf2.push_back(pow(2, power));
        ++power;
        number = number / 2;
    }
    return minPowersOf2;
}

// Best one
vector<int> minPowersOf2EqualsNum(int number) {
    vector<int> minPowersOf2;
    for(int i = 0; i < 32; ++i)
        if(number & (1 << i))
            minPowersOf2.emplace_back(1 << i);
    return minPowersOf2;
}
