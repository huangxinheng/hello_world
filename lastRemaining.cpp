class Solution {
public:
    int lastRemaining(int n) {
        int head=1;
        int step=1;
        int remain=n;
        bool left2right=true;
        while(remain>1){
            if(left2right || remain%2==1) // from left to right or the remain is odd number
                head+=step;
            step=step*2;
            remain/=2;
            left2right=!left2right;
        }
        return head;
    }
};