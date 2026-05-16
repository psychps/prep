// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int firstbadversion = 1;
        while(right>=left){
            int mid = left + (right-left)/2;
            if(isBadVersion(mid)){
                right = mid-1;
                firstbadversion = mid;
            }
            else{
                left = mid+1;
            }
        }

    return firstbadversion;
    }
};