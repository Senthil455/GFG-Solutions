int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    int time = duration;
    for( int ind = timeSeriesSize - 2 ; ind >= 0  ; ind-- ) {
        if( timeSeries[ind + 1] - timeSeries[ind] < duration) {
            time += timeSeries[ind + 1] - timeSeries[ind];
        }
        else time += duration;
    }
    return time;
}
