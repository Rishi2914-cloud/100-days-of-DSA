int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};

    // Count frequency of each task
    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    // Find max frequency
    int maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq)
            maxFreq = freq[i];
    }

    // Count how many tasks have max frequency
    int countMax = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq)
            countMax++;
    }

    // Apply formula
    int partCount = (maxFreq - 1) * (n + 1) + countMax;
    return (partCount > tasksSize) ? partCount : tasksSize;
}
