class NumArray {
public:
    int n;
    vector<int> segmentTree;

    //function to build segment Tree
    void buildSegmentTree(int i, int l, int r, vector<int>&nums){
        if(l == r){
            segmentTree[i] = nums[l];
            return;
        }//base case

        int mid = l + (r-l)/2;
        buildSegmentTree(2*i+1, l, mid, nums);//left child
        buildSegmentTree(2*i+2, mid+1, r, nums);//right child

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];//creating parent
    }

    void updateSegmentTree(int index, int val, int i, int l, int r){
        if(l == r){
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r-l)/2;
        if(index <= mid){
            updateSegmentTree(index, val, 2*i+1, l, mid);
        }else{
            updateSegmentTree(index, val, 2*i+2, mid+1, r);
        }
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];//update the value
    }

    int querySegmentTree(int left, int right, int i, int l, int r ){
      if(l > right || r < left){
        return 0;
      }

      if(l >= left && r <= right){
        return segmentTree[i];
      }

      int mid = l + (r-l) / 2;
      return querySegmentTree(left, right, 2*i+1, l, mid) + querySegmentTree(left, right, 2*i+2, mid+1, r);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n);//segment tree size
        buildSegmentTree(0, 0, n-1, nums);//0 for root, 0 to n-1 range and vector that we gonna use nums
    }
    
    void update(int index, int val) {
        updateSegmentTree(index, val, 0, 0, n-1); // Point update in a segment tree
    }
    
    int sumRange(int left, int right) {
        return querySegmentTree(left, right, 0, 0, n-1); // Range query
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */