class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if(points.size() != 3){return false;}
        //(y3 - y2)(x2 - x1) = (y2 - y1)(x3 - x2) 
        
        int first  = (points[2][1] - points[1][1])*(points[1][0] - points[0][0]);
        int second = (points[1][1] - points[0][1])*(points[2][0] - points[1][0]);
        
        if(first == second){return false;}
        else{return true;}
        
    }
};